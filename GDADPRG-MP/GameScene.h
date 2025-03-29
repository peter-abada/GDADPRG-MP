#pragma once
#include "AScene.h"
#include "PauseScreen.h"

class GameScene : public AScene {
public:
    GameScene();
    void onLoadResources();
    void onLoadObjects();
    void onUnloadResources();

};
