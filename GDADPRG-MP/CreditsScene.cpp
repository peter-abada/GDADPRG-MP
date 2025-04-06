#include "CreditsScene.h"
#include "CreditsScreen.h"
#include "GameObjectManager.h"
#include <iostream>
#include "EmptyGameObject.h"
#include "MusicManager.h"

/*

similar to the MainMenuScreen/Scene made during the lectures

*/


CreditsScene::CreditsScene() : AScene("CreditsScene") {
}

void CreditsScene::onLoadResources() {
}

void CreditsScene::onLoadObjects() {
	CreditsScreen* creditsMenu = new CreditsScreen("CreditsScreen");
	this->registerObject(creditsMenu);
	MusicManager::getInstance()->playSong("Credits");

}

void CreditsScene::onUnloadResources() {
}

