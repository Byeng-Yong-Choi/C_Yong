#include "C_ATTACK.h"

void C_ATTACK::Process(list<C_Monster*>& obj)
{
	
	TowerEffect* Effectnode;
	std::list<TowerEffect*>::iterator efiter;

	C_Monster* iter;
	int MonsterNumber;
	bool weapongo = false;
	fPOINT monpt;
	m_pTower->TowerStateNumber = 1;

	m_pTower->Frame();
	if (!m_pTower->m_WeaponList.empty())
	{
		for (auto Weapon1 : m_pTower->m_WeaponList)					//�̻����� ������ ��ġ�� �޾Ƽ� �����Ͽ� �� �������� ���ư��� ���̴�.
		{
			MonsterNumber = Weapon1->monsternum;
			for (auto monster : obj)
			{
				if (monster->index == MonsterNumber)
				{
					iter = monster;
					monpt = iter->GetPosition();
					weapongo = true;
					break;
				}
				else
					weapongo = false;
			}
			if (weapongo)
			{
				Weapon1->GetMonsterPosition(monpt);
				
			}
			else
			{

			}

		}
		
	}
	
	int Tower;
	Tower = m_pTower->TowerNumber;
	fSphere towerfS;
	fSphere monsterfS;

	if (m_pTower->MakeLvTower)
	{
		{
			for (auto monster : obj)																					//���Ϳ� ĳ������ ���� �浹���� �ľ��� �̻��� ���� �߻�
			{
				towerfS = m_pTower->m_LVTower[Tower].charfsp;
				monsterfS = monster->fsp;
				if (I_Col.Spherecollision(towerfS, monsterfS))
				{
					if (m_pTower->TowerNumber == 2)
					{
						
				
							monster->monSpeed = MONSTERSPPED - MONSTERSPPED / 3.0f;
							m_pTower->m_LVTower[Tower].Enemy(m_pTower->CenterPT, monster->GetPoint());
							cold = true;
					}
					else
					{
						if (m_pTower->m_LVTower[Tower].WeaponGo)
						{
							if (m_pTower->TowerNumber == 3 && m_pTower->m_WeaponList.size() == 1)
							{
								for (auto wealist : m_pTower->m_WeaponList)
								{
									dgr = m_pTower->m_LVTower[Tower].Enemy(m_pTower->CenterPT, monster->GetPoint());
									wealist->mondgr = dgr;
									if (m_pTower->m_LVTower[Tower].Revers)
									{
										wealist->Revers = true;
									}
									else
									{
										wealist->Revers = false;
									}
								}
							}
							else
							{
								MonsterNumber = monster->index;
								TowerWeapon* Weapon = new TowerWeapon(m_pTower->m_Weapon[Tower]);

								
								if (m_pTower->m_Tower[Tower].Revers)
								{
									Weapon->Revers = m_pTower->m_Tower[Tower].Revers;
									if (!m_pTower->TowerNumber == 3)
									{
										Weapon->SetPosition(m_pTower->BitMapRt.left, m_pTower->CenterPT.y);
									}
								}
								m_pTower->m_WeaponList.push_back(Weapon);
								m_pTower->m_WeaponList.back()->GetMonsterNum(MonsterNumber);
							}
						}

						m_pTower->m_LVTower[Tower].Enemy(m_pTower->CenterPT, monster->GetPoint());
				

						return;
					}
				}
			}
		}
		
	}
	else
	{
	
		{
			for (auto monster : obj)
			{
				towerfS = m_pTower->m_Tower[Tower].charfsp;
				monsterfS = monster->fsp;
				if (I_Col.Spherecollision(towerfS, monsterfS))
				{
					if (m_pTower->TowerNumber == 2)
					{
						
							monster->monSpeed = MONSTERSPPED - MONSTERSPPED / 4.0f;
							m_pTower->m_Tower[Tower].Enemy(m_pTower->CenterPT, monster->GetPoint());
							cold = true;
							
					}
					else
					{
						if (m_pTower->TowerNumber == 3 && m_pTower->m_WeaponList.size() == 1)
						{
							for (auto wealist : m_pTower->m_WeaponList)
							{
								dgr = m_pTower->m_Tower[Tower].Enemy(m_pTower->CenterPT, monster->GetPoint());
								wealist->mondgr = dgr;
								if (m_pTower->m_LVTower[Tower].Revers)
								{
									wealist->Revers = true;
								}
								else
								{
									wealist->Revers = false;
								}
							}
						}
						else
						{
							if (m_pTower->m_Tower[Tower].WeaponGo)
							{
								MonsterNumber = monster->index;
								TowerWeapon* Weapon = new TowerWeapon(m_pTower->m_Weapon[Tower]);
								if (m_pTower->m_Tower[Tower].Revers)
								{
									Weapon->Revers = m_pTower->m_Tower[Tower].Revers;
									if (!m_pTower->TowerNumber == 3)
									{
										Weapon->SetPosition(m_pTower->BitMapRt.left, m_pTower->CenterPT.y);
									}
								}
								m_pTower->m_WeaponList.push_back(Weapon);
								m_pTower->m_WeaponList.back()->GetMonsterNum(MonsterNumber);
							}
							
								m_pTower->m_Tower[Tower].Enemy(m_pTower->CenterPT, monster->GetPoint());
							
						}
						return;
					}
				}
			}
		}
	}

	if (cold)
	{
		cold = false;
		return;
	}

	m_pTower->SetAction(EVENT_LOSTTARGET);

}



C_ATTACK::C_ATTACK(C_Tower* host) : C_TowerStateProcess(host)
{
	
}


C_ATTACK::~C_ATTACK()
{
}
