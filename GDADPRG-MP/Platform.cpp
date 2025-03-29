#include "Platform.h"
#include "TextureManager.h"
#include "Game.h"
#include "Renderer.h"

#include <iostream>

Platform::Platform(std::string name, int stage, Counter* stageCounter)
    : APoolable(name), CollisionListener(), stage(stage), stageCounter(stageCounter) {
}

Platform::~Platform() {
    delete this->sprite;
}

void Platform::initialize() {
    std::cout << "Declared as " << this->getName() << std::endl;
    this->sprite = new sf::Sprite();
    sprite->setTexture(*TextureManager::getInstance()->getTexture("Platform"));
    sf::Vector2u textureSize = sprite->getTexture()->getSize();
    sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);

    this->setPosition(Game::WINDOW_WIDTH / 2 + 200, 300);
    this->getTransformable()->setRotation(180);

    Renderer* renderer = new Renderer("PlatformSprite");
    renderer->assignDrawable(sprite);
    this->attachComponent(renderer);

    this->collider = new Collider("PlatformCollider");
    this->collider->setLocalBounds(sprite->getGlobalBounds());
    this->collider->setCollisionListener(this);
    this->attachComponent(this->collider);
}

void Platform::onRelease() {
    PhysicsManager::getInstance()->untrackObject(this->collider);
}

void Platform::onActivate() {
    if (stage == 1) {

        std::cout << "COUNTER: " << stageCounter->getCounter() << std::endl;
        if (stageCounter->getCounter() == 1) {
            this->setPosition(Game::WINDOW_WIDTH / 2 + 200, 300);
        }
        else if (stageCounter->getCounter() == 2) {
            this->setPosition(Game::WINDOW_WIDTH / 2 - 200, 300);
        }
        else if (stageCounter->getCounter() == 3) {
            this->setPosition(Game::WINDOW_WIDTH / 2, 100);
        }
        stageCounter->increment();
    }
    else if (stage == 2) {
        this->setPosition(Game::WINDOW_WIDTH / 2 - 200, 300);
    }

    PhysicsManager::getInstance()->trackObject(this->collider);
}

APoolable* Platform::clone() {
    APoolable* copyObj = new Platform(this->name, this->stage, this->stageCounter);
    return copyObj;
}

void Platform::onCollisionEnter(AGameObject* gameObject) {
    if (gameObject->getName().find("PlaneObject") != std::string::npos) {
        std::cout << "player found";
        AirplanePlayer* airplanePlayer = (AirplanePlayer*)GameObjectManager::getInstance()->findObjectByName("PlaneObject");
        airplanePlayer->setGrounded(true);
    }
}

void Platform::onCollisionExit(AGameObject* gameObject) {
    AirplanePlayer* airplanePlayer = (AirplanePlayer*)GameObjectManager::getInstance()->findObjectByName("PlaneObject");
    airplanePlayer->setGrounded(false);
}

int Platform::getStage() {
    return this->stage;
}

