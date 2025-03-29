#pragma once
#include "AGameObject.h"
#include "CollisionListener.h"
#include "AComponent.h"
#include <unordered_set>
class Collider : public AComponent {
public:
    Collider(std::string name);
    void setCollisionListener(CollisionListener* listener);
    bool willCollide(Collider* another);
    bool hasCollisionWith(Collider* collider);
    void addCollision(Collider* collider);
    void removeCollision(Collider* collider);
    void setLocalBounds(sf::FloatRect localBounds);
    void collisionEnter(AGameObject* gameObjects);
    void collisionExit(AGameObject* gameObjects);
    sf::FloatRect getGlobalBounds();
    void perform();
    void clearCollisions();

private:
    bool checked = false;
    std::unordered_set<Collider*> collisions;
    sf::FloatRect localBounds;
    CollisionListener* listener;
};