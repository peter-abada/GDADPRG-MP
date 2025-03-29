#include "AScene.h"
#include "GameObjectManager.h"
#include <iostream>
AScene::AScene(std::string name) {
	this->name = name;
}

void AScene::onUnloadObjects() {
	std::cout << "deleting";
	GameObjectManager::getInstance()->deleteAllObjectsInScene();
}

std::string AScene::getName() {
	return this->name;
}

void AScene::registerObject(AGameObject* object) {

	GameObjectManager::getInstance()->addObject(object);
}