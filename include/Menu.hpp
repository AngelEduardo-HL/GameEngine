#pragma once

#include "Scene.hpp"
#include "Circle.hpp"
#include "GameGUI.hpp"

namespace skibidi
{
    class Menu : public Scene
    {
    public:

        Menu() = default;
        ~Menu() = default;

        void onEnter() override;
        void onExit() override;

        void Update() override;
        void Draw() override;

    private:

        Circle circle
        {
            400.0f,
            300.0f,
            30.0f,
            200.0f,
            150.0f,
            PINK
        };

        MenuGUI menuGUI;
    };
}