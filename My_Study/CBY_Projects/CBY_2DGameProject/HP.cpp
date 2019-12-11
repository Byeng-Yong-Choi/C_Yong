#include "HP.h"

HRESULT HP::HPCreate(ID3D11Device* pd3dDevice, ID3D11DeviceContext* Context)
{
	HRESULT hr = S_OK;

	/*m_HPList.resize(2);
	m_HPList[0] = std::make_shared<HP>();
	m_HPList[0]->Create(pd3dDevice, Context, L"../../data/shader/ColorBlend.txt", L"../../data/ui/hpc.png", "VSmat", "PS");
	
	m_HPList[1] = std::make_shared<HP>();
	m_HPList[1]->Create(pd3dDevice, Context, L"../../data/shader/ColorBlend.txt", L"../../data/ui/hpb.png", "VSmat", "PS");*/

	return hr;
}

HRESULT HP::CreateVertexData()
{
	HRESULT hr = S_OK;

	m_obj.m_VertexSize = sizeof(PCT_VERTEX);

	m_VerTex.resize(22);
	m_VerTex[0].p = D3DXVECTOR3(750.0f, 0.0f, 0.0f);
	m_VerTex[1].p = D3DXVECTOR3(785.0f, 0.0f, 0.0f);
	m_VerTex[2].p = D3DXVECTOR3(750.0f, 100.0f, 0.0f);
	m_VerTex[3].p = D3DXVECTOR3(785.0f, 100.0f, 0.0f);						
	m_VerTex[0].t = D3DXVECTOR2(0.0f, 0.0f);
	m_VerTex[1].t = D3DXVECTOR2(0.1f, 0.0f);
	m_VerTex[2].t = D3DXVECTOR2(0.0f, 1.0f);
	m_VerTex[3].t = D3DXVECTOR2(0.1f, 1.0f);			
	m_VerTex[0].c = D3DXVECTOR4(1.0f, 0.0f, 1.0f, 1.0f);
	m_VerTex[1].c = D3DXVECTOR4(0.0f, 1.0f, 0.0f, 1.0f);
	m_VerTex[2].c = D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f);
	m_VerTex[3].c = D3DXVECTOR4(1.0f, 1.0f, 0.0f, 1.0f);//hp 1ĭ

	m_VerTex[4].p = D3DXVECTOR3(820.0f, 0.0f, 0.0f);
	m_VerTex[5].p = D3DXVECTOR3(855.0f, 0.0f, 0.0f);
	m_VerTex[6].p = D3DXVECTOR3(820.0f, 100.0f, 0.0f);
	m_VerTex[7].p = D3DXVECTOR3(855.0f, 100.0f, 0.0f);
	m_VerTex[4].t = D3DXVECTOR2(0.2f, 0.0f);
	m_VerTex[5].t = D3DXVECTOR2(0.3f, 0.0f);
	m_VerTex[6].t = D3DXVECTOR2(0.2f, 1.0f);
	m_VerTex[7].t = D3DXVECTOR2(0.3f, 1.0f);			
	m_VerTex[4].c = D3DXVECTOR4(1.0f, 0.0f, 1.0f, 1.0f);
	m_VerTex[5].c = D3DXVECTOR4(0.0f, 1.0f, 0.0f, 1.0f);
	m_VerTex[6].c = D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f);
	m_VerTex[7].c = D3DXVECTOR4(1.0f, 1.0f, 0.0f, 1.0f);//hp 1ĭ

	m_VerTex[8].p = D3DXVECTOR3(890.0f, 0.0f, 0.0f);
	m_VerTex[9].p = D3DXVECTOR3(925.0f, 0.0f, 0.0f);
	m_VerTex[10].p = D3DXVECTOR3(890.0f, 100.0f, 0.0f);
	m_VerTex[11].p = D3DXVECTOR3(925.0f, 100.0f, 0.0f);
	m_VerTex[8].t = D3DXVECTOR2(0.4f, 0.0f);
	m_VerTex[9].t = D3DXVECTOR2(0.5f, 0.0f);
	m_VerTex[10].t = D3DXVECTOR2(0.4f, 1.0f);
	m_VerTex[11].t = D3DXVECTOR2(0.5f, 1.0f);			
	m_VerTex[8].c = D3DXVECTOR4(1.0f, 0.0f, 1.0f, 1.0f);
	m_VerTex[9].c = D3DXVECTOR4(0.0f, 1.0f, 0.0f, 1.0f);
	m_VerTex[10].c = D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f);
	m_VerTex[11].c = D3DXVECTOR4(1.0f, 1.0f, 0.0f, 1.0f);//hp 1ĭ

	m_VerTex[12].p = D3DXVECTOR3(960.0f, 0.0f, 0.0f);
	m_VerTex[13].p = D3DXVECTOR3(995.0f, 0.0f, 0.0f);
	m_VerTex[14].p = D3DXVECTOR3(960.0f, 100.0f, 0.0f);
	m_VerTex[15].p = D3DXVECTOR3(995.0f, 100.0f, 0.0f);
	m_VerTex[12].t = D3DXVECTOR2(0.6f, 0.0f);
	m_VerTex[13].t = D3DXVECTOR2(0.7f, 0.0f);
	m_VerTex[14].t = D3DXVECTOR2(0.6f, 1.0f);
	m_VerTex[15].t = D3DXVECTOR2(0.7f, 1.0f);			
	m_VerTex[12].c = D3DXVECTOR4(1.0f, 0.0f, 1.0f, 1.0f);
	m_VerTex[13].c = D3DXVECTOR4(0.0f, 1.0f, 0.0f, 1.0f);
	m_VerTex[14].c = D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f);
	m_VerTex[15].c = D3DXVECTOR4(1.0f, 1.0f, 0.0f, 1.0f);//hp 1ĭ

	m_VerTex[16].p = D3DXVECTOR3(1030.0f, 0.0f, 0.0f);
	m_VerTex[17].p = D3DXVECTOR3(1065.0f, 0.0f, 0.0f);
	m_VerTex[18].p = D3DXVECTOR3(1030.0f, 100.0f, 0.0f);
	m_VerTex[19].p = D3DXVECTOR3(1065.0f, 100.0f, 0.0f);
	m_VerTex[16].t = D3DXVECTOR2(0.8f, 0.0f);
	m_VerTex[17].t = D3DXVECTOR2(0.9f, 0.0f);
	m_VerTex[18].t = D3DXVECTOR2(0.8f, 1.0f);
	m_VerTex[19].t = D3DXVECTOR2(0.9f, 1.0f);			
	m_VerTex[16].c = D3DXVECTOR4(1.0f, 0.0f, 1.0f, 1.0f);
	m_VerTex[17].c = D3DXVECTOR4(0.0f, 1.0f, 0.0f, 1.0f);
	m_VerTex[18].c = D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f);
	m_VerTex[19].c = D3DXVECTOR4(1.0f, 1.0f, 0.0f, 1.0f);//hp 1ĭ

	m_VerTex[20].p = D3DXVECTOR3(1100.0f, 0.0f, 0.0f);
	m_VerTex[21].p = D3DXVECTOR3(1100.0f, 100.0f, 0.0f);
	m_VerTex[20].t = D3DXVECTOR2(1.0f, 0.0f);
	m_VerTex[21].t = D3DXVECTOR2(1.0f, 1.0f);	
	m_VerTex[20].c = D3DXVECTOR4(1.0f, 0.0f, 1.0f, 1.0f);
	m_VerTex[21].c = D3DXVECTOR4(0.0f, 1.0f, 0.0f, 1.0f);


	m_Object.Convert(m_VerTex);
	return hr;
}

