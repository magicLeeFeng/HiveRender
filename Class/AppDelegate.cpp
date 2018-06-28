#include "AppDelegate.h"


AppDelegate::AppDelegate(void)
{
	posY = 1.0f;
}


AppDelegate::~AppDelegate(void)
{
}

void AppDelegate::run()
{
	CameraManager::getInstance()->getMainCamera()->setPerspective(120,1,0.1,1000);
	//CameraManager::getInstance()->getMainCamera()->setOrthogonal(10,1,0.1f,100);
	CameraManager::getInstance()->getMainCamera()->setLookAt(ARVector3(0,0,0),ARVector3(0,0,0),ARVector3(0,0,0));
	this->director = Director::getInstance();
	this->director->init();

	{
		ARWaveObject* plan = new ARWaveObject();
		ARMaterial* materia = new ARMaterial;
		materia->loadFromFile("shader/wave.v","shader/wave.f");
		plan->setMaterial(materia);
		plan->translate.setPostion(ARVector3(0,-2,-20));
		plan->translate.setRotation(90,0,0);
		plan->translate.setScale(1,1,1);
		this->director->getScene()->addMesh(plan);
		materia->setUniform1f("time",posY);
		materia->setAmbientColor(ARVector3(0.3f,0.3f,0.3f));
		materia->setLightColorAndPosition(0,ARVector3(1,1,1),ARVector3(1,1,0));
	}

	{
// 		PolygonObject* object = new PolygonObject("test.obj");
// 		object->translate.setPostion(ARVector3(0,-1,-5));
// 		ARMaterial* materia = new ARMaterial;
// 		materia->loadFromFile("shader/diffuse.v","shader/diffuse.f");
// 		object->setMaterial(materia);
// 		materia->setAmbientColor(ARVector3(0.3f,0.3f,0.3f));
// 		materia->setLightColorAndPosition(0,ARVector3(1,1,1),ARVector3(1,1,0));
// 		//object->translate.setScale(0.5f,0.5f,0.5f);
// 		//object->translate.setRotation(0,0,3);
// 		this->director->getScene()->addMesh(object);
	}

// 	PolygonBox* box = new PolygonBox();
// 	box->translate.setPostion(ARVector3(0.5,0,0));
// 	this->director->getScene()->addMesh(box);

}

void AppDelegate::update()
{

}

void AppDelegate::draw()
{
	this->director->draw();
}
