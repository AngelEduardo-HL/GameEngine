#include "Engine.hpp"

#include "raylib.h"
#include "resource_dir.h"

namespace skibidi
{
    Engine::Engine()
    {

    }

    Engine::~Engine()
    {

    }

    void Engine::Init()
    {
        SetConfigFlags(
            FLAG_VSYNC_HINT |
            FLAG_WINDOW_HIGHDPI
        );

        InitWindow(
            screenWidth,
            screenHeight,
            "Game Engine"
        );

        SearchAndSetResourceDir("resources");

        // Comenzamos en Menu
        sceneManager.changeScene(&menu);

        TraceLog(
            LOG_INFO,
            "Game Engine iniciado"
        );
    }

    void Engine::run()
    {
        while (!WindowShouldClose())
        {
            Update();
            Draw();
        }
    }

    void Engine::Update()
    {
        // Actualiza solamente la escena actual
        sceneManager.Update();

        // SPACE cambia a Play
        if (IsKeyPressed(KEY_SPACE))
        {
            sceneManager.changeScene(&play);

            TraceLog(
                LOG_INFO,
                "Cambio a Play"
            );
        }

        // BACKSPACE regresa al Menu
        if (IsKeyPressed(KEY_BACKSPACE))
        {
            sceneManager.changeScene(&menu);

            TraceLog(
                LOG_INFO,
                "Cambio a Menu"
            );
        }
    }

    void Engine::Draw()
    {
        BeginDrawing();

        ClearBackground(BLACK);

        // Dibuja solamente la escena actual
        sceneManager.Draw();

        EndDrawing();
    }

    void Engine::Shutdown()
    {
        // Ejecuta onExit de la escena actual
        sceneManager.changeScene(nullptr);

        CloseWindow();
    }
}