#pragma once
#include "raylib.h"
#include "resources_manager.h"

using namespace skibidi;

class Score {

public:
	int scorePoints = 0;
	int playerLives = 3;

	Vector2 position = { 10.0f, 10.0f };
	Font scoreFont;

	Score() {
		scorePoints = 0;
		position = { 10.0f, 10.0f };
		scoreFont = ResourcesManager::get().getFont("SpaceFont3.ttf");
	}

	void addPoint() {
		scorePoints++;
	}

	void shipKilled() {
		playerLives--;
	}

	void draw() {
		DrawTextEx(scoreFont, std::to_string(scorePoints).c_str(), position, 20.0f, 0.0f, WHITE);
		DrawTextEx(scoreFont, ("Lives: " + std::to_string(playerLives)).c_str(), { position.x, position.y + 30.0f }, 20.0f, 0.0f, WHITE);
	}
		
};
