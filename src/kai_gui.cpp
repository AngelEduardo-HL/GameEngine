#include "kai_gui.hpp"

#include "raylib.h"
#include "raygui.h"

#include "EventBus.hpp"


namespace skibidi
{
    MenuGUI::MenuGUI()
    {
        position =
        {
            GetScreenWidth() / 2.0f,
            GetScreenHeight() / 2.0f
        };
    }


    void MenuGUI::drawGUI()
    {
        // PLAY
        if (GuiButton(
            Rectangle
            {
                100.0f,
                100.0f,
                200.0f,
                50.0f
            },
            "Play"
        ))
        {
            EventData data;

            data.name = "Play Button";
            data.tag = "Menu";

            EventBus::get().fire(
                "start_game",
                data
            );
        }


        // OPTIONS
        GuiButton(
            Rectangle
            {
                100.0f,
                200.0f,
                200.0f,
                50.0f
            },
            "Option"
        );


        // EXIT
        GuiButton(
            Rectangle
            {
                100.0f,
                300.0f,
                200.0f,
                50.0f
            },
            "Exit"
        );


        // CREDITS
        GuiButton(
            Rectangle
            {
                100.0f,
                400.0f,
                200.0f,
                50.0f
            },
            "Credits"
        );
    }


    PlayGUI::PlayGUI()
    {

    }


    void PlayGUI::drawGUI()
    {

    }
}