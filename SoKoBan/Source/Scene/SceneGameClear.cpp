#include "SceneGameClear.h"

void SceneGameClear::Init() {
	Scene::Init();
	gameClear.Load("Images/gameend.png");
	gameSprite.SetTexture(gameClear);
	gameSprite.SetAlpha(1.0f);
}
void SceneGameClear::Update() {
	if (Input_I->IsKeyUp(VK_RETURN)) {
		mNextScene = SceneType::Title;
	}
}
void SceneGameClear::Term() {
	gameClear.Unload();
	gameSprite.Term();
}
void SceneGameClear::Render() {
	gameSprite.Draw();
}
