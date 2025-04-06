#pragma once

#include "Entity.h"
#include "Text.h"
#include "SFXManager.h"
#include "GameObjectManager.h"
#include "FontManager.h"
#include "AGameObject.h"
#include "AComponent.h"
#include "TextureManager.h"
#include "BGObject.h"
#include "AirplanePlayer.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include "EmptyGameObject.h"
#include "MainMenuScreen.h"
#include "PauseScreen.h"
#include "PauseMenuScreen.h"
#include "ApplicationManager.h"
#include "AScene.h"
#include "SceneManager.h"
#include "MainMenuScene.h"



class Game {
public:
	static const int WINDOW_WIDTH = 800;
	static const int WINDOW_HEIGHT = 600;
	Game();
	void run();
	const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
private:
	void processEvents();
	void update(sf::Time deltaTime);
	void render();

private:
	sf::RenderWindow mWindow;

};