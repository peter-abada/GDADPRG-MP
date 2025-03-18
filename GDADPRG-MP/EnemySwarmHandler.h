#pragma once
#include "AComponent.h"
#include "GameObjectPool.h"
#include "ObjectPoolHolder.h"
#include "EnemyAirplane.h"

class EnemySwarmHandler : public AComponent
{
public:
	EnemySwarmHandler(int numEnemies, std::string, AGameObject* parent);
	~EnemySwarmHandler();
	void perform();
private:
	GameObjectPool* enemyPool;
	const float SPWAN_INTERVAL = 0.01f;
	float ticks = 0.f;

};

