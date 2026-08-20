#include "Play.hpp"

#include "raylib.h"
#include "scene_manager.hpp"


namespace skibidi
{
    void Play::OnInit()
    {
        if (!eventsBound)
        {
            listen("grab_coin");
            listen("enemy_hit");
            listen("player_hit");

            eventsBound = true;
        }
    }


    void Play::OnEnter()
    {
        TraceLog(
            LOG_INFO,
            "Entrando a Play"
        );
    }


    void Play::Update()
    {
        // C = recoger moneda
        if (IsKeyPressed(KEY_C))
        {
            player.GrabCoin();
        }


        // E = enemigo golpeado
        if (IsKeyPressed(KEY_E))
        {
            player.EnemyHit();
        }


        // P = jugador golpeado
        if (IsKeyPressed(KEY_P))
        {
            player.PlayerHit();
        }


        // Regresar al Menu
        if (IsKeyPressed(KEY_BACKSPACE))
        {
            SceneManager::get().changeScene(
                "menu"
            );
        }
    }


    void Play::Draw()
    {
        DrawText(
            "PLAY",
            350,
            150,
            40,
            WHITE
        );


        DrawText(
            "C = Grab Coin",
            300,
            250,
            20,
            WHITE
        );


        DrawText(
            "E = Enemy Hit",
            300,
            285,
            20,
            WHITE
        );


        DrawText(
            "P = Player Hit",
            300,
            320,
            20,
            WHITE
        );


        DrawText(
            "BACKSPACE = Menu",
            300,
            380,
            20,
            WHITE
        );
    }


    void Play::OnExit()
    {
        TraceLog(
            LOG_INFO,
            "Saliendo de Play"
        );
    }


    void Play::onEvent(
        EventData data
    )
    {
        if (data.type == "grab_coin")
        {
            TraceLog(
                LOG_INFO,
                "Se agarro una moneda"
            );
        }

        else if (data.type == "enemy_hit")
        {
            TraceLog(
                LOG_INFO,
                "Enemigo golpeado"
            );
        }

        else if (data.type == "player_hit")
        {
            TraceLog(
                LOG_INFO,
                "El jugador fue golpeado"
            );
        }
    }
}