#include "ARFile.h"
#include <fstream>
#include <iostream>

ARFile::ARFile(void)
{
}


ARFile::~ARFile(void)
{
}

int ARFile::loadImageBmp(char *strFile)
{
// 	FILE *fpi;  
// 	fpi=fopen(strFile,"rb");
// 	if(fpi != NULL){  
// 		GLuint texture[2];
// 		BITMAPFILEHEADER strHead;  
// 		RGBQUAD strPla[256];//256ɫ��ɫ��  
// 		BITMAPINFOHEADER strInfo;  
// 		//�ȶ�ȡ�ļ�����  
// 		WORD bfType;  
// 		fread(&bfType,sizeof(WORD),1,fpi);  
// 		if(0x4d42!=bfType)  
// 		{
// 			cout<<"the file is not a bmp file!"<<endl;
// 			return NULL;
// 		}
// 		fseek(fpi,0,SEEK_SET);
// 		//��ȡbmp�ļ����ļ�ͷ����Ϣͷ  
// 		fread(&strHead,sizeof(tagBITMAPFILEHEADER),1,fpi);  
// 		cout << strHead.bfOffBits << endl;
// 		//showBmpHead(strHead);//��ʾ�ļ�ͷ  
// 		fread(&strInfo,sizeof(tagBITMAPINFOHEADER),1,fpi);  
// 		//showBmpInforHead(strInfo);//��ʾ�ļ���Ϣͷ  
// 		//��ȡ��ɫ�� 
// 		for(unsigned int nCounti=0;nCounti<strInfo.biClrUsed;nCounti++)  
// 		{
// 			fread((char *)&(strPla[nCounti].rgbBlue),1,sizeof(BYTE),fpi); 
// 			fread((char *)&(strPla[nCounti].rgbGreen),1,sizeof(BYTE),fpi);
// 			fread((char *)&(strPla[nCounti].rgbRed),1,sizeof(BYTE),fpi);
// 			fread((char *)&(strPla[nCounti].rgbReserved),1,sizeof(BYTE),fpi);
// 		}
// 		int width,height;//ͼƬ�Ŀ�Ⱥ͸߶�
// 		width = strInfo.biWidth;
// 		height = strInfo.biHeight;
// 		IMAGEDATA *imagedata = NULL;//��̬����洢ԭͼƬ��������Ϣ�Ķ�ά����  
// 		imagedata = (IMAGEDATA*)malloc(width * height * sizeof(IMAGEDATA));  
// 		fread(imagedata,sizeof(struct tagIMAGEDATA) * width,height,fpi);
// // 		for(int i = 0;i < height;++i)
// // 		{
// // 			for(int j = 0;j < width;++j)  
// // 			{
// // 				printf("%d,%d,%d ",(*(imagedata + i * width + j)).red,
// // 					(*(imagedata + i * width + j)).green,
// // 					(*(imagedata + i * width + j)).blue);
// // 			}
// // 			cout << endl;
// // 		}
// 
// 		delete imagedata;
// 		fclose(fpi);
// 	}
	return 1;
}

ARData ARFile::getData(string fileName,bool bString)
{
	string type;
	if (bString == true)
	{
		type = "rt";
	}else
	{
		type =  "rb";
	}
	unsigned char* buffer = nullptr;
	size_t size = 0;
    size_t readsize;
	ARData data;
	FILE *fpi;
	
	fpi=fopen(fileName.c_str(),type.c_str());
	if(fpi != NULL){
		fseek(fpi,0,SEEK_END);
		size = ftell(fpi);
		fseek(fpi,0,SEEK_SET);
		if (bString == true)
		{
			buffer = (unsigned char*)malloc(sizeof(unsigned char) * (size + 1));
			buffer[size] = '\0';
		}else
		{
			buffer = (unsigned char*)malloc(sizeof(unsigned char) * size);
		}
		readsize = fread(buffer, sizeof(unsigned char), size, fpi);

		fclose(fpi);
		if (bString && readsize < size)
		{
			buffer[readsize] = '\0';
		}
	}
	data.setData(buffer,readsize);
	return data;
}

ARData ARFile::getDataFromFile(string fileName)
{
	return this->getData(fileName,true);
}

std::string ARFile::getStringFromFile(string fileName)
{
	ARData data = this->getData(fileName,true);
	std::string ret((const char*)data.getBytes());
	return ret;
}
