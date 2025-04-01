#pragma once
#include "AScene.h"
#include "PauseScreen.h"
#include "ProjectileObject.h"

class Level1Scene3 : public AScene {
public:
    Level1Scene3();
    void onLoadResources();
    void onLoadObjects();
    void onUnloadResources();

};
