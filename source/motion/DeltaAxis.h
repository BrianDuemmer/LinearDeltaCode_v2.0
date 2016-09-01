/*
 * DeltaAxis.h
 *
 *  Created on: Jul 23, 2016
 *      Author: Duemmer
 */

#ifndef SOURCE_MOTION_DELTAAXIS_H_
#define SOURCE_MOTION_DELTAAXIS_H_

#include "../source/util/VecMath.h"
#include "PID.h"

class DeltaAxis: public PID {
public:
	// functions
	DeltaAxis();
	virtual ~DeltaAxis();
	void updateStateData();
	float calcMotOut(float velSetpt);


	/////////////////////////////////// Variables //////////////////////////////////
	// Configuration data
	vec2d			c_axisPos;
	float			c_armLen;
	float 			c_vHeadOffset;
	float 			c_hHeadOffset;
	float 			c_endstopHitPos;
	float 			c_minAxisPos;
	float 			c_maxAxisPos;
	float 			c_encoderCPin;
	float 			c_accuracyThresh;
	bool 			c_invertEncoder;
	bool 			c_invertMotor;
	bool 			c_topEndstopNormalOpen;
	bool 			c_bottomEndstopNormalOpen;

	// State data
	int32_t			s_encoderCount;
	float 			s_armPos;
	float 			s_armVel;
	float 			s_motorVel;
	float 			s_motorOut;
	bool 			s_topEndstopHit;
	bool 			s_bottomEndstopHit;
	uint32_t 		s_prevUpdate;
	float 			s_encoderOffset;

};

#endif /* SOURCE_MOTION_DELTAAXIS_H_ */
