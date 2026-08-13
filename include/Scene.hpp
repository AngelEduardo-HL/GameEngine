#pragma once

namespace skibidi
{
	class Scene
	{
		public:
		virtual ~Scene() = default;

		virtual void onEnter() = 0;
		virtual void onExit() = 0;
		virtual void Update() = 0;
		virtual void Draw() = 0;

	};
}

