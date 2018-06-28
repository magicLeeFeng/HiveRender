/************************************************************************/
/*������                                                                     */
/************************************************************************/
#pragma once

class ARVector4;
/************************************************************************/
/*��ά����                                                                     */
/************************************************************************/
struct Mat2
{ 
public:
	Mat2();
	~Mat2();
public:
	float value[2][2];
};

/************************************************************************/
/* ��ά����                                                                     */
/************************************************************************/
struct Mat3
{
public:
	Mat3();
	~Mat3();
public:
	float value[3][3];
};


/************************************************************************/
/* ��ά����                                                                     */
/************************************************************************/
struct Mat4
{
public:
	Mat4(float value[4][4]);
	Mat4(void);
	~Mat4(void);
	Mat4 operator*(const Mat4 &m);
	ARVector4 operator*(const ARVector4 &v);
public:
	void setUnit();
	void setZero();
	void setRotationX(float x);
	void setRotationY(float y);
	void setRotationZ(float z);
	void setMove(float x,float y,float z);
	void setScale(float x,float y,float z);
	void print();
public:
	float value[4][4];
};