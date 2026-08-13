#pragma once

#include "raylib.h"
#include "raygui.h"

namespace skibidi
{
    class Canvas
    {
    public:

        virtual ~Canvas() = default;

        void draw()
        {
            if (isActive)
            {
                drawGUI();
            }
        }

        virtual void drawGUI() = 0;

        void setPosition(float x, float y)
        {
            position = { x, y };
        }

        void setSize(float width, float height)
        {
            size = { width, height };
        }

        void setActive(bool active)
        {
            isActive = active;
        }

        void show()
        {
            isActive = true;
        }

        void hide()
        {
            isActive = false;
        }

        void toggle()
        {
            isActive = !isActive;
        }

        bool getIsActive() const
        {
            return isActive;
        }

    protected:

        Vector2 position = { 0.0f, 0.0f };
        Vector2 size = { 0.0f, 0.0f };

        bool isActive = false;
    };
}