#pragma once
#include "AGameObject.h"
#include "APoolable.h"
#include "CollisionListener.h"
#include "Counter.h"

class Platform : public APoolable, public CollisionListener
{
public:
    Platform(std::string name, int stage, Counter* stageCounter);
    ~Platform();
    void initialize();

    void onRelease();
    void onActivate();
    APoolable* clone();

    void onCollisionEnter(AGameObject* gameObject) override;
    void onCollisionExit(AGameObject* gameObject) override;

    int getStage();

private:
    sf::Sprite* sprite = new sf::Sprite();
    int stage = 0;

    Collider* collider = nullptr;
    Counter* stageCounter; 
};

