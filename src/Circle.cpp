#include "Circle.hpp"

Circle::Circle()
{
    position = { 400.0f, 300.0f };
    vel = { 200.0f, 150.0f };

    rad = 30.0f;

    color = PINK;
}


void Circle::DrawCircle()
{
    DrawCircleV(
        position,
        rad,
        color
    );
}


void Circle::MoveCircle(
    int screenWidth,
    int screenHeight
)
{
    float deltaTime = GetFrameTime();

    position.x += vel.x * deltaTime;
    position.y += vel.y * deltaTime;


    // IZQUIERDA
    if (position.x - rad <= 0)
    {
        position.x = rad;
        vel.x = -vel.x;

        ChangeColor();
    }

    // DERECHA
    else if (position.x + rad >= screenWidth)
    {
        position.x = screenWidth - rad;
        vel.x = -vel.x;

        ChangeColor();
    }


    // ARRIBA
    if (position.y - rad <= 0)
    {
        position.y = rad;
        vel.y = -vel.y;

        ChangeColor();
    }

    // ABAJO
    else if (position.y + rad >= screenHeight)
    {
        position.y = screenHeight - rad;
        vel.y = -vel.y;

        ChangeColor();
    }
}


void Circle::ChangeColor()
{
    Color colors[] =
    {
        PINK,
        SKYBLUE,
        BEIGE,
        YELLOW,
        VIOLET,
        ORANGE,
        MAGENTA,
        LIME
    };

    color = colors[
        GetRandomValue(0, 7)
    ];
}