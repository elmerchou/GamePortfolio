#include "App.h"
#include "GameDef.h"
#include <iostream>
#include "CoinMaker.h"
#include "UI.h"
#include "Logic.h"
#include "Machine.h"
using namespace std;

CoinMaker mCoinMaker;
Logic mLogic;
UI mUI;
Machine mMachine;

//ゲームの更新処理を行う関数
void App::Init() {

	mCoinMaker.Init();
	mLogic.Init();
	mUI.Init();
	mMachine.Init(&mLogic,&mUI,&mCoinMaker);

}


//ゲームの更新処理を行う関数
void App::Update() {
	mCoinMaker.Update();
	mLogic.Update();
	mMachine.Update();
}

//ゲームの描画処理を行う関数
void App::Render() {//レンダー
	mUI.Render();
	mCoinMaker.Render();
}


// ゲームの後片付け処理を行う関数
void App::Term() {
	mUI.Term();
	mCoinMaker.Term();
}
