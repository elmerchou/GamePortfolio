#pragma once 
#include "Fwk/Graphics.h"
#include "Lib/Math/Vector.h"


struct Coin {
	Sprite sp;
	float rotate;
	float speed;
};

class CoinMaker {

public:
	void Init();
	void Update();
	void Render();
	void Term();
	void Set();
	bool IsInTurn();
	bool Completed();
	void Reset();

private:
	Texture texture;
	Coin coins[32];
	bool IO;
	bool completed;

};