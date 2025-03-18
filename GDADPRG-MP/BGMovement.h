#pragma once
#include "AComponent.h"
#include "AGameObject.h"
#include "Game.h"
class BGMovement : public AComponent
{
public:
	BGMovement(std::string name);
	void perform() override;

private:
	const float SPEED_MULTIPLIER = 100.f;
};

