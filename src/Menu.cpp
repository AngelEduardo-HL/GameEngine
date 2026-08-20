#include "Menu.hpp"

#include "raylib.h"

#include "scene_manager.hpp"


namespace skibidi
{
    Menu::Menu()
    {
        listen(
            "start_game"
        );
    }


    void Menu::OnInit()
    {
        // Mostrar GUI al iniciar Menu
        menuGUI.show();
    }


    void Menu::OnEnter()
    {
        TraceLog(
            LOG_INFO,
            "Entrando al Menu"
        );
    }


    void Menu::Update()
    {
        // Movimiento de la pelota
        circles.MoveCircle(
            GetScreenWidth(),
            GetScreenHeight()
        );


        // Mostrar u ocultar GUI
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


        // GUI
        menuGUI.draw();


        // Pelota
        circles.DrawCircle();
    }


    void Menu::OnExit()
    {
        TraceLog(
            LOG_INFO,
            "Saliendo del Menu"
        );
    }


    void Menu::onEvent(
        EventData data
    )
    {
        if (data.type == "start_game")
        {
            TraceLog(
                LOG_INFO,
                "Evento start_game recibido"
            );


            SceneManager::get().changeScene(
                "play"
            );
        }
    }
}