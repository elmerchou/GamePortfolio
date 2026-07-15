#pragma once
#include "Scene.h"
#include "Fwk/Graphics.h"
#include "AppDef.h"
#include "App.h"

class SceneInGame :public Scene {
public:
	void Init();
	void Term();
	void Update();
	void Render();

private:
	Texture stageClear;
	int stageNum;
	bool isSoundPlayed;
};