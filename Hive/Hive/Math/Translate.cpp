#include "Translate.h"
#include <iostream>

Translate::Translate(void)
{
	_parent = nullptr;
	this->position.zero();
	this->rotation.zero();
	this->scale.one();
}


Translate::~Translate(void)
{
}

Mat4 Translate::getMatrix()
{
	return this->_matrix;
}

void Translate::setLookAt(ARVector3 up,ARVector3 dir)
{

}


void Translate::setPostion(ARVector3 pos)
{
	this->position = pos;
	this->translateMatrix();
}

void Translate::setRotation(float x,float y,float z)
{
	x = 2*3.14f*x/360;
	y = 2*3.14f*y/360;
	z = 2*3.14f*z/360;
	this->rotation = ARVector3(x,y,z);
	this->translateMatrix();
}

void Translate::setScale(float x,float y,float z)
{
	this->scale = ARVector3(x,y,z);
	this->translateMatrix();
}

void Translate::translateMatrix()
{
	this->_matrix =this->getScaleMat() * this->getRotationMat() * this->getMoveMat();
}

Mat4 Translate::getRotationMat()
{
	Mat4 mRetX;
	Mat4 mRetY;
	Mat4 mRetZ;
	mRetX.setRotationX(this->rotation.x);
 	mRetY.setRotationY(this->rotation.y);
 	mRetZ.setRotationZ(this->rotation.z);
	Mat4 mRet = mRetZ * mRetY * mRetX;

	return mRet;
}

Mat4 Translate::getScaleMat()
{
	Mat4 mRet;
	mRet.setScale(this->scale.x,this->scale.y,this->scale.z);
	return mRet;
}

Mat4 Translate::getMoveMat()
{
	Mat4 mat;
	mat.setMove(this->position.x,this->position.y,this->position.z);
	return mat;
}

Mat4 Translate::getWorldTranslateARMatrix4()
{
	if (this->_parent!=nullptr)
	{
		return this->getWorldTranslateARMatrix4() * this->_parent->getMatrix();
	}
	return this->getMatrix();
}
