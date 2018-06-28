#include "ManagerMaterial.h"
#include <fstream>

ManagerMaterial::ManagerMaterial(void)
{
}

ManagerMaterial::~ManagerMaterial(void)
{
}

EmptyMaterial* ManagerMaterial::getEmptyMaterial()
{
	return new EmptyMaterial();
}