#include "Level1Scene2.h"
#include "GameObjectManager.h"
#include "BGObject.h"
#include "AirplanePlayer.h"
#include "EmptyGameObject.h"
#include "Ground.h"
#include "Platform.h"
#include "Counter.h"
#include "NextScreen.h"
#include "Enemy.h"

#include <iostream>



/*

These classes function as the levels and stages, the player starts on the left and they
have to make it all the way to the right to move to the next stage or level


Refer to GameScene.h for more details on how the levels are structured

*/


Level1Scene2::Level1Scene2() : AScene("Level1Scene2") {
}

void Level1Scene2::onLoadResources() {
    std::cout << "Loading game resources..." << std::endl;
}

void Level1Scene2::onLoadObjects() {

    std::cout << "Loading game objects..." << std::endl;

    EmptyGameObject* physicsManager = new EmptyGameObject("PhysicsManager");
    PhysicsManager::getInstance()->initialize("PhysicsManager", physicsManager);
    GameObjectManager::getInstance()->addObject(physicsManager);

    BGObject* bgObject = new BGObject("BGObject");
    this->registerObject(bgObject);

    Ground* ground = new Ground("Ground");
    this->registerObject(ground);

    NextScreen* nextScreen = new NextScreen("NextScreen", 2);
    this->registerObject(nextScreen);


    AirplanePlayer* planeObject = new AirplanePlayer("PlaneObject");
    this->registerObject(planeObject);


	// Added the enemy and platform pools
	Counter* enemyCounter = new Counter(1);
	//ENemy pool is set up in the same way as platform pool with the stage and counter as parameters.
	GameObjectPool* enemyPool = new GameObjectPool(ObjectPoolHolder::ENEMY_POOL_TAG, new Enemy("Enemy", 2, enemyCounter), 10, nullptr);
	enemyPool->initialize();
	ObjectPoolHolder::getInstance()->registerObjectPool(enemyPool);

    Counter* stageCounter = new Counter(1);

    GameObjectPool* platformPool = new GameObjectPool(ObjectPoolHolder::PLATFORM_POOL_TAG, new Platform("Platform", 2, stageCounter), 10, nullptr);
    platformPool->initialize();
    ObjectPoolHolder::getInstance()->registerObjectPool(platformPool);

	enemyPool->requestPoolable();
    platformPool->requestPoolable();
    

    PauseMenuScreen* PauseMenuSrn = new PauseMenuScreen("PauseMenuScreen");
    GameObjectManager::getInstance()->addObject(PauseMenuSrn);

    PauseScreen* pauseSrn = new PauseScreen("PauseScreen", PauseMenuSrn);
    GameObjectManager::getInstance()->addObject(pauseSrn);

}

void Level1Scene2::onUnloadResources() {

}
