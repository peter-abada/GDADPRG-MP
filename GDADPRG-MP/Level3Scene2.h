#pragma once
#include "AScene.h"
#include "PauseScreen.h"
#include "ProjectileObject.h"

class Level3Scene2 : public AScene {
public:
    Level3Scene2();
    void onLoadResources();
    void onLoadObjects();
    void onUnloadResources();

};
