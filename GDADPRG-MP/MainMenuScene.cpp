#include "MainMenuScene.h"
#include "MainMenuScreen.h"
#include "GameObjectManager.h"
#include <iostream>
#include "EmptyGameObject.h"
#include "MusicManager.h"
MainMenuScene::MainMenuScene() : AScene("MainMenuScene") {
}

void MainMenuScene::onLoadResources() {
}

void MainMenuScene::onLoadObjects() {
	MainMenuScreen* mainMenu = new MainMenuScreen("MainMenuScreen");
	this->registerObject(mainMenu);
	MusicManager::getInstance()->playSong("MenuMusic");
    
}

void MainMenuScene::onUnloadResources() {
}

