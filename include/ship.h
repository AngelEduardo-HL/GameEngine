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
        position = {400.0f,300.0f};

        texture = skibidi::ResourcesManager::get().getTexture("546Crusier.png");

        collider.radius = 100.0f;

        collider.update(position);
    }


    ~Ship()
    {

    }

    void update() override
    {
        if (!active)
        {
            return;
        }


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

        updateCollider();
    }


    void draw() override
    {
        if (!active ||texture.id == 0)
        {
            return;
        }

        Vector2 drawPosition = {position.x - texture.width / 2.0f,position.y - texture.height / 2.0f};

        DrawTextureV(texture,drawPosition,WHITE);

        if (debugCollider)
        {
            collider.debugDraw(RED);
        }
    }


    Vector2 getMuzzlePosition() const
    {
        return
        {
            position.x,

            position.y -
                texture.height / 2.0f
        };
    }
};