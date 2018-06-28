#include "ARMaterial.h"
#include <iostream>
#include "../Base/ARTextrue2D.h"
#include "../Tools/ARFile.h"
#include "ARRenderDefine.h"

ARMaterial::ARMaterial(void)
{
	glProgram = 0;
	baseTexture = 0;
}

ARMaterial::~ARMaterial(void)
{
}

void ARMaterial::loadFromFile(const char* vFile,const char* fFile)
{
	string vInfo = ARFile::getInstance()->getStringFromFile(vFile);
	string fInfo = ARFile::getInstance()->getStringFromFile(fFile);
	this->createShader(vInfo.c_str(),fInfo.c_str());
}


void ARMaterial::createShader(const char* vsh,const char* fsh)
{
	if (glProgram == 0)
	{
		glProgram = glCreateProgram();
	}

	//载入预设变量，注意添加顺序.
	string sV = vsh;
	string sF = fsh;
 	//顶点
	sV = "attribute vec4 ARPosition;\n" + sV;
 	sV = "attribute vec2 ARCoord;\n" + sV;
	sV = "attribute vec3 ARNORMAL;\n" + sV;
 	sV = "uniform mat4 ARMVP;\n" + sV;
	sV = "uniform vec3 AR_AMBIENT_COLOR;\n" + sV;
	sV = "uniform vec3 _LightColor0;\n" + sV;
	sV = "uniform vec3 _LightPosition0;\n" + sV;
	sV = "uniform mat4 _object2World;\n" + sV;
	//片元
	sF = "uniform vec3 AR_AMBIENT_COLOR;\n" + sF;
	sF = "uniform vec3 _LightColor0;\n" + sF;
	sF = "uniform vec3 _LightPosition0;\n" + sF;
	sF = "uniform mat4 _object2World;\n" + sF;
	sF = "precision mediump float;\n" + sF;

	GLuint	vertexShader;
	GLuint	fragmentShader;
	vertexShader = loadShader(GL_VERTEX_SHADER,sV.c_str());
	fragmentShader = loadShader(GL_FRAGMENT_SHADER,sF.c_str());
	glAttachShader(glProgram,vertexShader);
	glAttachShader(glProgram,fragmentShader);
	glLinkProgram(glProgram);
}

GLuint ARMaterial::loadShader(GLenum type, const char *shaderSrc)
{
	GLuint shader ;
	GLint compiled;
	shader = glCreateShader(type);
	glShaderSource(shader,1,&shaderSrc,nullptr);
	glCompileShader(shader);
	glGetShaderiv ( shader, GL_COMPILE_STATUS, &compiled);
	return shader;
}

void ARMaterial::activeMateral()
{
 	glUseProgram(this->glProgram);
}


void ARMaterial::resetMateral()
{
	glUseProgram(0);
}


void ARMaterial::activeTexture()
{
	if (baseTexture != 0)
	{
		glBindTexture(GL_TEXTURE_2D,this->baseTexture);
	}
}

void ARMaterial::setTexture(string sTexture)
{
	this->activeMateral();
	ARTextrue2D texture;
	texture.initWithFile(sTexture);
	this->baseTexture = texture.getTexture();
	
	GLint textureID = glGetUniformLocation(this->glProgram,"s_texture");
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D,this->baseTexture);
	glUniform1i(textureID,0);
}

void ARMaterial::setImage(string sImage)
{

}

void ARMaterial::setAmbientColor(ARVector3 color)
{
	this->activeMateral();
	GLint colorID = glGetUniformLocation(this->glProgram,SHADER_UNIFORM_AMBIENT_COLOR);
	glUniform3f(colorID,color.x,color.y,color.z);
}

void ARMaterial::setLightColorAndPosition(int index,ARVector3 color,ARVector3 pos)
{
	this->activeMateral();
	GLint colorID = glGetUniformLocation(this->glProgram,("_LightColor"+to_string(index)).c_str());
	glUniform3f(colorID,color.x,color.y,color.z);
	GLint positionID = glGetUniformLocation(this->glProgram,("_LightPosition"+to_string(index)).c_str());
	glUniform3f(positionID,pos.x,pos.y,pos.z);
}

void ARMaterial::setObject2WorldMatrix(Mat4 mat)
{
	this->activeMateral();
	GLint mvpID = glGetUniformLocation(glProgram,SHADER_UNIFORM_OBJ2WORLD);
	glUniformMatrix4fv(mvpID,1,GL_FALSE,&(mat.value[0][0]));
}

void ARMaterial::setUniform1f(const char* name,float value)
{
	this->activeMateral();
	GLint _id = glGetUniformLocation(this->glProgram,name);
	glUniform1f(_id,value);
}

