#include "Level3Scene3.h"
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
#include "Goal.h"
#include <iostream>

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

    GameObjectPool* enemyPool = new GameObjectPool(ObjectPoolHolder::ENEMY_POOL_TAG, new Enemy("Enemy", 9, enemyCounter), 10, nullptr);
    enemyPool->initialize();
    ObjectPoolHolder::getInstance()->registerObjectPool(enemyPool);

    for (int i = 0; i < 3; i++) {
        enemyPool->requestPoolable();
    }

    //Counter* stageCounter = new Counter(1);



    //GameObjectPool* platformPool = new GameObjectPool(ObjectPoolHolder::PLATFORM_POOL_TAG, new Platform("Platform", 3, stageCounter), 10, nullptr);
    //platformPool->initialize();
    //ObjectPoolHolder::getInstance()->registerObjectPool(platformPool);
    //platformPool->requestPoolable();



    PauseMenuScreen* PauseMenuSrn = new PauseMenuScreen("PauseMenuScreen");
    GameObjectManager::getInstance()->addObject(PauseMenuSrn);

    PauseScreen* pauseSrn = new PauseScreen("PauseScreen", PauseMenuSrn);
    GameObjectManager::getInstance()->addObject(pauseSrn);

}

void Level3Scene3::onUnloadResources() {

}
