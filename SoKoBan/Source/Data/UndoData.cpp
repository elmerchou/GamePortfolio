#include "UndoData.h"

UndoData undoData;

UndoData* GetUndoData() {
	return &undoData;
}

void UndoData::Init() {
	stepNow = 0;
	isCheck = false;
}

void UndoData::SetNewUndo(Direction dir, Vector2f pPos, int boxNo, Vector2f bPos) {
	undoData.push_back(Undo{ dir, pPos, boxNo,bPos});
	++stepNow;
	if (stepNow > 20) _PopOutFront();
	isCheck = false;
}
Direction UndoData::GetPlayerDirection() {
	return undoData.back().direct;
}
Vector2f UndoData::GetPlayerPosition() {
	return undoData.back().playerPos;
}
Vector2f UndoData::GetBoxPosition() {
	return undoData.back().boxPos;
}
int UndoData::GetBoxNo() {
	return undoData.back().boxNo;
}
void UndoData::_PopOutFront() {
	if (!undoData.empty()) {
		undoData.pop_front();
		--stepNow;
	} 
}
void UndoData::PopOutBack() {
	if (!undoData.empty()) {
		undoData.pop_back();
		--stepNow;
	}
}
void UndoData::ClearAll() {
	if (!undoData.empty()) undoData.clear();
	stepNow = 0;
}
int UndoData::GetStepNow() {
	return stepNow;
}
bool UndoData::IsEmpty() {
	return undoData.empty();
}

bool UndoData::IsCheckOpen() {
	return isCheck;
}
void UndoData::SetCheckOpen(bool b) {
	isCheck = b;
}