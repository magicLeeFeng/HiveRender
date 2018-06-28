/************************************************************************/
/* ÈýÎ¬Åö×²ºÐ AABBÊµÏÖ                                                                     */
/************************************************************************/
#pragma once
#include "ARPoint.h"

class ARBBox
{
public:
	ARBBox(void);
	ARBBox(const ARPoint &p1,const ARPoint &p2);
	~ARBBox(void);

	ARPoint lerp(float tx,float ty,float tz);

public:
	ARPoint pMin, pMax;
};

