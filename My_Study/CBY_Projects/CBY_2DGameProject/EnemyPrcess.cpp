#include "EnemyPrcess.h"
#include "C_EnemyAttack.h"
#include "C_EnemyPatrol.h"
#include "C_EnemyDeath.h"
#include "C_EnemyStandby.h"

void Enemy::Process(std::shared_ptr<Gokussgss>& obj)
{
	m_Action->Process(obj);
}

void Enemy::SetAction(DWORD Event)
{
	EnemyrState = EnemyFSM::Get().Output(EnemyrState, Event);
	m_Action = m_ActionList[EnemyrState];
}

bool Enemy::Init()
{
	EnemyFSM::Get().Init();

	EnemyrState = STATE_STANDBY;

	m_ActionList[STATE_STANDBY] = new C_EnemyStandby(this);
	m_ActionList[STATE_PATROL] = new C_EnemyPatrol(this);
	m_ActionList[STATE_ATTACK] = new C_EnemyAttack(this);
	m_ActionList[STATE_DEATH] = new C_EnemyDeath(this);
	
	

	m_Action = m_ActionList[EnemyrState];


	return true;
}

void Enemy::VertexData()
{
	m_vertexdata.resize(4);
	/*m_vertexdata[0].p = D3DXVECTOR3(110.0f, -120.0f, 0.5f);
	m_vertexdata[1].p = D3DXVECTOR3(370.0f, -120.0f, 0.5f);
	m_vertexdata[2].p = D3DXVECTOR3(110.0f, -340.0f, 0.5f);
	m_vertexdata[3].p = D3DXVECTOR3(370.0f, -340.0f, 0.5f);	*/			//정점 좌표 입력
	m_vertexdata[0].p = D3DXVECTOR3(-130.0f, -120.0f, 0.5f);
	m_vertexdata[1].p = D3DXVECTOR3(130.0f, -120.0f, 0.5f);
	m_vertexdata[2].p = D3DXVECTOR3(-130.0f, -340.0f, 0.5f);
	m_vertexdata[3].p = D3DXVECTOR3(130.0f, -340.0f, 0.5f);

	m_vertexdata[0].c = D3DXVECTOR4(1.0f, 0.0f, 1.0f, 1.0f);
	m_vertexdata[1].c = D3DXVECTOR4(0.0f, 1.0f, 0.0f, 1.0f);
	m_vertexdata[2].c = D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f);
	m_vertexdata[3].c = D3DXVECTOR4(1.0f, 1.0f, 0.0f, 1.0f);			//정점 컬러값 입력

	m_vertexdata[0].t = D3DXVECTOR2(0.0f, 0.0f);
	m_vertexdata[1].t = D3DXVECTOR2(1.0f, 0.0f);
	m_vertexdata[2].t = D3DXVECTOR2(0.0f, 1.0f);
	m_vertexdata[3].t = D3DXVECTOR2(1.0f, 1.0f);			//정점 텍스쳐 좌표

	//m_Sprite.Convert(m_vertexdata);

	m_Center.x = (m_vertexdata[0].p.x + m_vertexdata[1].p.x) / 2;
	m_Center.y = (m_vertexdata[0].p.y + m_vertexdata[2].p.y) / 2;
	m_Center.z = (m_vertexdata[0].p.z + m_vertexdata[1].p.z) / 2;

	m_Size.x = abs((m_vertexdata[0].p.x - m_vertexdata[1].p.x) / 2)*0.5f;
	m_Size.y = abs((m_vertexdata[2].p.y - m_vertexdata[0].p.y) / 2)*0.5f;
	m_Size.z = abs((m_vertexdata[0].p.z - m_vertexdata[1].p.z) / 2)*0.5f;

	m_fRect.left = m_Center.x - m_Size.x;
	m_fRect.top = m_Center.y - m_Size.y;
	m_fRect.right = m_Center.x + m_Size.x;
	m_fRect.bottom = m_Center.y + m_Size.y;
}

