#pragma once
#include "AComponent.h"
#include "AGameObject.h"
#include "Game.h"
#include <SFML/Graphics.hpp>


class EnemyBehavior : public AComponent
{
public:
	enum EnemyMovementType { Delay = 0, Forward = 1, SlowForward = 2, Side = 3 };

	EnemyBehavior(std::string name);
	void perform();
	void configure(float delay);
	void reset();

private:
	const float SPEED_MULTIPLIER = 100.0f;
	EnemyBehavior::EnemyMovementType movementType = Forward;
	float ticks = 0.f;
	float delay = 0.f;
	float forwardDuration = 0.f;

};

