#include "PlayerInputController.h"
#include <iostream>
PlayerInputController::PlayerInputController(std::string name) : GenericInputController(name) {
}

PlayerInputController::~PlayerInputController() {
}

void PlayerInputController::perform() {

	bool keyFlag = false;
	if (event.type == sf::Event::KeyPressed) {
		keyFlag = true;
	}
	else if (event.type == sf::Event::KeyReleased) {
		keyFlag = false;
	}

	switch (event.key.code) {
	case sf::Keyboard::Space:
		this->moveUp = keyFlag;
		break;
	case sf::Keyboard::A:
		this->moveLeft = keyFlag;
		break;
	case sf::Keyboard::D:
		this->moveRight = keyFlag;
		break;
	}


}

bool PlayerInputController::hasFired() {
	return this->fire;
}


bool PlayerInputController::isUp() {
	return this->moveUp;
}

bool PlayerInputController::isLeft() {
	return this->moveLeft;
}			
	
bool PlayerInputController::isRight() {
	return this->moveRight;
}	