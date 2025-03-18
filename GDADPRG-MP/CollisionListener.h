#pragma once
#include "AGameObject.h"

class CollisionListener
{
public:
	virtual void onCollisionEnter(AGameObject* gameObjects) = 0;
	virtual void onCollisionExit(AGameObject* gameObjects) = 0;
protected:
	CollisionListener() {};

};
