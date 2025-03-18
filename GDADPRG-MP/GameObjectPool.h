#pragma once
#include <vector>
#include "APoolable.h"
#include "GameObjectManager.h"

class GameObjectPool
{
public:
	GameObjectPool(std::string tag, APoolable* poolableCopy, int poolableSize, AGameObject* parent);
	~GameObjectPool();
	void initialize();
	bool hasObjectAvailable(int requestSize);
	APoolable* requestPoolable();
	std::vector<APoolable*> requestPoolableBath(int size);

	void releasePoolable(APoolable* poolableObject);
	void releasePoolableBatch(std::vector<APoolable*> objectList);

	std::string getTag();
private:
	std::string tag;
	APoolable* objectCopy = NULL;
	AGameObject* parent = NULL;
	int maxPoolSize = 20;
	std::vector<APoolable*> availableObjects;
	std::vector<APoolable*> usedObjects;

	void setEnabled(APoolable* poolableObject, bool flag);
};

