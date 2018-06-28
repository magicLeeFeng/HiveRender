#pragma once
#include <vector>
#include "ARMesh.h"

using namespace std;

class ARScene
{
public:
	ARScene(void);
	~ARScene(void);
	
	void addMesh(ARMesh* mesh);
	void draw();
	
public:
	vector<ARMesh*> vecMesh;
};

