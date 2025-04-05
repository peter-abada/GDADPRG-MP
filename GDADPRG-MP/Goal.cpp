#include "Goal.h"
#include <iostream>
#include "TextureManager.h"
#include "Game.h"

Goal::Goal(std::string name, int stage, int xPos, int yPos) : AGameObject(name), stage(stage) {
	this->xPos = xPos;
	this->yPos = yPos;
}

void Goal::initialize() {
	std::cout << "Declared as " << this->getName() << std::endl;

	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTexture("Goal"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	this->sprite->setOrigin(float(textureSize.x / 2), float(textureSize.y / 2));
	this->transformable.setPosition(xPos, yPos);

	Renderer* renderer = new Renderer("GoalRenderer");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);

	this->collider = new Collider("GoalCollider");
	this->collider->setLocalBounds(sprite->getGlobalBounds());
	this->collider->setCollisionListener(this);
	this->attachComponent(this->collider);
	PhysicsManager::getInstance()->trackObject(this->collider);
	std::cout << "BOUNDS " << sprite->getGlobalBounds().left << " " << sprite->getGlobalBounds().top << " " << sprite->getGlobalBounds().width << " " << sprite->getGlobalBounds().height << std::endl;


}

void Goal::processInput(sf::Event event) {
	AGameObject::processInput(event);
}

void Goal::update(sf::Time deltaTime) {
	AGameObject::update(deltaTime);
}



void Goal::onCollisionEnter(AGameObject* gameObject) {

	if (gameObject->getName().find("PlaneObject") != std::string::npos) {

		if (stage == 1) {
			std::cout << "going to next level!!";
			SceneManager::getInstance()->loadScene(SceneManager::LEVEL2_SCENE1_NAME);
		}
		if (stage == 2) {
			std::cout << "going to next level!!";
			SceneManager::getInstance()->loadScene(SceneManager::LEVEL3_SCENE1_NAME);
		}

	}

}

void Goal::onCollisionExit(AGameObject* gameObject) {}
