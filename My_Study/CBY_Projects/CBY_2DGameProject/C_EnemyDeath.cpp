#include "C_EnemyDeath.h"

void C_EnemyDeath::Process(std::shared_ptr<Gokussgss>& obj)
{
	m_pEnemy->SetState(STATE_HERODEATH);
	m_pEnemy->Frame();
}

C_EnemyDeath::C_EnemyDeath(Enemy* host) :EnemyPrcess(host)
{
}


C_EnemyDeath::~C_EnemyDeath()
{
}
