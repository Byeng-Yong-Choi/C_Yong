#include "Gokussgss.h"

HRESULT Gokussgss::Create(ID3D11Device* pd3dDevice, ID3D11DeviceContext* Context)
{
	HRESULT hr = S_OK;

	m_Input = std::make_shared<CBY_Input>();
	m_pd3dDevice = pd3dDevice;
	m_pContext = Context;
	m_StateList.resize(STATE_COUNT);
	VertexData();
	TextSrc();
	skill();

	StateNUM = STATE_START;
	return hr;
}

void Gokussgss::SetWorldandMatrix(D3DXMATRIX* world, D3DXMATRIX* view, D3DXMATRIX* proj, D3DXVECTOR3 pos, fRECT Enemy_rt)
{
	//D3DXVECTOR2 Enemy_Center;
	//Enemy_Center.x = (Enemy_rt.right + Enemy_rt.left) / 2;
	//Enemy_Center.y = (Enemy_rt.bottom + Enemy_rt.top) / 2;		//적의 센터위치를 추적

	D3DXMATRIX skillmat_0, skillmat_1;		//0은 캐릭터 앞에 쏘는 이펙트, 1은상대 캐릭터가 맞는 이펙트
	D3DXMatrixIdentity(&skillmat_1);
	skillmat_0 = *world;
	skillmat_0._41 += m_skillpos.x;
	skillmat_1._41 = Enemy_rt.left;

	if (Revers)
	{
		D3DXMATRIX rot;
		D3DXMatrixRotationY(&rot, 135);
		*world = rot * (*world);
		skillmat_0 = rot * skillmat_0;
		skillmat_1 = rot * skillmat_0;
	}
	
	m_StateList[StateNUM]->SetMatrix(world, view, proj);
	m_SkiiList[1]->SetMatrix(&skillmat_0, view, proj);
	m_SkiiList[2]->SetMatrix(&skillmat_1, view, proj);
	m_SkiiList[0]->SetMatrix(nullptr, view, proj);

	RectSet(pos);

	m_SkiiList[0]->m_VerTex[0].p.x = skillmat_0._41;
	m_SkiiList[0]->m_VerTex[2].p.x = skillmat_0._41;
	m_SkiiList[0]->m_VerTex[1].p.x = skillmat_1._41+ m_Size.x;
	m_SkiiList[0]->m_VerTex[3].p.x = skillmat_1._41+ m_Size.x;

	if (m_StateList[StateNUM]->Skill&&m_StateList[StateNUM]->Attack)
	{
		if (Revers)
		{
			m_fRect.left -= m_skillpos.x;
		}
		else
		{
			m_fRect.right += m_skillpos.x;
		}
	}
}




