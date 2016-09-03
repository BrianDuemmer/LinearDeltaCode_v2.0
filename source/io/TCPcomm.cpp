/*
 * TCPcomm.cpp
 *
 *  Created on: Aug 30, 2016
 *      Author: Duemmer
 */

#include <source/LinearDelta2.hpp>

// handle for the main TCP Server
static Task_Handle tcpServerTaskHdl;
static Task_Handle tcpClientTaskHdl[MAX_CLIENT_CT];

// server reference
static int server;

// client connection references
static int clientList[MAX_CLIENT_CT];

// called when the server is ready to go
void tcpOpenHook()
{
    Task_Params tcpServerTaskParams;
    Error_Block eb;

    /* Make sure Error_Block is initialized */
    Error_init(&eb);

    /*
     *  Create the Task that farms out incoming TCP connections.
     *  arg0 will be the port that this task listens to.
     */
    Task_Params_init(&tcpServerTaskParams);
    tcpServerTaskParams.stackSize = TCP_SERVER_STACK;
    tcpServerTaskParams.priority = 3;
    tcpServerTaskParams.arg0 = TCP_PORT;
    tcpServerTaskHdl = Task_create((Task_FuncPtr)tcpServerThreadFxn, &tcpServerTaskParams, &eb);
    if (tcpServerTaskHdl == NULL) {
        System_printf("tcpOpenHook: Failed to create tcpHandler Task\n");
        System_flush();
    }
}

// shutdown the server, and all clients. This is called whenever we disconnect from a network
void tcpCloseHook()
{
	int i = 0;
	while(i < MAX_CLIENT_CT)
	{
		i++;
		if(clientList[i] > NULL)
			close(clientList[i]);
		if(tcpClientTaskHdl[i] > NULL)
			Task_delete(&tcpClientTaskHdl[i]);
	}

	Task_delete(&tcpServerTaskHdl);
	if(server > NULL)
		close(server);
}


/*
* thread function for the TCP server. This thread starts running upon connecting
* to a network. It initializes the server, Accepts incoming connections,
* and allocates seperate threads to handle each individual client
*/
void tcpServerThreadFxn(UArg arg0, UArg arg1)
{
    int                status;
    int                clientfd;
    struct sockaddr_in localAddr;
    struct sockaddr_in clientAddr;
    int                optval;
    int                optlen = sizeof(optval);
    socklen_t          addrlen = sizeof(clientAddr);
    Task_Handle        taskHandle;
    Task_Params        taskParams;
    Error_Block        eb;
    // open the server
    server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (server == -1) {
        System_printf("Error: socket not created.\n");
        goto shutdown;
    }


    // initialize localAddr to all 0's
    memset(&localAddr, 0, sizeof(localAddr));

    // set the server address, address type, and port number
    localAddr.sin_family = AF_INET;
    localAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    localAddr.sin_port = htons(arg0);

    // bind the server to a port
    status = bind(server, (struct sockaddr *)&localAddr, sizeof(localAddr));
    if (status == -1) {
        System_printf("Error: bind failed.\n");
        goto shutdown;
    }

    // allow the server to accept MAX_CLIENT_CT number of incoming connections
    status = listen(server, MAX_CLIENT_CT);
    if (status == -1) {
        System_printf("Error: listen failed.\n");
        goto shutdown;
    }

    // set the server options. Shud down the server if it fails
    optval = 1;
    if (setsockopt(server, SOL_SOCKET, SO_KEEPALIVE, &optval, optlen) < 0) {
        System_printf("Error: setsockopt failed\n");
        goto shutdown;
    }

    while ((clientfd =
            accept(server, (struct sockaddr *)&clientAddr, &addrlen)) != -1) {

        System_printf("tcpHandler: Creating thread clientfd = %d\n", clientfd);

        /* Init the Error_Block */
        Error_init(&eb);

        /* Initialize the defaults and set the parameters. */
        Task_Params_init(&taskParams);
        taskParams.arg0 = (UArg)clientfd;
        taskParams.stackSize = 4096;
        taskHandle = Task_create((Task_FuncPtr)tcpClientThreadFxn, &taskParams, &eb);
        if (taskHandle == NULL) {
            System_printf("Error: Failed to create new Task\n");
            close(clientfd);
        }

        /* addrlen is a value-result param, must reset for next accept call */
        addrlen = sizeof(clientAddr);
    }

    System_printf("Error: accept failed.\n");

shutdown:
    if (server > 0) {
        close(server);
    }

    while(1)
    	Task_sleep(2000000); //spin harmlessly to prevent the default taskKill routine
    						 //from running, netCloseHook will take care of it
}

/*
 * TCP client thread:
 *
 * Each time a client connects to the server, a new instance of this task is created to
 * handle communications with that client. This thread accepts incoming Gcode and routes
 * them to their proper destination
 */
void tcpClientThreadFxn(UArg arg0, UArg arg1)
{
    int  clientfd = (int)arg0;
    int  bytesRcvd;
    int  bytesSent;
    char rxbuffer[TCP_PACKET_SIZE] = {0};


    System_printf("tcpWorker: start clientfd = 0x%x\n", clientfd);

    while ((bytesRcvd = recv(clientfd, rxbuffer, TCP_PACKET_SIZE, 0)) > 0)
    {
    	System_printf("recieved %d bytes\n", bytesRcvd);
    	GCline *rcv = new GCline(rxbuffer);
    	rcv->sysPrint();
    	delete rcv;
    }
    System_printf("tcpWorker stop clientfd = 0x%x\n", clientfd);

    close(clientfd);
}


















