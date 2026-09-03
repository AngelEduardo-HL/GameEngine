#pragma once

#include "entity.h"
#include "resources_manager.h"


class Ship : public Entity
{
public:

    float speed = 65.0f;

    Ship()
    {
        name = "Ship";

        active = true;

        position =
        {
            400.0f,
            300.0f
        };

        texture = skibidi::ResourcesManager::get().getTexture("546Crusier.png");
    }

    ~Ship()
    {
    }

    void update() override
    {
        if (IsKeyDown(KEY_W))
        {
            position.y -= speed * GetFrameTime();
        }

        if (IsKeyDown(KEY_S))
        {
            position.y += speed * GetFrameTime();
        }

        if (IsKeyDown(KEY_A))
        {
            position.x -= speed * GetFrameTime();
        }

        if (IsKeyDown(KEY_D))
        {
            position.x += speed *GetFrameTime();
        }
    }

    void draw() override
    {
        if (!isActive() || texture.id == 0)
        {
            return;
        }

        DrawTexture(texture,static_cast<int>(position.x),static_cast<int>(position.y),WHITE);
    }
};