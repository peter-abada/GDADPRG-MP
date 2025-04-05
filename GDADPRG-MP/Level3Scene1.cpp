#include "Level3Scene1.h"
#include "GameObjectManager.h"
#include "Level3BGObject.h"
#include "AirplanePlayer.h"
#include "EmptyGameObject.h"
#include "EnemySwarmHandler.h"
#include "Ground.h"
#include "Platform.h"
#include "Counter.h"
#include "NextScreen.h"
#include <iostream>
#include "MusicManager.h"
#include "Game.h"
Level3Scene1::Level3Scene1() : AScene("Level3Scene1") {
}

void Level3Scene1::onLoadResources() {
    std::cout << "Loading game resources..." << std::endl;
}

void Level3Scene1::onLoadObjects() {

    std::cout << "Loading game objects..." << std::endl;
    //sf::Music* backgroundMusic = MusicManager::getInstance()->getMusic("BackgroundMusic");
    //if (backgroundMusic) {
    //    backgroundMusic->setLoop(true); // Enable looping
    //    backgroundMusic->play();
    //}
    MusicManager::getInstance()->playSong("Level3Music");
    EmptyGameObject* physicsManager = new EmptyGameObject("PhysicsManager");
    PhysicsManager::getInstance()->initialize("PhysicsManager", physicsManager);
    GameObjectManager::getInstance()->addObject(physicsManager);

    Level3BGObject* bgObject = new Level3BGObject("Level3BGObject");
    this->registerObject(bgObject);

    Ground* ground = new Ground("Ground", Game::WINDOW_WIDTH - 1000, 500);
    this->registerObject(ground);

    NextScreen* nextScreen = new NextScreen("NextScreen", 7);
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



    GameObjectPool* platformPool = new GameObjectPool(ObjectPoolHolder::PLATFORM_POOL_TAG, new Platform("Platform", 7, stageCounter), 10, nullptr);
    // probably dont need to use pools ubt instead just the object itself so we can manually put x and y so we dont need stage coutner

    platformPool->initialize();
    ObjectPoolHolder::getInstance()->registerObjectPool(platformPool);

    for (int i = 0; i < 4; i++) {
        platformPool->requestPoolable();
    }


    PauseMenuScreen* PauseMenuSrn = new PauseMenuScreen("PauseMenuScreen");
    GameObjectManager::getInstance()->addObject(PauseMenuSrn);

    PauseScreen* pauseSrn = new PauseScreen("PauseScreen", PauseMenuSrn);
    GameObjectManager::getInstance()->addObject(pauseSrn);

}

void Level3Scene1::onUnloadResources() {

}
