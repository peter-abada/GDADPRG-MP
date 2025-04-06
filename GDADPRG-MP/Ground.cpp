#include "Ground.h"
#include "TextureManager.h"
#include "Game.h"
#include "Renderer.h"
#include "AirplanePlayer.h"
#include <iostream>



/*


The ground class is just a regular gameobject and it functions as the main ground for the player to walk on,
it has two constructers, one that sets the position to cover the whole ground
the other makes it so there can be a hole in the floor or an elevated position.

*/

Ground::Ground(std::string name) : AGameObject(name), CollisionListener() {
    this->xPos = Game::WINDOW_WIDTH / 2;
    this->yPos = 500;

}

Ground::Ground(std::string name, int xPos, int yPos) : AGameObject(name), CollisionListener(), xPos(xPos), yPos(yPos) {   

	this->xPos = xPos;
	this->yPos = yPos;

}

Ground::~Ground() {
    delete this->sprite;
}

void Ground::initialize() {

    std::cout << "Declared as " << this->getName() << std::endl;
    this->sprite = new sf::Sprite();
    sprite->setTexture(*TextureManager::getInstance()->getTexture("Ground"));
    sf::Vector2u textureSize = sprite->getTexture()->getSize();
    sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);

    this->setPosition(xPos, yPos);

    Renderer* renderer = new Renderer("GroundSprite");
    renderer->assignDrawable(sprite);
    this->attachComponent(renderer);

    this->collider = new Collider("GroundCollider");
    this->collider->setLocalBounds(sprite->getGlobalBounds());
    this->collider->setCollisionListener(this);
    this->attachComponent(this->collider);
    PhysicsManager::getInstance()->trackObject(this->collider);
    std::cout << "BOUNDS " << sprite->getGlobalBounds().left << " " << sprite->getGlobalBounds().top << " " << sprite->getGlobalBounds().width << " " << sprite->getGlobalBounds().height << std::endl;
}


void Ground::processInput(sf::Event event) {
    AGameObject::processInput(event);
}

void Ground::update(sf::Time deltaTime) {
    AGameObject::update(deltaTime);
    //std::cout << sprite->getGlobalBounds().top << std::endl;
}


void Ground::onCollisionEnter(AGameObject* gameObject) {
	// if the player comes into contact with the ground, set the grounded variable to true
    if (gameObject->getName().find("PlaneObject") != std::string::npos) {

        std::cout << "player found";
        AirplanePlayer* airplanePlayer = (AirplanePlayer*)GameObjectManager::getInstance()->findObjectByName("PlaneObject");
        airplanePlayer->setGrounded(true);
    }
}

void Ground::onCollisionExit(AGameObject* gameObject) {
	// When the player leaves the ground, set the grounded variable to false
    if (gameObject->getName().find("PlaneObject") != std::string::npos) {
        AirplanePlayer* airplanePlayer = (AirplanePlayer*)GameObjectManager::getInstance()->findObjectByName("PlaneObject");
        airplanePlayer->setGrounded(false);

    }
}
