#pragma once
#include "Fwk/Audio/MP3Sound.h"
#include "Fwk/Audio/SoundSource.h"
#include "Fwk/Framework.h"

class SEManager {
public:
	enum class SE {
		BGM,
		Move,
		Undo,
		Retry,
		StageClear,
		SE_AMOUNT,
	};
	void Init();
	void Term();
	void PlayEffect(SE se);

private:
	const string SEAdress[(int)SE::SE_AMOUNT] = {
	"SE/BGM.mp3",
	"SE/Move.mp3",
	"SE/Undo.mp3",
	"SE/Retry.mp3",
	"SE/StageClear.mp3",
	};

	MP3Sound mSound[(int)SE::SE_AMOUNT];
	SoundSource mSoundSourceBGM;
	SoundSource mSoundSourceEffects[(int)SE::SE_AMOUNT -1];
};

SEManager* GetSEManager();