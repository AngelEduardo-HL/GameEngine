//#pragma once
//#include <raylib.h>
//#include "even_bus.hpp"
//
//class Player {
//public:
//	void grabCoin() {
//		// Dispara un evento para notificar que se ha recogido una moneda
//		EventData data;
//		data.type = "grab_coin";
//		EventBus::get().fire("grab_coin", data);
//	}
//
//	void enemyHit() {
//		// Dispara un evento para notificar que el jugador ha sido golpeado por un enemigo
//		EventData data;
//		data.type = "enemy_hit";
//		EventBus::get().fire("enemy_hit", data);
//	}
//
//	void playerHit() {
//		// Dispara un evento para notificar que el jugador ha sido golpeado
//		EventData data;
//		data.type = "player_hit";
//		data.intVal = 20;
//		EventBus::get().fire("player_hit", data);
//	}
//
//};
