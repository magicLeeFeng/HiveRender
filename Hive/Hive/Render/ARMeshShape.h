#pragma once

#include <vector>
#include "../Math/ARVector.h"
#include "AROpenGL.h"
#include "../Math/ARMatrix.h"

using namespace std;

class ARMeshShape
{
public:
	ARMeshShape(void);
	~ARMeshShape(void);
	void initAttr(GLint glprogram);
	void setPointAttr(GLint glprogram,vector<ARVector3> *vecPos,
					vector<ARVector4> *vecColor,
					vector<short> *indexVec,
						vector<ARVector2> *vecCoord,
						vector<ARVector3> * vecNormal);
	void updatePointPosition(std::vector<ARVector3> *vecPos);
	void draw(Mat4 matrix,GLint glProgram);
	void addVertexPos(ARVector3 pos);
	void addVertexColor(ARVector4  color);
	void addVertexCoord(ARVector2  coord);
	void addVertexNormal(ARVector3 normal);
	void addVertexIndex(short index);
protected:
	vector<ARVector3>	vecPoint;		//��
	vector<ARVector2>	vecTexCoord;	//����
	vector<ARVector3>	vecNormal;		//����
	vector<ARVector4>	vecColor;		//������ɫ
	vector<short>		vecIndex;		//���Ʊ��

	GLuint	vao;
	GLuint	posVbo;
	GLuint	colorVbo;
	GLuint	coordVbo;
	GLuint	indexVbo;
	GLuint	normalVbo;
	short	iTriNum;
};
