#include "SceneTitle.h"


void SceneTitle::Init() {
	Scene::Init();
	gamestart.Load("Images/gamestart.png");
	gameSprite.SetTexture(gamestart);
	gameSprite.SetAlpha(1.0f);
	isDisplay = true;
	gameHelp.Load("Images/gameHelp.png");
	help.Init();
	help.SetSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	help.SetPosition(WINDOW_WIDTH / 2, -WINDOW_HEIGHT / 2);
	help.SetTexture(gameHelp);
	help.SetVisible(false);
	
}
void SceneTitle::Update() {
	if (help.IsVisible()) {
		if (Input_I->IsKeyUp(VK_ESCAPE)) {
			help.SetVisible(false);
		}
	}
	else {
		menuTimer += Time_I->GetDeltaTime();
		if (menuTimer >= 0.5f) {
			isDisplay = !isDisplay;
			menuTimer = 0.0f;
		}
		if (Input_I->IsKeyUp(VK_RETURN)) {
			switch ((MENU)selected) {
			case PLAY:
				mNextScene = SceneType::Select;
				break;
			case HELP:
				help.SetVisible(true);
				break;
			}
		}
		else if (Input_I->IsKeyUp(VK_UP)) {
			--selected;
			if (selected < 0) selected = 1;
		}
		else if (Input_I->IsKeyUp(VK_DOWN)) {
			++selected;
			if (selected > 1) selected = 0;
		}
	}
}
void SceneTitle::Term() {
	gamestart.Unload();
	gameSprite.Term();
	gameHelp.Unload();
	help.Term();
}
void SceneTitle::Render() {
	gameSprite.Draw();
	help.Draw();
	if (!help.IsVisible()) {
		if (selected == 0 && isDisplay || selected != 0) PrintText("PLAY", (float)WINDOW_WIDTH / 2.0f - 40.0f, (float)WINDOW_HEIGHT / 2.0f + 75.0f);
		if (selected == 1 && isDisplay || selected != 1) PrintText("HELP", (float)WINDOW_WIDTH / 2.0f - 40.0f, (float)WINDOW_HEIGHT / 2.0f + 150.0f);
	}
}