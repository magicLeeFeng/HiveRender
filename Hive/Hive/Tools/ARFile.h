#pragma once
#include <string>
#include "../Render/AROpenGL.h"
#include "../Base/ARData.h"

using namespace std;

// typedef struct tagIMAGEDATA  
// {  
// 	BYTE blue;  
// 	BYTE green;  
// 	BYTE red;  
// }IMAGEDATA;  

class ARFile
{
public:
	ARFile(void);
	~ARFile(void);
public:
	static ARFile* getInstance()
	{
		static ARFile sFile;
		return &sFile;
	}
	ARData getDataFromFile(string fileName);
	string getStringFromFile(string fileName);
private:
	int loadImageBmp(char *filename);
	ARData getData(string path,bool bString);
public:

};

