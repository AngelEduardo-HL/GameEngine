#include "Play.hpp"

#include "raylib.h"
#include "scene_manager.hpp"
#include <iostream>

namespace skibidi
{
    void Play::OnInit()
    {
        if (!eventsBound)
        {
            listen("grab_coin");
            listen("enemy_hit");
            listen("player_hit");

			ship = new Ship();
			ship2 = new Ship();

			bullet = new Bullet();

			ship->setPosition(10, 20);
			ship2->setPosition(150, 225);

			bullet->setPosition(400, 300);

			entityMgr.add(ship);
			entityMgr.add(ship2);
			entityMgr.add(bullet);


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
		entityMgr.update();

        // Recoger moneda
        if (IsKeyPressed(KEY_C))
        {
            player.GrabCoin();
        }


        // Golpear enemigo
        if (IsKeyPressed(KEY_E))
        {
            player.EnemyHit();
        }


        // Jugador recibe golpe
        if (IsKeyPressed(KEY_P))
        {
            player.PlayerHit();
        }


        // Regresar al menu
        if (IsKeyPressed(KEY_BACKSPACE))
        {
            SceneManager::get().changeScene(
                "menu"
            );
        }
    }


    void Play::Draw()
    {
		entityMgr.draw();

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
            playerScore++;

            TraceLog(
                LOG_INFO,
                "Evento: grab_coin"
            );
        }

        else if (data.type == "enemy_hit")
        {
            TraceLog(
                LOG_INFO,
                "Evento: enemy_hit"
            );
        }

        else if (data.type == "player_hit")
        {
            TraceLog(
                LOG_INFO,
                "Evento: player_hit"
            );
        }
    }
}