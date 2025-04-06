#pragma once
#include "AGameObject.h"
#include "PlayerInputController.h"
#include "PlayerMovement.h"
#include "Renderer.h"
#include "CollisionListener.h"

class AirplanePlayer : public AGameObject, public CollisionListener
{
public:
    AirplanePlayer(std::string name);
    void initialize() override;
    void processInput(sf::Event event) override;
    void update(sf::Time deltaTime) override;
    bool getGrounded();
    void setGrounded(bool grounded);
    void onCollisionEnter(AGameObject* gameObject) override;
    void onCollisionExit(AGameObject* gameObject) override;

    bool getAlive();
	void setDead(bool dead);

private:
    bool grounded = false; // if the player is touching the ground or a playform
    Collider* collider = nullptr;
    bool dead = false; // if the player is dead or alive
};
