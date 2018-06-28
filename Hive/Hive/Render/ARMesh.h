/************************************************************************/
/* 几何形状                                                                     */
/************************************************************************/
#pragma once
#include "ARMaterial.h"
#include "Preset/EmptyMaterial.h"
#include "ARMeshShape.h"
#include "../Math/Translate.h"

class ARMesh
{
public:
	ARMesh(void);
	~ARMesh(void);
	void setMaterial(ARMaterial* materal);
	void setShape(ARMeshShape* shape);
	ARMeshShape* getShape();
	ARMaterial* getMaterial();
	virtual void draw();
private:
	ARMesh* _parentMesh;
public:
	ARMaterial*			materal;			//材质
	ARMeshShape*		shape;				//形状
	Translate			translate;			//变换
	
};