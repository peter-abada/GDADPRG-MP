#pragma once
#include "AGameObject.h"
#include "APoolable.h"
#include "CollisionListener.h"
#include "Counter.h"

class Enemy : public APoolable, public CollisionListener
{
public:
    Enemy(std::string name, int stage, Counter* enemyCounter);
    ~Enemy();
    void initialize();

    void onRelease();
    void onActivate();
    APoolable* clone();

    void onCollisionEnter(AGameObject* gameObject) override;
    void onCollisionExit(AGameObject* gameObject) override;
    bool getGrounded();
    void setGrounded(bool grounded);
    int getStage();

private:
    sf::Sprite* sprite = new sf::Sprite();
    int stage = 0;

    Collider* collider = nullptr;
    Counter* enemyCounter;
    bool grounded = false;
};

