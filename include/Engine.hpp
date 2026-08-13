#pragma once
#include "raylib.h"
#include "resource_dir.h"	// utility header for SearchAndSetResourceDir
#include "Circle.hpp"
#include "Menu.hpp"
#include "Scene.hpp"
#include "scene_manager.hpp"
#include "Play.hpp"

namespace skibidi
{

	class Engine
	{
	public:
		Engine();
		~Engine();

		//Circle circle;
		Texture wabbit;
		Menu menu;
		SceneManager sceneManager;
		Play play;

		void Init();
		void run();
		void Update();
		void Draw();
		void Shutdown();

	private:
		Vector2 position = { 50.0f, 50.0f };
		Vector2 velocity = { 100.0f, 100.0f };
		static const int screenWidth = 800;
		static const int screenHeight = 600;
		//static constexpr int circlesCount = 10;


	};
}
