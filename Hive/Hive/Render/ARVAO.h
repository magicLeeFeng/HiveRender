#pragma once
#include "AROpenGL.h"
#include <vector>
#include "../Math/ARVector.h"

#define ES_GL_VERTEX_POS_INDEX		0
#define ES_GL_VERTEX_COLOR_INDEX	1
#define ES_GL_VERTEX_COOR_INDEX		2


class ARVAO
{
public:
	ARVAO(void);
	~ARVAO(void);
public:
	void	initAttr(std::vector<ARVector3> *vecPos,std::vector<ARVector4> *vecColor,std::vector<short> *indexVec);
	void	draw();
	void	createGLPorgram();
	GLuint	LoadShader ( GLenum type, const char *shaderSrc );
	void	update(std::vector<ARVector3> *vecPos);
	void	setUniform(float fv);
public:
	GLuint	vao;
	GLuint	posVbo;
	GLuint	colorVbo;
	GLuint	indexVbo;
	short	iTriNum;
	GLuint  programObject;
};

