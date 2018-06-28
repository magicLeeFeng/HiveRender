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
	void setTexture(string sTexture);	//���������ӻ���ض�ȡ����
	void setImage(string sImage);		//����ͼƬ����Ӳ�̶�ȡ����ͼƬ��Ϊ����
	void setAmbientColor(ARVector3 color);	//���û�����
	void setObject2WorldMatrix(Mat4 mat);
	void setLightColorAndPosition(int index,ARVector3 color,ARVector3 pos); //���õƹ�(ƽ�й�)����ɫ��λ��
	void setUniform1f(const char* name,float value);
public:
	GLint glProgram;
	GLint baseTexture;
};