#pragma once

#include "entity.h"
#include "raylib.h"


class Bullet : public Entity
{
public:

    float speed = 350.0f;

    float radius = 4.0f;

    Bullet()
    {
        name = "Bullet";

        active = false;

        collider.radius = radius;

        collider.update(position);
    }

    void fire(Vector2 startPosition)
    {
        setPosition(startPosition);
        setActive(true);
    }

    void update() override
    {
        if (!active)
        {
            return;
        }

        position.y -= speed * GetFrameTime();

        updateCollider();

        if (position.y + radius < 0.0f)
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

        DrawCircleV(position,radius,GREEN);

        if (debugCollider)
        {
            collider.debugDraw(YELLOW);
        }
    }
};