void Gokussgss::TextSrc()
{
	//STATE_START:
		m_StateList[STATE_START] = std::make_shared<CSprite>();
		m_StateList[STATE_START]->Create(m_pd3dDevice, m_pContext, L"../../data/shader/ColorBlend.txt", nullptr, "VSmat", "PS");
		TextArray(STATE_START);
		m_StateList[STATE_START]->SetTextureArray(m_str);
		m_StateList[STATE_START]->UpdateVertexData(m_vertexdata);
		//m_StateList[STATE_START]->SetAnimation(1.0f, 0.1f, 6, 768, 7, 896);
		

	//STATE_NOMAL:
		m_StateList[STATE_NOMAL] = std::make_shared<CSprite>();
		m_StateList[STATE_NOMAL]->Create(m_pd3dDevice, m_pContext, L"../../data/shader/ColorBlend.txt", nullptr, "VSmat", "PS");
		TextArray(STATE_NOMAL);
		m_StateList[STATE_NOMAL]->SetTextureArray(m_str);
		m_StateList[STATE_NOMAL]->UpdateVertexData(m_vertexdata);
		//m_StateList[STATE_NOMAL]->SetAnimation(1.0f, 0.1f, 5, 640, 1, 128);
		

	//STATE_MOVE:
		m_StateList[STATE_MOVE] = std::make_shared<CSprite>();
		m_StateList[STATE_MOVE]->Create(m_pd3dDevice, m_pContext, L"../../data/shader/ColorBlend.txt", L"../../data/text/GokuSSGSS/move/Move.png", "VSmat", "PS");
		m_StateList[STATE_MOVE]->UpdateVertexData(m_vertexdata);
		m_StateList[STATE_MOVE]->SetAnimation(1.0f, 0.1f, 4, 512, 2, 256);
		
	//STATE_SIT:
		m_StateList[STATE_SIT] = std::make_shared<CSprite>();
		m_StateList[STATE_SIT]->Create(m_pd3dDevice, m_pContext, L"../../data/shader/ColorBlend.txt", L"../../data/text/GokuSSGSS/sit/Sit.png", "VSmat", "PS");
		m_StateList[STATE_SIT]->UpdateVertexData(m_vertexdata);
		m_StateList[STATE_SIT]->SetAnimation(1.0f, 0.1f, 2, 256, 2, 256);
		

	//STATE_JUMP:
		m_StateList[STATE_JUMP] = std::make_shared<CSprite>();
		m_StateList[STATE_JUMP]->Create(m_pd3dDevice, m_pContext, L"../../data/shader/ColorBlend.txt", L"../../data/text/GokuSSGSS/jump/Jump.png", "VSmat", "PS");
		m_StateList[STATE_JUMP]->UpdateVertexData(m_vertexdata);
		m_StateList[STATE_JUMP]->SetAnimation(1.0f, 0.2f, 5, 640, 2, 256);
		m_StateList[STATE_JUMP]->Jump = true;
		

	//STATE_DASH:
		m_StateList[STATE_DASH] = std::make_shared<CSprite>();
		m_StateList[STATE_DASH]->Create(m_pd3dDevice, m_pContext, L"../../data/shader/ColorBlend.txt", L"../../data/text/GokuSSGSS/dash/Dash.png", "VSmat", "PS");
		m_StateList[STATE_DASH]->UpdateVertexData(m_vertexdata);
		m_StateList[STATE_DASH]->SetAnimation(1.0f, 0.1f, 3, 384, 2, 256);
	

	//STATE_PUNCH0:
		m_StateList[STATE_PUNCH0] = std::make_shared<CSprite>();
		m_StateList[STATE_PUNCH0]->Create(m_pd3dDevice, m_pContext, L"../../data/shader/ColorBlend.txt", L"../../data/text/GokuSSGSS/punch/Punch0.png", "VSmat", "PS");
		m_StateList[STATE_PUNCH0]->UpdateVertexData(m_vertexdata);
		m_StateList[STATE_PUNCH0]->SetAnimation(1.0f, 0.1f, 2, 256, 2, 256);
	

	//STATE_PUNCH0_COMBO:
		m_StateList[STATE_PUNCH0_COMBO] = std::make_shared<CSprite>();
		m_StateList[STATE_PUNCH0_COMBO]->Create(m_pd3dDevice, m_pContext, L"../../data/shader/ColorBlend.txt", L"../../data/text/GokuSSGSS/punch/Puch0_Combo.png", "VSmat", "PS");
		m_StateList[STATE_PUNCH0_COMBO]->UpdateVertexData(m_vertexdata);
		m_StateList[STATE_PUNCH0_COMBO]->SetAnimation(1.0f, 0.1f, 5, 640, 3, 384);

	//STATE_KICK:
		m_StateList[STATE_KICK] = std::make_shared<CSprite>();
		m_StateList[STATE_KICK]->Create(m_pd3dDevice, m_pContext, L"../../data/shader/ColorBlend.txt", nullptr, "VSmat", "PS");
		TextArray(STATE_KICK);
		m_StateList[STATE_KICK]->SetTextureArray(m_str);
		m_StateList[STATE_KICK]->UpdateVertexData(m_vertexdata);
		

	//STATE_KICK_COMBO:
		m_StateList[STATE_KICK_COMBO] = std::make_shared<CSprite>();
		m_StateList[STATE_KICK_COMBO]->Create(m_pd3dDevice, m_pContext, L"../../data/shader/ColorBlend.txt", nullptr, "VSmat", "PS");
		TextArray(STATE_KICK_COMBO);
		m_StateList[STATE_KICK_COMBO]->SetTextureArray(m_str);
		m_StateList[STATE_KICK_COMBO]->UpdateVertexData(m_vertexdata);
		StateNUM = STATE_KICK_COMBO;
		SetAniTime(0.075f);
	

	//STATE_HERODAMAGE
		m_StateList[STATE_HERODAMAGE] = std::make_shared<CSprite>();
		m_StateList[STATE_HERODAMAGE]->Create(m_pd3dDevice, m_pContext, L"../../data/shader/ColorBlend.txt", nullptr, "VSmat", "PS");
		TextArray(STATE_HERODAMAGE);
		m_StateList[STATE_HERODAMAGE]->SetTextureArray(m_str);
		m_StateList[STATE_HERODAMAGE]->UpdateVertexData(m_vertexdata);
		m_StateList[STATE_HERODAMAGE]->Jump = true;

	//STATE_SKILL:
		m_StateList[STATE_SKILL] = std::make_shared<CSprite>();
		m_StateList[STATE_SKILL]->Create(m_pd3dDevice, m_pContext, L"../../data/shader/ColorBlend.txt", nullptr, "VSmat", "PS");
		TextArray(STATE_SKILL);
		m_StateList[STATE_SKILL]->SetTextureArray(m_str);
		m_StateList[STATE_SKILL]->UpdateVertexData(m_vertexdata);
		//m_StateList[STATE_SKILL]->SetAnimation(1.0f, 0.1f, 4, 512, 3, 384);
		m_StateList[STATE_SKILL]->Skill = true;
	
	//STATE_DEATH
		m_StateList[STATE_HERODEATH] = std::make_shared<CSprite>();
		m_StateList[STATE_HERODEATH]->Create(m_pd3dDevice, m_pContext, L"../../data/shader/ColorBlend.txt", nullptr, "VSmat", "PS");
		TextArray(STATE_HERODEATH);
		m_StateList[STATE_HERODEATH]->SetTextureArray(m_str);
		m_StateList[STATE_HERODEATH]->UpdateVertexData(m_vertexdata);
		m_StateList[STATE_HERODEATH]->Death = true;
	

}

