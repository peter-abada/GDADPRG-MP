#pragma once
#include "AGameObject.h"
#include <string>
#include "UIButton.h"
#include "UIText.h"
#include "ButtonListener.h"

class MainMenuScreen : public AGameObject, public ButtonListener {
public:
    MainMenuScreen(std::string name);
    void initialize();
    void onButtonClick(UIButton* button);
    void onButtonReleased(UIButton* button);

private:
    UIButton* button1;
    UIButton* button2;
    UIButton* buttonYes;
    UIButton* buttonNo;
    UIText* confirmText;
};
