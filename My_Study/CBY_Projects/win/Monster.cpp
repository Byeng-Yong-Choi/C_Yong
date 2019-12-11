#include "Monster.h"



bool Monster::Init()
{
	return true;
}

bool Monster::Frame()
{
	return true;
}

bool Monster::Render()
{
	BitBlt(g_offScreenDC, IX, IY, rtdesk.right, rtdesk.bottom, m_BitMap.MemDC, rtsrc.left, rtsrc.top, SRCAND);
	BitBlt(g_offScreenDC, IX, IY, rtdesk.right, rtdesk.bottom, m_MaskBitMap.MemDC, rtsrc.left, rtsrc.top, SRCINVERT);
	BitBlt(g_offScreenDC, IX, IY, rtdesk.right, rtdesk.bottom, m_MaskBitMap.MemDC, rtsrc.left, rtsrc.top, SRCINVERT);
	return true;
}

bool Monster::Release()
{
	return true;
}

Monster::Monster()
{
}


Monster::~Monster()
{
}
