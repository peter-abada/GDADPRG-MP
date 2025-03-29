#pragma once
#include "AGameObject.h"
#include "APoolable.h"
#include "ProjectileMovement.h"
#include "PhysicsManager.h"
#include "CollisionListener.h"


class ProjectileObject : public APoolable, public CollisionListener
{

public:
	ProjectileObject(std::string name);
	void initialize();
	void onRelease();
	void onActivate();
	APoolable* clone();


	void onCollisionEnter(AGameObject* contact);
	void onCollisionExit(AGameObject* contact);

private:
	ProjectileMovement* projectileMovement = nullptr;
	Collider* collider = nullptr;
	bool hasHit = false;

};
