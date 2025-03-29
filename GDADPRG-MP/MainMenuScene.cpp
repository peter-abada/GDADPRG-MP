#include "MainMenuScene.h"
#include "MainMenuScreen.h"
#include "GameObjectManager.h"
#include <iostream>

MainMenuScene::MainMenuScene() : AScene("MainMenuScene") {
}

void MainMenuScene::onLoadResources() {
}

void MainMenuScene::onLoadObjects() {
	MainMenuScreen* mainMenu = new MainMenuScreen("MainMenuScreen");
	this->registerObject(mainMenu);
}

void MainMenuScene::onUnloadResources() {
}

