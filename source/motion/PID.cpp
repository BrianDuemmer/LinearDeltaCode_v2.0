/*
 * PID.cpp
 *
 *  Created on: Jul 24, 2016
 *      Author: Duemmer
 */

#include <source/motion/PID.h>

PID::PID() {

}

void PID::setPID_Data(
	float P,
	float I,
	float D,
	float outMin_arg,
	float outMax_arg
	)
{
	Kp = P;
	Ki = I;
	Kd = D;

	outMin = outMin_arg;
	outMax = outMax_arg;

}

float PID::updatePID(uint32_t msecTime, float pv, float setpt)
{
	if(lastUpdateMsec == 0){
		// if zero, then the controller needs to be initialized.
		// reset, and set lastUpdateMsec to the provided time
		reset();
		lastUpdateMsec = msecTime;
		return 0;
	}

	float dt = (msecTime - lastUpdateMsec) / 1000;
	float error = setpt - pv;
	float output;

	// update gain term
	Pval = Kp * error;

	//update integral term
	Ival += Ki * error * dt;

	// update derivative term
	Dval = (Kd * (error - prevErr)) / dt;

	// combine them to get the process output
	output = Pval + Ival + Pval;

	//constrain the output to the min and max values
	if(output > outMax){
		output = outMax;
	}

	if(output < outMin){
		output = outMin;
	}

	// update the timestamp, previous control output, and previous error
	lastUpdateMsec = msecTime;
	prevCtl = output;
	prevErr = error;

	return output;
}

// reset the PID controller
void PID::reset()
{
	Pval = 0;
	Ival = 0;
	Dval = 0;

	prevCtl = 0;
	prevErr = 0;

	lastUpdateMsec = 0;
}

PID::~PID() {
	// TODO Auto-generated destructor stub
}

