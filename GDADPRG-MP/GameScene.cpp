#include "GameScene.h"
#include "GameObjectManager.h"
#include "BGObject.h"
#include "AirplanePlayer.h"
#include "EmptyGameObject.h"
#include "EnemySwarmHandler.h"
#include "Ground.h"
#include "Platform.h"
#include "Counter.h"
#include "NextScreen.h"
#include <iostream>

GameScene::GameScene() : AScene("GameScene") {
}

void GameScene::onLoadResources() {
    std::cout << "Loading game resources..." << std::endl;
}

void GameScene::onLoadObjects() {

    std::cout << "Loading game objects..." << std::endl;

    EmptyGameObject* physicsManager = new EmptyGameObject("PhysicsManager");
    PhysicsManager::getInstance()->initialize("PhysicsManager", physicsManager);
    GameObjectManager::getInstance()->addObject(physicsManager);

    BGObject* bgObject = new BGObject("BGObject");
    this->registerObject(bgObject);

	Ground* ground = new Ground("Ground");
	this->registerObject(ground);

	NextScreen* nextScreen = new NextScreen("NextScreen", 1);
    this->registerObject(nextScreen);

	//Platform* platform = new Platform("Platform");
	//this->registerObject(platform);

    AirplanePlayer* planeObject = new AirplanePlayer("PlaneObject");
    this->registerObject(planeObject);

    //srand(time(nullptr));
    //EmptyGameObject* enemiesManager = new EmptyGameObject("EnemiesManager");
    //EnemySwarmHandler* swarmHandler = new EnemySwarmHandler(10, "SwarmHandler", enemiesManager);
    //enemiesManager->attachComponent(swarmHandler);
    //this->registerObject(enemiesManager);

    Counter* stageCounter = new Counter(1);



    GameObjectPool* platformPool = new GameObjectPool(ObjectPoolHolder::PLATFORM_POOL_TAG, new Platform("Platform", 1, stageCounter), 10, nullptr);
    // probably dont need to use pools ubt instead just the object itself so we can manually put x and y so we dont need stage coutner

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

void GameScene::onUnloadResources() {

}
