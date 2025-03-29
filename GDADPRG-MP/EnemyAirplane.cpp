#include "EnemyAirplane.h"
#include "TextureManager.h"
#include "Game.h"
#include "Renderer.h"
#include "EnemyBehavior.h"

#include <iostream>
EnemyAirplane::EnemyAirplane(std::string name) : APoolable(name), CollisionListener() {}

EnemyAirplane::~EnemyAirplane() {
    delete this->sprite;
}

void EnemyAirplane::initialize() {
    std::cout << "Declared as " << this->getName() << std::endl;
    this->sprite = new sf::Sprite();
    sprite->setTexture(*TextureManager::getInstance()->getTexture("Avenger"));
    sf::Vector2u textureSize = sprite->getTexture()->getSize();
    sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);

    this->setPosition(Game::WINDOW_WIDTH / 2, -30);
    this->getTransformable()->move(rand() % SPAWN_RANGE - rand() % SPAWN_RANGE, 0);
    this->getTransformable()->setRotation(180);

    Renderer* renderer = new Renderer("EnemySprite");
    renderer->assignDrawable(sprite);
    this->attachComponent(renderer);

    EnemyBehavior* enemyBehavior = new EnemyBehavior("EnemyBehavior");
    this->attachComponent(enemyBehavior);
    enemyBehavior->configure(1.0f);

    this->collider = new Collider("EnemyCollider");
    this->collider->setLocalBounds(sprite->getGlobalBounds());
    this->collider->setCollisionListener(this);
    this->attachComponent(this->collider);
}

void EnemyAirplane::onRelease() {
    PhysicsManager::getInstance()->untrackObject(this->collider);
}

void EnemyAirplane::onActivate() {
    EnemyBehavior* enemyBehavior = (EnemyBehavior*)this->findComponentByName("EnemyBehavior");
    enemyBehavior->reset();

    PhysicsManager::getInstance()->trackObject(this->collider);

    this->setPosition(Game::WINDOW_WIDTH / 2, -30);
    this->getTransformable()->move(rand() % SPAWN_RANGE - rand() % SPAWN_RANGE, 0);
}

APoolable* EnemyAirplane::clone() {
    APoolable* copyObj = new EnemyAirplane(this->name);
    return copyObj;
}

void EnemyAirplane::onCollisionEnter(AGameObject* gameObject) { 
    if (gameObject->getName().find("projectile") != std::string::npos) {
        GameObjectPool* enemyPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::ENEMY_POOL_TAG);
        enemyPool->releasePoolable((APoolable*)this);
    }
}

void EnemyAirplane::onCollisionExit(AGameObject* gameObject) {}
