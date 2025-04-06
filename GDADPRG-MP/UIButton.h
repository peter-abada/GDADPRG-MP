#pragma once
#include "AGameObject.h"
#include "ButtonListener.h"
#include "UIButtonInputController.h"

class UIButton : public AGameObject
{
public:
    UIButton(std::string name, sf::Texture* normalTexture, sf::Texture* pressedTexture);
    void changeButtonToNormal();
    void changeButtonToPressed();
    sf::FloatRect getLocalBounds();
    sf::FloatRect getGlobalBounds();
    void setButtonListener(ButtonListener* listener);
    void initialize();

private:
    sf::Texture* normalTexture;
    sf::Texture* pressedTexture;
    ButtonListener* listener;
};
