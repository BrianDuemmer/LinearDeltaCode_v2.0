/*
 * DeltaKinematics.cpp
 *
 *  Created on: Aug 6, 2016
 *      Author: Duemmer
 * The main motion controller of the printer
 */

#include <source/LinearDelta2.hpp>

	DeltaKinematics::DeltaKinematics()
	{
		// TODO do stuff in the constructor maybe?
	}

DPosVec	DeltaKinematics::cartToDelta(vec3d cpos3d)
{
	vec2d	cpos2d = VecMath::toVec2d(cpos3d);

	float 	distA = VecMath::dist(axisA.c_axisPos, cpos2d) - axisA.c_hHeadOffset;
	float	distB = VecMath::dist(axisB.c_axisPos, cpos2d) - axisB.c_hHeadOffset;
	float	distC = VecMath::dist(axisC.c_axisPos, cpos2d) - axisC.c_hHeadOffset;

	float	Zha = std::sqrtf((axisA.c_armLen* axisA.c_armLen) - (distA * distA));
	float	Zhb = std::sqrtf((axisB.c_armLen* axisB.c_armLen) - (distB * distB));
	float	Zhc = std::sqrtf((axisC.c_armLen* axisC.c_armLen) - (distC * distC));

	float 	Zta = Zha + cpos3d.z + axisA.c_vHeadOffset;
	float	Ztb = Zhb + cpos3d.z + axisB.c_vHeadOffset;
	float	Ztc = Zhc + cpos3d.z + axisC.c_vHeadOffset;

	DPosVec	rtn = {Zta, Ztb, Ztc};

	return rtn;
}

vec3d	DeltaKinematics::deltaToCart(DPosVec dpos)
{
	// TODO: derive the forward kinematics for the system

	return {0, 0, 0};
}


void 	DeltaKinematics::setAxisA(DeltaAxis a_in)
{
	axisA = a_in;
}

void 	DeltaKinematics::setAxisB(DeltaAxis b_in)
{
	axisB = b_in;
}

void 	DeltaKinematics::setAxisC(DeltaAxis c_in)
{
	axisC = c_in;
}


void DeltaKinematics::updateMotion_cl(vec3d dstPos_in, float fVel_in)
{
	// update the state data
	axisA.updateStateData();
	axisB.updateStateData();
	axisC.updateStateData();

	g_deltaPos = (DPosVec){
		axisA.s_armPos,
		axisB.s_armPos,
		axisC.s_armPos
	};

	dstPos = dstPos_in;
	fVel = fVel_in;

	// calc the difference between the current and destination positions
	vec3d dPosTotal = dstPos_in - g_headPos;

	// calc the position that we should be in on the next tick
	float mag = VecMath::mag(dPosTotal);
		// velocity per second
	vec3d nextTickPos = dPosTotal *  (fVel / mag);
		// convert to velocity per update tick
	nextTickPos *= (UPDATE_MSEC / 1000);
		// add to the current pos
	nextTickPos += g_headPos;

	// convert to delta coordinates
	DPosVec nextPos_delta = cartToDelta(nextTickPos);

	// find the instantaneous velocity that the arms need to travel
	DPosVec armsVel = (nextPos_delta - g_deltaPos) * 1000 / UPDATE_MSEC;

	// update the motors
	setAllMotVel(armsVel.a, armsVel.b, armsVel.c);
}

void DeltaKinematics::setAllMotVel(float aVel, float bVel, float cVel)
{
	g_hwl.setAxisApwm(axisA.calcMotOut(aVel));
	g_hwl.setAxisBpwm(axisB.calcMotOut(bVel));
	g_hwl.setAxisCpwm(axisC.calcMotOut(cVel));
}


void DeltaKinematics::setAllMotRaw(float aVel, float bVel, float cVel)
{
	g_hwl.setAxisApwm(aVel);
	g_hwl.setAxisBpwm(bVel);
	g_hwl.setAxisCpwm(cVel);
}


DeltaAxis *DeltaKinematics::getAxisA()
{
	return &axisA;
}

DeltaAxis *DeltaKinematics::getAxisB()
{
	return &axisB;
}

DeltaAxis *DeltaKinematics::getAxisC()
{
	return &axisC;
}













