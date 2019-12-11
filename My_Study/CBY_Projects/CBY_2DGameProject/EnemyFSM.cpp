#include "EnemyFSM.h"

bool EnemyFSM::Init()
{
	Input(STATE_STANDBY, EVENT_START, STATE_PATROL);
	Input(STATE_PATROL, EVENT_COL, STATE_ATTACK);
	Input(STATE_ATTACK, EVENT_LOST, STATE_PATROL);
	Input(STATE_PATROL, EVENT_DEATH, STATE_DEATH);
	Input(STATE_ATTACK, EVENT_DEATH, STATE_DEATH);

	return true;
}

void EnemyFSM::Input(DWORD State, DWORD Event, DWORD Output)
{
	EnemyState* monst = nullptr;

	std::map< DWORD, EnemyState*>::iterator monIter;
	monIter = m_MapList.find(State);
	if (monIter == m_MapList.end())
	{
		monst = new EnemyState;
		m_MapList[State] = monst;
	}
	else
	{
		monst = (EnemyState*)monIter->second;
	}

	monst->Input(Event, Output);

}

DWORD EnemyFSM::Output(DWORD State, DWORD Event)
{
	EnemyState* monst = m_MapList[State];
	return monst->Output(Event);
}

EnemyFSM::EnemyFSM()
{
}


EnemyFSM::~EnemyFSM()
{
}
