#include "ApplicationManager.h"


ApplicationManager* ApplicationManager::sharedInstance = NULL;

ApplicationManager::ApplicationManager() {

}

ApplicationManager* ApplicationManager::getInstance() {
	if (sharedInstance == NULL) {
		sharedInstance = new ApplicationManager();
	}
	return sharedInstance;
}

void ApplicationManager::initialize(sf::RenderWindow* window) {
	this->window = window;
}

void ApplicationManager::applicationQuit() {
	this->window->close();
}

void ApplicationManager::pauseApplication() {
	this->gameState = Paused;
}

void ApplicationManager::resumeApplication() {
	this->gameState = Running;
}

bool ApplicationManager::isPaused() {
	return this->gameState == Paused;
}

ApplicationManager::~ApplicationManager() {
	delete this->window;
}