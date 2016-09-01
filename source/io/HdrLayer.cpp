/*
 * HdrLayer.cpp
 *
 *  Created on: Aug 13, 2016
 *      Author: Duemmer
 */

#include <source/LinearDelta2.hpp>


///////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////// PWM Functions ////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

void HdrLayer::initPWM()
{
	Board_initPWM();

	victorDeadbandPercent = VecMath::mapf
	(
		0,
		VICTOR_PWM_MAX_USEC_HIGH - VICTOR_PWM_MIN_USEC_HIGH,
		0,
		1,
		VICTOR_PWM_DEADBAND_USEC
	);

	PWM_Params params;
	PWM_Params_init(&params);
	params.period = VICTOR_PWM_PERIOD;

	axisA_PWMhdl = PWM_open(AXIS_A_PWM_IDX, &params);
	axisB_PWMhdl = PWM_open(AXIS_B_PWM_IDX, &params);
	axisC_PWMhdl = PWM_open(AXIS_C_PWM_IDX, &params);

}


void HdrLayer::setAxisApwm(float motOut)
{
	PWM_setDuty(axisA_PWMhdl, floatToPWM(motOut));
}


void HdrLayer::setAxisBpwm(float motOut)
{
	PWM_setDuty(axisB_PWMhdl, floatToPWM(motOut));
}


void HdrLayer::setAxisCpwm(float motOut)
{
	PWM_setDuty(axisC_PWMhdl, floatToPWM(motOut));
}


uint32_t HdrLayer::floatToPWM(float motOut)
{
	if(motOut > 0)
		motOut += victorDeadbandPercent;
	else if(motOut < 0)
		motOut -= victorDeadbandPercent;

	if(motOut > 1) { motOut = 1; }
	if(motOut < -1) { motOut = -1; }

	uint32_t ret = VecMath::mapf
	(
		-1,
		1,
		VICTOR_PWM_MIN_USEC_HIGH,
		VICTOR_PWM_MAX_USEC_HIGH,
		motOut
	);

	return ret;
}

void HdrLayer::stopPWM()
{
	PWM_close(axisA_PWMhdl);
	PWM_close(axisB_PWMhdl);
	PWM_close(axisC_PWMhdl);
}

///////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// Encoder / GPIO Functions //////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

void HdrLayer::initQEI()
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_QEI0);
	QEIEnable(QEI0_BASE);
	QEIConfigure
		(	QEI0_BASE,
			QEI_CONFIG_CAPTURE_A_B |
			QEI_CONFIG_NO_RESET |
			QEI_CONFIG_QUADRATURE |
			QEI_CONFIG_NO_SWAP,
			0xffffffff
		);
	QEIVelocityEnable(QEI0_BASE);
}


void HdrLayer::initGPIO()
{
	Board_initGPIO();

	// enable interrupt on Port C pins 4, 5, 6, and 7
	GPIOIntEnable
	(
		GPIO_PORTC_BASE,
			GPIO_PIN_4 |
			GPIO_PIN_5 |
			GPIO_PIN_6 |
			GPIO_PIN_7
	);

	GPIOIntTypeSet
	(
		GPIO_PORTC_BASE,
			GPIO_PIN_4 |
			GPIO_PIN_5 |
			GPIO_PIN_6 |
			GPIO_PIN_7 ,
		GPIO_BOTH_EDGES
	);

	// enable interrupt on Port E pins 0 and 1
	GPIOIntEnable
	(
		GPIO_PORTE_BASE,
			GPIO_PIN_0 |
			GPIO_PIN_1
	);
	GPIOIntTypeSet
	(
		GPIO_PORTE_BASE,
			GPIO_PIN_0 |
			GPIO_PIN_1,
		GPIO_BOTH_EDGES
	);
}



///////////////////////////////////// GPIO port C ISR //////////////////////////////////
/*
 * Handle all GPIO interrupts occuring in GPIO port C.
 * Things handled here:
 * 		EncoderB_ISR
 * 		EncoderC_ISR
 */
