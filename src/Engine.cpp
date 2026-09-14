#include "Engine.hpp"

#include "raylib.h"
#include "resource_dir.h"

#include "Menu.hpp"
#include "win_scene.h"
#include "game_over_scene.h"
#include "Play.hpp"

namespace skibidi
{
    void Engine::Init()
    {
        SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);


        InitWindow(screenWidth,screenHeight,"Game Engine");

        InitAudioDevice();

        SearchAndSetResourceDir("resources");

        sceneMgr.addScene("menu",new Menu());
        sceneMgr.addScene("play",new Play());
		sceneMgr.addScene("win", new WinScene());
		sceneMgr.addScene("loose", new GameOverScene());

        sceneMgr.changeScene("menu");

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
        CloseAudioDevice();

        CloseWindow();
    }
}