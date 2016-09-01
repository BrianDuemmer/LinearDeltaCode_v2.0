/*
 * VecMath.cpp
 *
 *  Created on: Aug 7, 2016
 *      Author: Duemmer
 */

#include <source/LinearDelta2.hpp>

////////////////////////////// Operator Overloads /////////////////////////////////

//////////////////////////////////// vec2d ////////////////////////////////////////
vec2d vec2d::operator+(vec2d other)
{
	vec2d ret;
	ret.x = this->x + other.x;
	ret.y = this->y + other.y;
	return ret;
}

vec2d vec2d::operator-(vec2d other)
{
	vec2d ret;
	ret.x = this->x - other.x;
	ret.y = this->y - other.y;
	return ret;
}

vec2d vec2d::operator*(float other)
{
	vec2d ret;
	ret.x = this->x * other;
	ret.y = this->y * other;
	return ret;
}

vec2d vec2d::operator/(float other)
{
	vec2d ret;
	ret.x = this->x / other;
	ret.y = this->y / other;
	return ret;
}

vec2d vec2d::operator++()
{
	this->x++;
	this->y++;
	return *this;
}

vec2d vec2d::operator--()
{
	this->x--;
	this->y--;
	return *this;
}

vec2d vec2d::operator+=(vec2d other)
{
	this->x += other.x;
	this->y += other.y;
	return *this;
}

vec2d vec2d::operator+=(float other)
{
	this->x += other;
	this->y += other;
	return *this;
}

vec2d vec2d::operator-=(vec2d other)
{
	this->x -= other.x;
	this->y -= other.y;
	return *this;
}

vec2d vec2d::operator-=(float other)
{
	this->x -= other;
	this->y -= other;
	return *this;
}

vec2d vec2d::operator*=(float other)
{
	this->x *= other;
	this->y *= other;
	return *this;
}

vec2d vec2d::operator/=(float other)
{
	this->x /= other;
	this->y /= other;
	return *this;
}


//////////////////////////////////// vec3d ////////////////////////////////////////
vec3d vec3d::operator+(vec3d other)
{
	vec3d ret;
	ret.x = this->x + other.x;
	ret.y = this->y + other.y;
	ret.z = this->z + other.z;
	return ret;
}

vec3d vec3d::operator-(vec3d other)
{
	vec3d ret;
	ret.x = this->x - other.x;
	ret.y = this->y - other.y;
	ret.z = this->z - other.z;
	return ret;
}

vec3d vec3d::operator*(float other)
{
	vec3d ret;
	ret.x = this->x * other;
	ret.y = this->y * other;
	ret.z = this->z * other;
	return ret;
}

vec3d vec3d::operator/(float other)
{
	vec3d ret;
	ret.x = this->x / other;
	ret.y = this->y / other;
	ret.z = this->z / other;
	return ret;
}

vec3d vec3d::operator++()
{
	this->x++;
	this->y++;
	this->z++;
	return *this;
}

vec3d vec3d::operator--()
{
	this->x--;
	this->y--;
	this->z--;
	return *this;
}

vec3d vec3d::operator+=(vec3d other)
{
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
	return *this;
}

vec3d vec3d::operator+=(float other)
{
	this->x += other;
	this->y += other;
	this->y += other;
	return *this;
}

vec3d vec3d::operator-=(vec3d other)
{
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
	return *this;
}

vec3d vec3d::operator-=(float other)
{
	this->x -= other;
	this->y -= other;
	this->z -= other;
	return *this;
}

vec3d vec3d::operator*=(float other)
{
	this->x *= other;
	this->y *= other;
	this->z *= other;
	return *this;
}

vec3d vec3d::operator/=(float other)
{
	this->x /= other;
	this->y /= other;
	this->z /= other;
	return *this;
}

/////////////////////////////////////// DPosVec ///////////////////////////////////

DPosVec DPosVec::operator+(DPosVec other)
{
	DPosVec ret;
	ret.a = this->a + other.a;
	ret.b = this->b + other.b;
	ret.c = this->c + other.c;
	return ret;
}

DPosVec DPosVec::operator-(DPosVec other)
{
	DPosVec ret;
	ret.a = this->a - other.a;
	ret.b = this->b - other.b;
	ret.c = this->c - other.c;
	return ret;
}

DPosVec DPosVec::operator*(float other)
{
	DPosVec ret;
	ret.a = this->a * other;
	ret.b = this->b * other;
	ret.c = this->c * other;
	return ret;
}

DPosVec DPosVec::operator/(float other)
{
	DPosVec ret;
	ret.a = this->a / other;
	ret.b = this->b / other;
	ret.c = this->c / other;
	return ret;
}

DPosVec DPosVec::operator+=(DPosVec other)
{
	this->a += other.a;
	this->b += other.b;
	this->c += other.c;
	return *this;
}

DPosVec DPosVec::operator+=(float other)
{
	this->a += other;
	this->b += other;
	this->c += other;
	return *this;
}

DPosVec DPosVec::operator-=(DPosVec other)
{
	this->a -= other.a;
	this->b -= other.b;
	this->c -= other.c;
	return *this;
}

DPosVec DPosVec::operator-=(float other)
{
	this->a -= other;
	this->b -= other;
	this->c -= other;
	return *this;
}

DPosVec DPosVec::operator*=(float other)
{
	this->a *= other;
	this->b *= other;
	this->c *= other;
	return *this;
}

DPosVec DPosVec::operator/=(float other)
{
	this->a /= other;
	this->b /= other;
	this->c /= other;
	return *this;
}

