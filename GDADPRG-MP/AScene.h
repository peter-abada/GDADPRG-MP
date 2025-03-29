#pragma once
#include "AGameObject.h"

class AScene
{
public:
	AScene(std::string name);

	virtual void onLoadResources() = 0;
	virtual void onLoadObjects() = 0;

	virtual void onUnloadResources() = 0;
	virtual void onUnloadObjects();

	std::string getName();

protected:
	void registerObject(AGameObject* object);
	std::string name;

};

