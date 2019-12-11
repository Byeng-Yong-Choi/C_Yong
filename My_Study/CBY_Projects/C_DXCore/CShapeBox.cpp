#include "CShapeBox.h"

HRESULT CShapeBox::CreateVertexData()
{
	HRESULT hr = S_OK;
	m_obj.m_VertexSize = sizeof(PCT_VERTEX);
	m_VerTex.resize(24);
	// front
	m_VerTex[0] = PCT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, -1.0f), D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.0f, 0.0f));
	m_VerTex[1] = PCT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, -1.0f), D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(1.0f, 0.0f));
	m_VerTex[2] = PCT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, -1.0f), D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(1.0f, 1.0f));
	m_VerTex[3] = PCT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, -1.0f), D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.0f, 1.0f));
	// back
	m_VerTex[4] = PCT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, 1.0f), D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.0f, 0.0f));
	m_VerTex[5] = PCT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, 1.0f), D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(1.0f, 0.0f));
	m_VerTex[6] = PCT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, 1.0f), D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(1.0f, 1.0f));
	m_VerTex[7] = PCT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, 1.0f), D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.0f, 1.0f));
	// right
	m_VerTex[8] = PCT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, -1.0f), D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.0f, 0.0f));
	m_VerTex[9] = PCT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, 1.0f), D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(1.0f, 0.0f));
	m_VerTex[10] = PCT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, 1.0f), D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(1.0f, 1.0f));
	m_VerTex[11] = PCT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, -1.0f), D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.0f, 1.0f));
	// left
	m_VerTex[12] = PCT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, 1.0f), D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.0f, 0.0f));
	m_VerTex[13] = PCT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, -1.0f), D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(1.0f, 0.0f));
	m_VerTex[14] = PCT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, -1.0f), D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(1.0f, 1.0f));
	m_VerTex[15] = PCT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, 1.0f), D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.0f, 1.0f));
	// up
	m_VerTex[16] = PCT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, 1.0f), D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.0f, 0.0f));
	m_VerTex[17] = PCT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, 1.0f), D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(1.0f, 0.0f));
	m_VerTex[18] = PCT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, -1.0f), D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(1.0f, 1.0f));
	m_VerTex[19] = PCT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, -1.0f), D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.0f, 1.0f));
	// down
	m_VerTex[20] = PCT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, -1.0f), D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.0f, 0.0f));
	m_VerTex[21] = PCT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, -1.0f), D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(1.0f, 0.0f));
	m_VerTex[22] = PCT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, 1.0f), D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(1.0f, 1.0f));
	m_VerTex[23] = PCT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, 1.0f), D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.0f, 1.0f));

	return hr;
}
HRESULT CShapeBox::CreateIndexData()
{
	HRESULT hr = S_OK;
	m_IndexData.resize(36);
	int iIndex = 0;
	m_IndexData[iIndex++] = 0; m_IndexData[iIndex++] = 1; m_IndexData[iIndex++] = 2;
	m_IndexData[iIndex++] = 0; m_IndexData[iIndex++] = 2; m_IndexData[iIndex++] = 3;
	m_IndexData[iIndex++] = 4; m_IndexData[iIndex++] = 5; m_IndexData[iIndex++] = 6;
	m_IndexData[iIndex++] = 4; m_IndexData[iIndex++] = 6; m_IndexData[iIndex++] = 7;

	m_IndexData[iIndex++] = 8; m_IndexData[iIndex++] = 9; m_IndexData[iIndex++] = 10;
	m_IndexData[iIndex++] = 8; m_IndexData[iIndex++] = 10; m_IndexData[iIndex++] = 11;
	m_IndexData[iIndex++] = 12; m_IndexData[iIndex++] = 13; m_IndexData[iIndex++] = 14;
	m_IndexData[iIndex++] = 12; m_IndexData[iIndex++] = 14; m_IndexData[iIndex++] = 15;

	m_IndexData[iIndex++] = 16; m_IndexData[iIndex++] = 17; m_IndexData[iIndex++] = 18;
	m_IndexData[iIndex++] = 16; m_IndexData[iIndex++] = 18; m_IndexData[iIndex++] = 19;
	m_IndexData[iIndex++] = 20; m_IndexData[iIndex++] = 21; m_IndexData[iIndex++] = 22;
	m_IndexData[iIndex++] = 20; m_IndexData[iIndex++] = 22; m_IndexData[iIndex++] = 23;

	return hr;
}

CShapeBox::CShapeBox()
{
}


CShapeBox::~CShapeBox()
{
}
