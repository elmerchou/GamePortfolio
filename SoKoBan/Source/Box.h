#pragma once

#include <Fwk/Graphics.h>
#include <Lib/Math/Vector.h>


using namespace Lib::Math;


class Box {
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

	bool IsActive();
	void SetActive(bool isActive);

	Vector2f GetPosition();
	void SetPosition(Vector2f position);
	void SetTarget(Vector2f position);
	Vector2f GetTarget();


private:
	Texture mTexture;
	Sprite mSprite;
	Vector2f mPosition;
	bool mIsActive;
	Status mStatus;
	Vector2f mTargetPosition;

};