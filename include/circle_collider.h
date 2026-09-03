#pragma once
#include "raylib.h"
#include "raymath.h"

namespace skibidi
{
	class CircleCollider
	{
	public:
		Vector2 center = { 0.0f, 0.0f };
		float radius = 0.0f;

		CircleCollider(float r = 10.0f) : radius(r) {}

		void update(Vector2 pos)
		{
			center = pos;
		}

		bool colliders(CircleCollider& other)
		{
			return Vector2Distance(center, other.center) <= (radius + other.radius);
		}

		void debugDraw(Color color = GREEN)
		{
			DrawCircleLines((int)center.x, (int)center.y, radius, color);
			DrawCircleV(center, 2.0f, color);
		}

	};
}