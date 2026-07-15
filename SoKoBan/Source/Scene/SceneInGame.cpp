#include "SceneInGame.h"
#include "GameObjectMng.h"
#include "Data/GamePlayData.h"
#include "Data/UndoData.h"
#include "AppDef.h"
#include "SE/SEManager.h"


void SceneInGame::Init() {
	Scene::Init();
	stageClear.Load("Images/gameclear.png");
	gameSprite.SetTexture(stageClear);	
	gameSprite.SetAlpha(0.0f);
	stageNum = GetPlayData()->GetStageNo();
	GameObjectInit(stageNum);
	isSoundPlayed = false;
}
void SceneInGame::Update() {
	
	if (GameClear()) {
		if (!isSoundPlayed) {
			GetSEManager()->PlayEffect(SEManager::SE::StageClear);
			isSoundPlayed = true;
		}
		
		if(GetStageNum() == 3)  mNextScene = SceneType::GameClear;
		else {
			GetPlayData()->SetStageState(stageNum+1,true);
			gameSprite.SetAlpha(1.0f);
			if (Input_I->IsKeyUp(VK_RETURN)) {
				gameSprite.SetAlpha(0.0f);
				stageNum++;
				LoadStage(stageNum);
				GetUndoData()->ClearAll();
				isSoundPlayed = false;
			}else if (Input_I->IsKeyUp(VK_ESCAPE)) {
				mNextScene = SceneType::Title;
				GetUndoData()->ClearAll();
			}
		}
	}
	else {
		GameObjectUpdate();
		if (Input_I->IsKeyUp(VK_ESCAPE)) {
			mNextScene = SceneType::Title;
			GetUndoData()->ClearAll();
		}
	}
}
void SceneInGame::Term() {
	stageClear.Unload();
	gameSprite.Term();
	GameObjectTerm();
}
void SceneInGame::Render() {
	GameObjectRender();
	gameSprite.Draw();

	if (!GameClear()) {
		string str = "STAGE " + std::to_string(stageNum + 1);
		string str2 = "Undo: "+ std::to_string(GetUndoData()->GetStepNow());
		PrintText(str, 10.0f, 5.0f);
		PrintText(str2, WINDOW_WIDTH-160.0f, 5.0f);
	}
}