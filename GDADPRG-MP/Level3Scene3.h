#pragma once
#include "AScene.h"
#include "PauseScreen.h"
#include "ProjectileObject.h"

class Level3Scene3 : public AScene {
public:
    Level3Scene3();
    void onLoadResources();
    void onLoadObjects();
    void onUnloadResources();

};
