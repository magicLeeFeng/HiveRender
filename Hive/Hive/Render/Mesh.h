#pragma once
#include "ARVAO.h"

class Mesh
{
public:
	Mesh(void);
	Mesh(int width,int height);
	Mesh(int width,int height,int xPoint,int yPoint);
	~Mesh(void);
public:
	void init();
	void draw();
	void update();
	void loadTextrue(const char* fileName);
protected:
	void addVertexPos(Cv2 pos);
	void addVertexColor(Cv4  color);
	void addVertexCoord(Cv2  coord);
	void addVertexIndex(short index);
protected:
	std::vector<Cv2> vecPosition;
	std::vector<Cv2> vecCoord;
	std::vector<Cv4> vecColor;
	std::vector<short> vecIndex;
	ARVAO vao;
	float imgWidht;
	float imgHeight;
	int iMaxX;
	int iMaxY;
	float iSpaceX;
	float iSpaceY;
};

