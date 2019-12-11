#include "C_Object.h"

bool C_Object::Load(const TCHAR* FileName, const TCHAR* MaskFileName)
{

	if (m_BitMap.Load(FileName))
	{
		m_MaskBitMap.Load(MaskFileName);
	}
	return true;
}

bool C_Object::GetRECT(RECT rt1, RECT rt2)
{
	rtdesk = rt1;
	rtdesk = rt2;
	IX = rt1.left;
	IY = rt1.top;

	return true;
}

bool C_Object::Init()
{
	return true;
}
bool C_Object::Frame()
{
	return true;
}
bool C_Object::Render()									//기본 이미지 출력
{
	BitBlt(g_offScreenDC, IX, IY, rtdesk.right, rtdesk.bottom, m_BitMap.MemDC, rtsrc.left, rtsrc.top, SRCAND);
	BitBlt(g_offScreenDC, IX, IY, rtdesk.right, rtdesk.bottom, m_MaskBitMap.MemDC, rtsrc.left, rtsrc.top, SRCINVERT);
	BitBlt(g_offScreenDC, IX, IY, rtdesk.right, rtdesk.bottom, m_MaskBitMap.MemDC, rtsrc.left, rtsrc.top, SRCINVERT);
	return true;
}
bool C_Object::Release()
{
	return true;
}

C_Object::C_Object()
{
}


C_Object::~C_Object()
{
}
