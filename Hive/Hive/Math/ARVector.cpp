#include "ARVector.h"
#include <math.h>
#include <iostream>

/************************************************************************/
/* 三维点                                                                     */
/************************************************************************/

ARVector3::ARVector3(void)
{
	this->x = this->y = this->z = 0.0f;
}

ARVector3::ARVector3(float _x,float _y,float _z)
{
	this->x = _x;
	this->y = _y;
	this->z = _z;
}

ARVector3::~ARVector3(void)
{
}

ARVector3 ARVector3::operator+(const ARVector3 & v) const
{
	return ARVector3(x+v.x,y+v.y,z+v.z);
}

ARVector3 ARVector3::operator=(const ARVector3 & v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
	return *this;
}

ARVector3 ARVector3::operator+=(const ARVector3 &v)
{
	this->x += v.x;
	this->y += v.y;
	this->z += v.z;
	return *this;
}

ARVector3 ARVector3::operator-(const ARVector3 &v) const
{
	return ARVector3(x - v.x,y - v.y,z - v.z);
}

ARVector3 ARVector3::operator-=(const ARVector3 &v      )
{
	this->x -= v.x;
	this->y -= v.y;
	this->z -= v.z;
	return *this;
}

ARVector3 ARVector3::operator*(float f)
{
	return ARVector3(x*=f,y*=f,z*=f);
}

ARVector3 ARVector3::operator*=(float f)
{
	this->x *= f;
	this->y *= f;
	this->z *= f;
	return *this;
}

float ARVector3::dot(const ARVector3 v1, const ARVector3 v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v1.z;
}

ARVector3 ARVector3::cross(const ARVector3 v1, const ARVector3 v2)
{
	return ARVector3(v1.y * v2.z - v1.z * v2.y,
					v1.z * v2.x - v1.x * v2.z,
					v1.x * v2.y - v1.y * v2.x);
}

float ARVector3::lengthSquared() const
{
	return x*x + y*y + z*z;
}

float ARVector3::length() const
{
	return sqrtf(this->lengthSquared());
}

void ARVector3::one()
{
	this->x = this->y = this->z = 1.0f;
}

void ARVector3::zero()
{
	this->x = this->y = this->z = 0.0f;
}

void ARVector3::print()
{
	printf("%f,%f,%f \n",x,y,z);
}

/************************************************************************/
/* 二维点                                                                     */
/************************************************************************/


ARVector2::ARVector2(void)
{
	x = y = 0;
}

ARVector2::ARVector2(float _x,float _y)
{
	x = _x; y = _y;
}

ARVector2::~ARVector2(void)
{

}

ARVector2 ARVector2::operator=(const ARVector2 &v)
{
	return *this;
}

ARVector2 ARVector2::operator+(const ARVector2 &v) const
{
	return *this;
}

ARVector2 ARVector2::operator+=(const ARVector2 &v)
{
	return *this;
}

ARVector2 ARVector2::operator-(const ARVector2 &v) const
{
	return *this;
}

ARVector2 ARVector2::operator-=(const ARVector2 &v)
{
	return *this;
}

ARVector2 ARVector2::operator*(float f)
{
	return *this;
}

ARVector2 ARVector2::operator*=(float f)
{
	return *this;
}

void ARVector2::print()
{
	printf("%f,%f \n",x,y);
}


/************************************************************************/
/* 四维向量                                                                     */
/************************************************************************/
ARVector4::ARVector4(void)
{
	for (int i = 0;i<4;i++)
	{
		this->value[i] = 0;
	}
}

ARVector4::ARVector4(float _x,float _y,float _z,float _w)
{
	this->value[0] = _x;
	this->value[1] = _y;
	this->value[2] = _z;
	this->value[3] = _w;
}

ARVector4::~ARVector4(void)
{
}

ARVector4 ARVector4::operator=(const ARVector4 &v)
{
	return *this;
}

ARVector4 ARVector4::operator+(const ARVector4 &v) const
{
	return *this;
}

ARVector4 ARVector4::operator+=(const ARVector4 &v)
{
	return *this;
}

ARVector4 ARVector4::operator-(const ARVector4 &v) const
{
	return *this;
}

ARVector4 ARVector4::operator-=(const ARVector4 &v)
{
	return *this;
}

ARVector4 ARVector4::operator*(float f)
{
	return *this;
}

ARVector4 ARVector4::operator*=(float f)
{
	return *this;
}

void ARVector4::print()
{
	printf("========= \n");
	for (int i = 0;i<4;i++)
	{
		printf("%f \n",this->value[i]);
	}
}
