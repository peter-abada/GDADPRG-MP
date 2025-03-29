#include "Game.h"
#include "MainMenuScene.h"
#include "GameScene.h"
#include "Level1Scene2.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>

Game::Game() : mWindow(sf::VideoMode(Game::WINDOW_WIDTH, Game::WINDOW_HEIGHT), "Marco Valdez") {
    mWindow.setFramerateLimit(240);
    ApplicationManager::getInstance()->initialize(&mWindow);
    SFXManager::getInstance()->loadAll();

    TextureManager::getInstance()->loadAll();
    FontManager::getInstance()->loadAll();

    SceneManager::getInstance()->registerScene(new MainMenuScene());
    SceneManager::getInstance()->registerScene(new GameScene()); // level 1 screen 1
    SceneManager::getInstance()->registerScene(new Level1Scene2()); // level 1 screen 2
    SceneManager::getInstance()->loadScene(SceneManager::MAIN_MENU_SCENE_NAME);

}

void Game::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    float fps = 0.f;
    float frameCount = 0.f;
    sf::Time elapsedTime = sf::Time::Zero;

    while (mWindow.isOpen()) {
        processEvents();
        sf::Time deltaTime = clock.restart();

        frameCount++;
        elapsedTime += deltaTime;
        if (elapsedTime >= sf::seconds(1.f)) {
            fps = frameCount;
            frameCount = 0;
            elapsedTime = sf::Time::Zero;
        }

        timeSinceLastUpdate += deltaTime;
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }

        render();
        SceneManager::getInstance()->checkLoadedScene();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            mWindow.close();
            break;
        }
        GameObjectManager::getInstance()->processInput(event);
    }
}

void Game::render() {
    mWindow.clear();
    GameObjectManager::getInstance()->draw(&mWindow);
    mWindow.display();
}


void Game::update(sf::Time deltaTime) {
    if (!ApplicationManager::getInstance()->isPaused()) {
        GameObjectManager::getInstance()->update(deltaTime);
    }
}