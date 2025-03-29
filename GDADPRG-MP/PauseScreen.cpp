#include "PauseScreen.h"
#include "TextureManager.h"
#include "Game.h"
#include "Renderer.h"
#include "GameObjectManager.h"
#include "ApplicationManager.h"
#include <iostream>
#include <string>

PauseScreen::PauseScreen(std::string name, PauseMenuScreen* pauseMenuScreen) : AGameObject(name), ButtonListener(), pauseMenuScreen(pauseMenuScreen) {
}

void PauseScreen::initialize() {
	sf::Sprite* sprite = new sf::Sprite();
	sprite->setTexture(*TextureManager::getInstance()->getTexture("bar_1"));
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);

	Renderer* renderer = new Renderer("PauseScreen");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);

	float posX = Game::Game::WINDOW_WIDTH / 2;
	float posY = Game::Game::WINDOW_HEIGHT / 2;

	this->setPosition(Game::WINDOW_WIDTH - 200, Game::WINDOW_HEIGHT - 50);
	this->transformable.setScale(sf::Vector2f(0.7f, 0.7f));

	sf::Texture* btnNormal = TextureManager::getInstance()->getTexture("btn_normal");
	sf::Texture* btnPressed = TextureManager::getInstance()->getTexture("btn_pressed");

	UIButton* button1 = new UIButton("button_1", btnNormal, btnPressed);
	this->attachChild(button1);
	button1->setPosition(0, 0);
	button1->getTransformable()->setScale(0.2f, 0.2f);

	button1->setButtonListener(this);

	UIText* button_1Text = new UIText("text_1");
	button1->attachChild(button_1Text);
	button_1Text->setPosition(0, -20);
	button_1Text->setSize(100);
	button_1Text->setText("PAUSE");


}

void PauseScreen::onButtonClick(UIButton* button) {
	std::cout << button->getName();
	if (button->getName() == "button_1") {
		pauseMenuScreen->setEnabled(true);
		ApplicationManager::getInstance()->pauseApplication();
	}
}

void PauseScreen::onButtonReleased(UIButton* button) {
	std::cout << button->getName();
}