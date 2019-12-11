#include "EnemyState.h"

void EnemyState::Input(DWORD Event, DWORD Output)
{
	m_StateMap[Event] = Output;
}

DWORD EnemyState::Output(DWORD Event)
{
	return m_StateMap[Event];
}

EnemyState::EnemyState()
{
}


EnemyState::~EnemyState()
{
}
