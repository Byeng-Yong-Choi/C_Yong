#include "C_Actor.h"

bool C_Actor::GetRECT(RECT rt1)										//소스의 위치정보 받기
{
	rtsrc = rt1;

	DestSize = sqrt((rt1.right*rt1.right) + (rt1.bottom*rt1.bottom));
	return true;
}


bool C_Actor::GetRECT(vector<RECT>& rtList)										//소스의 위치정보 받기
{
	m_rtlist = rtList;

	return true;
}

bool C_Actor::SetPosition(float x, float y)												//소스의 데이터 입력
{
	IX = x-(rtsrc.right/2);
	if (IX < 0)
	{
		IX = 0;
	}
	else if (IX > Winrt.right)
	{
		IX = Winrt.right - rtsrc.right;
	}
	IY = y-(rtsrc.bottom/2);
	if (IY < 0)
	{
		IY = 0;
	}
	else if (IY > Winrt.bottom)
	{
		IY = Winrt.bottom - rtsrc.bottom;
	}

	BitMapRt.right = IX + rtsrc.right;
	BitMapRt.bottom = IY + rtsrc.bottom;
	BitMapRt.left = IX;
	BitMapRt.top = IY;
	return true;
}


bool C_Actor::Init()
{
	return true;
}

bool C_Actor::Frame()
{
	return true;
}

bool C_Actor::Render()
{
	return true;
}

bool C_Actor::Release()
{
	return true;
}

C_Actor::C_Actor()
{
}


C_Actor::~C_Actor()
{
}
