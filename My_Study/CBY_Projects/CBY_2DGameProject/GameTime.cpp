#include "GameTime.h"

HRESULT GameTime::Create(ID3D11Device* pd3dDevice, ID3D11DeviceContext* Context)
{
	HRESULT hr = S_OK;
	
	VertexData();
	m_Timer.resize(2);
	TextArray();
	for (int i = 0; i < m_Timer.size(); i++)
	{
		m_Timer[i] = std::make_shared<CSprite>();
		m_Timer[i]->Create(pd3dDevice, Context, L"../../data/shader/ColorBlend.txt", nullptr, "VSmat", "PS");
		VertexSet(i);
		m_Timer[i]->UpdateVertexData(m_vertexdata);
		m_Timer[i]->SetTextureArray(m_str);
	}

	m_Timer[0]->m_Index = 9;
	m_Timer[1]->m_Index = 0;


	return hr;
}

void GameTime::VertexSet(int i)
{
	switch (i)
	{
	case 0:
		m_vertexdata[0].p = D3DXVECTOR3(585.0f, 20.0f, 0.0f);
		m_vertexdata[1].p = D3DXVECTOR3(635.0f, 20.0f, 0.0f);
		m_vertexdata[2].p = D3DXVECTOR3(585.0f, 70.0f, 0.0f);
		m_vertexdata[3].p = D3DXVECTOR3(635.0f, 70.0f, 0.0f);				//정점 좌표 입력
		m_Sprite.Convert(m_vertexdata);
		break;

	case 1:
		m_vertexdata[0].p = D3DXVECTOR3(645.0f, 20.0f, 0.0f);
		m_vertexdata[1].p = D3DXVECTOR3(695.0f, 20.0f, 0.0f);
		m_vertexdata[2].p = D3DXVECTOR3(645.0f, 70.0f, 0.0f);
		m_vertexdata[3].p = D3DXVECTOR3(695.0f, 70.0f, 0.0f);				//정점 좌표 입력
		m_Sprite.Convert(m_vertexdata);
		break;
	}
	
}

void GameTime::TextArray()
{
	m_str.clear();
	int index = 0;
	m_str.resize(10);
	m_str[index++] = L"../../data/ui/time_40-0.png";
	m_str[index++] = L"../../data/ui/time_40-1.png";
	m_str[index++] = L"../../data/ui/time_40-2.png";
	m_str[index++] = L"../../data/ui/time_40-3.png";
	m_str[index++] = L"../../data/ui/time_40-4.png";
	m_str[index++] = L"../../data/ui/time_40-5.png";
	m_str[index++] = L"../../data/ui/time_40-6.png";
	m_str[index++] = L"../../data/ui/time_40-7.png";
	m_str[index++] = L"../../data/ui/time_40-8.png";
	m_str[index++] = L"../../data/ui/time_40-9.png";
}


void GameTime::VertexData()
{
	m_vertexdata.resize(4);
	m_vertexdata[0].p = D3DXVECTOR3(0.0f, 20.0f, 0.0f);
	m_vertexdata[1].p = D3DXVECTOR3(0.0f, 20.0f, 0.0f);
	m_vertexdata[2].p = D3DXVECTOR3(0.0f, 80.0f, 0.0f);
	m_vertexdata[3].p = D3DXVECTOR3(0.0f, 80.0f, 0.0f);				//정점 좌표 입력
	
	m_vertexdata[0].c = D3DXVECTOR4(1.0f, 0.0f, 1.0f, 1.0f);
	m_vertexdata[1].c = D3DXVECTOR4(0.0f, 1.0f, 0.0f, 1.0f);
	m_vertexdata[2].c = D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f);
	m_vertexdata[3].c = D3DXVECTOR4(1.0f, 1.0f, 0.0f, 1.0f);			//정점 컬러값 입력

	m_vertexdata[0].t = D3DXVECTOR2(0.0f, 0.0f);
	m_vertexdata[1].t = D3DXVECTOR2(1.0f, 0.0f);
	m_vertexdata[2].t = D3DXVECTOR2(0.0f, 1.0f);
	m_vertexdata[3].t = D3DXVECTOR2(1.0f, 1.0f);			//정점 텍스쳐 좌표

	m_Sprite.Convert(m_vertexdata);
}

bool GameTime::Frame()
{
	m_ChangeTime += g_SecondTime;

	if (m_ChangeTime >= 1.0f)
	{
		m_ChangeTime = 0;
		m_Timer[1]->m_Index-=1;
		if (m_Timer[1]->m_Index < 0)
		{
			m_Timer[0]->m_Index -= 1;
			m_Timer[1]->m_Index = 9;
			if (m_Timer[0]->m_Index < 0)
			{
				m_Timer[0]->m_Index = 0;
			}
		
		}
	}
	return true;
}

bool GameTime::Render()
{
	for (int i = 0; i < m_Timer.size(); i++)
	{
		m_Timer[i]->Render();
	}
	return true;
}



GameTime::GameTime()
{
	m_Spritenum = 0;
	m_ChangeTime = 0.0f;
}


GameTime::~GameTime()
{
}
