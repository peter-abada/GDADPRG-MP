#pragma once
#include "AGameObject.h"
#include "CollisionListener.h"
#include "Game.h"

class Ground : public AGameObject, public CollisionListener
{
public:
    Ground(std::string name);
    Ground(std::string name, int xPos, int yPos);
    ~Ground();
    void initialize();

	void processInput(sf::Event event) override;
	void update(sf::Time deltaTime) override;

    void onCollisionEnter(AGameObject* gameObject) override;
    void onCollisionExit(AGameObject* gameObject) override;

private:
    sf::Sprite* sprite = new sf::Sprite();
    int xPos;
    int yPos;
    Collider* collider = nullptr;
};
