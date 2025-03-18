#pragma once
#include <SFML/Graphics.hpp>

class Text
{

public:
	Text();
	void setFont(sf::Font& mFont);
	sf::Text* getText();
private:
	sf::Text mText;
	sf::Font mFont;
};

