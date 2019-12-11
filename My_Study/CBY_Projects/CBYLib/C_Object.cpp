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

bool C_Object::GetRECT(vector<RECT>& rtList, float showtime)
{
	CharTime = showtime / rtList.size();
	m_rtlist = rtList;
	return true;
}


fPOINT C_Object::GetPoint()
{
	return { IX,IY };
}

bool C_Object::GetRECT(RECT rt1)										//�ҽ��� ��ġ���� �ޱ�
{
	rtsrc = rt1;

	DestSize = sqrt((rt1.right*rt1.right) + (rt1.bottom*rt1.bottom));
	return true;
}

bool C_Object::GetRECT(vector<RECT>& rtList)										//�ҽ��� ��ġ���� �ޱ�
{
	m_rtlist = rtList;

	return true;
}

bool C_Object::SetPosition(float x, float y)												//�ҽ��� ������ �Է�
{
	IX = x;
	IY = y;

	BitMapRt.right = IX + rtsrc.right;
	BitMapRt.bottom = IY + rtsrc.bottom;
	BitMapRt.left = IX;
	BitMapRt.top = IY;

	return true;
}

fPOINT C_Object::GetPosition()
{
	BitMapRt.right = IX + rtsrc.right;
	BitMapRt.bottom = IY + rtsrc.bottom;
	BitMapRt.left = IX;
	BitMapRt.top = IY;

	return { IX,IY };
}

bool C_Object::Init()
{
	return true;
}
bool C_Object::Frame()
{
	Input.Frame();
	m_mousepos.x = (float)Input.m_Mouse.x;
	m_mousepos.y = (float)Input.m_Mouse.y;
	return true;
}
bool C_Object::Render()									//�⺻ �̹��� ���
{
	BitBlt(g_offScreenDC, IX, IY, rtsrc.right, rtsrc.bottom, m_pBitMap->MemDC, rtsrc.left, rtsrc.top, SRCCOPY);
	
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
