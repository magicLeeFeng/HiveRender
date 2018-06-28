#include "Camera.h"
#include <math.h>

Camera::Camera(void)
{
}


Camera::~Camera(void)
{
}
//透视投影
void Camera::setPerspective(float fAngle,float aspect,float near,float farDis)
{
	this->projectMatrix.setZero();
	this->projectMatrix.value[0][0] = cot(fAngle*0.5f)/aspect;
	this->projectMatrix.value[1][1] = cot(fAngle*0.5f);
	this->projectMatrix.value[2][2] = (near+farDis)/(farDis-near)*-1;
	this->projectMatrix.value[2][3] = -1;
	this->projectMatrix.value[3][2] = (2*near*farDis)/(farDis-near)*-1;
}
//正交投影
void Camera::setOrthogonal(float height,float aspect,float near,float farDis)
{
	this->projectMatrix.setZero();
	this->projectMatrix.value[0][0] = 1/(aspect*height*0.5f);
	this->projectMatrix.value[1][1] = 1/(height*0.5f);
	this->projectMatrix.value[2][2] = (1/((farDis - near)*0.5f))*-1;
	this->projectMatrix.value[3][3] = 1.0f;
	this->projectMatrix.value[3][2] = ((farDis+near)/(farDis-near))*-1;
}
//视角和方向
void Camera::setLookAt(ARVector3 pos,ARVector3 upPos,ARVector3 dir) 
{
	this->lookAtMatrix.setUnit();
	this->lookAtMatrix.value[3][0] = pos.x;
	this->lookAtMatrix.value[3][1] = pos.y;
	this->lookAtMatrix.value[3][2] = pos.z;

	Mat4 matN;
	matN.value[2][2] = -1;
	this->lookAtMatrix = this->lookAtMatrix * matN;
}

Mat4 Camera::getProjectMatrix()
{
	return projectMatrix;
}

Mat4 Camera::getLookAtMatrix()
{
	lookAtMatrix = lookAtMatrix * this->translate.getWorldTranslateARMatrix4();
	return lookAtMatrix;
}

float Camera::cot(float x)
{
	return 1/tan(x);
}
