#include "Logic.h"


void Logic::Init() {
	gameIO = false;//まだ始まらない
	firstGame = true;
	winCount = -1;//連勝数初期化
	srand((unsigned int)std::time(NULL));//乱数
	timer = 0.0f;
	drawTimer = 0.0f;
	speed = 0.2f;
}

void Logic::Update() {
	if (gameIO) {
		timer += Time_I->GetDeltaTime();
		if (timer >= speed) {//自動的にじゃんけんを変える
			timer = 0.0f;
			//(jankenNow + 1) >= 3 ? jankenNow = 0 : jankenNow++;
			jankenNow = (Janken)(rand() % 3);
		}
	}
	else if (outcome == Outcome::draw) {//引き分けの時、一秒後直接続きます
		drawTimer += Time_I->GetDeltaTime();
		if (drawTimer >= 1.0f) {
			drawTimer = 0.0f;
			gameIO = true;
		}
	}
}

bool Logic::IsGameStart() {
	return gameIO;
}

bool Logic::IsFirstRun() {
	return firstGame;
}

Outcome Logic::GetOutcome() {
	return outcome;
}

Janken Logic::GetJankenFromPlayer() {
	return jankenPlayer;
}
Janken Logic::GetJankenFromPC() {
	return jankenNow;
}
void Logic::SetWinCount(int i) {
	winCount = i;
}

int  Logic::GetWinCount() {
	return winCount;
}

Outcome Logic::OutcomeDecide(int player) {
	gameIO = false;//リセット
	if (player == jankenNow) {
		outcome = Outcome::draw;
	}
	else if ((player + 1) == jankenNow || (player == (int)Janken::pan && jankenNow == (int)Janken::gu)) {
		winCount = winCount + 1;
		if (speed >= 0.05f) speed -= 0.04f;//難易度上がる
		if (winCount >= 4) {
			winCount = 4;
		}
		outcome = Outcome::win;
		
	}
	else {
		winCount = -1;//連勝リセット
		speed = 0.2f;//スピードリセット
		outcome = Outcome::lose;
	}
	return outcome;
}

void Logic::GameStart() {
	gameIO = true;
	firstGame = false;
}
