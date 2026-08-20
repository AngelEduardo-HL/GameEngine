#include "Engine.hpp"

#include "raylib.h"
#include "resource_dir.h"


namespace skibidi
{
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


        // Registramos las escenas.
        sceneMgr.addScene(
            "menu",
            new Menu()
        );


        sceneMgr.addScene(
            "play",
            new Play()
        );


        // Escena inicial.
        sceneMgr.changeScene(
            "menu"
        );
    }


    void Engine::Update()
    {
        sceneMgr.Update();
    }


    void Engine::Draw()
    {
        BeginDrawing();

        ClearBackground(BLACK);

        sceneMgr.Draw();

        EndDrawing();
    }


    void Engine::Run()
    {
        while (!WindowShouldClose())
        {
            Update();
            Draw();
        }
    }


    void Engine::Shutdown()
    {
        CloseWindow();
    }
}