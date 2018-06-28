#include "ARPoint.h"
#include "ARVector.h"

ARPoint::ARPoint(void)
{
}

ARPoint::ARPoint(float x,float y,float z):
	x(x),y(y),z(z)
{

}


ARPoint::~ARPoint(void)
{
}

ARPoint ARPoint::operator+(const ARVector3 &v) const
{
	return ARPoint(x + v.x, y + v.y, z + v.z);
}

ARPoint ARPoint::operator+=(const ARVector3 &v)
{
	this->x += v.x;
	this->y += v.y;
	this->z += v.z;
	return *this;
}

ARPoint ARPoint::operator-(const ARVector3 &v) const
{
	return ARPoint(x + v.x, y + v.y ,z + v.z);
}

ARPoint ARPoint::operator-=(const ARVector3 &v)
{
	this->x -= v.x;
	this->y -= v.y;
	this->z -= v.z;
	return *this;
}

ARVector3 ARPoint::operator-(const ARPoint &p) const
{
	return ARVector3(x - p.x ,y - p.y ,z - p.z);
}
 

float ARPoint::distance(const ARPoint &a, const ARPoint &b)
{
	return (a - b).length();
}


float ARPoint::distanceSuqared(const ARPoint &a,const ARPoint &b)
{
	return (a - b).lengthSquared();
}