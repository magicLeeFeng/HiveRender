#pragma once
#include "ARTextrue2D.h"

class TextureCacheManager
{
public:
	TextureCacheManager(void);
	~TextureCacheManager(void);
	static TextureCacheManager* getInstance()
	{
		static TextureCacheManager sManager;
		return &sManager;
	}
public:
	ARTextrue2D* getTexture(char* fileName);
	
};

