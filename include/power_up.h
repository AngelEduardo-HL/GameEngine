#pragma once

#include "entity.h"
#include "raylib.h"

class PowerUp : public Entity
{
public:
    float speed = 120.0f;
    float radius = 14.0f;

    PowerUp()
    {
        name = "Double Shot PowerUp";
        active = false;
        collider.radius = radius;
        collider.update(position);
    }

    void spawn(Vector2 spawnPosition)
    {
        setPosition(spawnPosition);
        setActive(true);
    }

    void update() override
    {
        if (!active)
        {
            return;
        }

        position.y += speed * GetFrameTime();
        updateCollider();

        if (position.y - radius > GetScreenHeight())
        {
            active = false;
        }
    }

    void draw() override
    {
        if (!active)
        {
            return;
        }

        DrawCircleV(position, radius, GOLD);
        DrawCircleLines(static_cast<int>(position.x), static_cast<int>(position.y), radius, YELLOW);

        DrawText("2X", static_cast<int>(position.x - 10.0f), static_cast<int>(position.y - 7.0f), 14, BLACK);

        if (debugCollider)
        {
            collider.debugDraw(YELLOW);
        }
    }
};