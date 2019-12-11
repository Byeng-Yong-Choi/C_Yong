#include "C_Sound.h"

bool C_Sound::Load(FMOD::System*  pSystem, const TCHAR* SoundFile)										//���� ���� �ε��� ��ȣ �����Ͽ� �ޱ�,���ڷ� �޴� bool���� �÷��� ����
{
	std::string loadfile = wtm(SoundFile);
	if (pSystem->createSound(loadfile.c_str(),FMOD_DEFAULT, nullptr, &m_pSound) != FMOD_OK)
	{
		return false;
	}
	return true;
}

bool C_Sound::Play(FMOD::System*  pSystem)
{
	bool PlayCheck = false;
	if (m_pChannel != nullptr)
	{
		m_pChannel->isPlaying(&PlayCheck);
	}
	else
	{
		pSystem->playSound(m_pSound, nullptr, false, &m_pChannel);
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
	return true;
}


C_Sound::C_Sound()
{
	m_SoundList = 0;
}


C_Sound::~C_Sound()
{
}
