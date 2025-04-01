#pragma once
#include "AGameObject.h"
#include "SceneManager.h"
#include "Renderer.h"
#include "CollisionListener.h"

class Goal : public AGameObject, public CollisionListener
{
public:
    Goal(std::string name, int stage, int xPos,  int yPos);
    void initialize() override;
    void processInput(sf::Event event) override;
    void update(sf::Time deltaTime) override;

    void onCollisionEnter(AGameObject* gameObject) override;
    void onCollisionExit(AGameObject* gameObject) override;

private:

    int stage = 0;
    Collider* collider = nullptr;
	int xPos;
	int yPos;
};
