#pragma once
#include <string>
#include "../Render/AROpenGL.h"
using namespace std;

class ARTextrue2D
{
public:
	ARTextrue2D(void);
	~ARTextrue2D(void);
	void initWithFile(string fileName);
	GLuint getTexture();
private:
	char*				key;
	int					width;
	int					height;
	unsigned char*		_data;
	GLuint				textureID;
};

