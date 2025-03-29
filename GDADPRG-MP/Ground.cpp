#include "Ground.h"
#include "TextureManager.h"
#include "Game.h"
#include "Renderer.h"
#include "AirplanePlayer.h"
#include <iostream>

Ground::Ground(std::string name) : AGameObject(name), CollisionListener() {}

Ground::~Ground() {
    delete this->sprite;
}

void Ground::initialize() {

    std::cout << "Declared as " << this->getName() << std::endl;
    this->sprite = new sf::Sprite();
    sprite->setTexture(*TextureManager::getInstance()->getTexture("Ground"));
    sf::Vector2u textureSize = sprite->getTexture()->getSize();
    sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);

    this->setPosition(Game::WINDOW_WIDTH / 2, 500);

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
    std::cout << "a";
    if (gameObject->getName().find("PlaneObject") != std::string::npos) {

        std::cout << "player found";
        AirplanePlayer* airplanePlayer = (AirplanePlayer*)GameObjectManager::getInstance()->findObjectByName("PlaneObject");
        airplanePlayer->setGrounded(true);
    }
}

void Ground::onCollisionExit(AGameObject* gameObject) {
    AirplanePlayer* airplanePlayer = (AirplanePlayer*)GameObjectManager::getInstance()->findObjectByName("PlaneObject");
    airplanePlayer->setGrounded(false);
}
