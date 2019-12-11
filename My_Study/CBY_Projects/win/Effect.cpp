#include "Effect.h"


bool Effect::Init()
{
	return true;
}

bool Effect::Frame()
{

	if (CBY_Input::GetKekCheck(VK_UP))																//방향키로 캐릭터의 이동을 정의 계산하며 사양의 차이에 불공정함이 생기지 않게 시간의 동기화를 이용
	{
		IY -= CHARSPEED * g_SecondTime;
	}
	if (CBY_Input::GetKekCheck(VK_LEFT))
	{
		IX -= CHARSPEED * g_SecondTime;
	}
	if (CBY_Input::GetKekCheck(VK_RIGHT))
	{
		IX += CHARSPEED * g_SecondTime;
	}
	if (CBY_Input::GetKekCheck(VK_DOWN))
	{
		IY += CHARSPEED * g_SecondTime;
	}
	return true;
}

bool Effect::Render()
{
	BitBlt(g_offScreenDC, IX, IY, rtdesk.right, rtdesk.bottom, m_BitMap.MemDC, rtsrc.left, rtsrc.top, SRCAND);
	BitBlt(g_offScreenDC, IX, IY, rtdesk.right, rtdesk.bottom, m_MaskBitMap.MemDC, rtsrc.left, rtsrc.top, SRCINVERT);
	BitBlt(g_offScreenDC, IX, IY, rtdesk.right, rtdesk.bottom, m_MaskBitMap.MemDC, rtsrc.left, rtsrc.top, SRCINVERT);
	return true;
}

bool Effect::Release()
{
	return true;
}

Effect::Effect()
{
}


Effect::~Effect()
{
}
