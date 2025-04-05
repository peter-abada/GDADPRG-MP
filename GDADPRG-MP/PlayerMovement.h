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

	const float JUMP_INTERVAL = 0.1f; // change to add delays to jump

	float ticks = 0.f;
};

