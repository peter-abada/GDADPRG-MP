#include "Level1Scene3.h"
#include "GameObjectManager.h"
#include "BGObject.h"
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

Level1Scene3::Level1Scene3() : AScene("Level1Scene3") {
}

void Level1Scene3::onLoadResources() {
    std::cout << "Loading game resources..." << std::endl;
}

void Level1Scene3::onLoadObjects() {

    std::cout << "Loading game objects..." << std::endl;

    EmptyGameObject* physicsManager = new EmptyGameObject("PhysicsManager");
    PhysicsManager::getInstance()->initialize("PhysicsManager", physicsManager);
    GameObjectManager::getInstance()->addObject(physicsManager);

    BGObject* bgObject = new BGObject("BGObject");
    this->registerObject(bgObject);

    Ground* ground = new Ground("Ground", Game::WINDOW_WIDTH / 2- 400, 500);
    this->registerObject(ground);    
    
    Ground* ground2 = new Ground("Ground2", Game::WINDOW_WIDTH / 2+ 550, 500);
    this->registerObject(ground2);



    // Debugging positions of grounds
    std::cout << "Ground 1 PositiEASDEWEEWFWEFon: (" << ground->getTransformable()->getPosition().x << ", " << ground->getTransformable()->getPosition().y << ")" << std::endl;
    std::cout << "Ground 2 Position: (" << ground2->getTransformable()->getPosition().x << ", " << ground2->getTransformable()->getPosition().y << ")" << std::endl;

    Goal* goal = new Goal("Goal", 1, Game::WINDOW_WIDTH / 2 + 300, 300);
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

    Counter* enemyCounter = new Counter(1);

    GameObjectPool* enemyPool = new GameObjectPool(ObjectPoolHolder::ENEMY_POOL_TAG, new Enemy("Enemy", 3, enemyCounter), 10, nullptr);
    enemyPool->initialize();
    ObjectPoolHolder::getInstance()->registerObjectPool(enemyPool);

    //Counter* stageCounter = new Counter(1);



    //GameObjectPool* platformPool = new GameObjectPool(ObjectPoolHolder::PLATFORM_POOL_TAG, new Platform("Platform", 3, stageCounter), 10, nullptr);
    //platformPool->initialize();
    //ObjectPoolHolder::getInstance()->registerObjectPool(platformPool);

    enemyPool->requestPoolable();
    //platformPool->requestPoolable();



    PauseMenuScreen* PauseMenuSrn = new PauseMenuScreen("PauseMenuScreen");
    GameObjectManager::getInstance()->addObject(PauseMenuSrn);

    PauseScreen* pauseSrn = new PauseScreen("PauseScreen", PauseMenuSrn);
    GameObjectManager::getInstance()->addObject(pauseSrn);

}

void Level1Scene3::onUnloadResources() {

}
