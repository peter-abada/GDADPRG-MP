#pragma once
#include "AGameObject.h"
#include "SceneManager.h"
#include "Renderer.h"
#include "CollisionListener.h"

class NextScreen : public AGameObject, public CollisionListener
{
public:
    NextScreen(std::string name, int screen);
    void initialize() override;
    void processInput(sf::Event event) override;
    void update(sf::Time deltaTime) override;

    void onCollisionEnter(AGameObject* gameObject) override;
    void onCollisionExit(AGameObject* gameObject) override;

private:

    int screen = 0;
    Collider* collider = nullptr;
};
