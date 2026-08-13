#pragma once
#include "Play.hpp"
#include "Scene.hpp"
#include "scene_manager.hpp"

namespace skibidi
{
	class Play : public Scene
	{
	public:
		~Play() = default;
		void onEnter() override;
		void onExit() override;
		void Update() override;
		void Draw() override;
	//private:
	//	Circle circle{ 100, 100, 50, 40, 20, RED };
	};
}