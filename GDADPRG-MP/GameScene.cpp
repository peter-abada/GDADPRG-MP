#include "GameScene.h"
#include "GameObjectManager.h"
#include "BGObject.h"
#include "AirplanePlayer.h"
#include "EmptyGameObject.h"
#include "Ground.h"
#include "Platform.h"
#include "Counter.h"
#include "NextScreen.h"
#include <iostream>
#include "MusicManager.h"

/*

These classes function as the levels and stages, the player starts on the left and they
have to make it all the way to the right to move to the next stage or level


*/


GameScene::GameScene() : AScene("GameScene") {
}

void GameScene::onLoadResources() {
    std::cout << "Loading game resources..." << std::endl;
}

void GameScene::onLoadObjects() {

    std::cout << "Loading game objects..." << std::endl;


    // Plays the first levels music
    MusicManager::getInstance()->playSong("Level1Music");
    EmptyGameObject* physicsManager = new EmptyGameObject("PhysicsManager");
    PhysicsManager::getInstance()->initialize("PhysicsManager", physicsManager);
    GameObjectManager::getInstance()->addObject(physicsManager);

    BGObject* bgObject = new BGObject("BGObject");
    this->registerObject(bgObject);

	Ground* ground = new Ground("Ground");
	this->registerObject(ground);


    // Transition point for next screen, the number represents the current stage so it knows what level to load next
	NextScreen* nextScreen = new NextScreen("NextScreen", 1);
    this->registerObject(nextScreen);

	//Platform* platform = new Platform("Platform");
	//this->registerObject(platform);

    AirplanePlayer* planeObject = new AirplanePlayer("PlaneObject");
    this->registerObject(planeObject);

    // starts the counter at 1
    Counter* stageCounter = new Counter(1);


    // creates a platform pool with parameters of the current stage and the counter, it also has a max size of 10
    GameObjectPool* platformPool = new GameObjectPool(ObjectPoolHolder::PLATFORM_POOL_TAG, new Platform("Platform", 1, stageCounter), 10, nullptr);

    platformPool->initialize();
    ObjectPoolHolder::getInstance()->registerObjectPool(platformPool);

    // Spawns in 3 platforms
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
