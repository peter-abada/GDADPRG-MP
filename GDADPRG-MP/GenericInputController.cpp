#include "GenericInputController.h"

GenericInputController::GenericInputController(std::string name) : AComponent(name, Input) {
	this->type = Input;
}

GenericInputController::~GenericInputController() {
	AComponent::~AComponent();
}


void GenericInputController::assignEvent(sf::Event event) {
	this->event = event;
}

void GenericInputController::perform() {

}