#pragma once
#include "CShapeObject.h"

class HP : public CShapeObject
{
public:
	std::vector<std::shared_ptr<HP>> m_HPList;
	CShapeObject m_Object;

public:
	HRESULT CreateVertexData() override;					//���� ���� ������ ����
	HRESULT CreateIndexData() override;					//�ε��� ���� ������ ����
	//HRESULT CreateVertexBuffer() override;				//���� ���� ����
	//HRESULT CreateIndexBuffer() override;				//�ε��� ���� ����
	HRESULT HPCreate(ID3D11Device* pd3dDevice, ID3D11DeviceContext* Context);
	//bool Frame();
	//bool Render();
public:
	HP();
	~HP();
};

