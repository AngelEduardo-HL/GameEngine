#pragma once

#include "raylib.h"
#include "resources_manager.h"

#include <string>

using namespace skibidi;

class Score
{
public:
    int scorePoints = 0;
    int playerLives = 3;

    Vector2 position = { 20.0f, 20.0f };
    Font scoreFont;

    Score()
    {
        scoreFont = ResourcesManager::get().getFont("SpaceFont3.ttf");
        reset();
    }

    void reset()
    {
        scorePoints = 0;
        playerLives = 3;
    }

    void addPoint()
    {
        scorePoints++;
    }

    void shipKilled()
    {
        if (playerLives > 0)
        {
            playerLives--;
        }
    }

    void draw()
    {
        DrawTextEx(scoreFont,("Score: " + std::to_string(scorePoints)).c_str(), position, 20.0f, 0.0f, WHITE);

        DrawTextEx(scoreFont,("Lives: " + std::to_string(playerLives)).c_str(),{ position.x, position.y + 30.0f }, 20.0f, 0.0f, WHITE);
    }
};