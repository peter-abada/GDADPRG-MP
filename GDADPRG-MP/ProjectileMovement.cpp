#include "ProjectileMovement.h"

ProjectileMovement::ProjectileMovement(std::string name) : AComponent(name, Script) {
}

void ProjectileMovement::perform() {
	sf::Transformable* transform = this->getOwner()->getTransformable();
	transform->move(0, -this->deltaTime.asSeconds() * SPEED_MULTIPLIER);
	this->ticks += this->deltaTime.asSeconds();

	if (this->ticks > 3.f) {
		reset();
		ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::PROJECTILE_POOL_TAG)->releasePoolable((APoolable*)this->getOwner());
	}

}


void ProjectileMovement::reset() {
	this->ticks = 0.f;
}