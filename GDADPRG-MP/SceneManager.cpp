#include "SceneManager.h"
#include <iostream>

std::string SceneManager::MAIN_MENU_SCENE_NAME = "MainMenuScene";
std::string SceneManager::GAME_SCENE_NAME = "GameScene";


SceneManager* SceneManager::sharedInstance = nullptr;

using namespace std;
SceneManager* SceneManager::getInstance()
{
	if (sharedInstance == nullptr)
	{
		sharedInstance = new SceneManager();
	}
	return sharedInstance;
}

SceneManager::SceneManager()
{
}

void SceneManager::registerScene(AScene* scene)
{
	std::cout << "Registering scene: " << scene->getName() << std::endl;
	storedScenes[scene->getName()] = scene;
}


void SceneManager::checkLoadedScene()
{
	if (this->isLoading) {
		this->unloadScene();
		this->activeScene = this->storedScenes[this->toLoadSceneName];
		this->activeScene->onLoadResources();
		this->activeScene->onLoadObjects();
		this->isLoading = false;
	}
}

void SceneManager::loadScene(std::string name)
{

	this->toLoadSceneName = name;
	this->isLoading = true;

}

void SceneManager::unloadScene()
{
	if (this->activeScene != nullptr)
	{
		this->activeScene->onUnloadResources();
		this->activeScene->onUnloadObjects();
	}
}

bool SceneManager::isSceneLoaded(std::string name)
{
	return this->activeScene->getName() == name;
}