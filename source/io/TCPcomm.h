/*
 * TCPcomm.h
 *
 *  Created on: Aug 30, 2016
 *      Author: Duemmer
 */

#ifndef SOURCE_IO_TCPCOMM_H_
#define SOURCE_IO_TCPCOMM_H_


extern "C"
{
	void tcpOpenHook();
	void tcpCloseHook();
	void tcpServerThreadFxn(UArg arg0);
}
#endif /* SOURCE_IO_TCPCOMM_H_ */
