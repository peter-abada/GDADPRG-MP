#pragma once
#include <SFML/Audio.hpp>
#include <unordered_map>

class SFXManager
{
public:
	static SFXManager* getInstance();
	void loadAll();
	sf::Sound* getSound(std::string);
private:
	SFXManager() {};
	SFXManager(SFXManager const&) {};
	SFXManager& operator = (SFXManager const&) {};
	static SFXManager* sharedInstance;

	void loadSound(std::string, std::string);
	std::unordered_map<std::string, sf::Sound*> soundMap;

};

