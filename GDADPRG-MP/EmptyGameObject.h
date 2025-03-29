#pragma once
#include "AGameObject.h"
#include "EnemySwarmHandler.h"
#include "GameObjectManager.h"


class EmptyGameObject : public AGameObject
{
public:
	EmptyGameObject(std::string name);
	void initialize();
};

