#pragma once
#include "GameDef.h"
#include <queue>

class UndoData {
	struct Undo {
		Direction direct;
		Vector2f playerPos;
		int boxNo;
		Vector2f boxPos;
	};


public:
	void Init();
	void SetNewUndo(Direction dir,Vector2f pPos, int boxNo,Vector2f bPos);
	Direction GetPlayerDirection();
	Vector2f GetPlayerPosition();
	Vector2f GetBoxPosition();
	int GetBoxNo();
	
	void PopOutBack();
	void ClearAll();
	int GetStepNow();
	bool IsEmpty();
	bool IsCheckOpen();
	void SetCheckOpen(bool b);


private:
	void _PopOutFront();

	deque<Undo> undoData;
	int stepNow;
	bool isCheck;
};

UndoData* GetUndoData();