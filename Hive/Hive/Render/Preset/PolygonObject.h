#pragma once
#include "../ARMesh.h"
#include <string>

class PolygonObject : public ARMesh
{
public:
	PolygonObject(void);
	~PolygonObject(void);
	PolygonObject(std::string path);
private:
	void initFile(std::string path);
};

