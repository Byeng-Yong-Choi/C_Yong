#include "GameMain.h"

bool GameMain::Init()
{
	m_Map = std::make_shared<Town>();
	m_Map->Create(m_pd3dDevice, m_pContext, L"../../data/shader/DefaultShader.txt", L"../../data/bitmap/KOF03_Town.png", "VSmat", "PS");
	m_Map->Init();
	
	m_Hero = std::make_shared<Gokussgss>();
	m_Hero->Create(m_pd3dDevice, m_pContext);
	
	m_Enemy = std::make_shared<Enemy>();
	m_Enemy->Create(m_pd3dDevice, m_pContext);
	m_Enemy->Init();
	m_Enemy->Revers = true;

	m_Time= std::make_shared<GameTime>();
	m_Time->Create(m_pd3dDevice, m_pContext);
	
	m_HpList.resize(2);
	m_HpList[0] = std::make_shared<HP>();
	m_HpList[0]->Create(m_pd3dDevice, m_pContext, L"../../data/shader/ColorBlend.txt", L"../../data/ui/hpc.png", "VSmat", "PS");
	

	m_HpList[1] = std::make_shared<HP>();
	m_HpList[1]->Create(m_pd3dDevice, m_pContext, L"../../data/shader/ColorBlend.txt", L"../../data/ui/hpb.png", "VSmat", "PS");

	//m_Hero->SetAniTime(0.1f);
	


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

	CDX::ApplyBS(m_pContext, CDX::CDxState::g_pAlpahBlend);
	CDX::ApplyRS(m_pContext, CDX::CDxState::g_pRSSold);
	CDX::ApplyDSS(m_pContext, CDX::CDxState::g_pDSS);

	m_Map->SetAnimation(1.0f, 0.1f);
	
	D3DXMATRIX scaling, move;
	D3DXMatrixIdentity(&HPWorld);
	D3DXMatrixIdentity(&scaling);
	D3DXMatrixIdentity(&move);
	D3DXMatrixScaling(&scaling, 1.5f, 1.6f, 1);
	D3DXMatrixTranslation(&move, -0.1f, -0.5f, 1);
	HPWorld = scaling * move;

	return true;
}

bool GameMain::Frame()
{
	D3DXMatrixIdentity(&matWorld);
	D3DXMatrixIdentity(&EnemyWorld);
	
	m_Hero->Frame();
	m_Map->Frame();
	m_Time->Frame();

	Heropos += CharMove::move(m_Hero, m_Enemy);
	Enemypos += CharMove::move(m_Enemy, m_Hero);

	Heropos.y = m_Hero->m_Jumppos;
	matWorld._41 = Heropos.x;
	matWorld._42 = Heropos.y;

	Enemypos.y = m_Enemy->m_Jumppos;
	EnemyWorld._41 = Enemypos.x;
	EnemyWorld._42 = Enemypos.y;


	
	m_Map->SetMatrix(nullptr, &m_pMainCamera->m_View, nullptr);
	//m_Hero->SetWorldandMatrix(&matWorld, &m_pMainCamera->m_View, &m_pMainCamera->m_OrthoProj,HeroMove);
	m_HpList[1]->SetMatrix(&HPWorld, &m_pMainCamera->m_View, nullptr);
	m_HpList[0]->SetMatrix(&HPWorld, &m_pMainCamera->m_View, nullptr);
	//m_Enemy->SetWorldandMatrix(&EnemyWorld, &m_pMainCamera->m_View, &m_pMainCamera->m_OrthoProj, EnemyMove);
	m_Hero->SetWorldandMatrix(&matWorld, nullptr, &m_pMainCamera->m_OrthoProj, Heropos,m_Enemy->m_fRect);
	m_Enemy->SetWorldandMatrix(&EnemyWorld, nullptr, &m_pMainCamera->m_OrthoProj, Enemypos, m_Hero->m_fRect);
	m_Enemy->Process(m_Hero);

	m_HpList[0]->m_obj.m_StartIndex = 6 * m_Enemy->Damage;;
	

	if (m_HpList[0]->m_obj.m_StartIndex > 59)
	{
		m_HpList[0]->m_obj.m_StartIndex = 59;
	}
	
	m_HpList[0]->Frame();
	return true;
}

bool GameMain::Render()
{
	CDX::ApplyDSS(m_pContext, CDX::CDxState::g_pDSSDisable);
	CDX::ApplySS(m_pContext, CDX::CDxState::g_pSSEdit.Get());
	CDX::ApplyBS(m_pContext, CDX::CDxState::g_pAlpahBlend);
	m_Map->Render();

	m_Time->Render();
	
	m_HpList[1]->Render();
	m_HpList[0]->Render();


	//CDX::ApplyDSS(m_pContext, CDX::CDxState::g_pDSS);
	CDX::ApplySS(m_pContext, CDX::CDxState::g_pSampler);
	//CDX::ApplyBS(m_pContext, CDX::CDxState::g_pBSEdit.Get());
	
	m_Hero->Render();

	m_Enemy->Render();


	return true;
}

bool GameMain::Release()
{
	return true;
}

HRESULT GameMain::CreateDXrc()
{
	HRESULT hr = S_OK;

	//m_Map->UpdateVertexData();
	//m_Map->m_obj.m_pContext->UpdateSubresource(m_Map->m_obj.m_pVertexBuffer, 0, nullptr, &m_Map->m_VerTex.at(0), 0, 0);

	return hr;
}

HRESULT	GameMain::DeleteDXrc()
{
	HRESULT hr = S_OK;


	return hr;
}


GameMain::GameMain()
{
	ShowTimebool = true;
	//m_pos = D3DXVECTOR3(0, 0, 0);
	//zoom = false;
	jump = 0.0f;
	Hight = false;
	DoubleClickTime = 0.0f;
	DoubleClick = false;
	Heropos = { -270,0,0 };
	Enemypos = { 240.f,0,0 };
}


GameMain::~GameMain()
{
}
