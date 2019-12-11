#pragma once
#include "C_Model.h"


class CShapeMap : public C_Model
{

public:
	C_Model m_Model;

public:
	HRESULT CreateVertexData();
	HRESULT CreateIndexData();
public:
	CShapeMap();
	~CShapeMap();
};

