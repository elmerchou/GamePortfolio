#pragma once 
#include "Fwk/Graphics.h"
#include "Lib/Math/Vector.h"
#include "GameDef.h"
#include "AppDef.h"
#include "Logic.h"
#include "CoinMaker.h"
#include "UI.h"


class Machine {

public:
	void Init(Logic* l,UI* u,CoinMaker* c);
	void Update();

private:
	Vector2f pt;//マウスの位置
	Logic* pLogic;
	UI* pUI;
	CoinMaker* pCoinMaker;


	//関数
	bool IsMouseInArea(Vector2f mouse, float xMin, float xMax, float yMin, float yMax);//マウス位置判定
	int GetJankenChoice(Vector2f mouse);//じゃんけん判定

};