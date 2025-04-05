#pragma once
#include "AScene.h"
#include "PauseScreen.h"
#include "ProjectileObject.h"

class Level2Scene2 : public AScene {
public:
    Level2Scene2();
    void onLoadResources();
    void onLoadObjects();
    void onUnloadResources();

};
