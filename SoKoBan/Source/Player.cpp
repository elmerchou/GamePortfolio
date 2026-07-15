#include "Player.h"
#include "GameObjectMng.h"
#include "Fwk/Framework.h"
#include <iostream>
#include "Data/UndoData.h"
#include "SE/SEManager.h"


void Player::Init() {
	mTexture.Load("Images/tilesheet.png");
	mSprite.Init();
	mSprite.SetTexture(mTexture);
	mSprite.SetSize(64.0f, 64.0f);
	mSprite.SetPivot(Pivot::TopLeft);
	mPosition = { 0.0f,0.0f };
	mTargetPosition = {0.0f,0.0f};

	_InitAnim();
}


void Player::Update() {
	
	switch (mStatus) {
	case Status::Idle: {
		Vector2f vMove;
		const float TileSize = GetMap()->GetTileSize();
		if (Input_I->IsKeyDown(VK_LEFT)) {
			vMove.x -= TileSize;
			direct = Direction::Left;
			//cout << "1";
		}
		if (Input_I->IsKeyDown(VK_RIGHT)) {
			vMove.x += TileSize;
			direct = Direction::Right;
			//cout << "2";
		}
		if (Input_I->IsKeyDown(VK_UP)) {
			vMove.y += TileSize;
			direct = Direction::Back;
			//cout << "3";
		}
		if (Input_I->IsKeyDown(VK_DOWN)) {
			vMove.y -= TileSize;
			direct = Direction::Front;
			//cout << "4";
		}
		if ((vMove.x != 0.0f && vMove.y == 0.0f) || ((vMove.x == 0.0f && vMove.y != 0.0f))) {
			if (!GetMap()->IsWall(mPosition + vMove)) {

				if ((!(GetMap()->IsWall(mPosition + vMove + vMove) && IsBox(mPosition + vMove)))&& !(IsBox(mPosition + vMove) && IsBox(mPosition + vMove + vMove))) {
					mTargetPosition = mPosition + vMove;
					GetUndoData()->SetCheckOpen(true);
					GetSEManager()->PlayEffect(SEManager::SE::Move);
					mStatus = Status::Moving;
				}
			} 
		}
		break;
	}
	case Status::Moving: {
		float speed = 240.0f * Time_I->GetDeltaTime();

		if ((mTargetPosition - mPosition).GetLength() > speed) {
			Vector2f vDirection = (mTargetPosition - mPosition).GetNormalized();
			mPosition += vDirection * speed;
		}
		else {
			mPosition = mTargetPosition;
			mStatus = Status::Idle;
		}
		break;
	}
	}

	_ChangeSprite();
}

void Player::Render() {
	mSprite.Draw();
}

void Player::Term() {
	
	mSprite.Term();
	mTexture.Unload();

}

Vector2f Player::GetMoving() {
	if (mTargetPosition != mPosition) {
		return mTargetPosition;
	} 
	else return Vector2f(0.0f, 0.0f);
}

Vector2f Player::GetDirect() {
	return (mTargetPosition - mPosition).GetNormalized();
}
void Player::SetPos(Vector2f pos) {
	mPosition = pos;
	mTargetPosition = pos;
	mSprite.SetPosition(mPosition);
	
	cout << mSprite.GetPosition().x << " " << mSprite.GetPosition().y << endl;
}

void Player::_InitAnim() {
	UVRect idle_front[] = {uvs[0]};
	UVRect idle_back[] = {uvs[3]};
	UVRect idle_right[] = {uvs[6]};
	UVRect idle_left[] = {uvs[9]};

	UVRect walk_front[] = {
		uvs[0],
		uvs[1],
		uvs[2],
	};

	UVRect walk_back[] = {
		uvs[3],
		uvs[4],
		uvs[5],
	};

	UVRect walk_right[] = {
	uvs[6],
	uvs[7],
	uvs[8],
	};

	UVRect walk_left[] = {
		uvs[9],
		uvs[10],
		uvs[11],
	};

	Animation anim[8];

	CreateAnimationUV(anim[0],"idle_front", 1, 0.0f, false, idle_front);
	CreateAnimationUV(anim[1],"idle_back", 1, 0.0f, false, idle_back);
	CreateAnimationUV(anim[2],"idle_right", 1, 0.0f, false, idle_right);
	CreateAnimationUV(anim[3],"idle_left", 1, 0.0f, false, idle_left);

	CreateAnimationUV(anim[4], "walk_front", 3, 0.3f, true, walk_front);
	CreateAnimationUV(anim[5], "walk_back", 3, 0.3f, true, walk_back);
	CreateAnimationUV(anim[6], "walk_right", 3, 0.3f, true, walk_right);
	CreateAnimationUV(anim[7], "walk_left",3, 0.3f, true, walk_left);

	for (int i = 0; i < 8; ++i) mSprite.AddAnimation(anim[i]);

	mSprite.PlayAnimation("idle_front");
}
void Player::_ChangeSprite() {
	string playAnimName;
	const string animName_idle[] = { "idle_front" ,"idle_back" ,"idle_right" ,"idle_left" };
	const string animName_walk[] = { "walk_front" ,"walk_back" ,"walk_right" ,"walk_left" };


	if (mStatus == Status::Idle) playAnimName = animName_idle[(int)direct];
	else if (mStatus == Status::Moving) playAnimName = animName_walk[(int)direct];

	mSprite.PlayAnimation(playAnimName, AnimationPlayStyle::Continue);
	mSprite.SetPosition(mPosition);
	mSprite.Update();
}

Direction Player::GetDirection() {
	return direct;
}
void Player::SetDirection(Direction d) {
	direct = d;
	_ChangeSprite();
}
Vector2f Player::GetPos() {
	return mPosition;
}