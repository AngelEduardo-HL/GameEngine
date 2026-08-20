#pragma once

#include "raylib.h"

class Circle
{
public:

    Circle();
    ~Circle() = default;

    void DrawCircle();

    void MoveCircle(
        int screenWidth,
        int screenHeight
    );

    void ChangeColor();


    Vector2 position;
    Vector2 vel;

    float rad;
    Color color;
};