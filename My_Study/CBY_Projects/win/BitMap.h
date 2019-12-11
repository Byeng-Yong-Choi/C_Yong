#pragma once
#include "Cstd.h"

class BitMap
{
public:
	HBITMAP H_BitMap;
	HDC MemDC;
	RECT rtdesk;
	RECT rtsrc;

public:
	bool Load(const TCHAR* filename);
	bool Init();
	bool Frame();
	bool Render();									//�⺻ �̹��� ���
	bool Release();

public:
	BitMap();
	~BitMap();
};

