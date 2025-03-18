#pragma once
#include "AGameObject.h"
#include "CollisionListener.h"


class Ground : public AGameObject, public CollisionListener
{
public:
    Ground(std::string name);
    ~Ground();
    void initialize();

	void processInput(sf::Event event) override;
	void update(sf::Time deltaTime) override;

    void onCollisionEnter(AGameObject* gameObject) override;
    void onCollisionExit(AGameObject* gameObject) override;

private:
    sf::Sprite* sprite = new sf::Sprite();

    Collider* collider = nullptr;
};
