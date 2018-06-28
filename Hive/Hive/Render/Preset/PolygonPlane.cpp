#include "PolygonPlane.h"


PolygonPlane::PolygonPlane(void)
{
	this->xGird = this->yGird = 2;
	this->init();
}

PolygonPlane::PolygonPlane(int x,int y)
{
	this->xGird = x;this->yGird = y;
	this->xGird >= 2 ? xGird : 2;
	this->yGird >= 2 ? yGird : 2;
	this->init();
}


PolygonPlane::~PolygonPlane(void)
{
}

void PolygonPlane::init()
{
	this->setShape(new ARMeshShape());
	float imgWidht = 10.0f;
	float imgHeight = 10.0f;
	int iPointNumX = 50;
	int iPointNumY = 50;
	float iSpaceX = imgWidht/(iPointNumX-1);
	float iSpaceY = imgHeight/(iPointNumY-1);

	for (int i=0;i<iPointNumY;i++)
	{
		for (int j=0;j<iPointNumX;j++)
		{
			float _posX =0.0f;
			float _posY =0.0f;

			_posX += j*iSpaceX - imgWidht*0.5f;
			_posY += i*iSpaceY - imgHeight*0.5f;
			ARVector3 pos = ARVector3(_posX,_posY,0);
			ARVector2 coord = ARVector2(j*1.0f/(iPointNumX-1),i*1.0f/(iPointNumY-1));
			ARVector3 normal = ARVector3(1,1,1);
			this->getShape()->addVertexPos(pos);
			this->getShape()->addVertexCoord(coord);
			this->getShape()->addVertexNormal(normal);
		}
	}
	
	for (int i=0;i<iPointNumY-1;i++)
	{
		for (int j=0;j<iPointNumX-1;j++)
		{
			this->getShape()->addVertexIndex(iPointNumX*i+j);
			this->getShape()->addVertexIndex(iPointNumX*i+1+iPointNumX+j);
			this->getShape()->addVertexIndex(iPointNumX*i+iPointNumX+j);
			this->getShape()->addVertexIndex(iPointNumX*i+j);
			this->getShape()->addVertexIndex(iPointNumX*i+1+j);
			this->getShape()->addVertexIndex(iPointNumX*i+1+iPointNumX+j);
		}
	}
	this->getShape()->initAttr(this->getMaterial()->glProgram);
}
