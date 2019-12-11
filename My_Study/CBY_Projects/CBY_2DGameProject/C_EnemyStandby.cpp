#include "C_EnemyStandby.h"

void C_EnemyStandby::Process(std::shared_ptr<Gokussgss>& obj)
{
	m_pEnemy->Frame();
	if (obj->m_StateList[obj->StateNUM]->End)
	{
		m_pEnemy->SetAction(EVENT_START);
	}
}

C_EnemyStandby::C_EnemyStandby(Enemy* host) :EnemyPrcess(host)
{
}


C_EnemyStandby::~C_EnemyStandby()
{
}
