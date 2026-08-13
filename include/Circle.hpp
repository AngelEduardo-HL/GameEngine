#pragma once
#include "raylib.h"

class Circle
{
public:
    Circle(float x, float y, float radius, float velx, float vely, Color color);

    void Update(float dt);

    // Dibuja el círculo en pantalla
    void Draw() const;

private:
    Vector2 position;
    Vector2 velocity;
    float radius;
    Color color;

	void CollisionCircle(float screenWidth, float screenHeight);
};

