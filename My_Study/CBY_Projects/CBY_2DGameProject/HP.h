#pragma once
#include "CShapeObject.h"

class HP : public CShapeObject
{
public:
	std::vector<std::shared_ptr<HP>> m_HPList;
	CShapeObject m_Object;

public:
	HRESULT CreateVertexData() override;					//정점 버퍼 데이터 생성
	HRESULT CreateIndexData() override;					//인덱스 버퍼 데이터 생성
	//HRESULT CreateVertexBuffer() override;				//정점 버퍼 생성
	//HRESULT CreateIndexBuffer() override;				//인덱스 버퍼 생성
	HRESULT HPCreate(ID3D11Device* pd3dDevice, ID3D11DeviceContext* Context);
	//bool Frame();
	//bool Render();
public:
	HP();
	~HP();
};

