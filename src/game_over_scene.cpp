#include "game_over_scene.h"

#include "raylib.h"
#include "scene_manager.hpp"

void GameOverScene::OnInit()
{

}

void GameOverScene::OnEnter()
{
    TraceLog(LOG_INFO, "Entrando a Game Over");
}

void GameOverScene::Update()
{
    // Nueva partida
    if (IsKeyPressed(KEY_R))
    {
        SceneManager::get().changeScene("play");
    }

    // Menu
    if (IsKeyPressed(KEY_M) || IsKeyPressed(KEY_BACKSPACE))
    {
        SceneManager::get().changeScene("menu");
    }
}

void GameOverScene::Draw()
{
    const char* title = "GAME OVER";
    DrawText(title, GetScreenWidth() / 2 - MeasureText(title, 50) / 2, 180, 50, RED);

    const char* restart = "R - Reintentar";
    DrawText(restart, GetScreenWidth() / 2 - MeasureText(restart, 25) / 2, 300, 25, WHITE);

    const char* menu = "M - Menu principal";
    DrawText(menu, GetScreenWidth() / 2 - MeasureText(menu, 25) / 2, 350, 25, WHITE);
}

void GameOverScene::OnExit()
{

}