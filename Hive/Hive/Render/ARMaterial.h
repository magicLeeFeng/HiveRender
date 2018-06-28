#pragma once
#include "AROpenGL.h"
#include "string"
#include "../Math/ARMath.h"

using namespace std;

class ARMaterial
{
public:
	ARMaterial(void);
	~ARMaterial(void);
	void loadFromFile(const char* vFile,const char* fFile);
	void createShader(const char* vsh,const char* fsh);
	GLuint loadShader(GLenum type, const char *shaderSrc);
	void activeMateral();
	void resetMateral();
	void activeTexture();
	void setTexture(string sTexture);	//设置纹理（从缓存池读取纹理）
	void setImage(string sImage);		//设置图片（从硬盘读取整张图片作为纹理）
	void setAmbientColor(ARVector3 color);	//设置环境光
	void setObject2WorldMatrix(Mat4 mat);
	void setLightColorAndPosition(int index,ARVector3 color,ARVector3 pos); //设置灯光(平行光)的颜色和位置
	void setUniform1f(const char* name,float value);
public:
	GLint glProgram;
	GLint baseTexture;
};