#pragma once
#include "CSprite.h"

class Town:public CSprite
{
public:
	std::vector<RECT> m_rtlist;
	RECT rtsrc;
	

public:
	bool Init();
	HRESULT CreateVertexData();
	void UpdateVertexData();					//���� ���� ������ ������Ʈ
	void Rtsrc(int i);

public:
	Town();
	~Town();
};

