#pragma once
#include "Scene.hpp"

namespace skibidi
{
	class Menu : public Scene
	{
	public:
		~Menu() = default;

		void onEnter() override;
		void onExit() override;
		void Update() override;
		void Draw() override;

	};
}

