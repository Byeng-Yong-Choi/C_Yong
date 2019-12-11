#pragma once
#include "Cstd.h"
#include "BitMap.h"

class C_Object
{
public:
	BitMap m_BitMap;
	BitMap m_MaskBitMap;
	RECT rtdesk;
	RECT rtsrc;
	float IX;
	float IY;

public:
	bool Load(const TCHAR* FileName, const TCHAR* MaskFileName);
	virtual bool GetRECT(RECT rt1, RECT rt2);
	virtual bool Init();
	virtual bool Frame();
	virtual bool Render();									//기본 이미지 출력
	virtual bool Release();

public:
	C_Object();
	virtual ~C_Object();
};

