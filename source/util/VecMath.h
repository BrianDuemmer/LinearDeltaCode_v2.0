/*
 * VecMath.h
 *
 *  Created on: Aug 7, 2016
 *      Author: Duemmer
 */

#ifndef SOURCE_UTIL_VECMATH_H_
#define SOURCE_UTIL_VECMATH_H_

	///////////////////////////////// Common structs ///////////////////////////////////

	// 2D cartesian vector
	typedef struct vec2d	{
		float x;
		float y;

		vec2d operator+(vec2d other);
		vec2d operator-(vec2d other);
		vec2d operator*(float other);
		vec2d operator/(float other);
		vec2d operator++();
		vec2d operator--();

		vec2d operator+=(vec2d other);
		vec2d operator+=(float other);

		vec2d operator-=(vec2d other);
		vec2d operator-=(float other);

		vec2d operator*=(float other);
		vec2d operator/=(float other);


	}vec2d;

	// 3D cartesian vector
	typedef struct vec3d	{
		float x;
		float y;
		float z;

		vec3d operator+(vec3d other);
		vec3d operator-(vec3d other);
		vec3d operator*(float other);
		vec3d operator/(float other);
		vec3d operator++();
		vec3d operator--();

		vec3d operator+=(vec3d other);
		vec3d operator+=(float other);

		vec3d operator-=(vec3d other);
		vec3d operator-=(float other);

		vec3d operator*=(float other);
		vec3d operator/=(float other);


	}vec3d;

	// 2D polar vector
	typedef struct Pvec2d	{
		float r;
		float theta;
	}Pvec2d;

	// Delta position vector
	typedef struct DPosVec	{
		float a;
		float b;
		float c;

		DPosVec operator+(DPosVec other);
		DPosVec operator-(DPosVec other);
		DPosVec operator*(float other);
		DPosVec operator/(float other);

		DPosVec operator+=(DPosVec other);
		DPosVec operator+=(float other);

		DPosVec operator-=(DPosVec other);
		DPosVec operator-=(float other);

		DPosVec operator*=(float other);
		DPosVec operator/=(float other);

	}DPosVec;

class VecMath {
public:

	static float dist(vec2d vec1, vec2d vec2);
	static float dist(vec3d vec1, vec3d vec2);
	static float dist(Pvec2d vec1, Pvec2d vec2);

	static float mag(vec2d vec);
	static float mag(vec3d vec);

	static vec2d toVec2d(vec3d vecIn);
	static vec2d toVec2d(Pvec2d vecIn);

	static vec3d toVec3d(vec2d vecIn);
	static vec3d toVec3d(Pvec2d vecIn);

	static Pvec2d toPvec2d(vec2d vecIn);
	static Pvec2d toPvec2d(vec3d vecIn);

	static float dotProd(vec3d vec1, vec3d vec2);
	static float dotProd(vec2d vec1, vec2d vec2);

	static vec3d crossProd(vec3d vec1, vec3d vec2);

	static vec2d circumcenter(vec2d a, vec2d b, vec2d c);

	static float mapf(float in_min, float in_max, float out_min, float out_max, float input);
	static int32_t map(int32_t in_min, int32_t in_max, int32_t out_min, int32_t out_max, int32_t input);

};



#endif /* SOURCE_UTIL_VECMATH_H_ */










