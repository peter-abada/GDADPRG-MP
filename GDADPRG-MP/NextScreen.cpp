#include "NextScreen.h"
#include <iostream>
#include "TextureManager.h"
#include "Game.h"

NextScreen::NextScreen(std::string name, int screen) : AGameObject(name), screen(screen) {

}

void NextScreen::initialize() {
	std::cout << "Declared as " << this->getName() << std::endl;

	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTexture("NextScreen"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	this->sprite->setOrigin(float(textureSize.x / 2), float(textureSize.y / 2));
	this->transformable.setPosition(Game::WINDOW_WIDTH+25, Game::WINDOW_HEIGHT / 2);

	Renderer* renderer = new Renderer("NextScreenRenderer");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);

	this->collider = new Collider("NextScreenCollider");
	this->collider->setLocalBounds(sprite->getGlobalBounds());
	this->collider->setCollisionListener(this);
	this->attachComponent(this->collider);
	PhysicsManager::getInstance()->trackObject(this->collider);
	std::cout << "BOUNDS " << sprite->getGlobalBounds().left << " " << sprite->getGlobalBounds().top << " " << sprite->getGlobalBounds().width << " " << sprite->getGlobalBounds().height << std::endl;


}

void NextScreen::processInput(sf::Event event) {
	AGameObject::processInput(event);
}

void NextScreen::update(sf::Time deltaTime) {
	AGameObject::update(deltaTime);
}



void NextScreen::onCollisionEnter(AGameObject* gameObject) {
	std::cout << "aaa: " << screen;
	if (gameObject->getName().find("PlaneObject") != std::string::npos) {

		if (screen == 1) {
			std::cout << "going to next screen!!";
			SceneManager::getInstance()->loadScene(SceneManager::LEVEL1_SCENE2_NAME);
		}
	}

}

void NextScreen::onCollisionExit(AGameObject* gameObject) {}
