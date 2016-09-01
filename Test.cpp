/*
 * Test.cpp
 *
 *  Created on: Aug 28, 2016
 *      Author: Duemmer
 */

#include <source/LinearDelta2.hpp>


#define MAX_COUNT 10

void gcTest(UArg arg0, UArg arg1){
	char line[] = "N2000 g10 \"DICKS!!!\" x12.34 Y5.6 z7.89 F2000";
	for(int i = 0; i < MAX_COUNT; i++){
		GCline *testLine = new GCline(line);
		testLine->sysPrint();
		delete testLine;
	}
	System_printf("successfully completed %d executions\n", MAX_COUNT);
	System_flush();
	int x = 2;
}

void VecMathTest(UArg arg0, UArg arg1)
{
	vec2d a = {2, 3};
	vec2d b = {4, 5};
	vec2d res;
	float c = 6;

	res = a + b;
	System_printf("add: %f,%f \n", res.x, res.y);

	res = a - b;
	System_printf("sub: %f,%f \n", res.x, res.y);

	res = a * c;
	System_printf("mul: %f,%f \n", res.x, res.y);

	res = a / c;
	System_printf("div: %f,%f \n", res.x, res.y);

	res = a;
	res += b;
	System_printf("add=v: %f,%f \n", res.x, res.y);

	res = a;
	res -= b;
	System_printf("sub=v: %f,%f \n", res.x, res.y);

	res = a;
	res += c;
	System_printf("add=f: %f,%f \n", res.x, res.y);

	res = a;
	res -= c;
	System_printf("sub=f: %f,%f \n", res.x, res.y);

	res = a;
	++res;
	System_printf("inc: %f,%f \n", res.x, res.y);

	res = a;
	--res;
	System_printf("dec: %f,%f \n", res.x, res.y);

	System_flush();
}


void pwmTest(UArg arg0, UArg arg1)
{
	System_printf("Initializing PWM \n");
	System_flush();

	System_printf("Setting all PWM outputs to neutral \n");
	System_flush();
	g_hwl.setAxisApwm(0);
	g_hwl.setAxisBpwm(0);
	g_hwl.setAxisCpwm(0);

	Task_sleep(3000);

	System_printf("Setting all PWM outputs to 1 \n");
	System_flush();
	g_hwl.setAxisApwm(1);
	g_hwl.setAxisBpwm(1);
	g_hwl.setAxisCpwm(1);

	Task_sleep(3000);

	System_printf("Setting all PWM outputs to -1 \n");
	System_flush();
	g_hwl.setAxisApwm(-1);
	g_hwl.setAxisBpwm(-1);
	g_hwl.setAxisCpwm(-1);

	Task_sleep(3000);

	System_printf("Setting all PWM outputs to neutral \n");
	System_flush();
	g_hwl.setAxisApwm(0);
	g_hwl.setAxisBpwm(0);
	g_hwl.setAxisCpwm(0);

	Task_sleep(3000);

	System_printf("Shutting down all PWM outputs \n");
	System_flush();
	g_hwl.stopPWM();
}


void qeiTest(UArg arg0, UArg arg1)
{
	for(;;)
	{
		Task_sleep(500);
		System_printf
		(
			"Encoder positions	A: %d	B: %d\n",
			g_hwl.getAxisAEncoderCt(),
			g_hwl.getAxisBEncoderCt()
		);
		System_flush();
	}
}










