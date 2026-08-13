#include "Engine.hpp"

#include "raylib.h"
#include "resource_dir.h"

namespace skibidi
{
    Engine::Engine()
    {
        // Engine escucha el evento start_game
        listen("start_game");
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

        SearchAndSetResourceDir(
            "resources"
        );

        // Empezamos en Menu
        sceneManager.changeScene(
            &menu
        );

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


        // SPACE sigue funcionando como acceso rapido
        if (IsKeyPressed(KEY_SPACE))
        {
            sceneManager.changeScene(
                &play
            );

            TraceLog(
                LOG_INFO,
                "Cambio a Play con SPACE"
            );
        }


        // BACKSPACE vuelve al menu
        if (IsKeyPressed(KEY_BACKSPACE))
        {
            sceneManager.changeScene(
                &menu
            );

            TraceLog(
                LOG_INFO,
                "Regreso al Menu"
            );
        }
    }

    void Engine::Draw()
    {
        BeginDrawing();

        ClearBackground(BLACK);

        sceneManager.Draw();

        EndDrawing();
    }

    void Engine::Shutdown()
    {
        sceneManager.changeScene(
            nullptr
        );

        CloseWindow();
    }

    void Engine::onEvent(EventData data)
    {
        // Comprobamos que evento recibimos
        if (data.type == "start_game")
        {
            TraceLog(
                LOG_INFO,
                "EVENTO RECIBIDO: start_game"
            );

            TraceLog(
                LOG_INFO,
                "Cambiando de Menu a Play..."
            );

            // El evento cambia la escena
            sceneManager.changeScene(
                &play
            );
        }
    }
}