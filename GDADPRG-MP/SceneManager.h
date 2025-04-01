#pragma once
#include <unordered_map>
#include "AScene.h"

typedef std::unordered_map<std::string, AScene*> SceneTable;
typedef std::vector<std::string> SceneList;

class SceneManager {
public:
    static std::string MAIN_MENU_SCENE_NAME;
    static std::string GAME_SCENE_NAME;
    static std::string LEVEL1_SCENE2_NAME;
    static std::string LEVEL1_SCENE3_NAME;

    static SceneManager* getInstance();
    void registerScene(AScene* scene);
    void loadScene(std::string name);
    void unloadScene();
    bool isSceneLoaded(std::string name);
    void checkLoadedScene();

private:
    SceneManager();
    SceneManager(SceneManager const&) {};
    SceneManager& operator=(SceneManager const&) {};
    static SceneManager* sharedInstance;

    SceneTable storedScenes;
    AScene* activeScene;
    std::string toLoadSceneName;
    bool isLoading = false;
};
