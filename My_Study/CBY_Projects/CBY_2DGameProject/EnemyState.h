#pragma once
#include "Cstd.h"

enum State
{
	STATE_STANDBY = 0,
	STATE_PATROL,
	STATE_ATTACK,
	STATE_DEATH,
	STATE_NUM
};

enum Event
{
	EVENT_START = 0,
	EVENT_LOST,
	EVENT_COL,
	EVENT_HIT,
	EVENT_DEATH,
	EVENT_END
};

class EnemyState
{
public:
	std::map<DWORD, DWORD> m_StateMap;
	DWORD m_State;

public:
	void Input(DWORD Event, DWORD Output);
	DWORD Output(DWORD Event);


public:
	EnemyState();
	~EnemyState();
};
