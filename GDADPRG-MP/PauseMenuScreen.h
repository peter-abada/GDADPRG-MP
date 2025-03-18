#pragma once
#include "AGameObject.h"
#include <string>
#include "UIButton.h"
#include "UIText.h"
#include "ButtonListener.h"
#include "SceneManager.h"

class PauseMenuScreen : public AGameObject, public ButtonListener
{

public:
	PauseMenuScreen(std::string name);
	void initialize();

	void onButtonClick(UIButton* button);
	void onButtonReleased(UIButton* button);
};
