#pragma once
#include "EventBus.hpp"
#include "scene_manager.hpp"

class GameManager : public EventListener 
{
public:
	int max_kills = 10;
	int curret_kills = 0;
	int player_lives = 3;

	void init() {
		reset();
		listen("player_kill");
		listen("enemy_kill");
	}

	void exit() {
		EventBus::get().unbind("player_kill", 0);
		EventBus::get().unbind("enemy_kill", 0);
	}

	void onEnemyHit() {
		curret_kills++;
		TraceLog(LOG_INFO, "Enemy killed. Current kills: %i", curret_kills);
		if (curret_kills > max_kills) {
			skibidi::SceneManager::get().changeScene("win");
		}

	}

	void onPlayerHit() {
		player_lives--;
		TraceLog(LOG_INFO, "Player hit. Remaining lives: %i", player_lives);
		if (player_lives <= 0) {
			skibidi::SceneManager::get().changeScene("loose");
		}
	}

	void onEvent(EventData data) override {
		if (data.type == "player_kill") {
			onPlayerHit();
		}

		if(data.type == "enemy_kill") {
			onEnemyHit();
		}
	}

	void reset() {
		curret_kills = 0;
		player_lives = 3;
	}
};
