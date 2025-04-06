#include "MusicManager.h"
#include <iostream>




/*

A copy of the SFXManager class from one of the first assignments, it uses sf::Music instead

*/

MusicManager* MusicManager::sharedInstance = nullptr;

MusicManager* MusicManager::getInstance() {
    if (sharedInstance == nullptr) {
        sharedInstance = new MusicManager();
    }
    return sharedInstance;
}

MusicManager::MusicManager() {
}

void MusicManager::loadAll() {

    loadMusic("MenuMusic", "Media/Music/MenuMusic.wav");
    loadMusic("Level1Music", "Media/Music/Level1Music.wav");
    loadMusic("Level2Music", "Media/Music/Level2Music.wav");
    loadMusic("Level3Music", "Media/Music/Level3Music.wav");
    loadMusic("Credits", "Media/Music/Credits.wav");
    


}

void MusicManager::loadMusic(const std::string& key, const std::string& path) {
    sf::Music* music = new sf::Music();
    if (music->openFromFile(path)) {
        music->setVolume(70); 
        std::cout << "Loaded: " << path << std::endl;
        musicMap[key] = music;
    }
    else {
        std::cout << "Failed to load music: " << path << std::endl;
        delete music;
    }
}
// Gets the desired song
sf::Music* MusicManager::getMusic(const std::string& key) {
    if (musicMap.find(key) != musicMap.end() && musicMap[key] != nullptr) {
        std::cout << "Playing music: " << key << std::endl;
        return musicMap[key];
    }
    else {
        std::cout << "No music found for key: " << key << std::endl;
        return nullptr;
    }
}

// Plays and stops the songs so that only one song can play at once
void MusicManager::playSong(const std::string& key) {
    // Stop the currently playing music if any
    if (currentMusic != nullptr && currentMusic->getStatus() == sf::Music::Playing) {
        currentMusic->stop();
    }

    // Get the music by key and play it
    currentMusic = getMusic(key);
    if (currentMusic != nullptr) {
        currentMusic->play();
    }
}