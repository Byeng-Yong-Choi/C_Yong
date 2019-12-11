#pragma once
#include "C_Model.h"

class CShapeObject: public C_Model
{
public:
	C_Model m_Model;

public:
	virtual HRESULT CreateVertexData();
	virtual HRESULT CreateIndexData();
	virtual void UpdateVertexData();					//���� ���� ������ ������Ʈ

public:
	CShapeObject();
	~CShapeObject();
};

