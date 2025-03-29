#include "PauseMenuScreen.h"
#include "TextureManager.h"
#include "Game.h"
#include "Renderer.h"
#include "GameObjectManager.h"
#include "ApplicationManager.h"
#include <iostream>
#include <string>

PauseMenuScreen::PauseMenuScreen(std::string name) : AGameObject(name), ButtonListener() {
}

void PauseMenuScreen::initialize() {
    this->setEnabled(false);
    sf::Sprite* sprite = new sf::Sprite();
    sprite->setTexture(*TextureManager::getInstance()->getTexture("title_bg"));
    sf::Vector2u textureSize = sprite->getTexture()->getSize();
    sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);

    Renderer* renderer = new Renderer("PauseMenuScreen");
    renderer->assignDrawable(sprite);
    this->attachComponent(renderer);

    float posX = Game::Game::WINDOW_WIDTH / 2;
    float posY = Game::Game::WINDOW_HEIGHT / 2;

    this->setPosition(Game::WINDOW_WIDTH / 2, Game::WINDOW_HEIGHT / 2);
    this->transformable.setScale(sf::Vector2f(0.7f, 0.7f));

    sf::Texture* btnNormal = TextureManager::getInstance()->getTexture("btn_normal");
    sf::Texture* btnPressed = TextureManager::getInstance()->getTexture("btn_pressed");

    UIButton* button1 = new UIButton("button_1", btnNormal, btnPressed);
    this->attachChild(button1);
    button1->setPosition(-150, 0);
    button1->getTransformable()->setScale(0.3f, 0.3f);

    button1->setButtonListener(this);

    UIText* button_1Text = new UIText("text_1");
    button1->attachChild(button_1Text);
    button_1Text->setPosition(0, -20);
    button_1Text->setSize(100);
    button_1Text->setText("YES");

    UIButton* button2 = new UIButton("button_2", btnNormal, btnPressed);
    this->attachChild(button2);
    button2->setPosition(150, 0);
    button2->getTransformable()->setScale(0.3f, 0.3f);
    button2->setButtonListener(this);

    UIText* button_2Text = new UIText("text_1");
    button2->attachChild(button_2Text);
    button_2Text->setPosition(0, -20);
    button_2Text->setSize(100);
    button_2Text->setText("NO");


    UIText* pauseText = new UIText("text_1");
    this->attachChild(pauseText);
    pauseText->setPosition(0, -100);
    pauseText->setSize(60);
    pauseText->setText("Do you want to quit?");

}

void PauseMenuScreen::onButtonClick(UIButton* button) {
    std::cout << button->getName();
    if (button->getName() == "button_1") {
        ApplicationManager::getInstance()->resumeApplication();
        SceneManager::getInstance()->loadScene(SceneManager::MAIN_MENU_SCENE_NAME);
    }
    if (button->getName() == "button_2") {
        ApplicationManager::getInstance()->resumeApplication();
        this->setEnabled(false);
    }
}

void PauseMenuScreen::onButtonReleased(UIButton* button) {
    std::cout << button->getName();
}