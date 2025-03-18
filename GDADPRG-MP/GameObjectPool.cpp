#include "GameObjectPool.h"
#include <iostream>



GameObjectPool::GameObjectPool(std::string tag, APoolable* poolableCopy, int poolableSize, AGameObject* parent) {
	this->tag = tag;
	this->objectCopy = poolableCopy;
	this->maxPoolSize = poolableSize;
	this->parent = parent;
}

GameObjectPool::~GameObjectPool() {
	delete this->objectCopy;
	this->objectCopy = nullptr;
	this->parent = nullptr;
}


void GameObjectPool::initialize() {
	for (int i = 0; i < this->maxPoolSize; i++) {
		APoolable* poolableObject = this->objectCopy->clone();
		if (this->parent != nullptr) {
			this->parent->attachChild(poolableObject);
		}
		else {
			GameObjectManager::getInstance()->addObject(poolableObject);
		}

		poolableObject->setEnabled(false);
		this->availableObjects.push_back(poolableObject);
	}
}

bool GameObjectPool::hasObjectAvailable(int requestSize) {
	return requestSize <= this->availableObjects.size();
}

APoolable* GameObjectPool::requestPoolable() {
	
	if (this->hasObjectAvailable(1)) {
		APoolable* poolableObject = this->availableObjects[this->availableObjects.size() - 1];
		this->availableObjects.erase(this->availableObjects.begin() + this->availableObjects.size() - 1);
		this->usedObjects.push_back(poolableObject);
		std::cout << "Requested object Available: " << this->availableObjects.size() << "Used: " << this->usedObjects.size() << std::endl;
		this->setEnabled(poolableObject, true);	
		return poolableObject;

	}
	else {
		return NULL;	
	}

}

std::vector<APoolable*> GameObjectPool::requestPoolableBath(int size) {
	std::vector<APoolable*> returnList;
	if (this->hasObjectAvailable(size)) {
		for (int i = 0; i < size; i++) {
			returnList.push_back(this->requestPoolable());
		}
	}
	else {
		std::cerr << "Insufficient " << this->objectCopy->getName() << " available" << std::endl;
	}
	return returnList;
}

void GameObjectPool::releasePoolable(APoolable* poolableObject) {
	for (int i = 0; i < this->usedObjects.size(); i++) {
		if (this->usedObjects[i] == poolableObject) {
			this->usedObjects.erase(this->usedObjects.begin() + i);
			this->availableObjects.push_back(poolableObject);
			this->setEnabled(poolableObject, false);
		}
	}
}

void GameObjectPool::releasePoolableBatch(std::vector<APoolable*> objectList) {
	for (size_t i = 0; i < objectList.size(); i++) {
		this->releasePoolable(objectList[i]);
	}
}



std::string GameObjectPool::getTag() {
	return this->tag;
}

void GameObjectPool::setEnabled(APoolable* poolableObject, bool flag) {
	if (flag) {
		poolableObject->setEnabled(true);
		poolableObject->onActivate();
	}
	else {
		poolableObject->setEnabled(false);
		poolableObject->onRelease();
	}
}


