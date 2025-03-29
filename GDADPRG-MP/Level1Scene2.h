#pragma once
#include "AScene.h"
#include "PauseScreen.h"
#include "ProjectileObject.h"

class Level1Scene2 : public AScene {
public:
    Level1Scene2();
    void onLoadResources();
    void onLoadObjects();
    void onUnloadResources();

};
