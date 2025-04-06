#include "NextScreen.h"
#include <iostream>
#include "TextureManager.h"
#include "Game.h"


/*

this clsas is used to go to the next screen/scene of a level 

*/


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




// Takes in the screen parameter then uses it to properly mvoe to the next screen

void NextScreen::onCollisionEnter(AGameObject* gameObject) {
	std::cout << "aaa: " << screen;
	if (gameObject->getName().find("PlaneObject") != std::string::npos) {

		if (screen == 1) {
			std::cout << "going to next screen!!";
			SceneManager::getInstance()->loadScene(SceneManager::LEVEL1_SCENE2_NAME);
		}
		else if (screen == 2) {
			std::cout << "going to next screen!!";
			SceneManager::getInstance()->loadScene(SceneManager::LEVEL1_SCENE3_NAME);
		}

		else if (screen == 4) {
			std::cout << "level 2 stage 2";
			SceneManager::getInstance()->loadScene(SceneManager::LEVEL2_SCENE2_NAME);
		}		
		else if (screen == 5) {
			std::cout << "level 2 stage 3";
			SceneManager::getInstance()->loadScene(SceneManager::LEVEL2_SCENE3_NAME);
		}
		else if (screen == 7) {
			std::cout << "level 3 stage 2";
			SceneManager::getInstance()->loadScene(SceneManager::LEVEL3_SCENE2_NAME);
		}
		else if (screen == 8) {
			std::cout << "level 3 stage 3";
			SceneManager::getInstance()->loadScene(SceneManager::LEVEL3_SCENE3_NAME);
		}

	}

}

void NextScreen::onCollisionExit(AGameObject* gameObject) {}
