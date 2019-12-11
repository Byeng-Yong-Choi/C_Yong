#pragma once
#include "Cstd.h"
class maskBitMap
{
public:
	HBITMAP H_BitMap;
	HDC MemDC;
	RECT rtdesk;
	RECT rtsrc;

public:
	bool Load(TCHAR const* Filename);
	bool Init();
	bool Frame();
	bool Render();
	bool Release();
	maskBitMap();
	~maskBitMap();
};

