#include "C_EnemyPatrol.h"

void C_EnemyPatrol::Process(std::shared_ptr<Gokussgss>& obj)
{
	srand(time(NULL));
	int Choice = rand() % 10;
	StateTime -= g_SecondTime;

	if (StateTime < 0)
	{
		/*if (0 <= Choice && Choice <= 1)
		{
			m_pEnemy->StateValue = LEFT;
			StateTime = 1.0f;
		}
		else if (Choice ==2)
		{
			m_pEnemy->StateValue = UP;
			StateTime = 1.0f;
		}
		else if (3 <= Choice && Choice <=4)
		{
			m_pEnemy->StateValue = RIGHT;
			StateTime = 1.0f;
		}
		else if (5 <= Choice && Choice <= 6)
		{
			m_pEnemy->DoubleClick[LEFT] = true;
			m_pEnemy->StateValue = LEFT;
			StateTime = 1.0f;
		}
		else if (7 <= Choice && Choice <= 8)
		{
			m_pEnemy->StateValue = Z;
			StateTime = 2.0f;
		}
		else if (Choice == 9)
		{
			m_pEnemy->StateValue = G;
			StateTime = 3.0f;
		}*/
		if (0 <= Choice && Choice <= 3)
		{
			m_pEnemy->StateValue = LEFT;
			StateTime = 1.0f;
		}
		else if (4 <= Choice && Choice <= 7)
		{
			m_pEnemy->StateValue = RIGHT;
			StateTime = 1.0f;
		}
		else if (8 <= Choice && Choice <= 9)
		{
			m_pEnemy->DoubleClick[LEFT] = true;
			m_pEnemy->StateValue = LEFT;
			StateTime = 1.0f;
		}
	}
	
	m_pEnemy->Frame();

	if (I_Col.collision(obj->m_fRect, m_pEnemy->m_fRect))
	{
		m_pEnemy->SetAction(EVENT_COL);
	}

}

C_EnemyPatrol::C_EnemyPatrol(Enemy* host) :EnemyPrcess(host)
{
	StateTime = 0.0f;
}


C_EnemyPatrol::~C_EnemyPatrol()
{
}