void Gokussgss::TextArray(int i)
{
	m_str.clear();
	int index = 0;

	switch (i)
	{
	case STATE_START:
		m_str.resize(42);
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_1.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_2.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_3.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_4.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_5.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_6.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_7.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_8.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_9.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_10.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_11.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_12.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_13.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_14.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_15.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_16.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_17.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_18.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_19.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_20.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_21.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_22.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_23.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_24.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_25.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_26.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_27.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_28.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_29.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_30.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_31.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_32.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_33.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_34.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_35.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_36.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_37.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_38.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_39.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_40.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_41.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/start/Start_42.png";
		break;

	case STATE_NOMAL:
		m_str.resize(5);
		m_str[index++] = L"../../data/text/GokuSSGSS/stand/Stand_1.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/stand/Stand_2.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/stand/Stand_3.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/stand/Stand_4.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/stand/Stand_5.png";
		break;
	
	case STATE_KICK:
		m_str.resize(9);
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_0.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_1.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_2.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_3.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_4.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_5.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_6.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_7.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_8.png";
		break;

	case STATE_KICK_COMBO:
		m_str.resize(47);
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_0.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_1.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_2.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_3.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_4.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_5.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_6.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_7.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_8.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_9.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_10.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_11.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_12.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_13.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_14.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_15.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_16.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_17.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_18.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_19.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_20.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_21.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_22.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_23.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_24.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_25.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_26.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_27.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_28.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_29.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_30.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_31.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_32.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_33.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_34.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_35.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_36.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_37.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_38.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_39.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_40.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_41.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_42.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_43.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_44.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_45.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/kick/Kick_Combo_46.png";
		break;

	case STATE_HERODAMAGE:
		m_str.resize(5);
		m_str[index++] = L"../../data/text/GokuSSGSS/damage/Damage_0.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/damage/Damage_1.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/damage/Damage_2.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/damage/Damage_3.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/damage/Damage_4.png";
		break;

	case STATE_SKILL:
		m_str.resize(11);
		m_str[index++] = L"../../data/text/GokuSSGSS/skill/Energy_1.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/skill/Energy_2.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/skill/Energy_3.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/skill/Energy_4.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/skill/Energy_5.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/skill/Energy_6.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/skill/Energy_7.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/skill/Energy_8.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/skill/Energy_9.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/skill/Energy_10.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/skill/Energy_11.png";
		break;

	case STATE_HERODEATH:
		m_str.resize(6);
		m_str[index++] = L"../../data/text/GokuSSGSS/death/Death_1.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/death/Death_2.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/death/Death_3.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/death/Death_4.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/death/Death_5.png";
		m_str[index++] = L"../../data/text/GokuSSGSS/death/Death_6.png";
		break;
	}

}

