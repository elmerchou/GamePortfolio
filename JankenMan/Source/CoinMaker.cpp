#include "CoinMaker.h"
#include "AppDef.h"
#include <iostream>



void CoinMaker::Init() {
	texture.Load("Images/coin.png");
	for (int i = 0; i < sizeof(coins) / sizeof(coins[0]); ++i) {
		coins[i].sp.Init();
		coins[i].sp.SetTexture(texture);
		coins[i].sp.SetVisible(false);
		coins[i].sp.SetSize(114,70);
		coins[i].sp.SetPriority(100);
	}
	IO = false;
}

void CoinMaker::Term() {
	for (int i = 0; i < sizeof(coins) / sizeof(coins[0]); ++i) {
		coins[i].sp.Term();
	}
	texture.Unload();
}

void CoinMaker::Set() {
	
	for (int i = 0; i < sizeof(coins) / sizeof(coins[0]); ++i) {
		coins[i].sp.SetPosition(rand()% WINDOW_WIDTH- WINDOW_WIDTH/2.0f,WINDOW_HEIGHT/2.0f);
		coins[i].speed = rand() % 100+5;
		coins[i].rotate = rand() % 30;
		coins[i].sp.SetVisible(true);
	}
	IO = true;
}

void  CoinMaker::Update() {
	if (!IO) return;

	bool anyVisible = false;
	for (int i = 0; i < sizeof(coins) / sizeof(coins[0]); ++i) {
		auto& c = coins[i];
		if (!c.sp.IsVisible()) continue;

		anyVisible = true;
		Vector2f pos = c.sp.GetPosition();

		c.sp.SetPosition(pos.x, pos.y - c.speed);
		c.sp.SetRotation(c.sp.GetRotation() + c.rotate);

		if (pos.y < -WINDOW_HEIGHT / 2.0f) {
			c.sp.SetVisible(false);
		}
	}
	if (!anyVisible) {
		IO = false;
		completed = true;
	}
}

void  CoinMaker::Render() {
	for (int i = 0; i < sizeof(coins) / sizeof(coins[0]); ++i) {
		coins[i].sp.Draw();
	}
}

bool CoinMaker::IsInTurn() {
	return IO;
}

bool CoinMaker::Completed() {
	return completed;
}

void CoinMaker::Reset() {
	completed = false;
}