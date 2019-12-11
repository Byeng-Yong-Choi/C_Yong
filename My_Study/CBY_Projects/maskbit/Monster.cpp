#include "Monster.h"



bool Monster::Init()
{
	C_Object::Init();
	alpha.BlendOp = AC_SRC_OVER;
	alpha.AlphaFormat = AC_SRC_OVER;	//32비트 이미지면 alpha아니면 0
	alpha.BlendFlags=0;				//무조건 0
	alpha.SourceConstantAlpha = 255;		//알파값 투명도 0~255를 넣는다.

	AlphaDC = CreateCompatibleDC(g_ScreenDC);
	AlphaBitMap = CreateCompatibleBitmap(g_ScreenDC, Winrt.right, Winrt.bottom);
	SelectObject(AlphaDC, AlphaBitMap);

	return true;
}

bool Monster::Frame()
{
	if (Death == 1)
	{
		if (AlphaNum == 0.0f)
		{
			return true;
		}
		else
		{
			AlphaNum -= g_SecondTime * 200;
			if (AlphaNum < 0)
			{
				AlphaNum = 0.0f;
			}
			alpha.SourceConstantAlpha = AlphaNum;
		}
		temp = 1;
	}
	else if (Death == 2)
	{
		if (temp == 1)
		{
			IX = rand() % (Winrt.right - rtsrc.right);
			temp = 0;
		}
		AlphaNum += g_SecondTime * 200;
		if (AlphaNum > 255)
		{
			AlphaNum = 255.0f;
			Death == 0;
		}
		alpha.SourceConstantAlpha = AlphaNum;
		
	}



	return true;
}

bool Monster::Render()
{
	if (Death == 1)
	{
		BitBlt(AlphaDC, 0, 0, Winrt.right, Winrt.bottom, g_offScreenDC, 0, 0, SRCCOPY);
		BitBlt(AlphaDC, IX, IY, rtsrc.right, rtsrc.bottom, m_pMaskBitMap->MemDC, rtsrc.left, rtsrc.top, SRCAND);
		BitBlt(AlphaDC, IX, IY, rtsrc.right, rtsrc.bottom, m_pBitMap->MemDC, rtsrc.left, rtsrc.top, SRCINVERT);
		BitBlt(AlphaDC, IX, IY, rtsrc.right, rtsrc.bottom, m_pMaskBitMap->MemDC, rtsrc.left, rtsrc.top, SRCINVERT);

		AlphaBlend(g_offScreenDC, IX, IY, rtsrc.right, rtsrc.bottom, AlphaDC, IX, IY, rtsrc.right, rtsrc.bottom, alpha);
	}
	else if (Death == 2)
	{
		BitBlt(AlphaDC, 0, 0, Winrt.right, Winrt.bottom, g_offScreenDC, 0, 0, SRCCOPY);
		BitBlt(AlphaDC, IX, IY, rtsrc.right, rtsrc.bottom, m_pMaskBitMap->MemDC, rtsrc.left, rtsrc.top, SRCAND);
		BitBlt(AlphaDC, IX, IY, rtsrc.right, rtsrc.bottom, m_pBitMap->MemDC, rtsrc.left, rtsrc.top, SRCINVERT);
		BitBlt(AlphaDC, IX, IY, rtsrc.right, rtsrc.bottom, m_pMaskBitMap->MemDC, rtsrc.left, rtsrc.top, SRCINVERT);

		AlphaBlend(g_offScreenDC, IX, IY, rtsrc.right, rtsrc.bottom, AlphaDC, IX, IY, rtsrc.right, rtsrc.bottom, alpha);
	}
	else
	{
		BitBlt(g_offScreenDC, IX, IY, rtsrc.right, rtsrc.bottom, m_pMaskBitMap->MemDC, rtsrc.left, rtsrc.top, SRCAND);
		BitBlt(g_offScreenDC, IX, IY, rtsrc.right, rtsrc.bottom, m_pBitMap->MemDC, rtsrc.left, rtsrc.top, SRCINVERT);
		BitBlt(g_offScreenDC, IX, IY, rtsrc.right, rtsrc.bottom, m_pMaskBitMap->MemDC, rtsrc.left, rtsrc.top, SRCINVERT);
	}

	BitMapRt.right = IX + rtsrc.right;
	BitMapRt.bottom = IY + rtsrc.bottom;
	BitMapRt.left = IX;
	BitMapRt.top = IY;
	return true;
}

bool Monster::Release()
{
	C_Object::Release();
	DeleteObject(AlphaBitMap);
	ReleaseDC(g_hwnd, AlphaDC);
	return true;
}

Monster::Monster()
{
	temp = 0;
	AlphaNum = 255.0f;
	Death = 0;
}


Monster::~Monster()
{
}
