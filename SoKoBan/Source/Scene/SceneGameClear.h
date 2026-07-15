#pragma once
#include "Scene.h"

class SceneGameClear:public Scene {
public:
	void Init();
	void Term();
	void Update();
	void Render();

private:
	Texture gameClear;
};