/////////////////////////////////// Common Methods ////////////////////////////////

float VecMath::dist(vec2d vec1, vec2d vec2)
{
	// manually square it instead of using pow, for performance reasons
	float xPart = (vec1.x - vec2.x) * (vec1.x - vec2.x);
	float yPart = (vec1.y - vec2.y) * (vec1.y - vec2.y);

	float dist = std::sqrtf(xPart + yPart);

	return dist;
}

float VecMath::dist(vec3d vec1, vec3d vec2)
{
	// manually square it instead of using pow, for performance reasons
	float xPart = (vec1.x - vec2.x) * (vec1.x - vec2.x);
	float yPart = (vec1.y - vec2.y) * (vec1.y - vec2.y);
	float zPart = (vec1.z - vec2.z) * (vec1.z - vec2.z);

	float dist = std::sqrtf(xPart + yPart + zPart);

	return dist;
}

float VecMath::dist(Pvec2d vec1, Pvec2d vec2)
{
	float angPt = std::cosf(vec1.theta - vec2.theta) * vec1.r * vec2.r * 2;
	float sqdPt = (vec1.r * vec1.r) + (vec2.r * vec2.r);
	float dist = std::sqrtf(sqdPt - angPt);

	return dist;
}

float VecMath::mag(vec2d vec)
{
	vec2d zero = {0,0};
	return dist(vec, zero);
}

float VecMath::mag(vec3d vec)
{
	vec3d zero = {0,0,0};
	return dist(vec, zero);
}

vec2d VecMath::toVec2d(vec3d vecIn)
{
	vec2d ret = {vecIn.x, vecIn.y};
	return ret;
}

vec2d VecMath::toVec2d(Pvec2d vecIn)
{
	float x = vecIn.r * std::cosf(vecIn.theta);
	float y = vecIn.r * std::sinf(vecIn.theta);
	vec2d ret = {x, y};
	return ret;
}

vec3d VecMath::toVec3d(vec2d vecIn)
{
	vec3d ret = {vecIn.x, vecIn.y, 0};
	return ret;
}

vec3d VecMath::toVec3d(Pvec2d vecIn)
{
	float x = vecIn.r * std::cosf(vecIn.theta);
	float y = vecIn.r * std::sinf(vecIn.theta);

	vec3d ret = {x, y, 0};
	return ret;
}

Pvec2d VecMath::toPvec2d(vec2d vecIn)
{
	Pvec2d ret;
	ret.r = mag(vecIn);
	ret.theta = std::atan2f(vecIn.y, vecIn.x);
	return ret;
}

Pvec2d VecMath::toPvec2d(vec3d vecIn)
{
	Pvec2d ret;
	ret.r = mag(vecIn);
	ret.theta = std::atan2f(vecIn.y, vecIn.x);
	return ret;
}

float VecMath::dotProd(vec3d vec1, vec3d vec2)
{
	float ret = vec1.x * vec2.x;
	ret += vec1.y * vec2.y;
	ret += vec1.z * vec2.z;
	return ret;
}

float VecMath::dotProd(vec2d vec1, vec2d vec2)
{
	float ret = vec1.x * vec2.x;
	ret += vec1.y * vec2.y;
	return ret;
}

vec3d VecMath::crossProd(vec3d vec1, vec3d vec2)
{
	vec3d ret;
	ret.x = (vec1.y * vec2.z) - (vec2.y * vec1.z);
	ret.y = (vec2.x * vec1.z) - (vec1.x * vec2.z);
	ret.z = (vec1.x * vec2.y) - (vec2.x * vec1.y);

	return ret;
}

vec2d VecMath::circumcenter(vec2d a, vec2d b, vec2d c)
{
	// calculate the slopes of the line between a and b, and a and c
	float Sab = (a.y - b.y) / (a.x - b.x);
	float Sac = (a.y - c.y) / (a.x - c.x);

	// find the midpoints of those lines
	vec2d Mab =
	{
		(a.x + b.x) / 2,
		(a.y + b.y) / 2
	};

	vec2d Mac =
	{
		(a.x + c.x) / 2,
		(a.y + c.y) / 2
	};

	// find the slopes of the lines perpendicular to the above lines
	float Pab = -1 / Sab;
	float Pac = -1 / Sac;

	/*  formula for the perpendicular lines:
	 *  y = Pab * x - Pab * Mab.x + Mab.y
	 *  y = Pac * x - Pac * Mac.x + Mac.y
	 *
	 *  Solving for x gives us:
	 *
	 *  Pab*x - Pab*Mab.x + Mab.y = Pac*x - Pac*Mac.x + Mac.y
	 *  x*(Pab - Pac) = Pab*Mab.x - Mab.y - Pac*Mac.x + Mac.y
	 *  x = ( Pab*Mab.x - Mab.y - Pac*Mac.x + Mac.y) / (Pab - Pac)
	 *
	 *  and y can be solved by plugging into one of the original equations
	 */

	vec2d ret;
	ret.x = ( Pab*Mab.x - Mab.y - Pac*Mac.x + Mac.y) / (Pab - Pac);
	ret.y = Pab*(ret.x - Mab.x) + Mab.y;

	return ret;
}


float VecMath::mapf(float in_min, float in_max, float out_min, float out_max, float input)
{
	return (input - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


int32_t VecMath::map(int32_t in_min, int32_t in_max, int32_t out_min, int32_t out_max, int32_t input)
{
	return (input - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}




















