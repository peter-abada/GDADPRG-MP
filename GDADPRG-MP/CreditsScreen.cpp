#include "CreditsScreen.h"
#include "TextureManager.h"
#include "Game.h"
#include "Renderer.h"
#include "GameObjectManager.h"
#include "ApplicationManager.h"
#include "SceneManager.h"
#include <iostream>
#include <string>


/*

Basically a copy and paste of hte MainMenuScreen class with differnet wordings

*/

CreditsScreen::CreditsScreen(std::string name)
    : AGameObject(name), ButtonListener(), button1(nullptr), button2(nullptr), buttonYes(nullptr), buttonNo(nullptr), confirmText(nullptr) {
}

void CreditsScreen::initialize() {
    sf::Sprite* sprite = new sf::Sprite();
    sprite->setTexture(*TextureManager::getInstance()->getTexture("MainMenuBG"));
    sf::Vector2u textureSize = sprite->getTexture()->getSize();
    sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);

    Renderer* renderer = new Renderer("CreditsScreen");
    renderer->assignDrawable(sprite);
    this->attachComponent(renderer);


    float posX = Game::WINDOW_WIDTH / 2;
    float posY = Game::WINDOW_HEIGHT / 2;

    this->setPosition(Game::WINDOW_WIDTH / 2, Game::WINDOW_HEIGHT / 2);
    this->transformable.setScale(sf::Vector2f(0.8f, 0.8f));

    sf::Texture* btnNormal = TextureManager::getInstance()->getTexture("btn_normal");
    sf::Texture* btnPressed = TextureManager::getInstance()->getTexture("btn_pressed");

    button1 = new UIButton("button_1", btnNormal, btnPressed);
    this->attachChild(button1);
    button1->setPosition(0, -50);
    button1->getTransformable()->setScale(0.3f, 0.3f);
    button1->setButtonListener(this);

    UIText* button_1Text = new UIText("text_1");
    button1->attachChild(button_1Text);
    button_1Text->setPosition(0, -20);
    button_1Text->setSize(100);
    button_1Text->setText("MAIN MENU");

    button2 = new UIButton("button_2", btnNormal, btnPressed);
    this->attachChild(button2);
    button2->setPosition(0, 50);
    button2->getTransformable()->setScale(0.3f, 0.3f);
    button2->setButtonListener(this);

    UIText* button_2Text = new UIText("text_1");
    button2->attachChild(button_2Text);
    button_2Text->setPosition(0, -20);
    button_2Text->setSize(100);
    button_2Text->setText("EXIT");

    buttonYes = new UIButton("button_yes", btnNormal, btnPressed);
    this->attachChild(buttonYes);
    buttonYes->setPosition(-250, 100);
    buttonYes->getTransformable()->setScale(0.3f, 0.3f);
    buttonYes->setButtonListener(this);
    buttonYes->setEnabled(false);

    UIText* buttonYesText = new UIText("text_yes");
    buttonYes->attachChild(buttonYesText);
    buttonYesText->setPosition(0, -20);
    buttonYesText->setSize(100);
    buttonYesText->setText("YES");

    buttonNo = new UIButton("button_no", btnNormal, btnPressed);
    this->attachChild(buttonNo);
    buttonNo->setPosition(250, 100);
    buttonNo->getTransformable()->setScale(0.3f, 0.3f);
    buttonNo->setButtonListener(this);
    buttonNo->setEnabled(false);

    UIText* buttonNoText = new UIText("text_no");
    buttonNo->attachChild(buttonNoText);
    buttonNoText->setPosition(0, -20);
    buttonNoText->setSize(100);
    buttonNoText->setText("NO");

    confirmText = new UIText("text_confirm");
    this->attachChild(confirmText);
    confirmText->setPosition(0, 0);
    confirmText->setSize(60);
    confirmText->setText("Do you want to exit?");
    confirmText->setEnabled(false);

    ApplicationManager::getInstance()->pauseApplication();
}

void CreditsScreen::onButtonClick(UIButton* button) {
    std::cout << button->getName();
    if (button->getName() == "button_1") {

        ApplicationManager::getInstance()->resumeApplication();
        SceneManager::getInstance()->loadScene(SceneManager::MAIN_MENU_SCENE_NAME);
    }
    else if (button->getName() == "button_2") {
        buttonYes->setEnabled(true);
        buttonNo->setEnabled(true);
        confirmText->setEnabled(true);
        button1->setEnabled(false);
        button2->setEnabled(false);
    }
    else if (button->getName() == "button_yes") {
        ApplicationManager::getInstance()->applicationQuit();
    }
    else if (button->getName() == "button_no") {
        buttonYes->setEnabled(false);
        buttonNo->setEnabled(false);
        confirmText->setEnabled(false);
        button1->setEnabled(true);
        button2->setEnabled(true);
    }
}

void CreditsScreen::onButtonReleased(UIButton* button) {
    std::cout << button->getName();
}
