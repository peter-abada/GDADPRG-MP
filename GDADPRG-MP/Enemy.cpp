#include "Enemy.h"
#include "TextureManager.h"
#include "Game.h"
#include "Renderer.h"
#include <iostream>
#include "SFXManager.h"
#include "EnemyBehavior.h"

/*

The enemy class is a poolable object such that it handles spawning multiple enmemies easier and 
better for memory management.

*/

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



/*

the stages and enemyCounters here represents where to spawn the enemy.
the stage reprents the stage (there are 3 levels with 3 stages within them, 
so if I wanted to spawn enemies on level 2 stage 1) I set stage to 4
enemyCounters uses the Counter class to keep track of the currently spawned enemies and make sure it doesn't
spawn the same enemy twice.

*/

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

	if (stage == 8) {
		if (enemyCounter->getCounter() == 1) {
			this->setPosition(Game::WINDOW_WIDTH / 2 + 210, 140);
		}
		if (enemyCounter->getCounter() == 2) {
			this->setPosition(Game::WINDOW_WIDTH / 2 + 110, 290);
		}
		if (enemyCounter->getCounter() == 3) {
			this->setPosition(Game::WINDOW_WIDTH / 2 + 10, 440);
		}
		enemyCounter->increment();
	}

    if (stage == 9) {
        if (enemyCounter->getCounter() == 1) {
            this->setPosition(Game::WINDOW_WIDTH / 2 + 350, Game::WINDOW_HEIGHT / 2 + 25);
        }
        if (enemyCounter->getCounter() == 2) {
            this->setPosition(Game::WINDOW_WIDTH / 2 + 250, Game::WINDOW_HEIGHT / 2 + 25);
        }
        if (enemyCounter->getCounter() == 3) {
            this->setPosition(Game::WINDOW_WIDTH / 2 + 150, Game::WINDOW_HEIGHT / 2 + 25);
        }
        enemyCounter->increment();
    }

}

APoolable* Enemy::clone() {
    APoolable* copyObj = new Enemy(this->name, this->stage, this->enemyCounter);
    return copyObj;
}

void Enemy::onCollisionEnter(AGameObject* gameObject) {

    // Detects if the player touches the enemy
    if (gameObject->getName().find("PlaneObject") != std::string::npos) {
        std::cout << "ENEMY TOUCHED PLAYER";
        AirplanePlayer* airplanePlayer = (AirplanePlayer*)GameObjectManager::getInstance()->findObjectByName("PlaneObject");
        if (airplanePlayer->getGrounded() == true) {
            // if the player is on teh ground, the player dies
            airplanePlayer->setDead(true);
        } else {

            // if the player is above the enemy and lands on it, the enemy gets released from the pool
            GameObjectPool* enemyPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::ENEMY_POOL_TAG);
            enemyPool->releasePoolable((APoolable*)this);
            SFXManager::getInstance()->getSound("Stomp")->play();
			airplanePlayer->getTransformable()->move(0, -150);
        }

    }

	// When it comes into contact with the ground or platform, it becomes grounded
    if (gameObject->getName().find("Ground") != std::string::npos) {
        std::cout << "ENEMY TOUCHED GROUND";
        this->setGrounded(true);
    }
    if (gameObject->getName().find("Platform") != std::string::npos) {
        std::cout << "ENEMY TOUCHED Platform";
        this->setGrounded(true);
    }
}

void Enemy::onCollisionExit(AGameObject* gameObject) {
	// If the enemy leaves the ground or platform, it becomes ungrounded
    if (gameObject->getName().find("Ground") != std::string::npos) {
        std::cout << "ENEMY LEFT GROUND" << std::endl;
        this->setGrounded(false);
    }
    if (gameObject->getName().find("Platform") != std::string::npos) {
        std::cout << "ENEMY LEFT Platform" << std::endl;
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