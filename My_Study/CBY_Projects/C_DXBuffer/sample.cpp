#pragma once
#include "CBYCore.h"
#include "CSprite.h"
#include "CShapeMap.h"
#include "CShapeBox.h"

class main :public CBYCore
{
public:
	std::shared_ptr<CSprite> m_Hero;
	std::shared_ptr<CSprite> m_Mon;
	std::shared_ptr<CShapeMap> m_Map;
	std::shared_ptr<CShapeBox> m_Box;
	std::vector<RECT> m_rtsrc;
	D3DXVECTOR3 m_pos;
	bool zoom;
	bool ShowTimebool;
	float ShowTime;
	D3DXMATRIX matWorld;
	D3DXMATRIX matMon;
	int splitenum;
public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();

public:
	main();
	~main();
};

CBY_RUN(main, C_DX, CBY_DX);


bool main::Init()
{
	m_Map = std::make_shared<CShapeMap>();
	m_Map->Create(m_pd3dDevice, m_pContext, L"../../data/shader/DefaultShader.txt", L"../../data/bitmap/map.bmp", "VSmat", "PS");
	//m_Map->Create(m_pd3dDevice, m_pContext, L"../../data/shader/DefaultShader.txt", L"../../data/bitmap/KOF03_Town.png", "VSmat", "PS");

	

	D3D11_BLEND_DESC bs;
	ZeroMemory(&bs, sizeof(D3D11_BLEND_DESC));
	//bs.AlphaToCoverageEnable;
	bs.IndependentBlendEnable = TRUE;;
	bs.RenderTarget[0].BlendEnable = TRUE;
	bs.RenderTarget[0].SrcBlend = D3D11_BLEND_ONE;
	bs.RenderTarget[0].DestBlend = D3D11_BLEND_SRC1_COLOR;
	bs.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
	bs.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
	bs.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
	bs.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
	bs.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
	CDX::CDxState::SetBlendState(m_pd3dDevice, m_pContext, &bs);

	D3D11_SAMPLER_DESC Samp;
	ZeroMemory(&Samp, sizeof(D3D11_SAMPLER_DESC));
	Samp.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	Samp.AddressU = D3D11_TEXTURE_ADDRESS_MIRROR;
	Samp.AddressV = D3D11_TEXTURE_ADDRESS_MIRROR;
	Samp.AddressW = D3D11_TEXTURE_ADDRESS_MIRROR;
	CDX::CDxState::SetSamplerState(m_pd3dDevice, m_pContext, &Samp);

	m_Box = std::make_shared<CShapeBox>();
	m_Box->Create(m_pd3dDevice, m_pContext, L"../../data/shader/ColorBlend.txt", L"../../data/bitmap/get_item_03.dds", "VSmat", "PSBlend");

	
	m_Hero = std::make_shared<CSprite>();
	m_Hero->Create(m_pd3dDevice, m_pContext, L"../../data/shader/ColorBlend.txt", L"../../data/bitmap/firem512.dds", "VSmat", "PSBlend");

	m_Mon = std::make_shared<CSprite>();
	m_Mon->Create(m_pd3dDevice, m_pContext, L"../../data/shader/ColorBlend.txt", L"../../data/bitmap/BlackPig.bmp", "VSmat", "PS");
	

	CDX::ApplyBS(m_pContext,CDX::CDxState::g_pAlpahBlend);
	CDX::ApplyRS(m_pContext, CDX::CDxState::g_pRSSold);
	CDX::ApplyDSS(m_pContext, CDX::CDxState::g_pDSS);
	
	m_rtsrc.resize(4);

	m_rtsrc[0] = { 1, 137, 55, 38 };
	m_rtsrc[1] = { 78, 202, 55, 38 };
	m_rtsrc[2] = { 135, 202, 60, 38 };
	m_rtsrc[3] = { 198, 203, 57, 36 };

	m_Box->SetRectAnimation(1.0f, 4, 510, 4, 510);
	m_Hero->SetAnimation(1.0f, 0.1f, 4, 510, 4, 510);
	m_Mon->SetRectArray(m_rtsrc, 688, 529);
	m_Mon->SetAnimation(1.0f, 0.1f);
	return true;
}

