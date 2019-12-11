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
	BitBlt(g_offScreenDC, rtdest.left, rtdest.top, rtdest.right, rtdest.bottom, MemDC, rtsrc.left, rtsrc.top, SRCCOPY);
	return true;
}

bool maskBitMap::Release()
{
	return true;
}

maskBitMap::maskBitMap()
{
}


maskBitMap::~maskBitMap()
{
}
