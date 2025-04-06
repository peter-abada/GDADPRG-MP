#include "EnemyBehavior.h"
#include "Enemy.h"
#include <iostream>

EnemyBehavior::EnemyBehavior(std::string name) : AComponent(name, AComponent::Script) {
    this->reset();
}

void EnemyBehavior::perform() {
    this->ticks += this->deltaTime.asSeconds();

    sf::Transformable* transformable = this->getOwner()->getTransformable();

    // Move the enemy to the left
    transformable->move(-this->deltaTime.asSeconds() * SPEED_MULTIPLIER * 1.5f, 0);

    Enemy* enemy = (Enemy*)this->getOwner();
    if (enemy && !enemy->getGrounded()) { // If the enemy is not collding with the ground or platform it will start falling down
        transformable->move(0, this->deltaTime.asSeconds() * SPEED_MULTIPLIER*3);
    }
}

void EnemyBehavior::configure(float delay) {
    this->delay = delay;
}

void EnemyBehavior::reset() {
    this->ticks = 0.f;
}
