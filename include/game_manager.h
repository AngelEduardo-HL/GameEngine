#pragma once

#include "EventBus.hpp"
#include "scene_manager.hpp"
#include "raylib.h"

class GameManager : public EventListener
{
public:
    int max_kills = 10;
    int current_kills = 0;
    int player_lives = 3;

    bool initialized = false;

    void init()
    {
        if (!initialized)
        {
            listen("player_kill");
            listen("enemy_kill");

            initialized = true;
        }

        reset();
    }

    void reset()
    {
        current_kills = 0;
        player_lives = 3;
    }

    void onEnemyKilled()
    {
        current_kills++;
        TraceLog(LOG_INFO, "Enemy killed. Current kills: %i", current_kills);

        if (current_kills >= max_kills)
        {
            skibidi::SceneManager::get().changeScene("win");
        }
    }

    void onPlayerKilled()
    {
        player_lives--;

        TraceLog(LOG_INFO, "Player hit. Remaining lives: %i", player_lives);

        if (player_lives <= 0)
        {
            skibidi::SceneManager::get().changeScene("loose");
        }
    }

    void onEvent(EventData data) override
    {
        if (data.type == "player_kill")
        {
            onPlayerKilled();
        }

        if (data.type == "enemy_kill")
        {
            onEnemyKilled();
        }
    }
};