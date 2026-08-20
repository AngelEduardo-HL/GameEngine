#include "raylib.h"
#include "Engine.hpp"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"


int main()
{
    skibidi::Engine engine;

    engine.Init();
    engine.Run();
    engine.Shutdown();

    return 0;
}