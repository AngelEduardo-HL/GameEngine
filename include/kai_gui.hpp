#pragma once

#include "Canvas.hpp"

namespace skibidi
{
    class MenuGUI : public Canvas
    {
    public:

        MenuGUI();
        ~MenuGUI() = default;

        void drawGUI() override;

        int playBttnId = 0;
    };


    class PlayGUI : public Canvas
    {
    public:

        PlayGUI();
        ~PlayGUI() = default;

        void drawGUI() override;
    };
}