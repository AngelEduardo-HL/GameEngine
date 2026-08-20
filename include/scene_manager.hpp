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
            if (!nextScene)
            {
                return;
            }

            if (currentScene)
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

        SceneManager& operator=(
            const SceneManager&
            ) = delete;


        ~SceneManager()
        {
            for (auto& scene : scenes)
            {
                delete scene.second;
            }

            scenes.clear();
        }


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
            // Procesa cambios pendientes.
            processChange();

            if (currentScene)
            {
                currentScene->Update();
            }

            // También permite cambiar de escena
            // desde un evento generado durante Update.
            processChange();
        }


        void Draw()
        {
            if (currentScene)
            {
                currentScene->Draw();
            }
        }
    };
}