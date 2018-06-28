#include "ARTextrue2D.h"
#include "ARImage.h"

ARTextrue2D::ARTextrue2D(void)
{
}


ARTextrue2D::~ARTextrue2D(void)
{
}

void ARTextrue2D::initWithFile(string fileName)
{
	ARImage image;
	image.initWithImageFile(fileName);
	this->width = image.getWidth();
	this->height = image.getHeight();
	this->_data = image.getColorData();


	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glGenTextures(1,&textureID);
	glBindTexture(GL_TEXTURE_2D,textureID);
	
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,this->width,this->height,0,GL_RGB,
					GL_UNSIGNED_BYTE,this->_data);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);

}

GLuint ARTextrue2D::getTexture()
{
	return this->textureID;
}
