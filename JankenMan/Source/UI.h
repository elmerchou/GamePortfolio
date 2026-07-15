#pragma once 
#include "Fwk/Graphics.h"
#include "Lib/Math/Vector.h"
#include "GameDef.h"
#include "AppDef.h"


class UI {

public:
	void Init();
	void Render();
	void Term();
	void SetJankenVisible(bool b,Janken j);
	void SetOutcomeVisible(bool b,Outcome o);
	void SetSelectedVisible(bool b,Janken j);
	void SetVictoryVisible(bool b,int i);
	void SetStartVisible(bool b);
	void Reset();

private:
	//テキストやスプライト全般
	Texture bg;
	Sprite sBg;
	Texture janken[3];
	Sprite sJanken;

	Texture outcomePanel[3];
	Sprite sOutcomePanel;

	Texture blingbling;
	Sprite sBling;

	Texture startBling;
	Sprite sStartBling;

	Texture selectedBling;
	Sprite sSelectedBling;

};