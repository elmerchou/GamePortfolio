#pragma once
#include "Scene.h"


class SceneManager{
public:
	void Init(SceneType startScene);
	void Term();
	void Update();
	void Render();

private:
	void _biginScene(SceneType newScene);
	void _endCurrentScene();

	SceneType mCurrentScene;
	SceneType mNextScene;
	Scene* pScene;
};