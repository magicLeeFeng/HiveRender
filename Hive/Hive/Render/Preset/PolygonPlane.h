#pragma once
#include "../ARMesh.h"
class PolygonPlane : public ARMesh
{
public:
	PolygonPlane(void);
	PolygonPlane(int x,int y);
	~PolygonPlane(void);
	void init();
public:
	int xGird;
	int yGird;
};

