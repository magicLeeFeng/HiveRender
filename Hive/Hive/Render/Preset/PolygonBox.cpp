#include "PolygonBox.h"


PolygonBox::PolygonBox(void)
{
	this->init();
}


PolygonBox::~PolygonBox(void)
{
}

void PolygonBox::init()
{
	this->getMaterial();
	this->setShape(new ARMeshShape());

	int const posDataSize = 8;
	GLfloat posData[8*3]={
		0,0,0,
		1,0,0,
		1,0,1,
		0,0,1,
		0,1,0,
		1,1,0,
		1,1,1,
		0,1,1
	};
	
	GLint drawData[]={
		0,1,2,
		1,3,2,
		1,3,4,
		4,3,5,
		4,5,6,
		6,5,7,
		6,7,2,
		0,6,2,
		0,1,6,
		6,4,1,
		2,3,5,
		2,5,7
	};

	for (int i = 0;i<8;i+=2)
	{
		ARVector3 pos = ARVector3(posData[i],posData[i+1],posData[i+2]);
		this->getShape()->addVertexPos(pos);
		ARVector4 color = ARVector4(1,1,1,1);
		ARVector2 coord = ARVector2(0,0);
		this->getShape()->addVertexColor(color);
		this->getShape()->addVertexCoord(coord);
	}

	for (int i= 0 ;i<36;i++)
	{
		this->getShape()->addVertexIndex(drawData[i]);
	}
	
	this->getShape()->initAttr(this->getMaterial()->glProgram);
}
