#pragma once
#include "AScene.h"
#include "PauseScreen.h"

class Level3Scene1 : public AScene {
public:
    Level3Scene1();
    void onLoadResources();
    void onLoadObjects();
    void onUnloadResources();

};
