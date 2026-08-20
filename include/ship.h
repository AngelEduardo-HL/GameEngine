#pragma once
#include "entity.h"

class Ship : public Entity {
public:

	float speed = 25.0f;

	Ship() {
		name = "Ship";
		active = true;
		position = { 400.0f, 300.0f };
		texture = LoadTexture("resources/546Crusier.png");
	}

	~Ship() {
		UnloadTexture(texture);
	}

	void update() override {
		
		if (IsKeyDown(KEY_W)) {
			position.y -= speed * GetFrameTime();
		}
		if (IsKeyDown(KEY_S)) {
			position.y += speed * GetFrameTime();
		}
		if (IsKeyDown(KEY_A)) {
			position.x -= speed * GetFrameTime();
		}
		if (IsKeyDown(KEY_D)) {
			position.x += speed * GetFrameTime();
		}


	}

	void draw() override {

		if (!isActive() || texture.id != 0) {
			return;
		}
		DrawTexture(texture, position.x, position.y, WHITE);

	}

};
