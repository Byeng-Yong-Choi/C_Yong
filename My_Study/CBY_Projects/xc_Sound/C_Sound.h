#pragma once
#include "Cstd.h"
#include "fmod.h"
#include "fmod.hpp"
//#define MAX_SOUNDLIST 32

class C_Sound
{
public:
	FMOD::System* m_pSystem;
	FMOD::Sound* m_pSound;
	FMOD::Channel* m_pChannel;
	int m_SoundList;

public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();
	
public:
	int Load(const TCHAR* soundfilename, bool play);
	bool Play();
	bool Pause();
	bool Volume(float ChangeVolume, bool UP);

public:
	C_Sound();
	~C_Sound();
};

