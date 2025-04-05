#include "SceneManager.h"
#include <iostream>

std::string SceneManager::MAIN_MENU_SCENE_NAME = "MainMenuScene";
std::string SceneManager::GAME_SCENE_NAME = "GameScene";
std::string SceneManager::LEVEL1_SCENE2_NAME = "Level1Scene2";
std::string SceneManager::LEVEL1_SCENE3_NAME = "Level1Scene3";
std::string SceneManager::LEVEL2_SCENE1_NAME = "Level2Scene1";
std::string SceneManager::LEVEL2_SCENE2_NAME = "Level2Scene2";
std::string SceneManager::LEVEL2_SCENE3_NAME = "Level2Scene3";
std::string SceneManager::LEVEL3_SCENE1_NAME = "Level3Scene1";
std::string SceneManager::LEVEL3_SCENE2_NAME = "Level3Scene2";
std::string SceneManager::LEVEL3_SCENE3_NAME = "Level3Scene3";
std::string SceneManager::CREDITS_SCENE_NAME = "Level3Scene3";

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
	this->storedScenes[scene->getName()] = scene;
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
		std::cout << "unloading";
		this->activeScene->onUnloadResources();
		this->activeScene->onUnloadObjects();
	}
}

bool SceneManager::isSceneLoaded(std::string name)
{
	return this->activeScene->getName() == name;
}