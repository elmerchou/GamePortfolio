#include "Tilemap.h"
#include <iostream>
#include "GameDef.h"

const float TileSize = 64.0f;

void Tilemap::Init() {
	boxCount = 0;
	goalCount = 0;
	mTexture.Load("Images/tilesheet.png");

	for (int i = 0; i < ROW_NUM; ++i) {
		for (int j = 0; j < COL_NUM; ++j) {
			mSprite[i][j].Init();
		}
		//cout << endl;
	}
	for (int i = 0; i < 5; ++i) {
		mGoal[i].Init();
	}
	for (int i = 0; i < 54; ++i) {
		mWall[i].Init();
	}
}

void Tilemap::Render() {
	for (int i = 0; i < ROW_NUM; ++i) {
		for (int j = 0; j < COL_NUM; ++j) {
			mSprite[i][j].Draw();
		}
	}
	for (int i = 0; i < goalCount; ++i) {
		mGoal[i].Draw();
	}
	for (int i = 0; i < wallCount; ++i) {
		mWall[i].Draw();
	}
}


void Tilemap::Term() {
	for (int i = 0; i < ROW_NUM; ++i) {
		for (int j = 0; j < COL_NUM; ++j) {
			mSprite[i][j].Term();
		}
	}
	for (int i = 0; i < 5; ++i) {
		mGoal[i].Term();
	}
	for (int i = 0; i < 54; ++i) {
		mWall[i].Term();
	}
	mTexture.Unload();

}

float Tilemap::GetTileSize() {
	return TileSize;
}

bool Tilemap::IsWall(Vector2f position) {
	int col = (int)(position.x / TileSize);
	int row = (int)(position.y / -TileSize);

	if (col < 0 || col >= COL_NUM || row < 0 || row >= ROW_NUM) {
		return false;
	}
	int id = mMapData[row][col];

	if (id == 5) return true;

	return false;
}

bool Tilemap::IsGoal(Vector2f position) {
	int col = (int)(position.x / TileSize);
	int row = (int)(position.y / -TileSize);

	if (col < 0 || col >= COL_NUM || row < 0 || row >= ROW_NUM) {
		return false;
	}
	int id = mMapData[row][col];

	if (id == 2) return true;

	return false;
}

Vector2f Tilemap::GetPlayerPos() {
	return playerPos;
}
Vector2f Tilemap::GetBoxPos(int i) {
	return boxPos[i];
}
Vector2f Tilemap::GetGoalPos(int i) {
	return goalPos[i];
}
int Tilemap::GetBoxAmount() {
	return boxCount;
}

void Tilemap::CreateMap(CSVData* pMapdata){
	//Term();
	boxCount = 0;
	goalCount = 0;
	wallCount = 0;
	for (int i = 0; i < ROW_NUM; ++i) {
		for (int j = 0; j < COL_NUM; ++j) {

		
			mSprite[i][j].SetTexture(mTexture);
			mSprite[i][j].SetSize(TileSize, TileSize);
			mSprite[i][j].SetPosition((float)j * TileSize, (float)-i * TileSize);

			int id = pMapdata->GetInt(j + (i * COL_NUM));
			mMapData[i][j] = id;
			cout << id<< " ";
			if (id == 3) {
				id = 89;
				//playerPos = Vector2f((float)j * TileSize + 32.0f, (float)-i * TileSize - 32.0f);
				playerPos = Vector2f((float)j * TileSize , (float)-i * TileSize);
			}
			else if (id == 4) {
				id = 89;
				//boxPos[boxCount] = Vector2f((float)j * TileSize + 32.0f, (float)-i * TileSize - 32.0f);
				boxPos[boxCount] = Vector2f((float)j * TileSize, (float)-i * TileSize);
				boxCount++;
			}
			else if (id == 2) {
				id = 89;
				//goalPos[goalCount] = Vector2f((float)j * TileSize + 32.0f, (float)-i * TileSize - 32.0f);
				goalPos[goalCount] = Vector2f((float)j * TileSize, (float)-i * TileSize);
				goalCount++;
			}
			else if (id == 5) {
				id = 89;
				//goalPos[goalCount] = Vector2f((float)j * TileSize + 32.0f, (float)-i * TileSize - 32.0f);
				wallPos[wallCount] = Vector2f((float)j * TileSize, (float)-i * TileSize);
				wallCount++;
			}

			float u = (float)(id % TILE_WIDTH) * w;
			float v = (float)(id / TILE_WIDTH) * h;
			mSprite[i][j].SetTexCoord(u, v, w, h);
			mSprite[i][j].SetPivot(Pivot::TopLeft);


		}
		cout << endl;
	}
	_SetGoal();
	_SetWall();
}

void Tilemap::_SetGoal() {
	for (int i = 0; i < goalCount; ++i) {
		mGoal[i].SetTexture(mTexture);
		mGoal[i].SetTexCoord((float)(64 % TILE_WIDTH) * w, (float)(64 / TILE_WIDTH) * h, w, h);
		mGoal[i].SetSize(TileSize, TileSize);
		mGoal[i].SetPivot(Pivot::TopLeft);
		mGoal[i].SetPosition(goalPos[i].x, goalPos[i].y);
	}
}

void Tilemap::_SetWall() {
	for (int i = 0; i < wallCount; ++i) {
		mWall[i].SetTexture(mTexture);
		mWall[i].SetTexCoord((float)(5 % TILE_WIDTH) * w, (float)(5/ TILE_WIDTH) * h, w, h);
		mWall[i].SetSize(TileSize, TileSize);
		mWall[i].SetPivot(Pivot::TopLeft);
		mWall[i].SetPosition(wallPos[i].x, wallPos[i].y);
	}
}