void Enemy::skillvertex(int i)
{
	switch (i)
	{
	case 0:
		m_vertexdata[0].p = D3DXVECTOR3(80.0f, 480.0f, 0.0f);
		m_vertexdata[1].p = D3DXVECTOR3(366.0f, 480.0f, 0.0f);
		m_vertexdata[2].p = D3DXVECTOR3(80.0f, 700.0f, 0.0f);
		m_vertexdata[3].p = D3DXVECTOR3(366.0f, 700.0f, 0.0f);
		break;

	case 1:
		m_vertexdata[0].p = D3DXVECTOR3(516.0f, 480.0f, 0.0f);
		m_vertexdata[1].p = D3DXVECTOR3(800.0f, 480.0f, 0.0f);
		m_vertexdata[2].p = D3DXVECTOR3(516.0f, 700.0f, 0.0f);
		m_vertexdata[3].p = D3DXVECTOR3(800.0f, 700.0f, 0.0f);
		break;

	case 2:
		m_vertexdata[0].p = D3DXVECTOR3(0.0f, 480.0f, 0.0f);
		m_vertexdata[1].p = D3DXVECTOR3(210.0f, 480.0f, 0.0f);
		m_vertexdata[2].p = D3DXVECTOR3(0.0f, 700.0f, 0.0f);
		m_vertexdata[3].p = D3DXVECTOR3(210.0f, 700.0f, 0.0f);
		break;
	}
}



