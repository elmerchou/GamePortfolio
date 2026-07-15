#pragma once
#include "Scene.h"

class SceneTitle :public Scene{
	enum MENU {
		PLAY,
		HELP,
};

public:
	void Init();
	void Term();
	void Update();
	void Render();

private:
	Texture gamestart;
	bool isDisplay;
	float menuTimer;
	int selected;
	Texture gameHelp;
	Sprite help;
};