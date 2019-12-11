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
	virtual bool Render();									//�⺻ �̹��� ���
	virtual bool Release();

public:
	C_Object();
	virtual ~C_Object();
};

