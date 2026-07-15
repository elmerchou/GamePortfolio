#pragma once 
#include "Fwk/Graphics.h"
#include "Lib/Math/Vector.h"
#include "GameDef.h"
#include "AppDef.h"
#include "App.h"


class Logic {

public:
	void Init();
	void Update();

	bool IsGameStart();
	bool IsFirstRun();
	Outcome GetOutcome();
	Janken GetJankenFromPlayer();
	Janken GetJankenFromPC();
	void SetWinCount(int i);
	int GetWinCount();
	void GameStart();

	Outcome OutcomeDecide(int player);//勝負判定

private:
	int winCount;//連勝数

	bool gameIO;//開始かどうか
	bool firstGame;//初めてのターン

	Janken jankenNow;//PC今のじゃんけん
	Janken jankenPlayer;//プレイヤーの選択
	float timer;//PCのじゃんけん自動変更のタイマー
	float drawTimer;
	float speed;//変更のスピード
	Outcome outcome;//今の結果

	

};