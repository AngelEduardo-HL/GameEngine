#pragma once

#include "Canvas.hpp"

namespace skibidi
{
    class MenuGUI : public Canvas
    {
    public:

        MenuGUI() = default;
        ~MenuGUI() = default;

        void drawGUI() override
        {
            GuiButton(
                Rectangle{ 100.0f, 100.0f, 200.0f, 50.0f },
                "Play"
            );

            GuiButton(
                Rectangle{ 100.0f, 200.0f, 200.0f, 50.0f },
                "Options"
            );

            GuiButton(
                Rectangle{ 100.0f, 300.0f, 200.0f, 50.0f },
                "Exit"
            );

            GuiButton(
                Rectangle{ 100.0f, 400.0f, 200.0f, 50.0f },
                "Credits"
            );
        }
    };

    class PlayGUI : public Canvas
    {
    public:

        PlayGUI() = default;
        ~PlayGUI() = default;

        void drawGUI() override
        {

        }
    };
}