bool Enemy::Frame()
{
	m_pos = D3DXVECTOR3(0.0f, 0, 0);
	if (StateValue != Z)
	{
		combotime = 0.0f;
	}
	if (!Start && StateNUM != STATE_HERODEATH && StateNUM != STATE_HERODAMAGE)
	{
		m_DamageTime = 0.0f;
		if (!Revers)
		{
			m_pos = D3DXVECTOR3(0.0f, 0, 0);
			if (m_StateList[STATE_JUMP]->Jump == true)
			{
				//jump = 0.0f;
				SetState(STATE_NOMAL);

				switch (StateValue)
				{
				case UP:
					SetState(STATE_NOMAL);
					break;


				case DOWN:
					SetState(STATE_SIT);
					break;

				case RIGHT:
					if (m_Input->KeyCheck(VK_DOWN) != KEY_FREE)
					{
						SetState(STATE_SIT);
						m_pos = D3DXVECTOR3(CHARMOVESPEED, 0, 0) * g_SecondTime;
					}
					if (DoubleClick[RIGHT])
					{
						SetState(STATE_DASH);
						m_pos = D3DXVECTOR3(CHARMOVESPEED*CHARDASHSPEED, 0, 0) * g_SecondTime;
					}
					else
					{
						SetState(STATE_MOVE);
						m_pos = D3DXVECTOR3(CHARMOVESPEED, 0, 0) * g_SecondTime;
					}
					break;


				case LEFT:
					if (m_Input->KeyCheck(VK_DOWN) != KEY_FREE)
					{
						SetState(STATE_SIT);
						m_pos = D3DXVECTOR3(-CHARMOVESPEED, 0, 0) * g_SecondTime;
					}
					else
					{
						SetState(STATE_MOVE);
						m_pos = D3DXVECTOR3(-CHARMOVESPEED, 0, 0) * g_SecondTime;
					}
					break;

				case SPACE:
					SetState(STATE_JUMP);
					//jump += g_SecondTime;
					break;

				case Z:
					SetState(STATE_PUNCH0);
					combotime += g_SecondTime;
					if (combotime >= 0.5f)
					{
						SetState(STATE_PUNCH0_COMBO);
					}
					break;

				case X:
					SetState(STATE_KICK);
					combotime += g_SecondTime;
					if (combotime >= 0.5f)
					{
						SetState(STATE_KICK_COMBO);
					}
					break;

				case G:
					SetState(STATE_SKILL);
				}
			}
			else
			{
			
			}
		}
		else
		{
			m_pos = D3DXVECTOR3(0.0f, 0, 0);
			if (m_StateList[STATE_JUMP]->Jump == true)
			{
				//jump = 0.0f;
				SetState(STATE_NOMAL);

				switch (StateValue)
				{
				case UP:
					SetState(STATE_NOMAL);
					break;

				case DOWN:
					SetState(STATE_SIT);
					break;

				case RIGHT:
					if (m_Input->KeyCheck(VK_DOWN) != KEY_FREE)
					{
						SetState(STATE_SIT);
						m_pos = D3DXVECTOR3(CHARMOVESPEED, 0, 0) * g_SecondTime;
					}
					else
					{
						SetState(STATE_MOVE);
						m_pos = D3DXVECTOR3(CHARMOVESPEED, 0, 0) * g_SecondTime;
					}
					break;

				case LEFT:
					if (m_Input->KeyCheck(VK_DOWN) != KEY_FREE)
					{
						SetState(STATE_SIT);
						m_pos = D3DXVECTOR3(-CHARMOVESPEED, 0, 0) * g_SecondTime;
					}


					if (DoubleClick[LEFT])
					{
						SetState(STATE_DASH);
						m_pos = D3DXVECTOR3(-CHARMOVESPEED* CHARDASHSPEED, 0, 0) * g_SecondTime;
					}
					else
					{
						SetState(STATE_MOVE);
						m_pos = D3DXVECTOR3(-CHARMOVESPEED, 0, 0) * g_SecondTime;
					}
					break;



				case SPACE:
					SetState(STATE_JUMP);
					//jump += g_SecondTime;


				case Z:
					SetState(STATE_PUNCH0);
					combotime += g_SecondTime;
					if (combotime >= 0.5f)
					{
						SetState(STATE_PUNCH0_COMBO);
					}
					break;

				case X:
					SetState(STATE_KICK);
					combotime += g_SecondTime;
					if (combotime >= 0.5f)
					{
						SetState(STATE_KICK_COMBO);
					}
					break;

				case G:
					SetState(STATE_SKILL);
					break;
				}
			}
			else
			{
				/*if (StateValue == RIGHT)
				{
					m_pos = D3DXVECTOR3(0.5f, 0, 0) * g_SecondTime;
				}

				if (StateValue == LEFT)
				{
					m_pos = D3DXVECTOR3(-0.5f, 0, 0) * g_SecondTime;
				}

				if (jump <= 0.9f && !Hight)
				{
					jump += g_SecondTime;
				}
				else
				{
					Hight = true;
				}
				if (Hight)
				{
					jump -= g_SecondTime;
				}

				if (jump <= 0)
				{
					jump = 0;
					Hight = false;
				}*/
			}
		}

		for (int i = 0; i < STATE_COUNT; i++)
		{
			if (i != StateNUM)
			{
				m_StateList[i]->m_Index = 0;
			}
		}
	}
	else if(StateNUM ==STATE_HERODAMAGE)
	{
		m_DamageTime += g_SecondTime;

		if (m_DamageTime < 0.15f)
		{
			m_pos = D3DXVECTOR3(CHARMOVESPEED/2.0f, 0, 0)*g_SecondTime;
		}

		//m_Jumppos = -0.1f;
		if (m_DamageTime >= 1.0f)
		{
			SetState(STATE_NOMAL);
			m_DamageTime = 0.0f;
			//m_Jumppos = 0.0f;
		}
	}
	else if (StateNUM == STATE_HERODEATH && !m_StateList[STATE_HERODEATH]->DeathJump)
	{

		if (!m_StateList[STATE_HERODEATH]->End)
		{
			m_pos = D3DXVECTOR3(CHARMOVESPEED/2.0f, 0, 0) * g_SecondTime;
		}

		m_Jumptime += g_SecondTime* (CHARTIME/2);
		m_Jumppos = ((-m_Gravity)* m_Jumptime*m_Jumptime) + (m_Jump/1.5f * m_Jumptime);


		if (m_Jumppos <= (-0.2f))
		{
			m_Jumppos = -0.2f;
			JUMP = false;
			m_Jumptime = 0.0f;
			m_StateList[STATE_HERODEATH]->DeathJump = true;
		}
		
		
	}
	m_StateList[StateNUM]->Frame();
	if (m_StateList[StateNUM]->Skill&&m_StateList[StateNUM]->Attack)
	{
		for (int i = 0; i < m_SkiiList.size(); i++)
		{
			m_SkiiList[i]->Frame();
		}
	}
	Start = !(m_StateList[STATE_START]->End);
	return true;
}

bool Enemy::Render()
{
	Gokussgss::Render();


	return true;
}

bool Enemy::Release()
{
	//Gokussgss::Release();
	return true;
}


Enemy::Enemy()
{
	StateValue = NONE;
}


Enemy::~Enemy()
{

}

