#include "win_scene.h"

#include "raylib.h"
#include "scene_manager.hpp"

void WinScene::OnInit()
{

}

void WinScene::OnEnter()
{
    TraceLog(LOG_INFO, "Entrando a Win Scene");
}

void WinScene::Update()
{
    // Nueva partida
    if (IsKeyPressed(KEY_R))
    {
        SceneManager::get().changeScene("play");
    }

    // Menu
    if (IsKeyPressed(KEY_M) || IsKeyPressed(KEY_BACKSPACE))
    {
        SceneManager::get().changeScene( "menu");
    }
}

void WinScene::Draw()
{
    const char* title = "YOU WIN!";

    DrawText(title, GetScreenWidth() / 2 - MeasureText(title, 50) / 2, 180, 50, GREEN);

    const char* restart = "R - Jugar otra vez";

    DrawText(restart, GetScreenWidth() / 2 - MeasureText(restart, 25) / 2, 300, 25, WHITE);

    const char* menu = "M - Menu principal";

    DrawText(menu, GetScreenWidth() / 2 - MeasureText(menu, 25) / 2, 350, 25, WHITE);
}

void WinScene::OnExit()
{

}