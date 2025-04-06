#include "Level2Scene2.h"
#include "GameObjectManager.h"
#include "Level2BGObject.h"
#include "AirplanePlayer.h"
#include "EmptyGameObject.h"
#include "Ground.h"
#include "Platform.h"
#include "Counter.h"
#include "NextScreen.h"
#include "Enemy.h"
#include "Game.h"
#include <iostream>
/*

These classes function as the levels and stages, the player starts on the left and they
have to make it all the way to the right to move to the next stage or level


Refer to GameScene.h for more details on how the levels are structured

*/

Level2Scene2::Level2Scene2() : AScene("Level2Scene2") {
}

void Level2Scene2::onLoadResources() {
    std::cout << "Loading game resources..." << std::endl;
}

void Level2Scene2::onLoadObjects() {

    std::cout << "Loading game objects..." << std::endl;

    EmptyGameObject* physicsManager = new EmptyGameObject("PhysicsManager");
    PhysicsManager::getInstance()->initialize("PhysicsManager", physicsManager);
    GameObjectManager::getInstance()->addObject(physicsManager);

    Level2BGObject* bgObject = new Level2BGObject("Level2BGObject");
    this->registerObject(bgObject);

    Ground* ground = new Ground("Ground", Game::WINDOW_WIDTH / 2 - 600, 500);
    this->registerObject(ground);

    Ground* ground2 = new Ground("Ground2", Game::WINDOW_WIDTH / 2 + 700, 500);
    this->registerObject(ground2);


    NextScreen* nextScreen = new NextScreen("NextScreen", 5);
    this->registerObject(nextScreen);

    AirplanePlayer* planeObject = new AirplanePlayer("PlaneObject");
    this->registerObject(planeObject);

    Counter* stageCounter = new Counter(1);



    GameObjectPool* platformPool = new GameObjectPool(ObjectPoolHolder::PLATFORM_POOL_TAG, new Platform("Platform", 5, stageCounter), 10, nullptr);
    platformPool->initialize();
    ObjectPoolHolder::getInstance()->registerObjectPool(platformPool);
    for (int i = 0; i < 3; i++) {
        platformPool->requestPoolable();
    }

    PauseMenuScreen* PauseMenuSrn = new PauseMenuScreen("PauseMenuScreen");
    GameObjectManager::getInstance()->addObject(PauseMenuSrn);

    PauseScreen* pauseSrn = new PauseScreen("PauseScreen", PauseMenuSrn);
    GameObjectManager::getInstance()->addObject(pauseSrn);

}

void Level2Scene2::onUnloadResources() {

}
