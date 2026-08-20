#pragma once

#include "Menu.hpp"
#include "Play.hpp"
#include "scene_manager.hpp"


namespace skibidi
{
    class Engine
    {
    public:

        Engine() = default;
        ~Engine() = default;


        void Init();

        void Run();

        void Update();

        void Draw();

        void Shutdown();


        SceneManager& sceneMgr =
            SceneManager::get();


        int screenWidth = 800;
        int screenHeight = 600;
    };
}