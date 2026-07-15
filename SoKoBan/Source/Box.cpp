#include "Box.h"
#include "Fwk/Framework.h"
#include "GameObjectMng.h"
#include "GameDef.h"


void Box::Init() {
	mTexture.Load("Images/tilesheet.png");
	

	mSprite.Init();
	mSprite.SetTexture(mTexture);
	mSprite.SetSize(64.0f, 64.0f);
	mSprite.SetPivot(Pivot::TopLeft);
	mStatus = Status::Idle;
	mIsActive = false;
}


void Box::Update() {
	if (!IsActive()) {
	}
	else {
		switch (mStatus) {
		case Status::Idle: {
			//mSprite.SetPosition(mPosition);
			if (GetMap()->IsGoal(mPosition)) {
				mSprite.SetTexCoord((float)(4 % TILE_WIDTH) * w, (float)(4 / TILE_WIDTH) * h, w, h);
			}
			else {
				mSprite.SetTexCoord((float)(1 % TILE_WIDTH) * w, (float)(1 / TILE_WIDTH) * h,w,h);
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
				if (GetMap()->IsGoal(mPosition)) {
					mSprite.SetTexCoord((float)(4 % TILE_WIDTH) * w, (float)(4 / TILE_WIDTH) * h, w, h);
				}
			}
			break;
		}

		}

		mSprite.SetPosition(mPosition);
	}
	
}

void Box::Render() {
	if (IsActive()) {
		mSprite.Draw();
	}
	
}

void Box::Term() {
	
	mSprite.Term();
	mTexture.Unload();

}

bool Box::IsActive() {
	return mIsActive;


}

void Box::SetActive(bool isActive) {
	mIsActive = isActive;
	mSprite.SetTexCoord((float)(1 % TILE_WIDTH) * w, (float)(1 / TILE_WIDTH) * h, w, h);

}

Vector2f Box::GetPosition() {
	return mPosition;
}

void Box::SetPosition(Vector2f position) {
	mPosition = position;
	mSprite.SetPosition(mPosition);
}

void Box::SetTarget(Vector2f position) {
	mTargetPosition = mPosition + position;
	mStatus = Status::Moving;
}
Vector2f Box::GetTarget() {
	return mTargetPosition;
}