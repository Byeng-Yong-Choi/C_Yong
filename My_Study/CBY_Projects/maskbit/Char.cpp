#include "Char.h"

bool Char::Init()
{
	C_Object::Init();
	LeftRt1 = { 0,0,33,59 };
	LeftRt2 = { 55,1,0,0 };
	Left2Rt1 = { 0,0,25,60 };
	Left2Rt2 = { 29,1,0,0 };
	RightRt1 = { 0,0,32,59 };
	RightRt2 = { 178,1,0,0 };
	Right2Rt1 = { 0,0,26,60 };
	Right2Rt2 = { 211,1,0,0 };
	EngineRt1 = {0,0,3,11};
	EngineRt2 = {265,1,0,0};
	return true;
}

bool Char::Frame()
{
	static float a = 0;
	a += 50 * g_SecondTime;
	MaskRotatBit = GetRotationBitMap(a, m_pMaskBitMap->MemDC);
	RotatBit = GetRotationBitMap(a, m_pBitMap->MemDC);
	OldMaskBitMap = (HBITMAP)SelectObject(MaskDC, MaskRotatBit);
	OldColorBitMap = (HBITMAP)SelectObject(ColorDC, RotatBit);
	pose = 0;
	if (Input.GetKeyCheck(VK_UP))																//방향키로 캐릭터의 이동을 정의 계산하며 사양의 차이에 불공정함이 생기지 않게 시간의 동기화를 이용
	{
		if (Input.GetKeyCheck(VK_RIGHT))
		{
			MaskRotatBit = GetRotationBitMap(45, m_pMaskBitMap->MemDC);
			RotatBit = GetRotationBitMap(45, m_pBitMap->MemDC);
			OldMaskBitMap = (HBITMAP)SelectObject(MaskDC, MaskRotatBit);
			OldColorBitMap = (HBITMAP)SelectObject(ColorDC, RotatBit);
			pose = 7;
		}
		else if (Input.GetKeyCheck(VK_LEFT))
		{
			MaskRotatBit = GetRotationBitMap(315, m_pMaskBitMap->MemDC);
			RotatBit = GetRotationBitMap(315, m_pBitMap->MemDC);
			OldMaskBitMap = (HBITMAP)SelectObject(MaskDC, MaskRotatBit);
			OldColorBitMap = (HBITMAP)SelectObject(ColorDC, RotatBit);
			pose = 6;
		}
		else
		{
			pose = 5;
		}
		IY -= CHARSPEED * g_SecondTime;
	}
	if (Input.GetKeyCheck(VK_LEFT))
	{
		if (Input.GetKeyCheck(VK_UP))
		{
			MaskRotatBit=GetRotationBitMap(315, m_pMaskBitMap->MemDC);
			RotatBit = GetRotationBitMap(315, m_pBitMap->MemDC);
			OldMaskBitMap=(HBITMAP)SelectObject(MaskDC,MaskRotatBit);
			OldColorBitMap = (HBITMAP)SelectObject(ColorDC, RotatBit);
			pose = 6;
		}
			else if (Input.KeyData[VK_LEFT] == KEY_PUSH)
			{
				num = 0;
				pose = 1;
			}
			else if (Input.KeyData[VK_LEFT] == KEY_HOLD)
			{
				num++;
				pose = 1;
				if (num > 300)
				{
					pose = 2;
				}
			}
			IX -= CHARSPEED * g_SecondTime;
	}
	if (Input.GetKeyCheck(VK_RIGHT))
	{
		if (Input.GetKeyCheck(VK_UP))
		{
			MaskRotatBit = GetRotationBitMap(45, m_pMaskBitMap->MemDC);
			RotatBit = GetRotationBitMap(45, m_pBitMap->MemDC);
			OldMaskBitMap = (HBITMAP)SelectObject(MaskDC, MaskRotatBit);
			OldColorBitMap = (HBITMAP)SelectObject(ColorDC, RotatBit);
			pose = 7;
		}
		else if (Input.KeyData[VK_RIGHT] == KEY_PUSH)
			{
				num = 0;
				pose = 3;
			}
		else if (Input.KeyData[VK_RIGHT] == KEY_HOLD)
			{
				num++;
				pose = 3;
				if (num > 300)
				{
					pose = 4;
				}

			}
			IX += CHARSPEED * g_SecondTime;
	}
	if (Input.GetKeyCheck(VK_DOWN))
	{
			IY += CHARSPEED * g_SecondTime;
	}

	if (IX <= Winrt.left)		//캐릭터가 화면 밖으로 이동하는것을 제한하는 조건문들이다.
	{
		IX = Winrt.left;
	}
	if (IX >= Winrt.right - rtsrc.right)
	{
		IX = Winrt.right - rtsrc.right;			//IX가 right좌표로 가면 화면 밖으로 나가므로 그 폭만큼 빼서 좌표를 넣으면 더 나가지 않고 딱 맞게 들어간다.
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
	switch (pose)
	{
	case 0:
		BitBlt(g_offScreenDC, IX, IY, rtsrc.right, rtsrc.bottom, m_pMaskBitMap->MemDC, rtsrc.left, rtsrc.top, SRCAND);
		BitBlt(g_offScreenDC, IX, IY, rtsrc.right, rtsrc.bottom, m_pBitMap->MemDC, rtsrc.left, rtsrc.top, SRCINVERT);
		BitBlt(g_offScreenDC, IX, IY, rtsrc.right, rtsrc.bottom, m_pMaskBitMap->MemDC, rtsrc.left, rtsrc.top, SRCINVERT);

		///*BitBlt(g_offScreenDC, IX, IY, DestSize, DestSize, MaskDC, 0, 0, SRCAND);
		//BitBlt(g_offScreenDC, IX, IY, DestSize, DestSize, ColorDC, 0, 0, SRCINVERT);
		//BitBlt(g_offScreenDC, IX, IY, DestSize, DestSize, MaskDC, 0, 0, SRCINVERT);
		//SelectObject(ColorDC, OldColorBitMap);
		//SelectObject(MaskDC, OldMaskBitMap);*/
		break;

	case 1:
		BitBlt(g_offScreenDC, IX, IY, LeftRt1.right, LeftRt1.bottom, m_pMaskBitMap->MemDC, LeftRt2.left, LeftRt2.top, SRCAND);
		BitBlt(g_offScreenDC, IX, IY, LeftRt1.right, LeftRt1.bottom, m_pBitMap->MemDC, LeftRt2.left, LeftRt2.top, SRCINVERT);
		BitBlt(g_offScreenDC, IX, IY, LeftRt1.right, LeftRt1.bottom, m_pMaskBitMap->MemDC, LeftRt2.left, LeftRt2.top, SRCINVERT);
		EX = IX + LeftRt1.right/2;
		EY = IY + LeftRt1.bottom;
		BitBlt(g_offScreenDC, EX, EY, EngineRt1.right, EngineRt1.bottom, m_pMaskBitMap->MemDC, EngineRt2.left, EngineRt2.top, SRCAND);
		BitBlt(g_offScreenDC, EX, EY, EngineRt1.right, EngineRt1.bottom, m_pBitMap->MemDC, EngineRt2.left, EngineRt2.top, SRCINVERT);
		BitBlt(g_offScreenDC, EX, EY, EngineRt1.right, EngineRt1.bottom, m_pMaskBitMap->MemDC, EngineRt2.left, EngineRt2.top, SRCINVERT);
		break;

	case 2:
		BitBlt(g_offScreenDC, IX, IY, Left2Rt1.right, Left2Rt1.bottom, m_pMaskBitMap->MemDC, Left2Rt2.left, Left2Rt2.top, SRCAND);
		BitBlt(g_offScreenDC, IX, IY, Left2Rt1.right, Left2Rt1.bottom, m_pBitMap->MemDC, Left2Rt2.left, Left2Rt2.top, SRCINVERT);
		BitBlt(g_offScreenDC, IX, IY, Left2Rt1.right, Left2Rt1.bottom, m_pMaskBitMap->MemDC, Left2Rt2.left, Left2Rt2.top, SRCINVERT);
		EX = IX + Left2Rt1.right/2;
		EY = IY + Left2Rt1.bottom;
		BitBlt(g_offScreenDC, EX, EY, EngineRt1.right, EngineRt1.bottom, m_pMaskBitMap->MemDC, EngineRt2.left, EngineRt2.top, SRCAND);
		BitBlt(g_offScreenDC, EX, EY, EngineRt1.right, EngineRt1.bottom, m_pBitMap->MemDC, EngineRt2.left, EngineRt2.top, SRCINVERT);
		BitBlt(g_offScreenDC, EX, EY, EngineRt1.right, EngineRt1.bottom, m_pMaskBitMap->MemDC, EngineRt2.left, EngineRt2.top, SRCINVERT);
		break;

	case 3:
		BitBlt(g_offScreenDC, IX, IY, RightRt1.right, RightRt1.bottom, m_pMaskBitMap->MemDC, RightRt2.left, RightRt2.top, SRCAND);
		BitBlt(g_offScreenDC, IX, IY, RightRt1.right, RightRt1.bottom, m_pBitMap->MemDC, RightRt2.left, RightRt2.top, SRCINVERT);
		BitBlt(g_offScreenDC, IX, IY, RightRt1.right, RightRt1.bottom, m_pMaskBitMap->MemDC, RightRt2.left, RightRt2.top, SRCINVERT);
		EX = IX + RightRt1.right/2;
		EY = IY + RightRt1.bottom;
		BitBlt(g_offScreenDC, EX, EY, EngineRt1.right, EngineRt1.bottom, m_pMaskBitMap->MemDC, EngineRt2.left, EngineRt2.top, SRCAND);
		BitBlt(g_offScreenDC, EX, EY, EngineRt1.right, EngineRt1.bottom, m_pBitMap->MemDC, EngineRt2.left, EngineRt2.top, SRCINVERT);
		BitBlt(g_offScreenDC, EX, EY, EngineRt1.right, EngineRt1.bottom, m_pMaskBitMap->MemDC, EngineRt2.left, EngineRt2.top, SRCINVERT);
		break;

	case 4:
		BitBlt(g_offScreenDC, IX, IY, Right2Rt1.right, Right2Rt1.bottom, m_pMaskBitMap->MemDC, Right2Rt2.left, Right2Rt2.top, SRCAND);
		BitBlt(g_offScreenDC, IX, IY, Right2Rt1.right, Right2Rt1.bottom, m_pBitMap->MemDC, Right2Rt2.left, Right2Rt2.top, SRCINVERT);
		BitBlt(g_offScreenDC, IX, IY, Right2Rt1.right, Right2Rt1.bottom, m_pMaskBitMap->MemDC, Right2Rt2.left, Right2Rt2.top, SRCINVERT);
		EX = IX + Right2Rt1.right / 2;
		EY = IY + Right2Rt1.bottom;
		BitBlt(g_offScreenDC, EX, EY, EngineRt1.right, EngineRt1.bottom, m_pMaskBitMap->MemDC, EngineRt2.left, EngineRt2.top, SRCAND);
		BitBlt(g_offScreenDC, EX, EY, EngineRt1.right, EngineRt1.bottom, m_pBitMap->MemDC, EngineRt2.left, EngineRt2.top, SRCINVERT);
		BitBlt(g_offScreenDC, EX, EY, EngineRt1.right, EngineRt1.bottom, m_pMaskBitMap->MemDC, EngineRt2.left, EngineRt2.top, SRCINVERT);
		break;

	case 5:
		BitBlt(g_offScreenDC, IX, IY, rtsrc.right, rtsrc.bottom, m_pMaskBitMap->MemDC, rtsrc.left, rtsrc.top, SRCAND);
		BitBlt(g_offScreenDC, IX, IY, rtsrc.right, rtsrc.bottom, m_pBitMap->MemDC, rtsrc.left, rtsrc.top, SRCINVERT);
		BitBlt(g_offScreenDC, IX, IY, rtsrc.right, rtsrc.bottom, m_pMaskBitMap->MemDC, rtsrc.left, rtsrc.top, SRCINVERT);
		EX = IX + Right2Rt1.right/2+6;
		EY = IY + Right2Rt1.bottom;
		BitBlt(g_offScreenDC, EX, EY, EngineRt1.right, EngineRt1.bottom, m_pMaskBitMap->MemDC, EngineRt2.left, EngineRt2.top, SRCAND);
		BitBlt(g_offScreenDC, EX, EY, EngineRt1.right, EngineRt1.bottom, m_pBitMap->MemDC, EngineRt2.left, EngineRt2.top, SRCINVERT);
		BitBlt(g_offScreenDC, EX, EY, EngineRt1.right, EngineRt1.bottom, m_pMaskBitMap->MemDC, EngineRt2.left, EngineRt2.top, SRCINVERT);
		break;

	case 6:
		BitBlt(g_offScreenDC, IX - (DestSize / 2), IY - (DestSize / 2), DestSize, DestSize, MaskDC, 0, 0, SRCAND);
		BitBlt(g_offScreenDC, IX - (DestSize / 2), IY - (DestSize / 2), DestSize, DestSize, ColorDC, 0, 0, SRCINVERT);
		BitBlt(g_offScreenDC, IX - (DestSize / 2), IY - (DestSize / 2), DestSize, DestSize, MaskDC, 0, 0, SRCINVERT);

		SelectObject(ColorDC, OldColorBitMap);
		SelectObject(MaskDC, OldMaskBitMap);
		break;

	case 7:
		BitBlt(g_offScreenDC, IX - (DestSize / 2), IY - (DestSize / 2), DestSize, DestSize, MaskDC, 0, 0, SRCAND);
		BitBlt(g_offScreenDC, IX - (DestSize / 2), IY - (DestSize / 2), DestSize, DestSize, ColorDC, 0, 0, SRCINVERT);
		BitBlt(g_offScreenDC, IX - (DestSize / 2), IY - (DestSize / 2), DestSize, DestSize, MaskDC, 0, 0, SRCINVERT);

		SelectObject(ColorDC, OldColorBitMap);
		SelectObject(MaskDC, OldMaskBitMap);
		break;
	}
	if (pose == 6 || pose == 7)
	{
		BitMapRt.right = (IX - (DestSize / 2)) + DestSize;
		BitMapRt.bottom = (IY - (DestSize / 2)) + DestSize;
		BitMapRt.left = IX - (DestSize / 2);
		BitMapRt.top = IY - (DestSize / 2);
	}
	else
	{
		BitMapRt.right = IX + rtsrc.right;
		BitMapRt.bottom = IY + rtsrc.bottom;
		BitMapRt.left = IX;
		BitMapRt.top = IY;
	}
	return true;
}

bool Char::Release()
{
	C_Object::Release();
	return true;
}

Char::Char()
{
	num = 0;
}


Char::~Char()
{
}
