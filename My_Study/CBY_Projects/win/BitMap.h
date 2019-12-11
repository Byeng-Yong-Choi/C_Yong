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
	bool Render();									//기본 이미지 출력
	bool Release();

public:
	BitMap();
	~BitMap();
};

