#include "CShapeObject.h"

HRESULT CShapeObject::CreateVertexData()
{
	HRESULT hr = S_OK;

	m_obj.m_VertexSize = sizeof(PCT_VERTEX);

	m_VerTex.resize(4);
	m_VerTex[0].p = D3DXVECTOR3(-1.0f, 1.0f, 0.0f);
	m_VerTex[1].p = D3DXVECTOR3(1.0f, 1.0f, 0.0f);
	m_VerTex[2].p = D3DXVECTOR3(-1.0f, -1.0f, 0.0f);
	m_VerTex[3].p = D3DXVECTOR3(1.0f, -1.0f, 0.0f);				//정점 좌표 입력

	m_VerTex[0].c = D3DXVECTOR4(1.0f, 0.0f, 1.0f, 1.0f);
	m_VerTex[1].c = D3DXVECTOR4(0.0f, 1.0f, 0.0f, 1.0f);
	m_VerTex[2].c = D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f);
	m_VerTex[3].c = D3DXVECTOR4(1.0f, 1.0f, 0.0f, 1.0f);									//정점 컬러값 입력

	m_VerTex[0].t = D3DXVECTOR2(0.0f, 0.0f);
	m_VerTex[1].t = D3DXVECTOR2(1.0f, 0.0f);
	m_VerTex[2].t = D3DXVECTOR2(0.0f, 1.0f);
	m_VerTex[3].t = D3DXVECTOR2(1.0f, 1.0f);												//정점 텍스쳐 좌표
	return hr;
}

HRESULT CShapeObject::CreateIndexData()
{
	HRESULT hr = S_OK;

	m_IndexData.resize(6);
	m_IndexData[0] = 0;
	m_IndexData[1] = 1;
	m_IndexData[2] = 2;

	m_IndexData[3] = 2;
	m_IndexData[4] = 1;
	m_IndexData[5] = 3;

	return hr;
}

void CShapeObject::UpdateVertexData()
{

}

CShapeObject::CShapeObject()
{
}


CShapeObject::~CShapeObject()
{
}
