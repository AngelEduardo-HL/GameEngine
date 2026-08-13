#pragma once

#include "raylib.h"

#include "resource_dir.h"

#include "Menu.hpp"
#include "Play.hpp"
#include "Scene.hpp"
#include "scene_manager.hpp"

#include "even_bus.hpp"

namespace skibidi
{
    class Engine : public EventListener
    {
    public:

        Engine();
        ~Engine();

        void Init();
        void run();

        void Update();
        void Draw();

        void Shutdown();

        // Recibe los eventos
        void onEvent(EventData data) override;

    private:

        static const int screenWidth = 800;
        static const int screenHeight = 600;

        Menu menu;
        Play play;

        SceneManager sceneManager;
    };
}