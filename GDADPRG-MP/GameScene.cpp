#include "GameScene.h"
#include "GameObjectManager.h"
#include "BGObject.h"
#include "AirplanePlayer.h"
#include "EmptyGameObject.h"
#include "EnemySwarmHandler.h"
#include "Ground.h"
#include "Platform.h"
#include "Counter.h"
#include <iostream>

GameScene::GameScene() : AScene("GameScene") {
}

void GameScene::onLoadResources() {
    std::cout << "Loading game resources..." << std::endl;
}

void GameScene::onLoadObjects() {

    std::cout << "Loading game objects..." << std::endl;

    BGObject* bgObject = new BGObject("BGObject");
    this->registerObject(bgObject);

	Ground* ground = new Ground("Ground");
	this->registerObject(ground);



	//Platform* platform = new Platform("Platform");
	//this->registerObject(platform);

    AirplanePlayer* planeObject = new AirplanePlayer("PlaneObject");
    this->registerObject(planeObject);

    //srand(time(nullptr));
    //EmptyGameObject* enemiesManager = new EmptyGameObject("EnemiesManager");
    //EnemySwarmHandler* swarmHandler = new EnemySwarmHandler(10, "SwarmHandler", enemiesManager);
    //enemiesManager->attachComponent(swarmHandler);
    //this->registerObject(enemiesManager);

	GameObjectPool* projectilePool = new GameObjectPool(ObjectPoolHolder::PROJECTILE_POOL_TAG, new ProjectileObject("projectile"), 10, nullptr);
	projectilePool->initialize();
	ObjectPoolHolder::getInstance()->registerObjectPool(projectilePool);


    Counter* stageCounter = new Counter(1);



    GameObjectPool* platformPool = new GameObjectPool(ObjectPoolHolder::PLATFORM_POOL_TAG, new Platform("Platform", 1, stageCounter), 10, nullptr);
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

void GameScene::onUnloadObjects() {

}
