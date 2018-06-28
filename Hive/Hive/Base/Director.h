#pragma once
#include "../Render/ARScene.h"

class Director
{
public:
	Director(void);
	~Director(void);
	static Director* getInstance()
	{
		static Director sDirectro;
		return &sDirectro;
	}
public:
	void init();
	void draw();
	void update();
	ARScene* getScene();
private:
	ARScene scene;
};