void Gokussgss::skill()
{
	m_SkiiList.resize(3);

	m_SkiiList[0] = std::make_shared<CSprite>();
	m_SkiiList[0]->Create(m_pd3dDevice, m_pContext, L"../../data/shader/ColorBlend.txt", L"../../data/text/GokuSSGSS/skill/EnergyEffect1_0.png", "VSmat", "PS");
	skillvertex(0);
	//m_Sprite.Convert(m_vertexdata);
	m_SkiiList[0]->UpdateVertexData(m_vertexdata);
	m_SkiiList[0]->SetAnimation(1.0f, 0.2f, 3, 384, 1, 128);
	//m_SkiiList[1]->SetEffectLength();
	
	m_SkiiList[1] = std::make_shared<CSprite>();
	m_SkiiList[1]->Create(m_pd3dDevice, m_pContext, L"../../data/shader/ColorBlend.txt", L"../../data/text/GokuSSGSS/skill/EnergyEffect0.png", "VSmat", "PS");
	skillvertex(1);		//정점 좌표 입력
	//m_Sprite.Convert(m_vertexdata);
	m_SkiiList[1]->UpdateVertexData(m_vertexdata);
	m_SkiiList[1]->SetAnimation(1.0f, 0.2f, 3, 384, 1, 128);

	
	m_SkiiList[2] = std::make_shared<CSprite>();
	m_SkiiList[2]->Create(m_pd3dDevice, m_pContext, L"../../data/shader/ColorBlend.txt", L"../../data/text/GokuSSGSS/skill/EnergyEffect2.png", "VSmat", "PS");
	skillvertex(2);			//정점 좌표 입력
	//m_Sprite.Convert(m_vertexdata);
	m_SkiiList[2]->UpdateVertexData(m_vertexdata);
	m_SkiiList[2]->SetAnimation(1.0f, 0.2f, 3, 384, 1, 128);
}

void Gokussgss::skillvertex(int i)
{
	switch (i)
	{
	case 0:
		m_vertexdata[0].p = D3DXVECTOR3(0.0f, -120.0f, 0.0f);
		m_vertexdata[1].p = D3DXVECTOR3(0.0f, -120.0f, 0.0f);
		m_vertexdata[2].p = D3DXVECTOR3(0.0f, -340.0f, 0.0f);
		m_vertexdata[3].p = D3DXVECTOR3(0.0f, -340.0f, 0.0f);		
		break;

	case 1:
		m_vertexdata[0].p = D3DXVECTOR3(-142.0f, -120.0f, 0.0f);
		m_vertexdata[1].p = D3DXVECTOR3(142.0f, -120.0f, 0.0f);
		m_vertexdata[2].p = D3DXVECTOR3(-142.0f, -340.0f, 0.0f);
		m_vertexdata[3].p = D3DXVECTOR3(142.0f, -340.0f, 0.0f);
		break;

	case 2:
		/*m_vertexdata[0].p = D3DXVECTOR3(430.0f, -120.0f, 0.0f);
		m_vertexdata[1].p = D3DXVECTOR3(640.0f, -120.0f, 0.0f);
		m_vertexdata[2].p = D3DXVECTOR3(430.0f, -340.0f, 0.0f);
		m_vertexdata[3].p = D3DXVECTOR3(640.0f, -340.0f, 0.0f);*/
		m_vertexdata[0].p = D3DXVECTOR3(-105.0f, -120.0f, 0.0f);
		m_vertexdata[1].p = D3DXVECTOR3(105.0f, -120.0f, 0.0f);
		m_vertexdata[2].p = D3DXVECTOR3(-105.0f, -340.0f, 0.0f);
		m_vertexdata[3].p = D3DXVECTOR3(105.0f, -340.0f, 0.0f);
		break;
	}
}



Gokussgss::Gokussgss()
{
	m_skillpos = { 200,0,0 };
	StateNUM = STATE_START;
}


Gokussgss::~Gokussgss()
{
}
