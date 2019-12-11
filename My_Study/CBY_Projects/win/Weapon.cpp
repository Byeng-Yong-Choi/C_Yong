#include "Weapon.h"



bool Weapon::Init()
{
	return true;
}

bool Weapon::Frame()
{
	if (CBY_Input::Weapon())
	{

	}
	return true;
}

bool Weapon::Render()
{
	BitBlt(g_offScreenDC, IX, IY, rtdesk.right, rtdesk.bottom, m_BitMap.MemDC, rtsrc.left, rtsrc.top, SRCAND);
	BitBlt(g_offScreenDC, IX, IY, rtdesk.right, rtdesk.bottom, m_MaskBitMap.MemDC, rtsrc.left, rtsrc.top, SRCINVERT);
	BitBlt(g_offScreenDC, IX, IY, rtdesk.right, rtdesk.bottom, m_MaskBitMap.MemDC, rtsrc.left, rtsrc.top, SRCINVERT);
	return true;
}

bool Weapon::Release()
{
	return true;
}


Weapon::Weapon()
{
}


Weapon::~Weapon()
{
}
