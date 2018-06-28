#include "Director.h"
#include <iostream>
#include "CameraManager.h"

Director::Director(void)
{
	this->init();
}


Director::~Director(void)
{
}

void Director::init()
{
	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);
}


void Director::draw()
{
	glClearColor(1,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  	Mat4 mat = CameraManager::getInstance()->getMainCamera()->getProjectMatrix() * 
  					CameraManager::getInstance()->getMainCamera()->getLookAtMatrix();
	scene.draw();
	glFlush();
}

void Director::update()
{
}

ARScene* Director::getScene()
{
	return &this->scene;
}
