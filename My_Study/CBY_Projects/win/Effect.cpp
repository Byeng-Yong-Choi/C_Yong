#include "Effect.h"


bool Effect::Init()
{
	return true;
}

bool Effect::Frame()
{

	if (CBY_Input::GetKekCheck(VK_UP))																//����Ű�� ĳ������ �̵��� ���� ����ϸ� ����� ���̿� �Ұ������� ������ �ʰ� �ð��� ����ȭ�� �̿�
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
