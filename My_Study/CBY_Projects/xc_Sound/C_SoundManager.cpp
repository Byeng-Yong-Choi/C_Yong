#include "C_SoundManager.h"


C_Sound* C_SoundManager::Load(const TCHAR* filename,bool play)
{
	C_Sound* sound;
	sound->Init();
	sound->Load(filename, play);
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i] == sound)
		{
			return sound;
		}
	}
	list.insert(make_pair(++SoundChannel, sound));
	return list[SoundChannel];
		
	delete sound;


	return nullptr;
}

bool C_SoundManager::Release()
{
	for (int i = 0; i < SoundChannel; i++)
	{
		C_Sound* temp = list[i];
		temp->Release();
		delete temp;
	}
	list.clear();
	return true;
}

C_SoundManager::C_SoundManager()
{
	SoundChannel = -1;
}


C_SoundManager::~C_SoundManager()
{
	Release();
}
