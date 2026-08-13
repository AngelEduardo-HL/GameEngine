#pragma once

#include "Scene.hpp"

#include"even_bus.hpp"
#include "player.hpp"

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
		//void onEvent(EventData data) override;

        int eventId_01;
		int eventId_02;

        int playerScore;
        int grabCoinEvId;
    };
}