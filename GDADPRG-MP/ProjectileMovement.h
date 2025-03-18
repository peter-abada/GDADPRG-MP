#pragma once
#include "AComponent.h"
#include "AGameObject.h"
#include "ObjectPoolHolder.h"
#include "TextureManager.h"
class ProjectileMovement : public AComponent
{
public:
	ProjectileMovement(std::string name);
	void perform();
	void reset();
private:
	const float SPEED_MULTIPLIER = 240.f;
	float ticks = 0.f;
};
