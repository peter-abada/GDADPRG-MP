#include "Level2BGObject.h"
#include <iostream>



// BGObject class for level 2
Level2BGObject::Level2BGObject(std::string name) : AGameObject(name) {

}

void Level2BGObject::initialize() {
	std::cout << "Declared as " << this->getName() << std::endl;
	sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->getTexture("Level2BGObject"));
	sf::Vector2u textureSize = this->sprite->getTexture()->getSize();

	sprite->setTextureRect(sf::IntRect(0, 0, Game::WINDOW_WIDTH, Game::WINDOW_HEIGHT * 8));
	sprite->setPosition(0, -Game::WINDOW_HEIGHT * 7);

	BGMovement* logicComponent = new BGMovement("BGMovement2");
	this->attachComponent(logicComponent);

	Renderer* renderer = new Renderer("BGRenderer2");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);

}

void Level2BGObject::update(sf::Time deltaTime) {
	AGameObject::update(deltaTime);
}

void Level2BGObject::processInput(sf::Event event) {

}
