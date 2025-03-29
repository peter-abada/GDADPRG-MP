#include "PlayerMovement.h"
#include <iostream>

PlayerMovement::PlayerMovement(std::string name) 
    : AComponent(name, AComponent::ComponentType::Script) {
}

void PlayerMovement::perform() {
    AirplanePlayer* airplanePlayer = (AirplanePlayer*)this->getOwner();
    PlayerInputController* inputController = (PlayerInputController*)(airplanePlayer->getComponentsOfType(AComponent::ComponentType::Input)[0]);
    sf::Transformable* playerTransformable = airplanePlayer->getTransformable();
    if (playerTransformable == nullptr || inputController == nullptr) {
        std::cout << "trans no found";
        return;
    }
    
    sf::Vector2f offset(0.f, 0.f);   
	if (!airplanePlayer->getGrounded()) {
		offset.y += this->SPEED_MULTIPLIER*2;
	}

      this->ticks += this->deltaTime.asSeconds();


      //if (inputController->hasFired() && this->ticks > this->BULLET_SPAWN_INTERVAL) {
      //    GameObjectPool* projectilePool = ObjectPoolHolder::getInstance()->getPool(ObjectPoolHolder::PROJECTILE_POOL_TAG);
      //    this->ticks = 0.f;
      //    projectilePool->requestPoolable();
      //}

    if (inputController->isUp() && airplanePlayer->getGrounded() && this->ticks > this->JUMP_INTERVAL) {

        this->ticks = 0.f;
        offset.y -= this->SPEED_MULTIPLIER*35;
        airplanePlayer->setGrounded(false);

    }
    if (inputController->isRight()) {
        offset.x += this->SPEED_MULTIPLIER*1.5f;
    }
    if (inputController->isLeft()) {
        offset.x -= this->SPEED_MULTIPLIER*1.5f;
    }

    playerTransformable->move(offset * deltaTime.asSeconds());
    //std::cout << "top: " << airplanePlayer->getSprite()->getGlobalBounds().top << std::endl;
}
