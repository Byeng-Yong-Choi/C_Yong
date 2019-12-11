
#include "Char.h"

bool Char::Init()
{
	return true;
}

bool Char::Frame()
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

	if (IX <= Winrt.left)		//캐릭터가 화면 밖으로 이동하는것을 제한하는 조건문들이다.
	{
		IX = Winrt.left;
	}
	if (IX >= Winrt.right - rtdesk.right)
	{
		IX = Winrt.right - rtdesk.right;			//IX가 right좌표로 가면 화면 밖으로 나가므로 그 폭만큼 빼서 좌표를 넣으면 더 나가지 않고 딱 맞게 들어간다.
	}
	if (IY <= Winrt.top)
	{
		IY = Winrt.top;
	}
	if (IY >= Winrt.bottom - rtdesk.bottom)
	{
		IY = Winrt.bottom - rtdesk.bottom;
	}
	return true;
}

bool Char::Render()
{
	C_Object::Render();
	return true;
}

bool Char::Release()
{
	return true;
}

Char::Char()
{
}


Char::~Char()
{
}
