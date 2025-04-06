#include "Level3Scene2.h"
#include "GameObjectManager.h"
#include "Level3BGObject.h"
#include "AirplanePlayer.h"
#include "EmptyGameObject.h"
#include "EnemySwarmHandler.h"
#include "Ground.h"
#include "Platform.h"
#include "Counter.h"
#include "NextScreen.h"
#include "Enemy.h"
#include "Game.h"
#include <iostream>

Level3Scene2::Level3Scene2() : AScene("Level3Scene2") {
}

void Level3Scene2::onLoadResources() {
    std::cout << "Loading game resources..." << std::endl;
}

void Level3Scene2::onLoadObjects() {

    std::cout << "Loading game objects..." << std::endl;

    EmptyGameObject* physicsManager = new EmptyGameObject("PhysicsManager");
    PhysicsManager::getInstance()->initialize("PhysicsManager", physicsManager);
    GameObjectManager::getInstance()->addObject(physicsManager);

    Level3BGObject* bgObject = new Level3BGObject("Level3BGObject");
    this->registerObject(bgObject);

    Ground* ground = new Ground("Ground", Game::WINDOW_WIDTH - 1000, 500);
    this->registerObject(ground);

    NextScreen* nextScreen = new NextScreen("NextScreen", 8);
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

    GameObjectPool* projectilePool = new GameObjectPool(ObjectPoolHolder::PROJECTILE_POOL_TAG, new ProjectileObject("projectile"), 10, nullptr);
    projectilePool->initialize();
    ObjectPoolHolder::getInstance()->registerObjectPool(projectilePool);

    Counter* enemyCounter = new Counter(1);

    GameObjectPool* enemyPool = new GameObjectPool(ObjectPoolHolder::ENEMY_POOL_TAG, new Enemy("Enemy", 8, enemyCounter), 10, nullptr);
    enemyPool->initialize();
    ObjectPoolHolder::getInstance()->registerObjectPool(enemyPool);

    Counter* stageCounter = new Counter(1);



    GameObjectPool* platformPool = new GameObjectPool(ObjectPoolHolder::PLATFORM_POOL_TAG, new Platform("Platform", 8, stageCounter), 10, nullptr);
    platformPool->initialize();
    ObjectPoolHolder::getInstance()->registerObjectPool(platformPool);
    for (int i = 0; i < 3; i++) {
        enemyPool->requestPoolable();
        platformPool->requestPoolable();
    }




    PauseMenuScreen* PauseMenuSrn = new PauseMenuScreen("PauseMenuScreen");
    GameObjectManager::getInstance()->addObject(PauseMenuSrn);

    PauseScreen* pauseSrn = new PauseScreen("PauseScreen", PauseMenuSrn);
    GameObjectManager::getInstance()->addObject(pauseSrn);

}

void Level3Scene2::onUnloadResources() {

}