#include "Circle.hpp"

Circle::Circle(
    float x,
    float y,
    float radius,
    float velx,
    float vely,
    Color color
)
{
    position = { x, y };
    velocity = { velx, vely };

    this->radius = radius;
    this->color = color;
}

void Circle::Update(float dt)
{
    position.x += velocity.x * dt;
    position.y += velocity.y * dt;

    CollisionCircle(
        static_cast<float>(GetScreenWidth()),
        static_cast<float>(GetScreenHeight())
    );
}

void Circle::Draw() const
{
    DrawCircleV(position, radius, color);
}

void Circle::CollisionCircle(float screenWidth, float screenHeight)
{
    // Izquierda
    if (position.x - radius <= 0)
    {
        position.x = radius;
        velocity.x *= -1;

        ChangeColor();

        //TraceLog(LOG_INFO, "La pelota pego a la izquierda");
    }

    // Derecha
    else if (position.x + radius >= screenWidth)
    {
        position.x = screenWidth - radius;
        velocity.x *= -1;

        ChangeColor();

        //TraceLog(LOG_INFO, "La pelota pego a la derecha");
    }

    // Arriba
    if (position.y - radius <= 0)
    {
        position.y = radius;
        velocity.y *= -1;

        ChangeColor();

        //TraceLog(LOG_INFO, "La pelota pego arriba");
    }

    // Abajo
    else if (position.y + radius >= screenHeight)
    {
        position.y = screenHeight - radius;
        velocity.y *= -1;

        ChangeColor();

        //TraceLog(LOG_INFO, "La pelota pego abajo");
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

    int randomColor = GetRandomValue(0, 7);

    color = colors[randomColor];
}