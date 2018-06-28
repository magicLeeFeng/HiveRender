#include "ARMeshShape.h"
#include <iostream>
#include <string>
#include "ARRenderDefine.h"

using namespace std;

ARMeshShape::ARMeshShape(void)
{
	this->vao = 0;
	this->posVbo = 0;
	this->colorVbo = 0;
	this->iTriNum = 0;
	this->coordVbo = 0;
	this->indexVbo = 0;
	this->normalVbo = 0;
}


ARMeshShape::~ARMeshShape(void)
{
	
}

void ARMeshShape::draw(Mat4 matrix,GLint glprogram)
{
	if (glprogram == 0 || this->iTriNum <= 0)
	{
		return;
	}
	
	GLint mvpID = glGetUniformLocation(glprogram,SHADER_UNIFORM_MVP);
	glUniformMatrix4fv(mvpID,1,GL_FALSE,&(matrix.value[0][0]));
	glBindVertexArray(this->vao);
	glDrawElements(GL_TRIANGLES,this->iTriNum,GL_UNSIGNED_SHORT,(GLvoid*)0);
	glBindVertexArray(0);
}

void ARMeshShape::setPointAttr(GLint glprogram,std::vector<ARVector3> *vecPos,
							   std::vector<ARVector4> *vecColor,
							   std::vector<short> *indexVec,
									vector<ARVector2> *vecCoord,
									vector<ARVector3> * vecNormal)
{
	glUseProgram(glprogram);
	this->iTriNum = (int)(indexVec->size());

	if (this->vao == 0)
	{
		glGenVertexArrays(1,&this->vao);
	}
	glBindVertexArray(this->vao);
	//位置
	if (this->posVbo == 0)
	{
		glGenBuffers(1,&this->posVbo);
	}
	
	GLint posIndex = glGetAttribLocation(glprogram,SHADER_ATTR_POSITION);
	glBindBuffer(GL_ARRAY_BUFFER,this->posVbo);
	glBufferData(GL_ARRAY_BUFFER,sizeof(ARVector3)*vecPos->size(),&vecPos->front(),GL_STATIC_DRAW);
	glEnableVertexAttribArray(posIndex);
	glVertexAttribPointer(posIndex,3,GL_FLOAT,GL_FALSE,sizeof(ARVector3),0);

// 	//颜色
// 	if (vecColor->size()>0)
// 	{
// 		if (this->colorVbo == 0)
// 		{
// 			glGenBuffers(1,&this->colorVbo);
// 		}
// 		GLint colorIndex = glGetAttribLocation(glprogram,SHADER_ATTR_COLOR);
// 		glBindBuffer(GL_ARRAY_BUFFER,this->colorVbo);
// 		glBufferData(GL_ARRAY_BUFFER,sizeof(ARVector4)*vecColor->size(),&vecColor->front(),GL_STATIC_DRAW);
// 		glEnableVertexAttribArray(colorIndex);
// 		glVertexAttribPointer(colorIndex,4,GL_FLOAT,GL_FALSE,sizeof(ARVector4),0);
// 	}

	//uv
	if (vecCoord->size()>0)
	{
		if (this->coordVbo == 0)
		{
			glGenBuffers(1,&this->coordVbo);
		}
		GLint coordIndex = glGetAttribLocation(glprogram,SHADER_ATTR_COORD);
		glBindBuffer(GL_ARRAY_BUFFER,this->coordVbo);
		glBufferData(GL_ARRAY_BUFFER,sizeof(ARVector2)*vecCoord->size(),&vecCoord->front(),GL_STATIC_DRAW);
		glEnableVertexAttribArray(coordIndex);
		glVertexAttribPointer(coordIndex,2,GL_FLOAT,GL_FALSE,sizeof(ARVector2),0);
	}

	//法线
	if (vecNormal->size()>0)
	{
		if (this->normalVbo == 0)
		{
			glGenBuffers(1,&this->normalVbo);
		}
		GLint normalIndex = glGetAttribLocation(glprogram,SHADER_ATTR_NORMAL);
		glBindBuffer(GL_ARRAY_BUFFER,this->normalVbo);
		glBufferData(GL_ARRAY_BUFFER,sizeof(ARVector3)*vecNormal->size(),&vecNormal->front(),GL_STATIC_DRAW);
		glEnableVertexAttribArray(normalIndex);
		glVertexAttribPointer(normalIndex,3,GL_FLOAT,GL_FALSE,sizeof(ARVector3),0);		
	}

	//绘制顺序
	if (indexVec->size()>0)
	{
		if(this->indexVbo == 0 )
		{
			glGenBuffers(1,&this->indexVbo);
		}
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,this->indexVbo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(short)*indexVec->size(),&indexVec->front(),GL_STATIC_DRAW);
	}

	glBindVertexArray(0);
}

void ARMeshShape::updatePointPosition(std::vector<ARVector3> *vecPos)
{
	glBindVertexArray(this->vao);
	glBindBuffer(GL_ARRAY_BUFFER,this->posVbo);
	glBufferData(GL_ARRAY_BUFFER,sizeof(ARVector3)*vecPos->size(),&vecPos->front(),GL_STATIC_DRAW);
	glBindVertexArray(0);
}

void ARMeshShape::addVertexPos(ARVector3 pos)
{
	this->vecPoint.push_back(pos);
}

void ARMeshShape::addVertexColor(ARVector4 color)
{
	this->vecColor.push_back(color);
}

void ARMeshShape::addVertexCoord(ARVector2 coord)
{
	this->vecTexCoord.push_back(coord);
}

void ARMeshShape::addVertexIndex(short index)
{
	this->vecIndex.push_back(index);
}


void ARMeshShape::addVertexNormal(ARVector3 normal)
{
	this->vecNormal.push_back(normal);
}

void ARMeshShape::initAttr(GLint glprogram)
{
	this->setPointAttr(glprogram,&this->vecPoint
		,&this->vecColor,
		&this->vecIndex,
		&this->vecTexCoord,
		&this->vecNormal);
}
