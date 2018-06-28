#pragma once
#include "../Math/Translate.h"
class Camera
{
public:
	Camera(void);
	~Camera(void);
	Translate translate;
private:
	Mat4 projectMatrix;	//投影矩阵
	Mat4 lookAtMatrix;		//观察矩阵
public:
	//设置位置和朝向
	void setLookAt(ARVector3 pos,ARVector3 upPos,ARVector3 dir);
	//透视投影
	void setPerspective(float fAngle,float aspect,float near,float farDis);
	//正交投影
	void setOrthogonal(float height,float aspect,float near,float farDis);
	Mat4 getProjectMatrix();
	Mat4 getLookAtMatrix();
	float cot(float x);
};
