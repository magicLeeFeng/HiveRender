#include "ARImage.h"
#include "../Tools/ARFile.h"
#include <iostream>

ARImage::ARImage(void)
{
}


ARImage::~ARImage(void)
{
	this->_data.cleanMemory();
}

void ARImage::initWithData(ARData* data)
{
	
}

void ARImage::initWithImageFile(std::string path)
{
	this->_data = ARFile::getInstance()->getDataFromFile(path);
	BITMAPINFOHEADER infoHead;
	unsigned char* _bytes = _data.getBytes();
	_bytes = _bytes + sizeof(BITMAPFILEHEADER);
	memcpy(&infoHead,_bytes,sizeof(BITMAPINFOHEADER));
	this->_width = infoHead.biWidth;
	this->_height = infoHead.biHeight;
	_bytes += sizeof(BYTE)*infoHead.biClrUsed;
	this->_colorData = _bytes;
}

int ARImage::getWidth()
{
	return this->_width;
}

int ARImage::getHeight()
{
	return this->_height;
}

unsigned char* ARImage::getColorData()
{
	return this->_colorData;
}
