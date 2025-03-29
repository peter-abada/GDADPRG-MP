#pragma once
#include "AGameObject.h"
#include <string>
#include "UIButton.h"
#include "UIText.h"
#include "ButtonListener.h"
#include "PauseMenuScreen.h"


class PauseScreen : public AGameObject, public ButtonListener
{

public:
	PauseScreen(std::string name, PauseMenuScreen* pauseMenuScreen);
	void initialize();

	void onButtonClick(UIButton* button);
	void onButtonReleased(UIButton* button);

private:
	PauseMenuScreen* pauseMenuScreen;
};
