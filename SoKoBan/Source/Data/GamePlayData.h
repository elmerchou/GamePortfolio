#pragma once
# include <map>
#include "GameDef.h"
#include "Fwk/File/KeyValueFile.h"

class GamePlayData {
public:
	void Init();

	int GetStageNo();
	void SetStageNo(int i);

	bool IsStageAvailable(int stageNo);
	void SetStageState(int stageNo, bool isCleared);

private:
	int mStageNo;
	KeyValueFile playFile;
	std::map<int, bool> stageData;
	const string dataAddress = "../../Assets/Data/GamePlayData.txt";
};

GamePlayData* GetPlayData();