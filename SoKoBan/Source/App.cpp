#include "App.h"
#include <iostream>
#include "Scene/SceneManager.h"
#include "Data/GamePlayData.h"
#include "Data/UndoData.h"
#include "SE/SEManager.h"


using namespace std;

SceneManager SceneMng;

//ゲームの更新処理を行う関数
void App::Init() {
	Camera camera;
	camera.SetPosition(WINDOW_WIDTH / 2, -WINDOW_HEIGHT / 2);
	RenderManager_I->SetCamera(camera);

	GetPlayData()->Init();
	GetUndoData()->Init();
	GetSEManager()->Init();

	SceneMng.Init(SceneType::Title);
}


//ゲームの更新処理を行う関数
void App::Update() {
	SceneMng.Update();
}

//ゲームの描画処理を行う関数
void App::Render() {//レンダー
	SceneMng.Render();
}


// ゲームの後片付け処理を行う関数
void App::Term() {
	SceneMng.Term();
	GetSEManager()->Term();
}
