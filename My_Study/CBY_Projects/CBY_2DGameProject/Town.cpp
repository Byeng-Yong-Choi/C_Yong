#include "Town.h"

HRESULT Town::CreateVertexData()
{
	HRESULT hr = S_OK;

	m_obj.m_VertexSize = sizeof(PCT_VERTEX);

	m_VerTex.resize(4);
	m_VerTex[0].p = D3DXVECTOR3(-1.0f, 1.0f, 1.0f);
	m_VerTex[1].p = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
	m_VerTex[2].p = D3DXVECTOR3(-1.0f, -1.0f, 1.0f);
	m_VerTex[3].p = D3DXVECTOR3(1.0f, -1.0f, 1.0f);										//Á¤Á¡ ÁÂÇ¥ ÀÔ·Â
	//m_VerTex[0].p = D3DXVECTOR3(-(Winrt.right / 2.0f), Winrt.bottom / 2.0f, 0.0f);
	//m_VerTex[1].p = D3DXVECTOR3(Winrt.right / 2.0f, Winrt.bottom / 2.0f, 0.0f);
	//m_VerTex[2].p = D3DXVECTOR3(-(Winrt.right / 2.0f), -(Winrt.bottom / 2.0f), 0.0f);
	//m_VerTex[3].p = D3DXVECTOR3(Winrt.right / 2.0f, -(Winrt.bottom / 2.0f), 0.0f);			//Á¤Á¡ ÁÂÇ¥ ÀÔ·Â



	return hr;
}

void Town::UpdateVertexData()
{

	m_VerTex[0].p = D3DXVECTOR3(-1.0f, 1.0f, 0.0f);
	m_VerTex[1].p = D3DXVECTOR3(1.0f, 1.0f, 0.0f);
	m_VerTex[2].p = D3DXVECTOR3(-1.0f, -1.0f, 0.0f);
	m_VerTex[3].p = D3DXVECTOR3(1.0f, -1.0f, 0.0f);										//Á¤Á¡ ÁÂÇ¥ ÀÔ·Â
}

bool Town::Init()
{
	m_rtlist.resize(8);

	for (int i = 0; i < m_rtlist.size(); i++)
	{
		Rtsrc(i);
		m_rtlist[i] = rtsrc;
	}

	SetRectArray(m_rtlist,780,2570);

	return true;
}

void Town::Rtsrc(int i)
{
	switch (i)
	{
	/*case 0:
		rtsrc = {14,0,253,246};
		break;
	case 1:
		rtsrc = { 14,249,253,246 };
		break;
	case 2:
		rtsrc = { 14,499,253,246 };
		break;
	case 3:
		rtsrc = { 14,749,253,246 };
		break;
	case 4:
		rtsrc = { 14,999,253,246 };
		break;
	case 5:
		rtsrc = { 14,1249,253,246 };
		break;
	case 6:
		rtsrc = { 14,1499,253,246 };
		break;
	case 7:
		rtsrc = { 14,1749,253,246 };
		break;*/
	case 0:
		rtsrc = { 14,1,752,245 };
		break;
	case 1:
		rtsrc = { 14,250,752,245 };
		break;
	case 2:
		rtsrc = { 14,499,752,245 };
		break;
	case 3:
		rtsrc = { 14,748,752,245 };
		break;
	case 4:
		rtsrc = { 14,997,752,245 };
		break;
	case 5:
		rtsrc = { 14,1246,752,245 };
		break;
	case 6:
		rtsrc = { 14,1495,752,245 };
		break;
	case 7:
		rtsrc = { 14,1744,752,245 };
		break;

	}
}

Town::Town()
{
}


Town::~Town()
{
}


