#pragma once
#include "AScene.h"
class MainMenuScene : public AScene
{
public:
	MainMenuScene();
	void onLoadResources();
	void onLoadObjects();
	void onUnloadResources();
	void onUnloadObjects();
};

