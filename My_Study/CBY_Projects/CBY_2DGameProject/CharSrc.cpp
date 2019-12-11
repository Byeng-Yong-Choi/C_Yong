#include "CharSrc.h"

HRESULT CharSrc::Create(ID3D11Device* pd3dDevice, ID3D11DeviceContext* Context)
{
	HRESULT hr = S_OK;


	return hr;
}

void CharSrc::SetWorldandMatrix(D3DXMATRIX* world, D3DXMATRIX* view, D3DXMATRIX* proj, D3DXVECTOR3 pos, fRECT Enemy_rt)
{

	if (Revers)
	{
		D3DXMATRIX rot,mat;
		D3DXMatrixRotationY(&rot,135);
		*world = rot*(*world);
	}

	m_StateList[StateNUM]->SetMatrix(world, view, proj);

	RectSet(pos);
}

void CharSrc::RectSet(D3DXVECTOR3 pos)
{
	D3DXVECTOR3 Center;
	Center.x = m_Center.x + pos.x;
	Center.y = m_Center.y + pos.y;
	Center.z = m_Center.z + pos.z;			//센터값에서 이동값 더함

	m_fRect.left = Center.x - m_Size.x;
	m_fRect.top = Center.y + m_Size.y;
	m_fRect.right = Center.x + m_Size.x;
	m_fRect.bottom = Center.y - m_Size.y;
}

void CharSrc::skill()
{

}

void CharSrc::SetState(int num)
{
	switch (num)
	{
	case STATE_START:
		StateNUM = STATE_START;
		break; 

	case STATE_NOMAL:
		StateNUM = STATE_NOMAL;
		break;

	case STATE_MOVE:
		StateNUM = STATE_MOVE;
		for (int i = 0; i < 4; i++)
		{
			DoubleClick[i] = false;
		}
		break;

	case STATE_SIT:
		StateNUM = STATE_SIT;
		for (int i = 0; i < 4; i++)
		{
			DoubleClick[i] = false;
		}
		break;

	case STATE_JUMP:
		StateNUM = STATE_JUMP;
		for (int i = 0; i < 4; i++)
		{
			DoubleClick[i] = false;
		}
		break;

	case STATE_DASH:
		StateNUM = STATE_DASH;
		for (int i = 0; i < 4; i++)
		{
			if (!Revers)
			{
				if (i != RIGHT)
					DoubleClick[i] = false;
			}
			else
			{
				if (i != LEFT)
					DoubleClick[i] = false;
			}
		}
		break;
		
	case STATE_PUNCH0:
		StateNUM = STATE_PUNCH0;
		for (int i = 0; i < 4; i++)
		{
			DoubleClick[i] = false;
		}
		break; 

	case STATE_PUNCH0_COMBO:
		StateNUM = STATE_PUNCH0_COMBO;
		for (int i = 0; i < 4; i++)
		{
			DoubleClick[i] = false;
		}
		break;

	case STATE_KICK:
		StateNUM = STATE_KICK;
		for (int i = 0; i < 4; i++)
		{
			DoubleClick[i] = false;
		}
		break;

	case STATE_KICK_COMBO:
		StateNUM = STATE_KICK_COMBO;
		for (int i = 0; i < 4; i++)
		{
			DoubleClick[i] = false;
		}
		break;

	case STATE_HERODAMAGE:
		StateNUM = STATE_HERODAMAGE;
		for (int i = 0; i < 4; i++)
		{
			DoubleClick[i] = false;
		}
		break;	
		
	case STATE_SKILL:
		StateNUM = STATE_SKILL;
		for (int i = 0; i < 4; i++)
		{
			DoubleClick[i] = false;
		}
		break; 	

	case STATE_HERODEATH:
		StateNUM = STATE_HERODEATH;
		for (int i = 0; i < 4; i++)
		{
			DoubleClick[i] = false;
		}
		break;

	}
	m_StateList[StateNUM]->End = false;
}

