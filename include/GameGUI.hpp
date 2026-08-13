#pragma once

#include "Canvas.hpp"
#include "even_bus.hpp"

namespace skibidi
{
    class MenuGUI : public Canvas
    {
    public:

        MenuGUI() = default;
        ~MenuGUI() = default;

        void drawGUI() override
        {
            // BOTON START GAME
            if (GuiButton(
                Rectangle{ 100.0f, 100.0f, 200.0f, 50.0f },
                "Start Game"
            ))
            {
                // Disparamos el evento
                EventData data;

                data.name = "Start Button";
                data.tag = "Menu";

                EventBus::get().fire(
                    "start_game",
                    data
                );
            }


            // BOTON OPTIONS
            GuiButton(
                Rectangle{ 100.0f, 200.0f, 200.0f, 50.0f },
                "Options"
            );


            // BOTON EXIT
            GuiButton(
                Rectangle{ 100.0f, 300.0f, 200.0f, 50.0f },
                "Exit"
            );


            // BOTON CREDITS
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