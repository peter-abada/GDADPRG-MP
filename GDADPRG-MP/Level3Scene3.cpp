#include "Level3Scene3.h"
#include "GameObjectManager.h"
#include "Level3BGObject.h"
#include "AirplanePlayer.h"
#include "EmptyGameObject.h"
#include "Ground.h"
#include "Platform.h"
#include "Counter.h"
#include "NextScreen.h"
#include "Enemy.h"
#include "Goal.h"
#include <iostream>
/*

These classes function as the levels and stages, the player starts on the left and they
have to make it all the way to the right to move to the next stage or level


Refer to GameScene.h for more details on how the levels are structured

*/

Level3Scene3::Level3Scene3() : AScene("Level3Scene3") {
}

void Level3Scene3::onLoadResources() {
    std::cout << "Loading game resources..." << std::endl;
}

void Level3Scene3::onLoadObjects() {

    std::cout << "Loading game objects..." << std::endl;

    EmptyGameObject* physicsManager = new EmptyGameObject("PhysicsManager");
    PhysicsManager::getInstance()->initialize("PhysicsManager", physicsManager);
    GameObjectManager::getInstance()->addObject(physicsManager);

    Level3BGObject* bgObject = new Level3BGObject("Level3BGObject");
    this->registerObject(bgObject);

    Ground* ground = new Ground("Ground");
    this->registerObject(ground);

    Goal* goal = new Goal("Goal", 3, Game::WINDOW_WIDTH / 2 + 300, 300);
    this->registerObject(goal);

    AirplanePlayer* planeObject = new AirplanePlayer("PlaneObject");
    this->registerObject(planeObject);


    Counter* enemyCounter = new Counter(1);

    GameObjectPool* enemyPool = new GameObjectPool(ObjectPoolHolder::ENEMY_POOL_TAG, new Enemy("Enemy", 9, enemyCounter), 10, nullptr);
    enemyPool->initialize();
    ObjectPoolHolder::getInstance()->registerObjectPool(enemyPool);

    for (int i = 0; i < 3; i++) {
        enemyPool->requestPoolable();
    }


    PauseMenuScreen* PauseMenuSrn = new PauseMenuScreen("PauseMenuScreen");
    GameObjectManager::getInstance()->addObject(PauseMenuSrn);

    PauseScreen* pauseSrn = new PauseScreen("PauseScreen", PauseMenuSrn);
    GameObjectManager::getInstance()->addObject(pauseSrn);

}

void Level3Scene3::onUnloadResources() {

}
