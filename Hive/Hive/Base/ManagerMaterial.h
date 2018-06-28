#pragma once
#include "../Render/Preset/EmptyMaterial.h"

class ManagerMaterial
{
public:
	ManagerMaterial(void);
	~ManagerMaterial(void);
	static ManagerMaterial* getInstance()
	{
		static ManagerMaterial sManager;
		return &sManager;
	}
	EmptyMaterial* getEmptyMaterial();

};

