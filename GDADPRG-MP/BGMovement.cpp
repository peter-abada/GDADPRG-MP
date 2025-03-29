#include "BGMovement.h"
#include <iostream>
BGMovement::BGMovement(std::string name) : AComponent(name, AComponent::ComponentType::Script) {
}

void BGMovement::perform() {
    sf::Vector2f offset(0.f, 0.f);
    offset.y += SPEED_MULTIPLIER;
    this->owner->getSprite()->move(offset * deltaTime.asSeconds());

    sf::Vector2f localPos = this->owner->getSprite()->getPosition();
    if (localPos.y * deltaTime.asSeconds() > 0) {
        this->owner->getSprite()->setPosition(0, -Game::WINDOW_HEIGHT * 7);
    }
}
