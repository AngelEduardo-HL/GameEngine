#pragma once
#include "entity.h"

class Bullet : public Entity {
public:
		float speed = 20.0f;
		Bullet() = default;

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

		//========= Con Textura =========
		/*Bullet() {
			name = "Bullet";
			active = true;
			position = { 400.0f, 300.0f };
			texture = LoadTexture("bullet.png");
		}
		~Bullet() {
			UnloadTexture(texture);
		}*/

		/*void update() override {
			position.y -= speed * GetFrameTime();
			if (position.y < 0) {
				active = false;
			}
		}
		void draw() override {
			if (!isActive() || texture.id == 0) {
				return;
			}
			DrawTexture(texture, position.x, position.y, WHITE);
		}*/

};
