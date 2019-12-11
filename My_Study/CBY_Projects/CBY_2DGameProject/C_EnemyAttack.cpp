#include "C_EnemyAttack.h"

void C_EnemyAttack::Process(std::shared_ptr<Gokussgss>& obj)
{
	m_pEnemy->SetState(STATE_HERODAMAGE);
	StateTime += g_SecondTime;
	
	if (StateTime >= 1.0f)
	{
		StateTime = 0.0f;
		m_pEnemy->Damage++;
		if (m_pEnemy->Damage >= 10)
		{
			m_pEnemy->SetAction(EVENT_DEATH);
			m_pEnemy->Damage = 10;
			m_pEnemy->Frame();
			return;
		}
		m_pEnemy->SetAction(EVENT_LOST);
		m_pEnemy->StateValue = UP;
	}
	m_pEnemy->Frame();
}

C_EnemyAttack::C_EnemyAttack(Enemy* host) :EnemyPrcess(host)
{
}


C_EnemyAttack::~C_EnemyAttack()
{
}
