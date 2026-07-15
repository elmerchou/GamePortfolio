#include "GamePlayData.h"
#include <iostream>
#include <filesystem> 
#include <fstream> 

GamePlayData playData;

GamePlayData* GetPlayData() {
	return &playData;
}

void GamePlayData::Init() {
	std::ifstream inFile(dataAddress);

	if (!inFile) {
		cout << "OPEN FAILED";
	}
	int key;
	int stats;

	while (inFile >> key >> stats) {
		stageData.emplace(key, (bool)stats);
		cout << key << " " << stats << endl;
	}
	//playFile.Load(dataAddress);
	//mStageNo = 0;
	//for (int i = 0; i < STAGE_AMOUNT; ++i) {
	//	playFile.GetCSVData("Data")->GetInt(i);
	//	stageData.emplace(i, playFile.GetCSVData("Data")->GetInt(i));
	//}
	//stageData[0] = true;
}

int GamePlayData::GetStageNo() {
	return mStageNo;
}
void GamePlayData::SetStageNo(int stageNo) {
	mStageNo = stageNo;
}

bool GamePlayData::IsStageAvailable(int stageNo) {
	return stageData.find(stageNo)->second;
}
void GamePlayData::SetStageState(int stageNo, bool isCleared) {
	if (stageData.count(stageNo)) {
		stageData[stageNo] = isCleared;
		std::ofstream outFile(dataAddress);
		for (int i = 0; i < STAGE_AMOUNT; ++i) {
			outFile << i <<  "\n"<<stageData[i] << "\n";
		}
	}
}