void HdrLayer::GPIOportC_ISR_Fxn()
{
	// get the GPIO values
	uint8_t portState = GPIOPinRead(GPIO_PORTC_BASE, 0xff);

	// see which ones saw a state change
	uint8_t intState = portState ^ portCPrevState;


	/////////////////////////////////// encoder "B" ///////////////////////////////////
	if(intState & (GPIO_PIN_7 | GPIO_PIN_6))
	{
		// fwd declare the previous state variable
		static uint8_t prevState_encB = 1;

		// calc which of the 4 encoder states we are currently in
		bool a = portState & GPIO_PIN_7;
		bool b = portState & GPIO_PIN_6;
		uint8_t currState_encB = encoderGetState(a, b);

		// see whether we will be incrementing or decrementing
		if(currState_encB > prevState_encB || (currState_encB == 1 && prevState_encB == 4)) {
			axisB_encoderCt++;
		}
		else if (currState_encB != prevState_encB){
			axisB_encoderCt--;
		}

		// update the previous state variable
		prevState_encB = currState_encB;
	}


	/////////////////////////////////// encoder "C" ///////////////////////////////////
	if(intState & (GPIO_PIN_5 | GPIO_PIN_4))
	{
		// fwd declare the previous state variable
		static uint8_t prevState_encC = 1;

		// calc which of the 4 encoder states we are currently in
		bool a = portState & GPIO_PIN_4;
		bool b = portState & GPIO_PIN_4;
		uint8_t currState_encC = encoderGetState(a, b);

		// see whether we will be incrementing or decrementing
		if(currState_encC > prevState_encC || (currState_encC == 1 && prevState_encC == 4)) {
			axisC_encoderCt++;
		}
		else if (currState_encC != prevState_encC){
			axisC_encoderCt--;
		}

		// update the previous state variable
		prevState_encC = currState_encC;
	}
}




// convert two quadrature values into a more usable state
uint8_t HdrLayer::encoderGetState(bool a, bool b){
	if(a && !b)			{return 1;	}
	else if(a && b)		{return 2;	}
	else if(!a && b)	{return 3;	}
	else if(!a && !b)	{return 4;	}
	else{
		// This statement is impossible to reach. it is only here to shut up the compiler.
		// Why 72? Because I said so.
		return 72;
	};
}




int32_t HdrLayer::getAxisAEncoderCt(){
	return QEIPositionGet(QEI0_BASE);
}

int32_t HdrLayer::getAxisBEncoderCt(){
	return axisB_encoderCt;
}

int32_t HdrLayer::getAxisCEncoderCt(){
	return axisC_encoderCt;
}


///////////////////////////////////// GPIO port E ISR //////////////////////////////////
/*
 * Handle all interrupts occuring in GPIO portE
 * Things handled here:
 * 		A_TopEndstop - P1
 * 		A_BottomEndstop - P0
 */
void HdrLayer::GPIOportE_ISR_Fxn()
{
	// get the GPIO values
	uint8_t portState = GPIOPinRead(GPIO_PORTE_BASE, 0xff);

	// see which ones saw a state change
	uint8_t intState = portState ^ portEPrevState;

	//////////////////////////////// top endstop /////////////////////////////////////

	// last time we recognized a state change on the Atop
	static uint32_t lastChgTime_Atop = 0;

	// make sure enough time has passed since the last state change before updating it
	if((intState & GPIO_PIN_1) && g_msecTime - lastChgTime_Atop > ENDSTOP_DEBOUNCE_TIME)
	{
		// invert the endstop if necessary
		bool invert = g_motionCtl.getAxisA()->c_topEndstopNormalOpen;
		g_motionCtl.getAxisA()->s_topEndstopHit = (portState & GPIO_PIN_1) ^ invert;
	}

	/////////////////////////////// bottom endstop ///////////////////////////////////

	// last time we recognized a state change on the Abottom
	static uint32_t lastChgTime_Abottom = 0;

	// make sure enough time has passed since the last state change before updating it
	if((intState & GPIO_PIN_0) && g_msecTime - lastChgTime_Abottom > ENDSTOP_DEBOUNCE_TIME)
	{
		// invert the endstop if necessary
		bool invert = g_motionCtl.getAxisA()->c_bottomEndstopNormalOpen;
		g_motionCtl.getAxisA()->s_bottomEndstopHit = (portState & GPIO_PIN_1) ^ invert;
	}

}




// these serve as C-Binding wrappers for the actual ISR funtions
void GPIOportC_ISR_Fxn_hlpr(unsigned int arg)
{
	g_hwl.GPIOportC_ISR_Fxn();
	GPIOIntClear(GPIO_PORTC_BASE, 0xff);
}

void GPIOportE_ISR_Fxn_hlpr(unsigned int arg)
{
	g_hwl.GPIOportE_ISR_Fxn();
	GPIOIntClear(GPIO_PORTE_BASE, 0xff);
}







