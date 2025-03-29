#pragma once
#include "AComponent.h"
#include "AGameObject.h"
#include "Game.h"
#include <SFML/Graphics.hpp>

class EnemyBehavior : public AComponent
{
public:

    EnemyBehavior(std::string name);
    void perform();
    void configure(float delay);
    void reset();

private:
    const float SPEED_MULTIPLIER = 100.f;
    float ticks = 0.f;
    float delay = 0.f;
};

