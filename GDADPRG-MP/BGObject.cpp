#include "BGObject.h"
#include <iostream>

BGObject::BGObject(std::string name) : AGameObject(name) {
 
}

void BGObject::initialize() {
    std::cout << "Declared as " << this->getName() << std::endl;
    sprite = new sf::Sprite();
    sprite->setTexture(*TextureManager::getInstance()->getTexture("Desert"));
    sf::Vector2u textureSize = this->sprite->getTexture()->getSize();

    sprite->setTextureRect(sf::IntRect(0, 0, Game::WINDOW_WIDTH, Game::WINDOW_HEIGHT * 8));
    sprite->setPosition(0, -Game::WINDOW_HEIGHT * 7);

	BGMovement* logicComponent = new BGMovement("BGMovement");
	this->attachComponent(logicComponent);

	Renderer* renderer = new Renderer("BGRenderer");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);

}

void BGObject::update(sf::Time deltaTime) {
	AGameObject::update(deltaTime);
}

void BGObject::processInput(sf::Event event) {

}
