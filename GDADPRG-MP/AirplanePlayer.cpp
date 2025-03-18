#include "AirplanePlayer.h"
#include <iostream>
#include "TextureManager.h"
#include "Game.h"

AirplanePlayer::AirplanePlayer(std::string name) : AGameObject(name) {

}

void AirplanePlayer::initialize() {
	std::cout << "Declared as " << this->getName() << std::endl;

	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTexture("Player"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	this->sprite->setOrigin(float(textureSize.x / 2), float(textureSize.y / 2));
	this->transformable.setPosition(Game::WINDOW_WIDTH / 2, Game::WINDOW_HEIGHT / 2);

	PlayerInputController* inputController = new PlayerInputController("PlayerInputController");
	this->attachComponent(inputController);

	PlayerMovement* movement = new PlayerMovement("PlayerMovement");
	this->attachComponent(movement);

	Renderer* renderer = new Renderer("PlayerSprite");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);

	this->collider = new Collider("PlayerCollider");
	this->collider->setLocalBounds(sprite->getGlobalBounds());
	this->collider->setCollisionListener(this);
	this->attachComponent(this->collider);
	PhysicsManager::getInstance()->trackObject(this->collider);
	std::cout << "BOUNDS " << sprite->getGlobalBounds().left << " " << sprite->getGlobalBounds().top << " " << sprite->getGlobalBounds().width << " " << sprite->getGlobalBounds().height << std::endl;


}

void AirplanePlayer::processInput(sf::Event event) {
	AGameObject::processInput(event);
}

void AirplanePlayer::update(sf::Time deltaTime) {
	AGameObject::update(deltaTime);
	//std::cout << sprite->getGlobalBounds().top << std::endl;
}

bool AirplanePlayer::getGrounded() {
	return this->grounded;
}

void AirplanePlayer::setGrounded(bool grounded) {
	this->grounded = grounded;
}



void AirplanePlayer::onCollisionEnter(AGameObject* gameObject) {
	std::cout << "a";
	if (gameObject->getName().find("Ground") != std::string::npos) {

		std::cout << "player found";
		AirplanePlayer* airplanePlayer = (AirplanePlayer*)GameObjectManager::getInstance()->findObjectByName("PlaneObject");
		airplanePlayer->setGrounded(true);
	}

	if (gameObject->getName().find("Platform") != std::string::npos) {

		std::cout << "platform found";
		AirplanePlayer* airplanePlayer = (AirplanePlayer*)GameObjectManager::getInstance()->findObjectByName("PlaneObject");
		airplanePlayer->setGrounded(true);
	}
}

void AirplanePlayer::onCollisionExit(AGameObject* gameObject) {}
