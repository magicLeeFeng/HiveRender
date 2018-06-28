#pragma once
#include "HiveRender.h"

class AppDelegate
{
public:
	AppDelegate(void);
	~AppDelegate(void);
	static AppDelegate* getInstance()
	{
		static AppDelegate sAPP;
		return &sAPP;
	}
	void run();
	void update();
	void draw();
public:
	Director* director;
	float posY;
};

