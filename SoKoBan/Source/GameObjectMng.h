#pragma once

#include "Tilemap.h"
#include <iostream>
#include "GameObjectMng.h"
#include "App.h"

using namespace::std;

void GameObjectInit(int stageNum);
void GameObjectTerm();
void GameObjectUpdate();
void GameObjectRender();
Tilemap* GetMap();
bool IsBox(Vector2f v);
bool GameClear();
void LoadStage(int num);
void LoadUndo();
int GetStageNum();