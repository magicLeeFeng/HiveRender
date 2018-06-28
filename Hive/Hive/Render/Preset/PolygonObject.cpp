#include "PolygonObject.h"
#include "../../Tools/ARFile.h"
#include "../../Tools/StringTools.h"
#include <iostream>

PolygonObject::PolygonObject(void)
{
}

PolygonObject::PolygonObject(std::string path)
{
	this->initFile(path);
}


PolygonObject::~PolygonObject(void)
{
}


void PolygonObject::initFile(std::string file)
{
	this->getMaterial();
	this->setShape(new ARMeshShape());
	
	string sInfo = ARFile::getInstance()->getStringFromFile(file);
	while(1)
	{
		string firstLine = spliteFistLine(&sInfo);
		if (sInfo.size() == 0 && firstLine.size()==0)
		{
			break;
		}else if (getFirstWord(&firstLine) == "v")	//顶点
		{
			vector<string> sVec = spliteFirstSpace(&firstLine);
			ARVector3 pos = ARVector3(atof(sVec[1].c_str()),atof(sVec[2].c_str()),atof(sVec[3].c_str()));
			this->getShape()->addVertexPos(pos);
		}else if (getFirstWord(&firstLine) == "vt")	//顶点UV
		{
 			vector<string> sVec = spliteFirstSpace(&firstLine);
 			ARVector2 uv = ARVector2(atof(sVec[1].c_str()),atof(sVec[2].c_str()));
 			this->getShape()->addVertexCoord(uv);
		}else if (getFirstWord(&firstLine) == "vn")	//顶点法线
		{
			vector<string> sVec = spliteFirstSpace(&firstLine);
			ARVector3 pointNormal = ARVector3(atof(sVec[1].c_str()),atof(sVec[2].c_str()),atof(sVec[3].c_str()));
			this->getShape()->addVertexNormal(pointNormal);
		}else if (getFirstWord(&firstLine) == "f")	//绘制信息
		{
			vector<string> sVec = spliteFirstSpace(&firstLine);
			for (int i = 1 ;i <= 3 ;i++)
			{
				string sInfo = sVec[i];
				vector<int> vecString = spliteStringToInt(&sInfo,"/");
				//顶点
				int point = vecString[0] - 1;
// 				//纹理坐标
// 				int uv = vecString[1] - 1;
// 				//法线
// 				int pointNormal = vecString[2] - 1;
				this->getShape()->addVertexIndex(point);
			}
		}
	}
	this->getShape()->initAttr(this->getMaterial()->glProgram);
}

