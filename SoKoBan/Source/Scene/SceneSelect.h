#pragma once
#include "Scene.h"
#include "GameDef.h"

class SceneSelect :public Scene{
public:
	void Init();
	void Term();
	void Update();
	void Render();

private:
	int mSeletedIndex;
	int stageAmount;
	float timer;
	bool isDisplay;
};