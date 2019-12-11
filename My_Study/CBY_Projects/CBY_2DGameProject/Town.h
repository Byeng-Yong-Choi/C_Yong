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
	void UpdateVertexData();					//정점 버퍼 데이터 업데이트
	void Rtsrc(int i);

public:
	Town();
	~Town();
};

