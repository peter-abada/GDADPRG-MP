#pragma once
#include "AComponent.h"
#include "AirplanePlayer.h"
#include "ObjectPoolHolder.h"
class PlayerMovement : public AComponent
{
public:
	PlayerMovement(std::string name);
	void perform();


private:
	const float SPEED_MULTIPLIER = 300.f;

	const float JUMP_INTERVAL = .5f;

	float ticks = 0.f;
};

