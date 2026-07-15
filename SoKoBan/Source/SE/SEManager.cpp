#include "SEManager.h"

SEManager seManager;

SEManager* GetSEManager() {
	return &seManager;
}

void SEManager::Init() {
	for (int i = 0; i < (int)SE::SE_AMOUNT; ++i) {
		mSound[i].Load(SEAdress[i]);
	}
	mSoundSourceBGM.Init(mSound[(int)SE::BGM]);
	mSoundSourceBGM.Play(-1);
	for (int i = 0; i < (int)SE::SE_AMOUNT-1; ++i) {
		mSoundSourceEffects[i].Init(mSound[i+1]);
	}
}

void SEManager::Term() {
	for (int i = 0; i < (int)SE::SE_AMOUNT; ++i) {
		mSound[i].Unload();
	}
	for (int i = 0; i < (int)SE::SE_AMOUNT - 1; ++i) {
		mSoundSourceEffects[i].Term();
	}
	mSoundSourceBGM.Term();
}
void SEManager::PlayEffect(SE se) {
	mSoundSourceEffects[(int)se-1].Play();
}