#pragma once

#include <Fwk/Graphics.h>
#include "GameDef.h"

using namespace Lib::Math;

class Player {
private:
	enum class Status {
		Idle,
		Moving,
	};


public:
	void Init();
	void Term();
	void Update();
	void Render();
	Vector2f GetMoving();
	Vector2f GetDirect();
	Direction GetDirection();
	void SetPos(Vector2f pos);
	Vector2f GetPos();
	void SetDirection(Direction d);



private:
	Texture mTexture;
	Sprite mSprite;
	Vector2f mPosition;
	Vector2f mTargetPosition;
	Status mStatus;
	Direction direct;

	void _InitAnim();
	void _ChangeSprite();

};