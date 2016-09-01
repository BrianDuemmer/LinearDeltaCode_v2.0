/*
 * DeltaAxis.cpp
 *
 *  Created on: Jul 23, 2016
 *      Author: Duemmer
 */

#include <source/LinearDelta2.hpp>

DeltaAxis::DeltaAxis() {


}

DeltaAxis::~DeltaAxis() {
	// TODO Auto-generated destructor stub
}

/*
 * Updates all of the floating point values for position, velocity, etc. This should
 * be called before every output update, or approximately at 60 Hz
 */
void DeltaAxis::updateStateData(){
	int32_t dMsecs = g_msecTime - s_prevUpdate;
	float newPos = s_encoderCount / c_encoderCPin;
	float newVel = (newPos - s_armPos) * 1000 / dMsecs;
	s_armPos = newPos;
	s_armVel = newVel;
}


float DeltaAxis::calcMotOut(float velSetpt)
{
	return updatePID(g_msecTime, s_armVel, velSetpt);
}
