#include "SceneSelect.h"
#include "Data/GamePlayData.h"
#include "Fwk/Framework.h"


void SceneSelect::Init() {
	Scene::Init();
	stageAmount = STAGE_AMOUNT;
	timer = 0.0f;
	isDisplay = true;
}
void SceneSelect::Update() {
	timer += Time_I->GetDeltaTime();
	if (timer >= 0.5f) {
		isDisplay = !isDisplay;
		timer = 0.0f;
	}
	if (Input_I->IsKeyUp(VK_RETURN)) {
		if (GetPlayData()->IsStageAvailable(mSeletedIndex)) {
			GetPlayData()->SetStageNo(mSeletedIndex);
			SetTextColor({ 256, 256, 256 });
			mNextScene = SceneType::InGame;
		}
	}
	else if (Input_I->IsKeyUp(VK_UP)) {
		--mSeletedIndex;
		if (mSeletedIndex < 0) mSeletedIndex = stageAmount-1;
	}
	else if (Input_I->IsKeyUp(VK_DOWN)) {
		++mSeletedIndex;
		if (mSeletedIndex >= stageAmount) mSeletedIndex = 0;
	}else if (Input_I->IsKeyUp(VK_ESCAPE)) {
		mNextScene = SceneType::Title;
	}
		
}
void SceneSelect::Term() {
}
void SceneSelect::Render() {
	PrintText("CHOOSE STAGE", (float)WINDOW_WIDTH / 2.0f - 160.0f, (float)WINDOW_HEIGHT / 2.0f - 150.0f);
	for (int i = 0; i < stageAmount; ++i) {
		if (GetPlayData()->IsStageAvailable(i)) {
			SetTextColor({ 256, 256, 256 });
		}
		else {
			SetTextColor({ 0, 0, 0 });
		}
		string str = "STAGE "+std::to_string(i + 1);
		if((i == mSeletedIndex && isDisplay) || i != mSeletedIndex)PrintText(str, (float)WINDOW_WIDTH / 2.0f - 100.0f, (float)WINDOW_HEIGHT / 2.0f - 75.0f + 40.0f * (i + 1));
		SetTextColor({ 256, 256, 256 });
		PrintText("PRESS[ESC] To Title", (float)WINDOW_WIDTH / 2.0f - 200.0f, (float)WINDOW_HEIGHT / 2.0f + 200.0f);

	}
}