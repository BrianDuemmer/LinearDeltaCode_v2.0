/*
 * PID.h
 *
 *  Created on: Jul 24, 2016
 *      Author: Duemmer
 */

#ifndef SOURCE_MOTION_PID_H_
#define SOURCE_MOTION_PID_H_

#include <stdint.h>

class PID {
public:
	float		Kp;
	float		Ki;
	float		Kd;

	PID();
	void setPID_Data(
			float P,
			float I,
			float D,
			float outMin_arg,
			float outMax_arg
		);

	virtual ~PID();
	float updatePID(uint32_t msecTime, float pv, float setpt);
	void reset();

private:
	uint32_t	lastUpdateMsec;

	float		Pval;
	float 		Ival;
	float		Dval;

	float		prevCtl;
	float		prevErr;

	float		outMin;
	float		outMax;

};

#endif /* SOURCE_MOTION_PID_H_ */
