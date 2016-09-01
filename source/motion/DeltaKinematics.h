/*
 * DeltaKinematics.h
 *
 *  Created on: Aug 6, 2016
 *      Author: Duemmer
 */

#ifndef SOURCE_MOTION_DELTAKINEMATICS_H_
#define SOURCE_MOTION_DELTAKINEMATICS_H_


class DeltaKinematics {
public:
	DeltaKinematics
	(
		DeltaAxis A,
		DeltaAxis B,
		DeltaAxis C
	);

	DeltaKinematics();

	void 	setAxisA(DeltaAxis a_in);
	void 	setAxisB(DeltaAxis b_in);
	void 	setAxisC(DeltaAxis c_in);

	// coordinate system conversions
	DPosVec	cartToDelta(vec3d cpos);
	vec3d	deltaToCart(DPosVec dpos);

	// update closed-loop movement
	void updateMotion_cl(vec3d dstPos_in, float fVel_in);
	void setAllMotVel(float aVel, float bVel, float cVel);
	void setAllMotRaw(float aVel, float bVel, float cVel);

	DeltaAxis *getAxisA();
	DeltaAxis *getAxisB();
	DeltaAxis *getAxisC();

private:
	DeltaAxis axisA;
	DeltaAxis axisB;
	DeltaAxis axisC;

	vec3d 	dstPos;
	float 	fVel;

};

#endif /* SOURCE_MOTION_DELTAKINEMATICS_H_ */
