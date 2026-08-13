#include "Play.hpp"

#include "raylib.h"

namespace skibidi
{
    void Play::onEnter()
    {
        TraceLog(LOG_INFO, "Entrando a Play");

		//listen("grab_coin");
    }

    void Play::onExit()
    {
        TraceLog(LOG_INFO, "Saliendo de Play");
    }

    void Play::Update()
    {
        if (IsKeyPressed(KEY_C))
        {
			//player.GrabCoin();
		}
        if (IsKeyPressed(KEY_BACKSPACE))
        {

		}
        if (IsKeyPressed(KEY_SPACE))
        {

		}
    }

    void Play::Draw()
    {
        DrawText(
            "PLAY",
            350,
            250,
            40,
            GREEN
        );

        DrawText(
            "BACKSPACE = Regresar al Menu",
            220,
            320,
            20,
            WHITE
        );
    }

    /*void Play::onEvent(EventData data)
    {
        if (data.type == "grab_coin")
        {
            playerScore += 10;
            TraceLog(LOG_INFO, "Moneda recogida! Puntuación: %d", playerScore);
        }
        else if (data.type == "enemy_hit")
        {
            playerScore -= 5;
            TraceLog(LOG_INFO, "Golpeado por un enemigo! Puntuación: %d", playerScore);
        }
        else if (data.type == "player_hit")
        {
            playerScore -= data.intVal;
            TraceLog(LOG_INFO, "Jugador golpeado! Puntuación: %d", playerScore);
        }
	}*/
}