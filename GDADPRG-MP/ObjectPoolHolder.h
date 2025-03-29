#pragma once
#include "GameObjectPool.h"
#include <unordered_map>

typedef std::unordered_map<std::string, GameObjectPool*> PoolMap;

class ObjectPoolHolder : sf::NonCopyable
{
public:
	static const std::string ENEMY_POOL_TAG;
	static const std::string PROJECTILE_POOL_TAG;
	static const std::string PLATFORM_POOL_TAG;

	static ObjectPoolHolder* getInstance();

	void registerObjectPool(GameObjectPool* pool);
	void unregisterObjectPool(GameObjectPool* pool);
	GameObjectPool* getPool(std::string tag);

private:
	ObjectPoolHolder() {};
	static ObjectPoolHolder* sharedInstance;	

	PoolMap poolMap;

};

