#include "Mesh.h"
#include <iostream>
#include <math.h>
#include <atlimage.h>

Mesh::Mesh(void)
{
	imgWidht	= 0.2f;
	imgHeight	= 0.2f;
	iMaxX = 10;
	iMaxY = 2;
}

Mesh::Mesh(int width,int height)
{
	imgWidht	= width;
	imgHeight	= height;
	iMaxX = 2;
	iMaxY = 2;
}

Mesh::Mesh(int width,int height,int xPoint,int yPoint)
{
	imgWidht	= width;
	imgHeight	= height;
	iMaxX = xPoint;
	iMaxY = yPoint;

}


Mesh::~Mesh(void)
{
}

void Mesh::init()
{
	iMaxX = iMaxX >= 2 ? iMaxX : 2;
	iMaxY = iMaxY >= 2 ? iMaxY : 2;
	iSpaceX = imgWidht/(iMaxX-1);
	iSpaceY = imgHeight/(iMaxY-1);

	for (int i=0;i<iMaxY;i++)
	{
		printf("\n");
		for (int j=0;j<iMaxX;j++)
		{
			printf("   ");
			float _posX =0.0f;
			float _posY =0.0f;
			float _offset = -0.5f;

			_offset = 0.0f;
			_posX = j*iSpaceX+_offset;
			_posY = i*iSpaceY+_offset;

			Cv2 pos = Cv2(_posX,_posY);
			printf("%0.3f=====%0.3f",pos.p1,pos.p2);
			Cv4 color = Cv4(1,1,1,1);
			Cv2 coord = Cv2(_posX*1.0f/imgWidht,1.0-_posY*1.0f/imgHeight);
			this->addVertexPos(pos);
			this->addVertexColor(color);
			this->addVertexCoord(coord);
		}
	}

	for (int i=0;i<iMaxY-1;i++)
	{
		for (int j=0;j<iMaxX-1;j++)
		{
			this->addVertexIndex(iMaxX*i+j);
			this->addVertexIndex(iMaxX*i+1+iMaxX+j);
			this->addVertexIndex(iMaxX*i+iMaxX+j);
			this->addVertexIndex(iMaxX*i+j);
			this->addVertexIndex(iMaxX*i+1+j);
			this->addVertexIndex(iMaxX*i+1+iMaxX+j);
		}
	}

	this->vao.initAttr(&this->vecPosition,&this->vecColor,&this->vecIndex);

	this->vao.setUniform(0.5f);
}


void Mesh::update()
{

}


void Mesh::draw()
{
// 	for (int i=0;i<this->vecPosition.size();i++)
// 	{
// 		this->vecPosition.at(i).p2 +=( (rand()%11)*0.1f-0.5f)*0.01f;
// 		//this->vecPosition.at(i).p1 +=( (rand()%11)*0.1f-0.5f)*0.01f;
// 	}
 	this->vao.update(&vecPosition);
	this->vao.draw();
}

void Mesh::addVertexPos(Cv2 pos)
{
	this->vecPosition.push_back(pos);
}

void Mesh::addVertexColor(Cv4 color)
{
	this->vecColor.push_back(color);
}

void Mesh::addVertexCoord(Cv2 coord)
{
	this->vecCoord.push_back(coord);
}

void Mesh::addVertexIndex(short index)
{
	this->vecIndex.push_back(index);
}

