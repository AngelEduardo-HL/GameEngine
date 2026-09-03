#pragma once
#include "entity.h"
#include "raylib.h"

class Bullet : public Entity {
public:
		float speed = 20.0f;
		float radius = 2.0f;

		Bullet() {
			active = false;
			collider.radius = radius;
		}

		void update() override {
			if (!active) return;

			position.y -= speed * GetFrameTime();

			if(position.y <= 0.0f) {
				active = false;
			}
		}

		void draw() override {
			DrawCircleV(position, 2.0f, GREEN);
		}

};
