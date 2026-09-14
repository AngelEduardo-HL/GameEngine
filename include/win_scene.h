#pragma once
#include "scene_manager.hpp"

using namespace skibidi;

class WinScene : public Scene {
	// Heredado vía Scene
	void OnInit() override;
	void OnEnter() override;
	void Update() override;
	void Draw() override;
	void OnExit() override;
};
