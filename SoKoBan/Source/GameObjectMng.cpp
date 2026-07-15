#include "GameObjectMng.h"
#include "Tilemap.h"
#include "Player.h"
#include "Box.h"
#include "Fwk/File/KeyValueFile.h"
#include "Data/UndoData.h"
#include "SE/SEManager.h"


Tilemap mMap;
Player mPlayer;
Box box[5];
int goalCount;
bool isClear;
int stageNum;



void GameObjectInit(int num) {
	mMap.Init();
	mPlayer.Init();
	for (int i = 0; i < size(box); ++i) {
		box[i].Init();
	}
	stageNum = num;
	LoadStage(stageNum);
}

void GameObjectTerm() {
	mMap.Term();
	mPlayer.Term();
	for (int i = 0; i < size(box); ++i) {
		box[i].Term();
	}
	
}
void GameObjectUpdate() {
	if (!isClear) {
		Direction d= mPlayer.GetDirection();
		mPlayer.Update();
		isClear = GameClear();
		for (int i = 0; i < size(box); ++i) {
			box[i].Update();
		}
		if (mPlayer.GetMoving() != Vector2f(0.0f, 0.0f) && GetUndoData()->IsCheckOpen()) {
			int boxNo=-1;
			for (int i = 0; i < size(box); ++i) {

				if (mPlayer.GetMoving() == box[i].GetPosition()) {
					if (mPlayer.GetDirect().x > 0) {
						//cout << "¶";
						box[i].SetTarget(Vector2f(64.0f, 0.0f));
						boxNo = i;
					}
					else if (mPlayer.GetDirect().x < 0) {
						//cout << "‰E";
						box[i].SetTarget(Vector2f(-64.0f, 0.0f));
						boxNo = i;
					}
					else if (mPlayer.GetDirect().y > 0) {
						//cout << "ã";
						box[i].SetTarget(Vector2f(0.0f, 64.0f));
						boxNo = i;
					}
					else {
						//cout << "‰º";
						box[i].SetTarget(Vector2f(0.0f, -64.0f));
						boxNo = i;
					}
				}
			}
			if(boxNo != -1)GetUndoData()->SetNewUndo(d, mPlayer.GetPos(),boxNo,box[boxNo].GetPosition());
			else GetUndoData()->SetNewUndo(d, mPlayer.GetPos(), boxNo, Vector2f{0.0f,0.0f});
		}
		else if (Input_I->IsKeyUp(VK_SPACE)) {
			LoadStage(stageNum);
			GetSEManager()->PlayEffect(SEManager::SE::Retry);
			GetUndoData()->ClearAll();
		}
		else if (Input_I->IsKeyUp(VK_BACK)) {
			LoadUndo();
			GetSEManager()->PlayEffect(SEManager::SE::Undo);
		}
	}
}
void GameObjectRender() {
	mMap.Render();
	mPlayer.Render();
	for (int i = 0; i < goalCount; ++i) {
		box[i].Render();
	}
}
Tilemap* GetMap() {
	return &mMap;
}
bool IsBox(Vector2f v) {
	for (int i = 0; i < goalCount; ++i) {
		if (box[i].GetPosition() == v)return true;
		
	}
	return false;
}
bool GameClear() {
	int i = 0;
	for (int j = 0; j < goalCount; ++j) {
		if ( IsBox(mMap.GetGoalPos(j))) {
			++i;
		}
			
	}
	if (i == goalCount) {
		return true;
	}
	return false;
}

void LoadStage(int num) {
	stageNum = num;
	KeyValueFile mapdataFile;
	string address = "Data/mapdata";
	address += to_string(stageNum);
	address += ".txt";
	mapdataFile.Load(address);
	mMap.CreateMap(mapdataFile.GetCSVData("Data"));
	goalCount = mMap.GetBoxAmount();
	for (int i = 0; i < size(box); ++i) {
		box[i].SetActive(false);
	}
	for (int i = 0; i < goalCount; ++i) {
		/*box[i].Init();*/
		box[i].SetPosition(mMap.GetBoxPos(i));
		box[i].SetActive(true);
	}
	isClear = false;
	mPlayer.SetPos(mMap.GetPlayerPos());
}
void LoadUndo() {
	UndoData* u = GetUndoData();
	if (!u->IsEmpty()) {
		cout << "test" << endl;
		mPlayer.SetPos(u->GetPlayerPosition());
		mPlayer.SetDirection(u->GetPlayerDirection());
		if (u->GetBoxNo() != -1) {
			box[u->GetBoxNo()].SetPosition(u->GetBoxPosition());
		}
		u->PopOutBack();
	}
	else {
		cout << "empty" << endl;
	}
	
}

int GetStageNum() {
	return stageNum;
}