#pragma once
#include "EnemyState.h"

class EnemyFSM
{
public:
	std::map<DWORD, EnemyState*>  m_MapList;

public:
	bool Init();
	void Input(DWORD State, DWORD Event, DWORD Output);
	DWORD Output(DWORD State, DWORD Event);

public:
	static EnemyFSM& Get()
	{
		static EnemyFSM mgr;
		return mgr;
	}

public:
	EnemyFSM();
	~EnemyFSM();
};