HRESULT HP::CreateIndexData()
{
	HRESULT hr = S_OK;
	int index=0;

	m_IndexData.resize(60);
	m_IndexData[index++] = 0; m_IndexData[index++] = 1; m_IndexData[index++] = 2; m_IndexData[index++] = 2; m_IndexData[index++] = 1; m_IndexData[index++] = 3;								//hp 1ĭ
	
	m_IndexData[index++] = 1; m_IndexData[index++] = 4; m_IndexData[index++] = 3; m_IndexData[index++] = 3; m_IndexData[index++] = 4; m_IndexData[index++] = 6;								//hp 1ĭ

	m_IndexData[index++] = 4; m_IndexData[index++] = 5; m_IndexData[index++] = 6; m_IndexData[index++] = 6; m_IndexData[index++] = 5; m_IndexData[index++] = 7;								//hp 1ĭ

	m_IndexData[index++] = 5; m_IndexData[index++] = 8; m_IndexData[index++] = 7; m_IndexData[index++] = 7; m_IndexData[index++] = 8; m_IndexData[index++] = 10;								//hp 1ĭ

	m_IndexData[index++] = 8; m_IndexData[index++] = 9; m_IndexData[index++] = 10; m_IndexData[index++] = 10; m_IndexData[index++] = 9; m_IndexData[index++] = 11;								//hp 1ĭ

	m_IndexData[index++] = 9; m_IndexData[index++] = 12; m_IndexData[index++] = 11; m_IndexData[index++] = 11; m_IndexData[index++] = 12; m_IndexData[index++] = 14;								//hp 1ĭ

	m_IndexData[index++] = 12; m_IndexData[index++] = 13; m_IndexData[index++] = 14; m_IndexData[index++] = 14; m_IndexData[index++] = 13; m_IndexData[index++] = 15;								//hp 1ĭ

	m_IndexData[index++] = 13; m_IndexData[index++] = 16; m_IndexData[index++] = 15; m_IndexData[index++] = 15; m_IndexData[index++] = 16; m_IndexData[index++] = 18;								//hp 1ĭ

	m_IndexData[index++] = 16; m_IndexData[index++] = 17; m_IndexData[index++] = 18; m_IndexData[index++] = 18; m_IndexData[index++] = 17; m_IndexData[index++] = 19;								//hp 1ĭ

	m_IndexData[index++] = 17; m_IndexData[index++] = 20; m_IndexData[index++] = 19; m_IndexData[index++] = 19; m_IndexData[index++] = 20; m_IndexData[index++] = 21;								//hp 1ĭ

	return hr;
}

//HRESULT HP::CreateVertexBuffer()
//{
//	HRESULT hr = S_OK;
//
//
//
//	return hr;
//}
//
//HRESULT HP::CreateIndexBuffer()
//{
//	HRESULT hr = S_OK;
//
//
//
//	return hr;
//}

//bool HP::Frame()
//{
//
//
//	return true;
//}
//
//bool HP::Render()
//{
//
//
//	return true;
//}



HP::HP()
{
}


HP::~HP()
{
}
