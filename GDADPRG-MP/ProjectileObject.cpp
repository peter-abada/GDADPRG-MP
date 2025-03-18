#include "ProjectileObject.h"
#include "TextureManager.h"
#include "ProjectileMovement.h"
#include "AirplanePlayer.h"
#include "GameObjectManager.h"
#include <string>
#include "ObjectPoolHolder.h"
#include "Renderer.h"
#include <iostream>


ProjectileObject::ProjectileObject(std::string name) : APoolable(name), CollisionListener() {
}

void ProjectileObject::initialize() {
	this->sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->getTexture("bullet"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	Renderer* renderer = new Renderer("ProjectileSprite");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);

	this->projectileMovement = new ProjectileMovement("projectile_movement");
	this->attachComponent(projectileMovement);

	this->collider = new Collider("ProjectileSprite"); 

	collider->setLocalBounds(sprite->getGlobalBounds());
	collider->setCollisionListener(this);
	this->attachComponent(collider);
}

void ProjectileObject::onRelease() {
	PhysicsManager::getInstance()->untrackObject(this->collider);
}


void ProjectileObject::onActivate() {
  	AirplanePlayer* player = (AirplanePlayer*)GameObjectManager::getInstance()->findObjectByName("PlaneObject");
	sf::Vector2f position = player->getTransformable()->getPosition();
	this->setPosition(position.x, position.y);

	this->hasHit = false;

	PhysicsManager::getInstance()->trackObject(this->collider);

}


APoolable* ProjectileObject::clone() {
	APoolable* copyObj = new ProjectileObject(this->name);
	return copyObj;
}


void ProjectileObject::onCollisionEnter(AGameObject* contact) {
	if (contact->getName().find("enemy") != std::string::npos && !this->hasHit) {
		this->hasHit = true;
		GameObjectPool* projectilePool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::PROJECTILE_POOL_TAG);
		projectilePool->releasePoolable((APoolable*)this);
		std::cout << "hit enemy" << std::endl;
	}
}

void ProjectileObject::onCollisionExit(AGameObject* contact) {
	std::cout << "exit\n";
}