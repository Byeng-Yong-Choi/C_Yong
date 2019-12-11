#pragma once
#include "Cstd.h"

class C_BitMap
{
public:
	HBITMAP H_BitMap;
	HDC MemDC;

private:
	RECT rtsrc;

public:
	bool Load(const TCHAR* filename);
	bool Init();
	bool Frame();
	bool Render();									//�⺻ �̹��� ���
	bool Release();

public:
	C_BitMap();
	~C_BitMap();
};

