#pragma once
#include "Scene.hpp"

namespace skibidi
{
	class SceneManager
	{
	public:
		SceneManager() = default;
		~SceneManager() = default;

		void changeScene(Scene* newScene)
		{
			if (currentScene)
			{
				currentScene->onExit();
			}
			currentScene = newScene;
			if (currentScene)
			{
				currentScene->onEnter();
			}
		}

		void Update()
		{
			if (currentScene)
			{
				currentScene->Update();
			}
		}

		void Draw()
		{
			if (currentScene)
			{
				currentScene->Draw();
			}
		}

	private:
		Scene* currentScene = nullptr;
	};
}