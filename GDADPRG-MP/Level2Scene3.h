#pragma once
#include "AScene.h"
#include "PauseScreen.h"
#include "ProjectileObject.h"

class Level2Scene3 : public AScene {
public:
    Level2Scene3();
    void onLoadResources();
    void onLoadObjects();
    void onUnloadResources();

};
