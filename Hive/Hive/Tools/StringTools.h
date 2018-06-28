#pragma once
#include <string>
#include <vector>
using namespace std;

string spliteFistLine(string* src)
{
	string sRet = "";
	while(1){
		if ((*src)[0] == '\0' || (*src)[0] == '\n')
		{
			src->erase(0,1);
			break;
		}
		sRet += (*src)[0];
		src->erase(0,1);
	}
	return sRet;
}

string getFirstWord(string* src)
{
	string sRet = "";
	int index = 0;
	while(1)
	{
		if ((*src)[index] == '\0' || (*src)[index] == ' ')
		{
			break;
		}
		sRet += (*src)[index];
		index++;
	}
	return sRet;
}

vector<string> spliteFirstSpace(string* src)
{
	vector<string> vRet;
	while(1)
	{
		string sRet = "";
		if((*src)[0] == '\n' || (*src)[0] == '\0')
		{
			src->erase(0,1);
			return vRet;
		}
		while(1){
			if ((*src)[0] == ' ' || (*src)[0] == '\0')
			{
				src->erase(0,1);
				if (sRet.size()>0)
				{
					break;
				}
			}
			sRet += (*src)[0];
			src->erase(0,1);
		}
		vRet.push_back(sRet);
	}
	return vRet;
}

vector<string> spliteString(string* src,const char* spliteByte)
{
	vector<string> vRet;
	string sInfo = "";
	for (int i = 0 ;i<src->length();i++)
	{
		bool bSp = false;
		if (src->at(i) != *spliteByte)
		{
			sInfo += src->at(i);
			bSp = true;
		}
		if (bSp ==  false || i == src->length()-1)
		{
			string sv = sInfo;
			vRet.push_back(sv);
			sInfo = "";
		}
	}

	return vRet;
}

vector<int> spliteStringToInt(string* src,const char* spliteByte)
{
	vector<int> vRet;
	string vSprite = "";
	for (int i = 0 ;i<src->length();i++)
	{
		bool bSp = false;
		if (src->at(i) != *spliteByte)
		{
			string sInfo = "";
			vSprite += src->at(i);
			bSp = true;
		}
		if (bSp == false || i == src->length()-1)
		{
			int iVaue = atof(vSprite.c_str());
			vRet.push_back(iVaue);
			vSprite.clear();
		}
	}

	return vRet;
}