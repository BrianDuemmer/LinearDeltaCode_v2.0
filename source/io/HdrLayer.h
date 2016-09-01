/*
 * HdrLayer.h
 *
 *  Created on: Aug 13, 2016
 *      Author: Duemmer
 */

#ifndef SOURCE_IO_HDRLAYER_H_
#define SOURCE_IO_HDRLAYER_H_

class HdrLayer {
public:

	// GPIO
	void initGPIO();
	void GPIOportC_ISR_Fxn();
	void GPIOportE_ISR_Fxn();

	void initSD();
	void initADC();

	// Encoder fxns
	void initQEI();
	inline uint8_t encoderGetState(bool a, bool b);
	int32_t getAxisAEncoderCt();
	int32_t getAxisBEncoderCt();
	int32_t getAxisCEncoderCt();


	// PWM fxns
	void initPWM();
	void setAxisApwm(float motOut);
	void setAxisBpwm(float motOut);
	void setAxisCpwm(float motOut);
	uint32_t floatToPWM(float motOut);
	void stopPWM();

private:
	PWM_Handle axisA_PWMhdl;
	PWM_Handle axisB_PWMhdl;
	PWM_Handle axisC_PWMhdl;

	float victorDeadbandPercent;

	int32_t axisB_encoderCt;
	int32_t axisC_encoderCt;

	uint8_t portCPrevState;
	uint8_t portEPrevState;

};

#endif /* SOURCE_IO_HDRLAYER_H_ */


// HWI wrapper routines
extern "C"
{
	void GPIOportC_ISR_Fxn_hlpr(UArg arg0);
	void GPIOportE_ISR_Fxn_hlpr(UArg arg0);
}
















