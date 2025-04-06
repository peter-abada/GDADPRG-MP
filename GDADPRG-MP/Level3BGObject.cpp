#include "Level3BGObject.h"
#include <iostream>

//BGobject for level 3

Level3BGObject::Level3BGObject(std::string name) : AGameObject(name) {

}

void Level3BGObject::initialize() {
	std::cout << "Declared as " << this->getName() << std::endl;
	sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->getTexture("Level3BGObject"));
	sf::Vector2u textureSize = this->sprite->getTexture()->getSize();

	sprite->setTextureRect(sf::IntRect(0, 0, Game::WINDOW_WIDTH, Game::WINDOW_HEIGHT * 8));
	sprite->setPosition(0, -Game::WINDOW_HEIGHT * 7);

	BGMovement* logicComponent = new BGMovement("BGMovement3");
	this->attachComponent(logicComponent);

	Renderer* renderer = new Renderer("BGRenderer3");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);

}

void Level3BGObject::update(sf::Time deltaTime) {
	AGameObject::update(deltaTime);
}

void Level3BGObject::processInput(sf::Event event) {

}
