#pragma once

#include "Scene.hpp"
#include "Circle.hpp"
#include "kai_gui.hpp"
#include "EventBus.hpp"


namespace skibidi
{
    class Menu :
        public Scene,
        public EventListener
    {
    private:

        MenuGUI menuGUI;

        int playEventId = 0;


    public:

        Circle circles;


        Menu();

        ~Menu() override = default;


        void OnInit() override;

        void OnEnter() override;

        void Update() override;

        void Draw() override;

        void OnExit() override;


        void onEvent(
            EventData data
        ) override;
    };
}