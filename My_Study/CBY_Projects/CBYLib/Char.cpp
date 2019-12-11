#include "Char.h"

bool Char::Init()
{
	C_Object::Init();
	C_Actor::Init();
	
	return true;
}

bool Char::Frame()
{
	C_Object::Frame();

	splitenum++;
			if (splitenum == m_rtlist.size())
			{
				splitenum = 0;
			}
			C_Object::GetRECT(m_rtlist[splitenum]);
		


	if (Input.GetKeyCheck(VK_UP))																//����Ű�� ĳ������ �̵��� ���� ����ϸ� ����� ���̿� �Ұ������� ������ �ʰ� �ð��� ����ȭ�� �̿�
	{
		IY -= CHARSPEED * g_SecondTime;
	}
	if (Input.GetKeyCheck(VK_LEFT))
	{
		IX -= CHARSPEED * g_SecondTime;
	}
	if (Input.GetKeyCheck(VK_RIGHT))
	{
		IX += CHARSPEED * g_SecondTime;
	}
	if (Input.GetKeyCheck(VK_DOWN))
	{
		IY += CHARSPEED * g_SecondTime;
	}

	if (IX <= Winrt.left)		//ĳ���Ͱ� ȭ�� ������ �̵��ϴ°��� �����ϴ� ���ǹ����̴�.
	{
		IX = Winrt.left;
	}
	if (IX >= Winrt.right - rtsrc.right)
	{
		IX = Winrt.right - rtsrc.right;			//IX�� right��ǥ�� ���� ȭ�� ������ �����Ƿ� �� ����ŭ ���� ��ǥ�� ������ �� ������ �ʰ� �� �°� ����.
	}
	if (IY <= Winrt.top)
	{
		IY = Winrt.top;
	}
	if (IY >= Winrt.bottom - rtsrc.bottom)
	{
		IY = Winrt.bottom - rtsrc.bottom;
	}

	return true;
}

bool Char::Render()
{
		/*BitBlt(g_offScreenDC, IX, IY, rtsrc.right, rtsrc.bottom, m_pMaskBitMap->MemDC, rtsrc.left, rtsrc.top, SRCAND);
		BitBlt(g_offScreenDC, IX, IY, rtsrc.right, rtsrc.bottom, m_pBitMap->MemDC, rtsrc.left, rtsrc.top, SRCINVERT);
		BitBlt(g_offScreenDC, IX, IY, rtsrc.right, rtsrc.bottom, m_pMaskBitMap->MemDC, rtsrc.left, rtsrc.top, SRCINVERT);*/
	BitBlt(g_offScreenDC, IX, IY, rtsrc.right, rtsrc.bottom, m_pBitMap->MemDC, rtsrc.left, rtsrc.top, SRCCOPY);

		BitMapRt.right = IX + rtsrc.right;
		BitMapRt.bottom = IY + rtsrc.bottom;
		BitMapRt.left = IX;
		BitMapRt.top = IY;

	return true;
}

bool Char::Release()
{
	C_Object::Release();
	C_Actor::Release();
	return true;
}

Char::Char()
{
	splitenum = 0;
	CharShowTime=0;
	num = 0;
}


Char::~Char()
{
}
