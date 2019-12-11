#include "C_Sound.h"

int C_Sound::Load(const TCHAR* soundfilename,bool play,)												//사운드 파일 인덱스 번호 지정하여 받기,인자로 받는 bool값은 플레이 여부
{
	m_pSystem->createSound(soundfilename, FMOD_DEFAULT, nullptr, &m_pSound);

	if (play)
	{
		m_pSystem->playSound(m_pSound, nullptr, false, &m_pChannel);		//false로 해줘야 생성과 동시에 음악이 플레이된다.
	}
	
	return m_SoundList;			//사운드 파일의 인덱스 번호
}

bool C_Sound::Play()
{
	bool PlayCheck = false;
	if (m_pChannel != nullptr)
	{
		m_pChannel->isPlaying(&PlayCheck);
	}
	else
	{
		m_pSystem->playSound(m_pSound, nullptr, false, &m_pChannel);
	}
	return true;
}
bool C_Sound::Pause()
{
	bool play;
	bool pause;
	if (m_pChannel != nullptr)
	{
		m_pChannel->isPlaying(&play);
		if (play)
		{
			m_pChannel->getPaused(&pause);
			m_pChannel->setPaused(&pause);
		}
	}
	return true;
}
bool C_Sound::Volume(float ChangeVolume,bool UP)
{
	float NowVolume;
	m_pChannel->getVolume(&NowVolume);
	if (m_pChannel == nullptr)
	{
		return false;
	}
	if (UP)
	{
		NowVolume += ChangeVolume;
		NowVolume = min(10.0f, NowVolume);
	}
	else
	{
		NowVolume -= ChangeVolume;
		NowVolume = max(0.0f, NowVolume);
	}
	m_pChannel->setVolume(NowVolume);

	return true;
}

bool C_Sound::Init()
{
	FMOD::System_Create(&m_pSystem);
	FMOD_RESULT Bool = m_pSystem->init(1, FMOD_INIT_NORMAL, 0);
	if (Bool != FMOD_OK)			//성공여부 판단
	{
		return false;
	}
	return true;
}

bool C_Sound::Frame()
{
	return true;
}

bool C_Sound::Render()
{
	return true;
}

bool C_Sound::Release()
{	
	m_pSound->release();
	m_pSystem->close();
	m_pSystem->release();
	return true;
}


C_Sound::C_Sound()
{
	m_SoundList = 0;
}


C_Sound::~C_Sound()
{
}
