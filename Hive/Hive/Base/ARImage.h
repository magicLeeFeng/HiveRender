#pragma once
#include "ARData.h"
#include <string>

using namespace std;

typedef struct tagIMAGEDATA  
{  
	unsigned char blue;
	unsigned char green;
	unsigned char red;
}IMAGEDATA;

class ARImage
{
public:
	ARImage(void);
	~ARImage(void);
public:
	void initWithImageFile(std::string path);
	void initWithData(ARData* data);
	int getWidth();
	int getHeight();
	unsigned char* getColorData();
private:
	int _width;
	int _height;
	unsigned char* _colorData;
	ARData _data;
};

