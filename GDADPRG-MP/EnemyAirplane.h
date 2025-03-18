#pragma once
#include "AGameObject.h"
#include "APoolable.h"
#include "CollisionListener.h"

class EnemyAirplane : public APoolable, public CollisionListener
{
public:
    EnemyAirplane(std::string name);
    ~EnemyAirplane();
    void initialize();

    void onRelease();
    void onActivate();
    APoolable* clone();

    void onCollisionEnter(AGameObject* gameObject) override;
    void onCollisionExit(AGameObject* gameObject) override;

private:
    sf::Sprite* sprite = new sf::Sprite();
    int counter = 0;

    const int SPAWN_RANGE = 300;

    Collider* collider = nullptr;
};
