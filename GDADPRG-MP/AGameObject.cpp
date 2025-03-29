#include "AGameObject.h"
#include <iostream>

AGameObject::AGameObject(std::string name) {
    this->name = name;
    this->sprite = nullptr;
    this->texture = nullptr;
}

AGameObject::~AGameObject() {
    if (this->sprite != nullptr) {
        delete this->sprite;
    }
	for (int i = 0; i < this->componentList.size(); i++) {
		delete this->componentList[i];
	}
    for (int i = 0; i < this->childList.size(); i++) {
        delete this->childList[i];
    }
}

std::string AGameObject::getName() {
    return name;
}

void AGameObject::draw(sf::RenderWindow* targetWindow, sf::RenderStates renderStates) {

    if (!this->isEnabled()) return;

    renderStates.transform = renderStates.transform * this->transformable.getTransform();

	std::vector<AComponent*> componentList = this->getComponentsOfType(AComponent::ComponentType::Renderer);

    //targetWindow->draw(*sprite, renderStates);
	for (int j = 0; j < componentList.size(); j++) {
		Renderer* renderer = (Renderer*)componentList[j];
		renderer->assignTargetWindow(targetWindow);
        renderer->setRenderStates(renderStates);
		renderer->perform();
	}


    for (int i = 0; i < this->childList.size(); i++) {
        AGameObject* child = this->childList[i];
        child->draw(targetWindow, renderStates);
    }
}

void AGameObject::attachChild(AGameObject* child) {
    this->childList.push_back(child);
    child->setParent(this);
    child->initialize();
}

void AGameObject::detachChild(AGameObject* child) {
    int index = -1;
    for (int i = 0; i < this->childList.size(); i++) {
        if (this->childList[i] == child) {
            index = i;
        }
    }

    if (index != -1) {
        this->childList.erase(this->childList.begin() + index);
        this->childList.shrink_to_fit();
    }
}

void AGameObject::setPosition(float x, float y) {
    this->transformable.setPosition(x, y);
}


void AGameObject::attachComponent(AComponent* component) {
    this->componentList.push_back(component);
    component->attachOwner(this);
}

void AGameObject::detachComponent(AComponent* component) {
    int index = -1;
    for (int i = 0; i < this->componentList.size(); i++) {
        if (this->componentList[i] == component) {
            index = i;
            this->componentList[i]->detachOwner();
            break;
        }
    }

    if (index != -1) {
        this->componentList.erase(this->componentList.begin() + index);
    }
}

AComponent* AGameObject::findComponentByName(std::string name) {
    for (int i = 0; i < this->componentList.size(); i++) {
        if (this->componentList[i]->getName() == name) {
            return this->componentList[i];
        }
    }
    return nullptr;
}

AComponent* AGameObject::findComponentOfType(AComponent::ComponentType type, std::string name) {
    for (int i = 0; i < this->componentList.size(); i++) {
        if (this->componentList[i]->getName() == name && this->componentList[i]->getType() == type) {
            return this->componentList[i];
        }
    }
    return nullptr;
}

std::vector<AComponent*> AGameObject::getComponentsOfType(AComponent::ComponentType type) {
    std::vector<AComponent*> foundList;
    for (int i = 0; i < componentList.size(); i++) {
        if (this->componentList[i]->getType() == type) {
            foundList.push_back(this->componentList[i]);
        }
    }
    return foundList;
}

sf::Transformable* AGameObject::getTransformable() {
    return &transformable;
}

void AGameObject::update(sf::Time deltaTime) {
    if (!this->isEnabled()) return;
    std::vector<AComponent*> componentList = this->getComponentsOfType(AComponent::ComponentType::Script);
    for (int j = 0; j < componentList.size(); j++) {
        componentList[j]->setDeltaTime(deltaTime);
        componentList[j]->perform();
    }

    for (int i = 0; i < this->childList.size(); i++) {
        childList[i]->update(deltaTime);
    }
}

void AGameObject::processInput(sf::Event event) {
    if (!this->isEnabled()) return;
    std::vector<AComponent*> componentList = this->getComponentsOfType(AComponent::ComponentType::Input);
    for (int j = 0; j < componentList.size(); j++) {
        ((GenericInputController*)componentList[j])->assignEvent(event);
        componentList[j]->perform();
    }

    for (int i = 0; i < this->childList.size(); i++) {
        childList[i]->processInput(event);
    }
}
sf::Sprite* AGameObject::getSprite()  {
    return sprite;
}


void AGameObject::setEnabled(bool flag) {
	this->enabled = flag;
}

bool AGameObject::isEnabled() {
	return this->enabled;
}


AGameObject* AGameObject::getParent() {
	return this->mParent;
}

void AGameObject::setParent(AGameObject* parent) {
    this->mParent = parent;
}


sf::Transform AGameObject::getGlobalTransform() {
    AGameObject* parentObj = this;
	std::vector<AGameObject*> parentList;
    while (parentObj != NULL) {
		parentList.push_back(parentObj);
		parentObj = parentObj->getParent();
    }

	sf::Transform transform = sf::Transform::Identity;
	int startIndex = parentList.size() - 1;
	for (int i = startIndex; i >= 0; i--) {
		transform = transform * parentList[i]->getTransformable()->getTransform();
	}
	return transform;

}