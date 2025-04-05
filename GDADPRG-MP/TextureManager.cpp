#include "TextureManager.h"
#include <iostream>

TextureManager* TextureManager::sharedInstance = NULL;

TextureManager* TextureManager::getInstance() {
	if (sharedInstance == NULL) {
		sharedInstance = new TextureManager();
	}
	return sharedInstance;
}


void TextureManager::loadAll() {
	loadTexture("Eagle", "Media/Textures/Eagle.png");
	loadTexture("Desert", "Media/Textures/Desert.png");
	loadTexture("Raptor", "Media/Textures/Raptor.png");
	loadTexture("Avenger", "Media/Textures/Avenger.png");
	loadTexture("title_bg", "Media/Textures/f.png");
	loadTexture("btn_normal", "Media/Textures/b_4.png");
	loadTexture("btn_pressed", "Media/Textures/b_5.png");
	loadTexture("bar_1", "Media/Textures/bar_1.png");
	loadTexture("MainMenuBG", "Media/Textures/TitleScreenBG.png");
	loadTexture("bullet", "Media/Textures/Bullet.png");
	loadTexture("Player", "Media/Textures/Player.png");
	loadTexture("Ground", "Media/Textures/Ground.png");
	loadTexture("Platform", "Media/Textures/Platform.png");
	loadTexture("NextScreen", "Media/Textures/NextScreen.png");
	loadTexture("Enemy", "Media/Textures/Enemy.png");
	loadTexture("Goal", "Media/Textures/Goal.png");
	loadTexture("Level2BGObject", "Media/Textures/Level2BGObject.png");
	loadTexture("Level3BGObject", "Media/Textures/Level3BGObject.png");

	sf::Texture* bgTex;
	bgTex = getTexture("Desert");
	bgTex->setRepeated(true);
}


void TextureManager::loadTexture(std::string key, std::string path) {
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile(path);
	textureMap[key] = texture;
}

sf::Texture* TextureManager::getTexture(std::string key) {
	if (textureMap[key] != nullptr) {
		return textureMap[key];
	}
	else {
		std::cout << "Couldn't find textrure for " << key << std::endl;
		return nullptr;
	}
}