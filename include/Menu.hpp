#ifndef SKIBIDI_MENU_HPP
#define SKIBIDI_MENU_HPP

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

        Circle circle
        {
            400.0f,
            300.0f,
            30.0f,
            200.0f,
            150.0f,
            PINK
        };

    public:

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

#endif