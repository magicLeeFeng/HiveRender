/************************************************************************/
/* µã                                                                     */
/************************************************************************/
#pragma once

class ARVector3; 

class ARPoint
{
public:
	ARPoint(void);
	~ARPoint(void);
	ARPoint(float x,float y,float z);

	ARPoint operator+(const ARVector3 &v) const;
	ARPoint operator+=(const ARVector3 &v);
	ARPoint operator-(const ARVector3 &v) const;
	ARVector3 operator-(const ARPoint &p) const;
	ARPoint operator-=(const ARVector3 &v);

	float distance(const ARPoint &a, const ARPoint &b);
	float distanceSuqared(const ARPoint &a,const ARPoint &b);
public:
	float x;
	float y;
	float z;
};

