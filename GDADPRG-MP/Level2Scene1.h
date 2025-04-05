#pragma once
#include "AScene.h"
#include "PauseScreen.h"

class Level2Scene1 : public AScene {
public:
    Level2Scene1();
    void onLoadResources();
    void onLoadObjects();
    void onUnloadResources();

};
