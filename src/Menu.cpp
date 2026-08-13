#include "Menu.hpp"

#include "raylib.h"

namespace skibidi
{
    void Menu::onEnter()
    {
        TraceLog(LOG_INFO, "Entrando al Menu");
    }

    void Menu::onExit()
    {
        TraceLog(LOG_INFO, "Saliendo del Menu");
    }

    void Menu::Update()
    {
        // Movimiento de la pelota
        circle.Update(GetFrameTime());

        // Muestra u oculta el menu GUI
        if (IsKeyPressed(KEY_M))
        {
            menuGUI.toggle();
        }
    }

    void Menu::Draw()
    {
        DrawText(
            "MENU",
            350,
            40,
            30,
            WHITE
        );

        DrawText(
            "M = Mostrar/Ocultar GUI",
            20,
            550,
            20,
            LIGHTGRAY
        );

        // Pelota
        circle.Draw();

        // Interfaz
        menuGUI.draw();
    }
}