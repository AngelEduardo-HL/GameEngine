#include "raylib.h"
#include "resource_dir.h"	// utility header for SearchAndSetResourceDir

#include "Engine.hpp"
#include "Circle.hpp"

namespace skibidi
{

	Engine::Engine()
	{

	}

	Engine::~Engine()
	{

	}

	void Engine::Init()
	{
		// Tell the window to use vsync and work on high DPI displays
		SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

		// Create the window and OpenGL context
		InitWindow(screenHeight, screenWidth, "Hello Raylib");
		TraceLog(LOG_INFO, "Se creo chido rey");

		// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
		SearchAndSetResourceDir("resources");

		sceneManager.changeScene(&menu); //Copia la dirección de memoria del menu y la pasa a sceneManager

		menu.onEnter();

		Circle circle(100, 100, 50, 40, 20, RED);
		TraceLog(LOG_INFO, "Si se seteo el circculo");

		// Load a texture from the resources directory
		Texture wabbit = LoadTexture("wabbit_alpha.png");

	}

	void Engine::run()
	{
		// game loop
		while (!WindowShouldClose())		// run the loop until the user presses ESCAPE or presses the Close button on the window
		{
			Update();	// update the game logic
			Draw();		// draw the game
		}
	}

	void Engine::Update()
	{
		//Hace el upadte
		menu.Update();
		sceneManager.Update();

		if(IsKeyPressed(KEY_SPACE))
		{
			sceneManager.changeScene(&play);
			TraceLog(LOG_INFO, "Cambio de Scene");
		}
		if(IsKeyPressed(KEY_M))
		{
			sceneManager.changeScene(&menu);
			TraceLog(LOG_INFO, "Cambio a menu");
		}
	}

	void Engine::Draw()
	{
		//Update y Draw
		// drawing
		BeginDrawing();

		sceneManager.Draw();
		menu.Draw();

		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	void Engine::Shutdown()
	{
		//Cierra el juego
		// destroy the window and cleanup the OpenGL context
		UnloadTexture(wabbit);

		menu.onExit();

		CloseWindow();
	}
}