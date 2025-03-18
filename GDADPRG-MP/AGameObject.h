#pragma once
#include <string>
#include "AComponent.h"
#include "Renderer.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "GenericInputController.h"
#include "PhysicsManager.h"
#include "Collider.h"


class AGameObject
{
public:
	AGameObject(std::string name);
	virtual ~AGameObject();
	virtual void initialize() = 0;
	virtual void processInput(sf::Event event);
	virtual void update(sf::Time deltaTime);
	virtual void draw(sf::RenderWindow* targetWindow, sf::RenderStates renderStates);
	std::string getName();

	void attachComponent(AComponent* component);
	void detachComponent(AComponent* component);
	AComponent* findComponentByName(std::string name);
	AComponent* findComponentOfType(AComponent::ComponentType type, std::string name);
	std::vector<AComponent*> getComponentsOfType(AComponent::ComponentType type);

	void attachChild(AGameObject* child);
	void detachChild(AGameObject* child);
	void setPosition(float x, float y);
	sf::Transformable* getTransformable();
	sf::Sprite* getSprite();

	void setEnabled(bool flag);
	bool isEnabled();	

	AGameObject* getParent();

	sf::Transform getGlobalTransform();

protected:
	void setParent(AGameObject* parent);
	sf::Transformable transformable;
	std::string name;
	sf::Sprite* sprite;
	sf::Texture* texture;
	std::vector<AGameObject*> childList;
	std::vector<AComponent*> componentList;

private:
	AGameObject* mParent;
	bool enabled = true;

};
