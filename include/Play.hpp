#pragma once

#include "Scene.hpp"

namespace skibidi
{
    class Play : public Scene
    {
    public:

        Play() = default;
        ~Play() = default;

        void onEnter() override;
        void onExit() override;

        void Update() override;
        void Draw() override;
    };
}