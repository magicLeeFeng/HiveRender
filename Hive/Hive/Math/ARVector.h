/************************************************************************/
/* 向量类                                                                     */
/************************************************************************/
#pragma once
class ARVector3
{
public:
	ARVector3(void);
	ARVector3(float _x,float _y,float _z);
	~ARVector3(void);
public:
	ARVector3 operator=(const ARVector3 &v);
	ARVector3 operator+(const ARVector3 &v) const;
	ARVector3 operator+=(const ARVector3 &v);
	ARVector3 operator-(const ARVector3 &v) const;
	ARVector3 operator-=(const ARVector3 &v);
	ARVector3 operator*(float f);
	ARVector3 operator*=(float f);

	float lengthSquared() const;
	float length() const;
	void one();
	void zero();
	void print();
	static float dot(const ARVector3 v1, const ARVector3 v2);	//点乘		|a|*|b|*cos(@)
	static ARVector3 cross(const ARVector3 v1, const ARVector3 v2);	//叉乘		P x Q = (PyQz - PzQy,PzQx - PxQz,PxQy - PyQx)//P x Q = |P x Q| = |P| * |Q| * sin(@) 
public:
	float x;
	float y;
	float z;
};


class ARVector2
{
public:
	ARVector2(void);
	ARVector2(float _x,float _y);
	~ARVector2(void);
public:
	ARVector2 operator=(const ARVector2 &v);
	ARVector2 operator+(const ARVector2 &v) const;
	ARVector2 operator+=(const ARVector2 &v);
	ARVector2 operator-(const ARVector2 &v) const;
	ARVector2 operator-=(const ARVector2 &v);
	ARVector2 operator*(float f);
	ARVector2 operator*=(float f);

	float lengthSquared() const;
	float length() const;
	void  print();
	static float dot(const ARVector2 v1, const ARVector2 v2);		//点乘		|a|*|b|*cos(@)
	static ARVector2 cross(const ARVector2 v1, const ARVector2 v2);	//叉乘		P x Q = (PyQz - PzQy,PzQx - PxQz,PxQy - PyQx)//P x Q = |P x Q| = |P| * |Q| * sin(@) 
public:
	float x;
	float y;
};

class ARVector4
{
public:
	ARVector4(void);
	ARVector4(float _x,float _y,float _z,float _w);
	~ARVector4(void);
public:
	ARVector4 operator=(const ARVector4 &v);
	ARVector4 operator+(const ARVector4 &v) const;
	ARVector4 operator+=(const ARVector4 &v);
	ARVector4 operator-(const ARVector4 &v) const;
	ARVector4 operator-=(const ARVector4 &v);
	ARVector4 operator*(float f);
	ARVector4 operator*=(float f);

	float lengthSquared() const;
	float length() const;
	void print();

	static float dot(const ARVector4 v1, const ARVector4 v2);		//点乘		|a|*|b|*cos(@)
	static ARVector4 cross(const ARVector4 v1, const ARVector4 v2);	//叉乘		P x Q = (PyQz - PzQy,PzQx - PxQz,PxQy - PyQx)//P x Q = |P x Q| = |P| * |Q| * sin(@) 
public:
	float value[4];
	
};