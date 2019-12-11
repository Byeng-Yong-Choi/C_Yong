#include "C_Object.h"


bool C_Object::Load(const TCHAR* FileName, const TCHAR* MaskFileName)
{
	m_pBitMap = (C_BitMapManager::get().Load(FileName));
	if (m_pBitMap != nullptr)
	{
		if (MaskFileName != nullptr)
		{
			m_pMaskBitMap = C_BitMapManager::get().Load(MaskFileName);
		}
	}
	return true;
}



bool C_Object::GetRECT(RECT rt1)										//소스의 위치정보 받기
{
	rtsrc = rt1;

	DestSize = sqrt((rt1.right*rt1.right) + (rt1.bottom*rt1.bottom));
	return true;
}

bool C_Object::SetPosition(float x, float y)												//소스의 데이터 입력
{
	IX = x;
	IY = y;

	BitMapRt.right = IX + rtsrc.right;
	BitMapRt.bottom = IY + rtsrc.bottom;
	BitMapRt.left = IX;
	BitMapRt.top = IY;

	return true;
}

bool C_Object::Init()
{
	Rotat = CreateCompatibleBitmap(g_ScreenDC, DestSize, DestSize);
	TransDC = CreateCompatibleDC(g_ScreenDC);
	BrushDC = CreateCompatibleDC(g_ScreenDC);
	MaskDC= CreateCompatibleDC(g_ScreenDC);
	ColorDC= CreateCompatibleDC(g_ScreenDC);
	COLORREF HColor = RGB(255, 255, 255);
	TransBrush = CreateSolidBrush(HColor);
	return true;
}
bool C_Object::Frame()
{
	return true;
}
bool C_Object::Render()									//기본 이미지 출력
{
	BitBlt(g_offScreenDC, IX, IY, rtsrc.right, rtsrc.bottom, m_pBitMap->MemDC, rtsrc.left, rtsrc.top, SRCCOPY);
	
	return true;
}
bool C_Object::Release()
{
	DeleteObject(OldBitMap);
	DeleteObject(TransBrush);
	DeleteDC(BrushDC);
	DeleteDC(TransDC);
	DeleteDC(MaskDC);
	DeleteDC(ColorDC);
	return true;
}

HBITMAP C_Object::GetRotationBitMap(float Angle,HDC SrcDC)
{
	OldBitMap = (HBITMAP)SelectObject(TransDC, Rotat);
	SelectObject(BrushDC, TransBrush);
	PatBlt(TransDC, 0, 0, DestSize, DestSize, PATCOPY);
	int Old=SetGraphicsMode(TransDC, GM_ADVANCED);
	XFORM xForm;
	float radian = Angle * (3.141592 / 180);
	xForm.eM11 = cos(radian);
	xForm.eM12 = sin(radian);
	xForm.eM21 = -sin(radian);
	xForm.eM22 = cos(radian);
	xForm.eDx= DestSize/2;
	xForm.eDy= DestSize/2;

	SetWorldTransform(TransDC, &xForm);
	BitBlt(TransDC, -(rtsrc.right / 2), -(rtsrc.bottom/2), rtsrc.right, rtsrc.bottom, SrcDC, rtsrc.left,rtsrc.top,SRCCOPY);
	xForm.eM11 = 1;	xForm.eM12 = 0;
	xForm.eM21 = 0;	xForm.eM22 = 1;
	xForm.eDx = 0;
	xForm.eDy = 0;
	SetWorldTransform(TransDC, &xForm);

	SetGraphicsMode(TransDC, Old);
	SelectObject(TransDC, OldBitMap);
	return Rotat;
}

C_Object::C_Object()
{
}


C_Object::~C_Object()
{
}
