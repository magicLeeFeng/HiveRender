#include "ARVAO.h"
#include <iostream>
#include <fstream>

ARVAO::ARVAO(void)
{
	this->vao = 0;
	this->posVbo = 0;
	this->colorVbo = 0;
	this->iTriNum = 0;
}


ARVAO::~ARVAO(void)
{
}

void ARVAO::initAttr(std::vector<ARVector3> *vecPos,std::vector<ARVector4> *vecColor,std::vector<short> *indexVec)
{
	this->createGLPorgram();
	this->iTriNum = (int)(indexVec->size());

	if (this->vao == 0)
	{
		glGenVertexArrays(1,&this->vao);
	}
	glBindVertexArray(this->vao);
	//Î»ÖÃ
	if (this->posVbo == 0)
	{
		glGenBuffers(1,&this->posVbo);
	}
	glBindBuffer(GL_ARRAY_BUFFER,this->posVbo);
	glBufferData(GL_ARRAY_BUFFER,sizeof(ARVector3)*vecPos->size(),&vecPos->front(),GL_STATIC_DRAW);
	glEnableVertexAttribArray(ES_GL_VERTEX_POS_INDEX);
	glVertexAttribPointer(ES_GL_VERTEX_POS_INDEX,2,GL_FLOAT,GL_FALSE,sizeof(ARVector3),0);

	//ÑÕÉ«
	if (this->colorVbo == 0)
	{
		glGenBuffers(1,&this->colorVbo);
	}
	glBindBuffer(GL_ARRAY_BUFFER,this->colorVbo);
	glBufferData(GL_ARRAY_BUFFER,sizeof(ARVector4)*vecColor->size(),&vecColor->front(),GL_STATIC_DRAW);
	glEnableVertexAttribArray(ES_GL_VERTEX_COLOR_INDEX);
	glVertexAttribPointer(ES_GL_VERTEX_COLOR_INDEX,4,GL_FLOAT,GL_FALSE,sizeof(ARVector4),0);

	//»æÖÆË³Ðò
	if(this->indexVbo ==0 )
	{
		glGenBuffers(1,&this->indexVbo);
	}
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,this->indexVbo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(short)*indexVec->size(),&indexVec->front(),GL_STATIC_DRAW);

	glBindVertexArray(0);

}



void ARVAO::draw()
{
	if (this->iTriNum <= 0)
	{
		return;
	}
	glUseProgram(this->programObject);
	glBindVertexArray(this->vao);
	glDrawElements(GL_TRIANGLES,this->iTriNum,GL_UNSIGNED_SHORT,(GLvoid*)0);
	glBindVertexArray(0);
}

void ARVAO::createGLPorgram()
{
	char buf[1024];
	std::string vShader; 
	std::ifstream  vShaderIn("Res/vShader.v");
	while (!vShaderIn.eof())
	{
		vShaderIn.getline(buf,100);
		vShader += buf;
		vShader += "\n";
	}

	std::string fShader; 
	std::ifstream  fShaderIn("Res/fShader.f");
	while (!fShaderIn.eof())
	{
		fShaderIn.getline(buf,100);
		fShader += buf;
		fShader += "\n";
	}



	GLuint vertexShader;
	GLuint fragmentShader;
	GLint linked;

	// Load the vertex/fragment shaders
	vertexShader = LoadShader ( GL_VERTEX_SHADER, vShader.c_str());
	fragmentShader = LoadShader ( GL_FRAGMENT_SHADER, fShader.c_str());

	this->programObject = glCreateProgram();

	glAttachShader ( programObject, vertexShader );
	glAttachShader ( programObject, fragmentShader );

	glLinkProgram ( programObject );
}

GLuint ARVAO::LoadShader ( GLenum type, const char *shaderSrc )
{
	GLuint shader;
	GLint compiled;

	// Create the shader object
	shader = glCreateShader ( type );

	// Load the shader source
	glShaderSource ( shader, 1, &shaderSrc, NULL );

	// Compile the shader
	glCompileShader ( shader );

	// Check the compile status
	glGetShaderiv ( shader, GL_COMPILE_STATUS, &compiled );

	return shader; 

}

void ARVAO::update(std::vector<ARVector3> *vecPos)
{
	glUseProgram(this->programObject);
	glBindVertexArray(this->vao);
	glBindBuffer(GL_ARRAY_BUFFER,this->posVbo);
	glBufferData(GL_ARRAY_BUFFER,sizeof(ARVector3)*vecPos->size(),&vecPos->front(),GL_STATIC_DRAW);
	glBindVertexArray(0);
}

void ARVAO::setUniform(float fv)
{
	glUseProgram(this->programObject);
	GLint numformId = glGetUniformLocation(this->programObject,"uniformTest");
	glUniform1f(numformId,fv);
	
}

