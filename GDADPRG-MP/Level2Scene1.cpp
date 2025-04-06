#include "Level2Scene1.h"
#include "GameObjectManager.h"
#include "Level2BGObject.h"
#include "AirplanePlayer.h"
#include "EmptyGameObject.h"
#include "Ground.h"
#include "Enemy.h"
#include "Platform.h"
#include "Counter.h"
#include "NextScreen.h"
#include <iostream>
#include "MusicManager.h"

/*

These classes function as the levels and stages, the player starts on the left and they
have to make it all the way to the right to move to the next stage or level


Refer to GameScene.h for more details on how the levels are structured

*/


Level2Scene1::Level2Scene1() : AScene("Level2Scene1") {
}

void Level2Scene1::onLoadResources() {
    std::cout << "Loading game resources..." << std::endl;
}

void Level2Scene1::onLoadObjects() {

    std::cout << "Loading game objects..." << std::endl;

    MusicManager::getInstance()->playSong("Level2Music");
    EmptyGameObject* physicsManager = new EmptyGameObject("PhysicsManager");
    PhysicsManager::getInstance()->initialize("PhysicsManager", physicsManager);
    GameObjectManager::getInstance()->addObject(physicsManager);

    Level2BGObject* bgObject = new Level2BGObject("Level2BGObject");
    this->registerObject(bgObject);

    Ground* ground = new Ground("Ground");
    this->registerObject(ground);

    NextScreen* nextScreen = new NextScreen("NextScreen", 4);
    this->registerObject(nextScreen);


    AirplanePlayer* planeObject = new AirplanePlayer("PlaneObject");
    this->registerObject(planeObject);


    Counter* stageCounter = new Counter(1);


    GameObjectPool* platformPool = new GameObjectPool(ObjectPoolHolder::PLATFORM_POOL_TAG, new Platform("Platform", 4, stageCounter), 10, nullptr);

    Counter* enemyCounter = new Counter(1);

    GameObjectPool* enemyPool = new GameObjectPool(ObjectPoolHolder::ENEMY_POOL_TAG, new Enemy("Enemy", 4, enemyCounter), 10, nullptr);
    enemyPool->initialize();
    ObjectPoolHolder::getInstance()->registerObjectPool(enemyPool);


    platformPool->initialize();
    ObjectPoolHolder::getInstance()->registerObjectPool(platformPool);
    platformPool->requestPoolable();
    for (int i = 0; i < 3; i++) {
        enemyPool->requestPoolable();
    }


    PauseMenuScreen* PauseMenuSrn = new PauseMenuScreen("PauseMenuScreen");
    GameObjectManager::getInstance()->addObject(PauseMenuSrn);

    PauseScreen* pauseSrn = new PauseScreen("PauseScreen", PauseMenuSrn);
    GameObjectManager::getInstance()->addObject(pauseSrn);

}

void Level2Scene1::onUnloadResources() {

}
