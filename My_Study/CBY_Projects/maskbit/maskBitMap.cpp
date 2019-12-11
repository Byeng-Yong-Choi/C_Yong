#include "maskBitMap.h"


bool maskBitMap::Load(TCHAR const* Filename)
{
	H_BitMap = (HBITMAP)LoadImage(g_hInstance, Filename, IMAGE_BITMAP, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);
	MemDC = CreateCompatibleDC(g_ScreenDC);
	SelectObject(MemDC, H_BitMap);
	return true;
}

bool maskBitMap::Init()
{
	return true;
}

bool maskBitMap::Frame()
{
	return true;
}

bool maskBitMap::Render()
{	
	return true;
}

bool maskBitMap::Release()
{
	DeleteObject(H_BitMap);
	ReleaseDC(g_hwnd,MemDC);
	return true;
}

maskBitMap::maskBitMap()
{
}


maskBitMap::~maskBitMap()
{
}
