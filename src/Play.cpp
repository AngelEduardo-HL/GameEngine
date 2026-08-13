#include "Play.hpp"

#include "raylib.h"

namespace skibidi
{
    void Play::onEnter()
    {
        TraceLog(LOG_INFO, "Entrando a Play");
    }

    void Play::onExit()
    {
        TraceLog(LOG_INFO, "Saliendo de Play");
    }

    void Play::Update()
    {

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
}