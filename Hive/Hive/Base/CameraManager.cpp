#include "CameraManager.h"


CameraManager::CameraManager(void)
{
}


CameraManager::~CameraManager(void)
{
}

Camera* CameraManager::getMainCamera()
{
	return &this->_mainCamera;
}
