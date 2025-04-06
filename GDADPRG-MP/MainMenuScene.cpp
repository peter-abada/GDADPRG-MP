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


// Loads the main menu screen and the music

void MainMenuScene::onLoadObjects() {
	MainMenuScreen* mainMenu = new MainMenuScreen("MainMenuScreen");
	this->registerObject(mainMenu);
	MusicManager::getInstance()->playSong("MenuMusic");
    
}

void MainMenuScene::onUnloadResources() {
}

