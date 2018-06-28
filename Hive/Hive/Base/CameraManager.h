#pragma once
#include "Camera.h"

class CameraManager
{
public:
	CameraManager(void);
	~CameraManager(void);
	static CameraManager* getInstance()
	{
		static CameraManager manager;
		return &manager;
	}

	Camera* getMainCamera();
private:
	Camera _mainCamera;
};

