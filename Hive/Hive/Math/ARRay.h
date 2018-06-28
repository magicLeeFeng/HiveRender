/************************************************************************/
/* 射线                                                                     */
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
	ARPoint o;	//起点
	ARVector3 d;	//方向
	mutable float mint, maxt;	//范围
	float time;
	int depth;
};

