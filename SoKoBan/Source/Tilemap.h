#pragma once

#include <Fwk/Graphics.h>
#include "Lib/Math/Vector.h"
#include "Fwk/File/CSVFile.h"

using namespace Lib::Math;

class Tilemap {
public:
	void Init();
	void Term();
	void Render();
	float GetTileSize();
	bool IsWall(Vector2f position);
	bool IsGoal(Vector2f position);
	Vector2f GetPlayerPos();
	Vector2f GetBoxPos(int i);
	Vector2f GetGoalPos(int i);
	int GetBoxAmount();
	void CreateMap(CSVData* pMapdata);

private:
	enum {
		COL_NUM = 16,
		ROW_NUM = 12,
	};
private:
	Texture mTexture;
	Sprite mSprite[ROW_NUM][COL_NUM];

	int mMapData[ROW_NUM][COL_NUM] = {
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,3,0,0,1,1,1,1,1,1,1,1,
		1,1,1,1,1,0,0,0,4,0,1,1,1,1,1,1,
		1,1,1,1,1,1,0,2,4,0,2,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	};
	Vector2f playerPos;
	Vector2f boxPos[5];
	Vector2f goalPos[5];
	Vector2f wallPos[54];
	int boxCount;
	int goalCount;
	int wallCount;

	Sprite mGoal[5];
	Sprite mWall[54];
	void _SetGoal();
	void _SetWall();
};