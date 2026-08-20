#include "Menu.hpp"

#include "raylib.h"
#include "scene_manager.hpp"

namespace skibidi
{
    Menu::Menu()
    {
        listen("start_game");
    }


    void Menu::OnInit()
    {
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
        circle.Update(
            GetFrameTime()
        );


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


        circle.Draw();

        menuGUI.draw();
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