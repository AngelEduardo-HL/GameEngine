#pragma once

#include "raylib.h"

#include "resource_dir.h"

#include "Menu.hpp"
#include "Play.hpp"
#include "Scene.hpp"
#include "scene_manager.hpp"

namespace skibidi
{
    class Engine
    {
    public:

        Engine();
        ~Engine();

        void Init();
        void run();

        void Update();
        void Draw();

        void Shutdown();

    private:

        static const int screenWidth = 800;
        static const int screenHeight = 600;

        Menu menu;
        Play play;

        SceneManager sceneManager;
    };
}