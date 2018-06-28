#pragma once
#include "../Math/Translate.h"
class Camera
{
public:
	Camera(void);
	~Camera(void);
	Translate translate;
private:
	Mat4 projectMatrix;	//ͶӰ����
	Mat4 lookAtMatrix;		//�۲����
public:
	//����λ�úͳ���
	void setLookAt(ARVector3 pos,ARVector3 upPos,ARVector3 dir);
	//͸��ͶӰ
	void setPerspective(float fAngle,float aspect,float near,float farDis);
	//����ͶӰ
	void setOrthogonal(float height,float aspect,float near,float farDis);
	Mat4 getProjectMatrix();
	Mat4 getLookAtMatrix();
	float cot(float x);
};
