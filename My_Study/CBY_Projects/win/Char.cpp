
#include "Char.h"

bool Char::Init()
{
	return true;
}

bool Char::Frame()
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

	if (IX <= Winrt.left)		//ĳ���Ͱ� ȭ�� ������ �̵��ϴ°��� �����ϴ� ���ǹ����̴�.
	{
		IX = Winrt.left;
	}
	if (IX >= Winrt.right - rtdesk.right)
	{
		IX = Winrt.right - rtdesk.right;			//IX�� right��ǥ�� ���� ȭ�� ������ �����Ƿ� �� ����ŭ ���� ��ǥ�� ������ �� ������ �ʰ� �� �°� ����.
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
