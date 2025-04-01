#pragma once
#include <SFML/Audio.hpp>
#include <unordered_map>
class MusicManager
{
public:
    static MusicManager* getInstance();
    void loadAll();
    sf::Music* getMusic(const std::string& key);
    void playSong(const std::string& key); 
private:
    MusicManager();
    MusicManager(MusicManager const&) = delete;
    MusicManager& operator=(MusicManager const&) = delete;
    static MusicManager* sharedInstance;

    void loadMusic(const std::string& key, const std::string& path);
    std::unordered_map<std::string, sf::Music*> musicMap;
    sf::Music* currentMusic; 
};
