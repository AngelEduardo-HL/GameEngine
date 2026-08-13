#include "Menu.hpp"
#include "raylib.h"

namespace skibidi
{
	void Menu::onEnter()
	{

	}

	void Menu::onExit()
	{
	}

	void Menu::Update()
	{
	}

	void Menu::Draw()
	{
		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(BLACK);

		// draw some text using the default font
		DrawText("Hello Raylib", 200, 200, 20, WHITE);

		// draw our texture to the screen
		DrawCircle(400, 200, 50, RED);

		// Update the circle's position based on its velocity and delta time
		//circle.Update(GetFrameTime());

		// Draw the circle to the screen
		//circle.Draw();
		//TraceLog(LOG_INFO, "Se dibuja el circulo!!");
	}
}