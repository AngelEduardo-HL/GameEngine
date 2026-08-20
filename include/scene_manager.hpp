#pragma once

#include <string>
#include <unordered_map>

#include "Scene.hpp"

namespace skibidi
{
    class SceneManager
    {
    private:

        std::unordered_map<std::string, Scene*> scenes;

        Scene* currentScene = nullptr;
        Scene* nextScene = nullptr;

        SceneManager() = default;


        void processChange()
        {
            if (nextScene == nullptr)
            {
                return;
            }

            if (currentScene != nullptr)
            {
                currentScene->OnExit();
            }

            currentScene = nextScene;
            nextScene = nullptr;

            currentScene->OnInit();
            currentScene->OnEnter();
        }


    public:

        static SceneManager& get()
        {
            static SceneManager instance;
            return instance;
        }


        SceneManager(const SceneManager&) = delete;

        SceneManager& operator=(const SceneManager&) = delete;


        void addScene(
            const std::string& name,
            Scene* scene
        )
        {
            scenes[name] = scene;
        }


        void changeScene(
            const std::string& name
        )
        {
            auto it = scenes.find(name);

            if (it == scenes.end())
            {
                return;
            }

            nextScene = it->second;
        }


        void Update()
        {
            processChange();

            if (currentScene != nullptr)
            {
                currentScene->Update();
            }

            processChange();
        }


        void Draw()
        {
            if (currentScene != nullptr)
            {
                currentScene->Draw();
            }
        }
    };
}