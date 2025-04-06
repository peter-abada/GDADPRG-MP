#pragma once
#include "AGameObject.h"
#include "GameObjectManager.h"


class EmptyGameObject : public AGameObject
{
public:
	EmptyGameObject(std::string name);
	void initialize();
};

