/************************************************************************/
/* ����                                                                     */
/************************************************************************/
#pragma once
#include "ARPoint.h"
#include "ARVector.h"

class ARRay
{
public:
	ARRay(void);
	~ARRay(void);
public:
	ARPoint o;	//���
	ARVector3 d;	//����
	mutable float mint, maxt;	//��Χ
	float time;
	int depth;
};

