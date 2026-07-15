#include "Machine.h"

void Machine::Init(Logic* l, UI* u, CoinMaker* c) {
	pLogic = l;
	pUI = u;
	pCoinMaker = c;
}

void Machine::Update() {
	pt = Framework_I->GetMousePointInClient();//マウス座標

	if (!pLogic->IsGameStart()) {//まだ始まらない場合

		if (pCoinMaker->IsInTurn()) {//コイン動画中
		}
		else {
			if (pLogic->IsFirstRun()) pUI->SetJankenVisible(false, pLogic->GetJankenFromPlayer());//first turn
			if (pCoinMaker->Completed()) {
				pCoinMaker->Reset();
				pLogic->SetWinCount(-1);
				pUI->Reset();
			}
			pUI->SetStartVisible(true);
			if (Input_I->IsKeyUp(VK_LBUTTON)) {//スタート押す
				if (IsMouseInArea(pt, startPosition[0].x, startPosition[1].x, startPosition[0].y, startPosition[1].y)) {
					pLogic->GameStart();
					pUI->SetStartVisible(false);
					pUI->SetJankenVisible(true, pLogic->GetJankenFromPC());
					if (pLogic->GetOutcome() == Outcome::lose)pUI->SetOutcomeVisible(false, pLogic->GetOutcome());//負けた時だけ、ライトを消す
				}
			}
		}
	}
	else {//ゲーム始まる
		pUI->SetJankenVisible(true, pLogic->GetJankenFromPC());
		//マウスの位置によって、ライトをつける
		int choice = GetJankenChoice(pt);
		if (choice != -1) {
			pUI->SetSelectedVisible(true, (Janken)choice);
			if (Input_I->IsKeyUp(VK_LBUTTON)) {	//押す
				Outcome result = pLogic->OutcomeDecide(choice);
				pUI->SetOutcomeVisible(true, result);
				if (result == Outcome::win && pLogic->GetWinCount() == 4) pCoinMaker->Set();
				pUI->SetVictoryVisible(result == Outcome::win || (result == Outcome::draw && pLogic->GetWinCount() != -1), pLogic->GetWinCount());
			}
		}
		else pUI->SetSelectedVisible(false, pLogic->GetJankenFromPC());
	}
}


bool Machine::IsMouseInArea(Vector2f mouse, float xMin, float xMax, float yMin, float yMax) {
	return (mouse.x >= xMin && mouse.x <= xMax && mouse.y >= yMin && mouse.y <= yMax);
}


int Machine::GetJankenChoice(Vector2f mouse) {
	if (IsMouseInArea(mouse, guPosition[0].x, guPosition[1].x, guPosition[0].y, guPosition[1].y)) return (int)Janken::gu;
	if (IsMouseInArea(mouse, chokiPosition[0].x, chokiPosition[1].x, chokiPosition[0].y, chokiPosition[1].y)) return (int)Janken::choki;
	if (IsMouseInArea(mouse, panPosition[0].x, panPosition[1].x, panPosition[0].y, panPosition[1].y)) return (int)Janken::pan;
	return -1;
}