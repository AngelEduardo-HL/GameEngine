#pragma once
#include "raylib.h"
#include <string>

class Entity {

public:

	std::string name = "";
	Vector2 position = { 0.0f, 0.0f };
	bool active = true;
	Texture2D texture;

	Entity() = default;
	virtual ~Entity() = default;

	virtual void update() {};
	virtual void draw() {};
	void setPosition(float x, float y) {
		position.x = x;
		position.y = y;
	}
	void setPosition(Vector2 pos) {
		position = pos;
	}
	bool isActive() const {
		return active;
	}

};