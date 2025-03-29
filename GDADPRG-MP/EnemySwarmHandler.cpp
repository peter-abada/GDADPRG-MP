#include "EnemySwarmHandler.h"
#include <iostream>

EnemySwarmHandler::EnemySwarmHandler(int numEnemies, std::string enemyTag, AGameObject* parent) : AComponent(name, Script) {
	this->enemyPool = new GameObjectPool(ObjectPoolHolder::ENEMY_POOL_TAG, new EnemyAirplane("EnemyAirplane"), numEnemies, parent);
	enemyPool->initialize();
	ObjectPoolHolder::getInstance()->registerObjectPool(enemyPool);
}

EnemySwarmHandler::~EnemySwarmHandler() {
	delete this->enemyPool;
}


void EnemySwarmHandler::perform() {
	GameObjectPool* enemyPool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::ENEMY_POOL_TAG);
	this->ticks += this->deltaTime.asSeconds();
	if (this->ticks > SPWAN_INTERVAL) {
		this->ticks = 0.0f;
		enemyPool->requestPoolable();
	}
}