bool main::Frame()
{

	
	D3DXMatrixIdentity(&matWorld);
	D3DXMATRIX matScale, matRotY, matHero, matMonScale, matMonRotY;
	D3DXMatrixIdentity(&matHero);
	D3DXMatrixIdentity(&matMonScale);
	D3DXMatrixIdentity(&matMonRotY);
	D3DXMatrixIdentity(&matScale);
	D3DXMatrixIdentity(&matRotY);
	D3DXMatrixScaling(&matScale, 0.5f, 0.5f, 0.5f);
	D3DXMatrixScaling(&matMonScale, 0.3f, 0.3f, 0.5f);
	D3DXMatrixRotationY(&matRotY, g_gametime);
	matWorld = matScale * matRotY;
	/*float ang = cos(g_gametime);

	if (zoom)
	{
		m_pMainCamera->m_Pos.z -= g_SecondTime;
		m_pMainCamera->m_Pos.x = ang;
		m_pMainCamera->m_At.x = ang;
		if (m_pMainCamera->m_Pos.z <= (-5.0f))
		{
			zoom = false;
		}
	}
	else
	{
		m_pMainCamera->m_Pos.z += g_SecondTime;
		m_pMainCamera->m_Pos.x = ang;
		m_pMainCamera->m_At.x = ang;
		if (m_pMainCamera->m_Pos.z >= 0.0f)
		{
			zoom = true;
		}
	}*/

	if (m_Input.KeyCheck('W') != KEY_FREE)
	{
		m_pMainCamera->m_Pos.z += 5.0f*g_SecondTime;
	}
	if (m_Input.KeyCheck('S') != KEY_FREE)
	{
		m_pMainCamera->m_Pos.z -= 5.0f*g_SecondTime;
	}
	if (m_Input.KeyCheck('A') != KEY_FREE)
	{
		m_pos -= D3DXVECTOR3(50.0f, 0, 0) *g_SecondTime;
		D3DXMatrixRotationY(&matMonRotY, 0);
	}
	if (m_Input.KeyCheck('D') != KEY_FREE)
	{
		m_pos += D3DXVECTOR3(50.0f, 0, 0) *g_SecondTime;
		D3DXMatrixRotationY(&matMonRotY, 135);
	}
	
	matWorld._41 = m_pos.x;
	matWorld._42 = m_pos.y;
	matWorld._43 = m_pos.z;

	matHero._41 = m_pos.x;
	matHero._42 = m_pos.y;
	matHero._43 = m_pos.z;

	matMon = matMonScale * matMonRotY;

	matMon._41 = m_pos.x;
	matMon._42 = -0.5f;
	matMon._43 = m_pos.z;

	m_Map->m_matWorld._43 = 50.0f;
	m_pMainCamera->m_Pos.x = m_pos.x;
	m_pMainCamera->m_At.x = m_pos.x;


	m_Map->SetMatrix(nullptr, &m_pMainCamera->m_View, &m_pMainCamera->m_OrthoProj);
	//m_Map->SetMatrix(nullptr, &m_pMainCamera->m_View, &m_pMainCamera->m_Proj);
	m_Box->SetMatrix(&matWorld, &m_pMainCamera->m_View, &m_pMainCamera->m_Proj);
	m_Hero->SetMatrix(&matHero, &m_pMainCamera->m_View, &m_pMainCamera->m_Proj);
	m_Mon->SetMatrix(&matMon, &m_pMainCamera->m_View, &m_pMainCamera->m_Proj);

	ShowTime += g_SecondTime;

	if (ShowTime > 0.1f)
	{
		ShowTimebool = true;
		splitenum++;
		ShowTime = 0.0f;
		if (splitenum >= m_Box->m_RectList.size())
		{
			splitenum = 0;
		}
	}

	if (ShowTimebool)
	{
		
		m_Box->m_VerTex[0].t = D3DXVECTOR2(m_Box->m_RectList[splitenum].UV.x, m_Box->m_RectList[splitenum].UV.y);
		m_Box->m_VerTex[1].t = D3DXVECTOR2(m_Box->m_RectList[splitenum].UV.z, m_Box->m_RectList[splitenum].UV.y);
		m_Box->m_VerTex[2].t = D3DXVECTOR2(m_Box->m_RectList[splitenum].UV.z, m_Box->m_RectList[splitenum].UV.w);
		m_Box->m_VerTex[3].t = D3DXVECTOR2(m_Box->m_RectList[splitenum].UV.x, m_Box->m_RectList[splitenum].UV.w);
		
		m_Box->m_VerTex[4].t = D3DXVECTOR2(m_Box->m_RectList[splitenum].UV.x, m_Box->m_RectList[splitenum].UV.y);
		m_Box->m_VerTex[5].t = D3DXVECTOR2(m_Box->m_RectList[splitenum].UV.z, m_Box->m_RectList[splitenum].UV.y);
		m_Box->m_VerTex[6].t = D3DXVECTOR2(m_Box->m_RectList[splitenum].UV.z, m_Box->m_RectList[splitenum].UV.w);
		m_Box->m_VerTex[7].t = D3DXVECTOR2(m_Box->m_RectList[splitenum].UV.x, m_Box->m_RectList[splitenum].UV.w);

		m_Box->m_VerTex[8].t = D3DXVECTOR2(m_Box->m_RectList[splitenum].UV.x, m_Box->m_RectList[splitenum].UV.y);
		m_Box->m_VerTex[9].t = D3DXVECTOR2(m_Box->m_RectList[splitenum].UV.z, m_Box->m_RectList[splitenum].UV.y);
		m_Box->m_VerTex[10].t = D3DXVECTOR2(m_Box->m_RectList[splitenum].UV.z, m_Box->m_RectList[splitenum].UV.w);
		m_Box->m_VerTex[11].t = D3DXVECTOR2(m_Box->m_RectList[splitenum].UV.x, m_Box->m_RectList[splitenum].UV.w);

		m_Box->m_VerTex[12].t = D3DXVECTOR2(m_Box->m_RectList[splitenum].UV.x, m_Box->m_RectList[splitenum].UV.y);
		m_Box->m_VerTex[13].t = D3DXVECTOR2(m_Box->m_RectList[splitenum].UV.z, m_Box->m_RectList[splitenum].UV.y);
		m_Box->m_VerTex[14].t = D3DXVECTOR2(m_Box->m_RectList[splitenum].UV.z, m_Box->m_RectList[splitenum].UV.w);
		m_Box->m_VerTex[15].t = D3DXVECTOR2(m_Box->m_RectList[splitenum].UV.x, m_Box->m_RectList[splitenum].UV.w);

		m_Box->m_VerTex[16].t = D3DXVECTOR2(m_Box->m_RectList[splitenum].UV.x, m_Box->m_RectList[splitenum].UV.y);
		m_Box->m_VerTex[17].t = D3DXVECTOR2(m_Box->m_RectList[splitenum].UV.z, m_Box->m_RectList[splitenum].UV.y);
		m_Box->m_VerTex[18].t = D3DXVECTOR2(m_Box->m_RectList[splitenum].UV.z, m_Box->m_RectList[splitenum].UV.w);
		m_Box->m_VerTex[19].t = D3DXVECTOR2(m_Box->m_RectList[splitenum].UV.x, m_Box->m_RectList[splitenum].UV.w);

		m_Box->m_VerTex[20].t = D3DXVECTOR2(m_Box->m_RectList[splitenum].UV.x, m_Box->m_RectList[splitenum].UV.y);
		m_Box->m_VerTex[21].t = D3DXVECTOR2(m_Box->m_RectList[splitenum].UV.z, m_Box->m_RectList[splitenum].UV.y);
		m_Box->m_VerTex[22].t = D3DXVECTOR2(m_Box->m_RectList[splitenum].UV.z, m_Box->m_RectList[splitenum].UV.w);
		m_Box->m_VerTex[23].t = D3DXVECTOR2(m_Box->m_RectList[splitenum].UV.x, m_Box->m_RectList[splitenum].UV.w);

		m_Box->m_obj.m_pVertexBuffer->Release();
		m_Box->CreateVertexBuffer();
		//m_Box->m_obj.m_pContext->UpdateSubresource(&m_Box->m_VerTex,)
		ShowTimebool = false;
	}

	m_Box->m_ConData.ddata.x = 0;//cos(g_gametime)*0.5f+0.5f;
	m_Hero->m_ConData.ddata.x = 0;
	m_Mon->m_ConData.ddata.x = 0;
	m_Hero->Frame();
	m_Mon->Frame();
	return true;
}

bool main::Render()
{
	CDX::ApplySS(m_pContext, CDX::CDxState::g_pSSEdit.Get());
	CDX::ApplyBS(m_pContext, CDX::CDxState::g_pAlpahBlend);
	m_Map->Render();
	
	CDX::ApplyDSS(m_pContext, CDX::CDxState::g_pDSSDisable);
	CDX::ApplySS(m_pContext, CDX::CDxState::g_pSampler);
	CDX::ApplyBS(m_pContext, CDX::CDxState::g_pBSEdit.Get());
	m_Box->Render();

	m_Hero->Render();

	CDX::ApplyBS(m_pContext, CDX::CDxState::g_pAlpahBlend);
	m_Mon->Render();
	return true;
}

bool main::Release()
{

	return true;
}


main::main()
{
	ShowTimebool = true;
	m_pos = D3DXVECTOR3(0,0,0);
	zoom = false;
	ShowTime = 0.0f;
	splitenum = 0;
}


main::~main()
{
}