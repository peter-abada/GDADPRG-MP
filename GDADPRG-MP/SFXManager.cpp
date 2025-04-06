#include "SFXManager.h"
#include <iostream>

SFXManager* SFXManager::sharedInstance = nullptr;

SFXManager* SFXManager::getInstance() {
    if (sharedInstance == nullptr) {
        sharedInstance = new SFXManager();
    }
    return sharedInstance;
}

void SFXManager::loadAll() {
    loadSound("EnemyGunfire", "Media/SFX/EnemyGunfire.wav");

    for (int i = 0; i < 2; i++) {
        std::string str_i = std::to_string(i + 1);
        loadSound("Explosion" + str_i, "Media/SFX/Explosion" + str_i + ".wav");
    }
    loadSound("LaunchMissile", "Media/SFX/LaunchMissile.wav");
    loadSound("Jump", "Media/SFX/Jump.wav");
	loadSound("Stomp", "Media/SFX/Stomp.wav");
    loadSound("DeathSFX", "Media/SFX/DeathSFX.wav");
}

void SFXManager::loadSound(std::string key, std::string path) {
    sf::SoundBuffer* buffer = new sf::SoundBuffer();
    if (buffer->loadFromFile(path)) {
        std::cout << "Loaded: " << path << std::endl;
        sf::Sound* sound = new sf::Sound();
        sound->setBuffer(*buffer);
        sound->setVolume(60);
        soundMap[key] = sound;

    } else {
        std::cout << "Failed to load sound: " << path << std::endl;
        delete buffer;
    }
}

sf::Sound* SFXManager::getSound(std::string key) {
    if (soundMap.find(key) != soundMap.end() && soundMap[key] != nullptr) {
        std::cout << "Playing sound: " << key << std::endl;
        return soundMap[key];
    } else {
        std::cout << "No sound found for key: " << key << std::endl;
        return nullptr;
    }
}
