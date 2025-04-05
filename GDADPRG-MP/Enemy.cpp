#include "Enemy.h"
#include "TextureManager.h"
#include "Game.h"
#include "Renderer.h"
#include <iostream>
#include "EnemyBehavior.h"
Enemy::Enemy(std::string name, int stage, Counter* enemyCounter)
    : APoolable(name), CollisionListener(), stage(stage), enemyCounter(enemyCounter) {
}

Enemy::~Enemy() {
    delete this->sprite;
}

void Enemy::initialize() {
    std::cout << "Declared as " << this->getName() << std::endl;
    this->sprite = new sf::Sprite();
    sprite->setTexture(*TextureManager::getInstance()->getTexture("Enemy"));
    sf::Vector2u textureSize = sprite->getTexture()->getSize();
    sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);

    this->setPosition(Game::WINDOW_WIDTH / 2 + 200, Game::WINDOW_HEIGHT / 2 + 25);
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

void Enemy::onRelease() {
    PhysicsManager::getInstance()->untrackObject(this->collider);
}

void Enemy::onActivate() {
    EnemyBehavior* enemyBehavior = (EnemyBehavior*)this->findComponentByName("EnemyBehavior");
    enemyBehavior->reset();


    PhysicsManager::getInstance()->trackObject(this->collider);


    if (stage == 3) {

        this->setPosition(Game::WINDOW_WIDTH / 2+300, Game::WINDOW_HEIGHT / 2 + 25);

    }

    if (stage == 4) {
        if (enemyCounter->getCounter() == 1) {
            this->setPosition(Game::WINDOW_WIDTH / 2 + 300, Game::WINDOW_HEIGHT / 2 + 25);
        }       
        if (enemyCounter->getCounter() == 2) {
            this->setPosition(Game::WINDOW_WIDTH / 2 + 200, Game::WINDOW_HEIGHT / 2 + 25);
        }      
        if (enemyCounter->getCounter() == 3) {
            this->setPosition(Game::WINDOW_WIDTH / 2 + 100, Game::WINDOW_HEIGHT / 2 + 25);
        }
        enemyCounter->increment();
    }

    if (stage == 6) {
        if (enemyCounter->getCounter() == 1) {
            this->setPosition(Game::WINDOW_WIDTH / 2 + 350, Game::WINDOW_HEIGHT / 2 + 25);
        }
        if (enemyCounter->getCounter() == 2) {
            this->setPosition(Game::WINDOW_WIDTH / 2 + 300, Game::WINDOW_HEIGHT / 2 + 25);
        }
        if (enemyCounter->getCounter() == 3) {
            this->setPosition(Game::WINDOW_WIDTH / 2 + 250, Game::WINDOW_HEIGHT / 2 + 25);
        }
		if (enemyCounter->getCounter() == 4) {
			this->setPosition(Game::WINDOW_WIDTH / 2 + 200, Game::WINDOW_HEIGHT / 2 + 25);
		}
		if (enemyCounter->getCounter() == 5) {
			this->setPosition(Game::WINDOW_WIDTH / 2 + 150, Game::WINDOW_HEIGHT / 2 + 25);
		}
		if (enemyCounter->getCounter() == 6) {
			this->setPosition(Game::WINDOW_WIDTH / 2 + 100, Game::WINDOW_HEIGHT / 2 + 25);
		}

        enemyCounter->increment();
    }

}

APoolable* Enemy::clone() {
    APoolable* copyObj = new Enemy(this->name, this->stage, this->enemyCounter);
    return copyObj;
}

void Enemy::onCollisionEnter(AGameObject* gameObject) {
    if (gameObject->getName().find("PlaneObject") != std::string::npos) {
        std::cout << "ENEMY TOUCHED PLAYER";
        AirplanePlayer* airplanePlayer = (AirplanePlayer*)GameObjectManager::getInstance()->findObjectByName("PlaneObject");
        if (airplanePlayer->getGrounded() == true) {
            airplanePlayer->setDead(true);
        } else {
            GameObjectPool* enemyPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::ENEMY_POOL_TAG);
            enemyPool->releasePoolable((APoolable*)this);
			airplanePlayer->getTransformable()->move(0, -150);
        }

    }
    if (gameObject->getName().find("Ground") != std::string::npos) {
        std::cout << "ENEMY TOUCHED GROUND";
        this->setGrounded(true);
    }
}

void Enemy::onCollisionExit(AGameObject* gameObject) {
    if (gameObject->getName().find("Ground") != std::string::npos) {
        std::cout << "ENEMY LEFT GROUND" << std::endl;
        this->setGrounded(false);
    }
}

int Enemy::getStage() {
    return this->stage;
}

bool Enemy::getGrounded() {
    return this->grounded;
}

void Enemy::setGrounded(bool grounded) {
    this->grounded = grounded;
}