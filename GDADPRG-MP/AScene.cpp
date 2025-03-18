#include "AScene.h"
#include "GameObjectManager.h"

AScene::AScene(std::string name) {
	this->name = name;
}

void AScene::onUnloadObjects() {
	GameObjectManager::getInstance()->deleteAllObjectsInScene();
}

std::string AScene::getName() {
	return this->name;
}

void AScene::registerObject(AGameObject* object) {
	GameObjectManager::getInstance()->addObject(object);
}