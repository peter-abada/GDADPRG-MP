#pragma once
#include "AGameObject.h"
#include "Game.h"
#include "BGMovement.h"
#include "Renderer.h"
#include <SFML/Window/Event.hpp>

class BGObject : public AGameObject {
public:
    BGObject(std::string name);

    void initialize();
    void processInput(sf::Event event); 
    void update(sf::Time deltaTime);
};
