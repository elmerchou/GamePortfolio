#include "Scene.h"

void Scene::Init() {
	mNextScene = SceneType::None;
	gameSprite.Init();
	gameSprite.SetSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	gameSprite.SetPosition(WINDOW_WIDTH / 2, -WINDOW_HEIGHT / 2);
}
void Scene::Update() {}
void Scene::Term() {}
void Scene::Render() {}
SceneType Scene::GetNextScene() {
	return mNextScene;
}