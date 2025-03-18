#include "EnemyBehavior.h"
#include <iostream>
EnemyBehavior::EnemyBehavior(std::string name) : AComponent(name, AComponent::Script) {
	this->reset();
}


void EnemyBehavior::perform() {
    this->ticks += this->deltaTime.asSeconds();

    sf::Transformable* transformable = this->getOwner()->getTransformable();

    if (this->ticks > this->forwardDuration && this->movementType != Side) {
        int counter = (this->movementType + 1) % EnemyMovementType::Side + 1;
        this->movementType = (EnemyMovementType)counter;
    }

    if (this->movementType == Forward) {
        transformable->move(0, this->deltaTime.asSeconds() * SPEED_MULTIPLIER);
    }
    else if (this->movementType == SlowForward) {
        transformable->move(0, this->deltaTime.asSeconds() * (SPEED_MULTIPLIER / 2.f));
    }
    else if (this->movementType == Side) {
        if (transformable->getPosition().x > Game::WINDOW_WIDTH / 2) {
            transformable->move(this->deltaTime.asSeconds() * SPEED_MULTIPLIER * 1.5f, 0);
        }
        else {
            transformable->move(-this->deltaTime.asSeconds() * SPEED_MULTIPLIER * 1.5f, 0);
        }

		if (transformable->getPosition().x > Game::WINDOW_WIDTH + 20 || transformable->getPosition().x < -20) {
			ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::ENEMY_POOL_TAG)->releasePoolable((APoolable*)this->getOwner());
		}

    }
}

void EnemyBehavior::configure(float delay) {
    this->delay = delay;
}

void EnemyBehavior::reset() {
    this->ticks = 0.f;
	this->movementType = Forward;
	this->forwardDuration = (rand() % 3 + 1);
}