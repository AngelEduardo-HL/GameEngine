#pragma once

#include "raylib.h"
#include <string>

#include "circle_collider.h"

using skibidi::CircleCollider;


class Entity
{
public:

    std::string name = "";

    Vector2 position =
    {
        0.0f,
        0.0f
    };

    bool active = true;
    bool debugCollider = true;
    Texture2D texture = {};
    CircleCollider collider;

    Entity() = default;

    virtual ~Entity() = default;

    virtual void update()
    {

    }


    virtual void draw()
    {

    }

    void setPosition(float x,float y)
    {
        position.x = x;
        position.y = y;

        collider.update(position);
    }


    void setPosition(Vector2 pos)
    {
        position = pos;

        collider.update(position);
    }


    Vector2 getPosition() const
    {
        return position;
    }

    bool isActive() const
    {
        return active;
    }


    void setActive(bool value)
    {
        active = value;
    }

    void updateCollider()
    {
        collider.update(position);
    }


    bool collidesWith(Entity& other)
    {
        return collider.colliders(other.collider);
    }
};