#include "UI.h"

void UI::Init() {
	//スプライト初期化
	bg.Load("Images/background.png");
	sBg.Init();
	sBg.SetTexture(bg);
	sBg.SetSize(WINDOW_WIDTH, WINDOW_HEIGHT);

	janken[Janken::gu].Load("Images/janken_01.png");
	janken[Janken::choki].Load("Images/janken_02.png");
	janken[Janken::pan].Load("Images/janken_03.png");
	sJanken.Init();
	sJanken.SetSize(280.0f, 280.0f);
	sJanken.SetPosition(0.0f, 30.0f);
	sJanken.SetTexture(janken[0]);

	blingbling.Load("Images/number_on_effect.png");
	sBling.Init();
	sBling.SetSize(105.0f, 105.0f);
	sBling.SetTexture(blingbling);
	sBling.SetVisible(false);

	selectedBling.Load("Images/selected_on_effect.png");
	sSelectedBling.Init();
	sSelectedBling.SetSize(105.0f, 105.0f);
	sSelectedBling.SetTexture(selectedBling);
	sSelectedBling.SetVisible(false);

	startBling.Load("Images/start_on_effect.png");
	sStartBling.Init();
	sStartBling.SetSize(105.0f, 105.0f);
	sStartBling.SetTexture(startBling);
	sStartBling.SetVisible(true);
	sStartBling.SetPosition(startPositionLight);

	outcomePanel[0].Load("Images/lamp_01.png");
	outcomePanel[1].Load("Images/lamp_02.png");
	outcomePanel[2].Load("Images/lamp_03.png");
	sOutcomePanel.Init();
	sOutcomePanel.SetSize(130.0f, 60.0f);
	sOutcomePanel.SetVisible(false);
	sOutcomePanel.SetTexture(outcomePanel[0]);

}

void UI::Render() {
	sBg.Draw();
	sJanken.Draw();
	sBling.Draw();
	sOutcomePanel.Draw();
	sStartBling.Draw();
	sSelectedBling.Draw();
}

void UI::Term() {
	sBg.Term();
	sJanken.Term();
	sBling.Term();
	sOutcomePanel.Term();
	sStartBling.Term();
	sSelectedBling.Term();
	for (int i = 0; i < size(janken); ++i) {
		janken[i].Unload();
		outcomePanel[i].Unload();
	}
	bg.Unload();
	blingbling.Unload();
	startBling.Unload();
	selectedBling.Unload();
}

void UI::SetJankenVisible(bool b,Janken j) {
	if (b == false) sJanken.SetVisible(b);
	else {
		sJanken.SetTexture(janken[j]);
		sJanken.SetVisible(true);
	}
}

void UI::SetOutcomeVisible(bool b, Outcome o) {
	if (b == false) sOutcomePanel.SetVisible(false);
	else {
		sOutcomePanel.SetTexture(outcomePanel[o]);
		sOutcomePanel.SetPosition(panelPosition[o]);
		sOutcomePanel.SetVisible(true);
	}
}
void UI::SetSelectedVisible(bool b, Janken j) {
	if (b == false) sSelectedBling.SetVisible(false);
	else {
		sSelectedBling.SetPosition(selectedPosition[j]);
		sSelectedBling.SetVisible(true);
	}
}
void UI::SetVictoryVisible(bool b, int i) {
	if (b == false) sBling.SetVisible(false);
	else {
		sBling.SetPosition(winPosition[i]);
		sBling.SetVisible(true);
	}
}
void UI::SetStartVisible(bool b) {
	sStartBling.SetVisible(b);
}

void UI::Reset() {
	sOutcomePanel.SetVisible(false);
	sBling.SetVisible(false);
	sSelectedBling.SetVisible(false);
	sJanken.SetVisible(false);
}