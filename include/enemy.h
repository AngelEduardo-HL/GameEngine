#pragma once
#include "entity.h"
#include "raylib.h"
#include "resources_manager.h"

using namespace skibidi;

class Enemy : public Entity {
public:
	float speed = 0.5f;
	int radius = 15;

	Enemy() {
		name = "Enemy";
		active = true;
		texture = ResourcesManager::get().getTexture("Tantive_I.png");

		collider.radius = 65.0f;
		collider.update(position);

	}

	void update() override {
		if (!active) return;
		position.y += speed;

		if (position.y >= GetScreenHeight() + radius) {
			active = false;
		}

		if (debugCollider) {
			collider.debugDraw(PURPLE);
		}
	}

	void draw() override {
		if (isActive() && texture.id != 0) {
			Vector2 pos = { position.x - texture.width / 2.0f, position.y - texture.height / 2.0f };
			DrawTextureEx(texture, pos, 0.0f, 1.0f, WHITE);
		}
	}

};
