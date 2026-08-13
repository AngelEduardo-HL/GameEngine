#include "Circle.hpp"
#include <algorithm>
#include "Engine.hpp"

Circle::Circle(float x, float y, float radius, float velx, float vely, Color color)
{
    float screenWidth = static_cast<float>(GetScreenWidth());
    float screenHeight = static_cast<float>(GetScreenHeight());

    position = Vector2{ x, y };
    velocity = Vector2{ velx, vely };
    this->radius = radius;
    this->color = color;

    CollisionCircle(screenWidth, screenHeight);
}

void Circle::Update(float dt)
{
    position.x += velocity.x * dt;
    position.y += velocity.y * dt;

    CollisionCircle(static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight()));
}

void Circle::Draw() const
{
    DrawCircleV(position, radius, color);
}

void Circle::CollisionCircle(float screenWidth, float screenHeight)
{
	//Izquierda y derecha
    if (position.x - radius < 0)
    {
        position.x = radius;
        velocity.x *= -1;

		TraceLog(LOG_INFO, "Skibidi pego izquierda");
    }
    else if (position.x + radius > screenWidth)
    {
        position.x = screenWidth - radius;
        velocity.x *= -1;

		TraceLog(LOG_INFO, "Skibidi pego derecha");
    }

	//Arriba y abajo
    if (position.y - radius < 0)
    {
        position.y = radius;
        velocity.y *= -1;

		TraceLog(LOG_INFO, "Skibidi pego arriba");
    }
    else if (position.y + radius > screenHeight)
    {
        position.y = screenHeight - radius;
        velocity.y *= -1;

		TraceLog(LOG_INFO, "Skibidi pego abajo");
	}
}