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

        position = { 400.0f, 300.0f };

        texture =
            skibidi::ResourcesManager::get()
            .getTexture("546Crusier.png");

		collider.radius = 20.0f;
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
            position.x += speed * GetFrameTime();
        }
    }

    void draw() override
    {
        if (!isActive() || texture.id == 0)
        {
			Vector2 pos = { position.x - texture.width / 2.0f, position.y - texture.height / 2.0f };
			DrawTextureEx(texture, position, 0.0f, 1.0f, WHITE);
        }

        DrawTexture(texture,position.x,position.y,WHITE);
    }
};