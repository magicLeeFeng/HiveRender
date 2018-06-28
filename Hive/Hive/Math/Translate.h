#pragma once
#include "ARVector.h"
#include "ARMatrix.h"

class Translate
{
public:
	Translate(void);
	~Translate(void);
public:
	void setPostion(ARVector3 pos);	
	void setRotation(float x,float y,float z);
	void setScale(float x,float y,float z);
	void setLookAt(ARVector3 up,ARVector3 dir);
	void setParent(Translate parent);
	void addChild(Translate child);
	Mat4 getMatrix();
	Mat4 getWorldTranslateARMatrix4();
protected:
	void translateMatrix();
	Mat4 getRotationMat();
	Mat4 getScaleMat();
	Mat4 getMoveMat();
protected:
	Mat4		_matrix;				//±‰ªªæÿ’Û
	ARVector3	_worldPosition;
	ARVector3	_localPostion;
	ARVector3	position;
	ARVector3	rotation;
	ARVector3	scale;
	Translate*	_parent;
};