void CharSrc::SetAniTime(float Time)
{
	m_StateList[StateNUM]->m_SecPerRender = Time;
}


bool CharSrc::Frame()
{
	if (!Start && StateNUM!= STATE_HERODEATH)
	{
		if (!Revers)
		{
			m_pos = D3DXVECTOR3(0.0f, 0, 0);
			if (!JUMP)
			{
				//jump = 0.0f;
				DoubleClickTime[RIGHT] -= g_SecondTime;

				SetState(STATE_NOMAL);


				if (m_Input->KeyCheck(VK_UP) != KEY_FREE)
				{
					SetState(STATE_NOMAL);
				}

				if (m_Input->KeyCheck(VK_DOWN) != KEY_FREE)
				{
					SetState(STATE_SIT);
				}

				if (m_Input->KeyCheck(VK_RIGHT) != KEY_FREE && m_Input->KeyCheck(VK_UP) == KEY_FREE)		//업키일때 좌우 이동불가
				{
					if (m_Input->KeyCheck(VK_DOWN) != KEY_FREE)
					{
						SetState(STATE_SIT);
						m_pos = D3DXVECTOR3(0.5f, 0, 0) * g_SecondTime;
					}
					else
					{
						if (m_Input->KeyData[VK_RIGHT] == KEY_PUSH)
						{
							if (DoubleClickTime[RIGHT] > 0.0f)
							{
								DoubleClick[RIGHT] = true;
							}
							else
							{
 								DoubleClickTime[RIGHT] = 0.3f;
								DoubleClick[RIGHT] = false;
							}
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
					}
				}

				if (m_Input->KeyCheck(VK_LEFT) != KEY_FREE && m_Input->KeyCheck(VK_UP) == KEY_FREE)    //업키일때 좌우 이동불가
				{
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
				}

				if (m_Input->KeyCheck(VK_SPACE) != KEY_FREE)
				{
					SetState(STATE_JUMP);
					JUMP = true;
					//jump += g_SecondTime;
				}

				if (m_Input->KeyCheck('Z') != KEY_FREE)
				{
					SetState(STATE_PUNCH0);
					combotime += g_SecondTime;
					if (combotime >= 0.5f)
					{
						SetState(STATE_PUNCH0_COMBO);
					}
				}
				

				if (m_Input->KeyCheck('X') != KEY_FREE)
				{
					SetState(STATE_KICK);
					combotime += g_SecondTime;
					if (combotime >= 0.5f)
					{
						SetState(STATE_KICK_COMBO);
					}
				}
				
				if (m_Input->KeyCheck('X') == KEY_FREE && m_Input->KeyCheck('Z') == KEY_FREE)
				{
					combotime = 0.0f;
				}

				if (m_Input->KeyCheck('G') != KEY_FREE)
				{
					SetState(STATE_SKILL);
				}
			}
			else
			{
				if (m_Input->KeyCheck(VK_RIGHT) != KEY_FREE)
				{
					m_pos = D3DXVECTOR3(CHARMOVESPEED, 0, 0) * g_SecondTime;
				}

				if (m_Input->KeyCheck(VK_LEFT) != KEY_FREE)
				{
					m_pos = D3DXVECTOR3(-CHARMOVESPEED, 0, 0) * g_SecondTime;
				}

				m_Jumptime += g_SecondTime* CHARTIME;
				m_Jumppos = ((-m_Gravity)* m_Jumptime*m_Jumptime) + (m_Jump*m_Jumptime);
				if (m_Jumppos <= m_Jumpfpos)
				{
					m_Jumppos = m_Jumpfpos;
					m_Jumptime = 0.0;
					JUMP = false;
					m_StateList[STATE_JUMP]->m_Index = 0;
				}

			}
		}
		else
		{
			m_pos = D3DXVECTOR3(0.0f, 0, 0);
			if (!JUMP)
			{
				//jump = 0.0f;
				DoubleClickTime[LEFT] -= g_SecondTime;

				SetState(STATE_NOMAL);


				if (m_Input->KeyCheck(VK_UP) != KEY_FREE)
				{
					SetState(STATE_NOMAL);
				}

				if (m_Input->KeyCheck(VK_DOWN) != KEY_FREE)
				{
					SetState(STATE_SIT);
				}

				if (m_Input->KeyCheck(VK_RIGHT) != KEY_FREE && m_Input->KeyCheck(VK_UP) == KEY_FREE)		//업키일때 좌우 이동불가
				{
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
				}

				if (m_Input->KeyCheck(VK_LEFT) != KEY_FREE && m_Input->KeyCheck(VK_UP) == KEY_FREE)    //업키일때 좌우 이동불가
				{
					if (m_Input->KeyCheck(VK_DOWN) != KEY_FREE)
					{
						SetState(STATE_SIT);
						m_pos = D3DXVECTOR3(-CHARMOVESPEED, 0, 0) * g_SecondTime;
					}
					else
					{
						if (m_Input->KeyData[VK_LEFT] == KEY_PUSH)
						{
							if (DoubleClickTime[LEFT] > 0.1f)
							{
								DoubleClick[LEFT] = true;
							}
							else
							{
								DoubleClickTime[LEFT] = 0.3f;
								DoubleClick[LEFT] = false;
							}
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
					}

				}

				if (m_Input->KeyCheck(VK_SPACE) != KEY_FREE)
				{
					SetState(STATE_JUMP);
					JUMP = true;
				}

				if (m_Input->KeyCheck('Z') != KEY_FREE)
				{
					SetState(STATE_PUNCH0);
					combotime += g_SecondTime;
				
					if (combotime >= 0.5f)
					{
						SetState(STATE_PUNCH0_COMBO);
					}
				}

				if (m_Input->KeyCheck('X') != KEY_FREE)
				{
					SetState(STATE_KICK);
					combotime += g_SecondTime;
					if (combotime >= 0.5f)
					{
						SetState(STATE_KICK_COMBO);
					}
				}
			
				if (m_Input->KeyCheck('X') == KEY_FREE && m_Input->KeyCheck('Z') == KEY_FREE)
				{
					combotime = 0.0f;
				}

				if (m_Input->KeyCheck('G') != KEY_FREE)
				{
					SetState(STATE_SKILL);
				}
			}
			else
			{
				if (m_Input->KeyCheck(VK_RIGHT) != KEY_FREE)
				{
					m_pos = D3DXVECTOR3(CHARMOVESPEED, 0, 0) * g_SecondTime;
				}

				if (m_Input->KeyCheck(VK_LEFT) != KEY_FREE)
				{
					m_pos = D3DXVECTOR3(-CHARMOVESPEED, 0, 0) * g_SecondTime;
				}

				m_Jumptime += g_SecondTime* CHARTIME;
				m_Jumppos = ((-m_Gravity)* m_Jumptime*m_Jumptime) + (m_Jump*m_Jumptime);
				if (m_Jumppos <= m_Jumpfpos)
				{
					m_Jumppos = m_Jumpfpos;
					m_Jumptime = 0.0f;
					JUMP = false;
					m_StateList[STATE_JUMP]->m_Index = 0;
				}
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
	else if (StateNUM == STATE_HERODEATH)
	{
		/*if (!m_StateList[STATE_HERODEATH]->End)
		{
			m_pos = D3DXVECTOR3(0.5f, 0, 0) * g_SecondTime;
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
			m_StateList[STATE_HERODEATH]->DeathJump=true;
		}*/
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

bool CharSrc::Render()
{
	m_StateList[StateNUM]->Render();
	if (m_StateList[StateNUM]->Skill&&m_StateList[StateNUM]->Attack)
	{
		for (int i = 0; i < m_SkiiList.size(); i++)
		{
			m_SkiiList[i]->Render();
		}
	}
	return true;
}

void CharSrc::VertexData()
{
	m_vertexdata.resize(4);
	//m_vertexdata[0].p = D3DXVECTOR3(240.0f, 480.0f, 0.0f);
	//m_vertexdata[1].p = D3DXVECTOR3(500.0f, 480.0f, 0.0f);
	//m_vertexdata[2].p = D3DXVECTOR3(240.0f, 700.0f, 0.0f);
	//m_vertexdata[3].p = D3DXVECTOR3(500.0f, 700.0f, 0.0f);				//정점 좌표 입력(원근 투영)
	
	m_vertexdata[0].p = D3DXVECTOR3(-130.0f, -120.0f, 0.5f);
	m_vertexdata[1].p = D3DXVECTOR3(130.0f, -120.0f, 0.5f);
	m_vertexdata[2].p = D3DXVECTOR3(-130.0f, -340.0f, 0.5f);
	m_vertexdata[3].p = D3DXVECTOR3(130.0f, -340.0f, 0.5f);				//정점 좌표 입력(직교 투영)	

	m_vertexdata[0].c = D3DXVECTOR4(1.0f, 0.0f, 1.0f, 1.0f);
	m_vertexdata[1].c = D3DXVECTOR4(0.0f, 1.0f, 0.0f, 1.0f);
	m_vertexdata[2].c = D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f);
	m_vertexdata[3].c = D3DXVECTOR4(1.0f, 1.0f, 0.0f, 1.0f);			//정점 컬러값 입력

	m_vertexdata[0].t = D3DXVECTOR2(0.0f, 0.0f);
	m_vertexdata[1].t = D3DXVECTOR2(1.0f, 0.0f);
	m_vertexdata[2].t = D3DXVECTOR2(0.0f, 1.0f);
	m_vertexdata[3].t = D3DXVECTOR2(1.0f, 1.0f);			//정점 텍스쳐 좌표



	//m_Sprite.Convert(m_vertexdata);

	m_Center.x = (m_vertexdata[1].p.x + m_vertexdata[0].p.x) / 2;
	m_Center.y = (m_vertexdata[0].p.y + m_vertexdata[2].p.y) / 2;
	m_Center.z = (m_vertexdata[0].p.z + m_vertexdata[1].p.z) / 2;

	m_Size.x = abs((m_vertexdata[0].p.x - m_vertexdata[1].p.x) / 2)*0.5f;
	m_Size.y = abs((m_vertexdata[2].p.y - m_vertexdata[0].p.y) / 2)*0.5f;
	m_Size.z = abs((m_vertexdata[0].p.z - m_vertexdata[1].p.z) / 2)*0.5f;

	m_fRect.left = m_Center.x - m_Size.x;
	m_fRect.top = m_Center.y + m_Size.y;
	m_fRect.right = m_Center.x + m_Size.x;
	m_fRect.bottom = m_Center.y - m_Size.y;
}


CharSrc::CharSrc()
{
	m_pos = D3DXVECTOR3(0, 0, 0);
	StateNUM = 0;
	JUMP = false;
	m_Jump= CHARJUMP;
	m_Jumptime=0.0f;
	m_Gravity = GRAVITY;
	m_Jumpfpos=0.0f;
	m_Jumppos = 0.0f;
	Start = true;
	combotime = 0.0f;
	Revers = false;
	for (int i = 0; i < KEYCOUNT; i++)
	{
		DoubleClickTime[i] = 0.0f;
		DoubleClick[i] = false;
	}
	D3DXMatrixIdentity(&m_mat);
	D3DXMatrixIdentity(&m_world);
	D3DXMatrixIdentity(&m_view);
	D3DXMatrixIdentity(&m_proj);
	Damage = 0;
	m_DamageTime = 0.0f;
}


CharSrc::~CharSrc()
{
}
