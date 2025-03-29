#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Entity
{

public:
	Entity();
	void setTexture(sf::Texture texture);
	sf::Sprite* getSprite();

	static Entity* createEntity(sf::Texture* texture, float x, float y);


private:
	sf::Texture mTexture;
	sf::Sprite mSprite;

};

