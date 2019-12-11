
#include "BitMap.h"

bool BitMap::Load(const TCHAR* filename)
{
	H_BitMap = (HBITMAP)LoadImage(g_hInstance, filename, IMAGE_BITMAP, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);
	MemDC = CreateCompatibleDC(g_ScreenDC);
	SelectObject(MemDC, H_BitMap);
	return true;
}

bool BitMap::Init()
{
	return true;
}
bool BitMap::Frame()
{
	return true;
}
bool BitMap::Render()									//기본 이미지 출력
{
	return true;
}
bool BitMap::Release()
{
	DeleteDC(MemDC);
	return true;
}

BitMap::BitMap()
{
}


BitMap::~BitMap()
{
}
