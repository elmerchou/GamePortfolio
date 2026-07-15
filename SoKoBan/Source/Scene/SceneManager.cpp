#include "SceneManager.h"

#include "SceneTitle.h"
#include "SceneSelect.h"
#include "SceneInGame.h"
#include "SceneGameClear.h"

void SceneManager::Init(SceneType startScene) {
	mCurrentScene = SceneType::None;
	mNextScene = startScene;
	pScene = nullptr;
}
void SceneManager::Term() {
	_endCurrentScene();
	mNextScene = SceneType::None;
}
void SceneManager::Update() {
	if (mNextScene != SceneType::None && mCurrentScene != mNextScene) {
		_biginScene(mNextScene);
	}
	if (pScene != nullptr) {
		pScene->Update();
		mNextScene = pScene->GetNextScene();
	}

}

void SceneManager::Render() {
	if (pScene != nullptr) {
		pScene->Render();
	}
}
void SceneManager::_biginScene(SceneType newScene) {
	_endCurrentScene();
	switch (newScene)
	{
	case SceneType::Title:
		pScene = new SceneTitle();
		break;
	case SceneType::Select:
		pScene = new SceneSelect();
		break;
	case SceneType::InGame:
		pScene = new SceneInGame();
		break;
	case SceneType::GameClear:
		pScene = new SceneGameClear();
		break;
	}
	if (pScene != nullptr) pScene->Init();

	mCurrentScene = newScene;
}


void  SceneManager::_endCurrentScene() {
	if (pScene != nullptr) {
		pScene->Term();
		SAFE_DELETE(pScene);
	}
	mCurrentScene = SceneType::None;
}