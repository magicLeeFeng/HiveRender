#include "ARScene.h"
#include "AROpenGL.h"
#include "Preset/PolygonPlane.h"

ARScene::ARScene(void)
{
}


ARScene::~ARScene(void)
{
}

void ARScene::draw()
{
	for (auto iter = vecMesh.begin(); iter != vecMesh.end(); ++iter)
	{
		(*iter)->draw();
	}
}

void ARScene::addMesh(ARMesh* mesh)
{
	this->vecMesh.push_back(mesh);
}
