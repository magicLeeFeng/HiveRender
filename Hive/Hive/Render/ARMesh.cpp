#include "ARMesh.h"
#include "../Base/ManagerMaterial.h"
#include "../Base/CameraManager.h"

ARMesh::ARMesh(void)
{
	this->materal = nullptr;
	this->shape = nullptr;
	this->_parentMesh = nullptr;
}

ARMesh::~ARMesh(void)
{
	if(materal)
	{
		delete materal;
	}
	if (shape)
	{
		delete shape;
	}
}

void ARMesh::setMaterial(ARMaterial* materal)
{
	this->materal = materal;
	this->getShape()->initAttr(this->materal->glProgram);
}

ARMaterial* ARMesh::getMaterial()
{
	if (this->materal == nullptr)
	{
		this->materal = ManagerMaterial::getInstance()->getEmptyMaterial();
	}
	return this->materal;
}

void ARMesh::setShape(ARMeshShape* shape)
{
	this->shape = shape;
}

void ARMesh::draw()
{
	this->getMaterial()->activeMateral();	//¼¤»îglprogram`1`1`
	Mat4 worldMat = this->translate.getWorldTranslateARMatrix4();
	Mat4 ndcMat = CameraManager::getInstance()->getMainCamera()->getLookAtMatrix()*
					worldMat*  
					CameraManager::getInstance()->getMainCamera()->getProjectMatrix();
	this->getMaterial()->setObject2WorldMatrix(worldMat);
	this->getMaterial()->activeTexture();
	this->shape->draw(ndcMat,this->getMaterial()->glProgram);
	glUseProgram(0);	//ÖØÖÃglprogram;
}

ARMeshShape* ARMesh::getShape()
{
	return this->shape;
}
