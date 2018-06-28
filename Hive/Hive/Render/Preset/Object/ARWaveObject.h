#pragma once
#include "../../ARMesh.h"
class ARWaveObject : public ARMesh
{
public:
	ARWaveObject(void);
	ARWaveObject(int x,int y);
	~ARWaveObject(void);
	void init();
	virtual void draw();
public:
	int xGird;
	int yGird;
	float posY;
};
