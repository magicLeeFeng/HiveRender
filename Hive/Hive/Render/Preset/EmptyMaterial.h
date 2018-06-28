#pragma once
#include "../ARMaterial.h"

class EmptyMaterial : public ARMaterial
{
public:
	EmptyMaterial(void);
	~EmptyMaterial(void);
	void createEmptyShader();
};

