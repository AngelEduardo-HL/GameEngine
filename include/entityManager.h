#pragma once
#include "entity.h"
#include <vector>

class EntityManager {
public:
	std::vector<Entity*> entities;

	EntityManager() = default;

	void add(Entity* entity) {
		if (entity != nullptr) {
			entities.push_back(entity);
		}
	}

	void update() {
		for(Entity* entity : entities) {
			if (entity && entity->active) {
				entity->update();
			}
		}
	}

	void draw() {
		for(Entity* entity : entities) {
			if (entity && entity->active) {
				entity->draw();
			}
		}
	}

	void clear() {
		for(Entity* entity : entities) {
			if (entity) {
				delete entity;
			}
		}
		entities.clear();
	}
};
