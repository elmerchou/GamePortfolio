#pragma once
#include "GameDef.h"
#include "Fwk/Graphics.h"
#include "AppDef.h"
#include "App.h"

class Scene {
public:
	virtual void Init();
	virtual void Term();
	virtual void Update();
	virtual void Render();
	SceneType GetNextScene();

protected:
	SceneType mNextScene;
	Sprite gameSprite;
};