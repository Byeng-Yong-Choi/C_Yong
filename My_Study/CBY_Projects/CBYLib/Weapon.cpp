#include "Weapon.h"



//bool Weapon::EndY(float Y)
//{
//	IY -= Y;
//	if (IY <= 0)																						//���Ⱑ �߻�ǰ� Ŭ���̾�Ʈ ȭ�� �ٱ����� �������ϸ� false�� ��ȯ�Ͽ� ���� ����		
//	{
//		return true;
//	}
//	return false;
//}

bool Weapon::Init()
{
	C_Object::Init();
	C_Actor::Init();
	return true;
}

bool Weapon::Frame()
{
	C_Object::Frame();
	if (Input.GetKeyCheck(VK_SPACE))																//SPACE BAR�Է½� ���Ⱑ �߻�ǰ� �Է� �޴´�
	{
		if (Input.KeyData[VK_SPACE] == KEY_PUSH || Input.KeyData[VK_SPACE] == KEY_HOLD)
		{
			if (Input.KeyData[VK_SPACE] == KEY_HOLD)											//KEY_HOLD���¸� ��� �߻簡 �̷�����°� �ƴ� 500�����ӿ� �ѹ��� �߻簡 �ǵ��� �Ѵ�
			{
				num += 1;
				if (num == 100)
				{
					num = 0;
					return true;
				}
				else
				{
					return false;
				}
			}
			else if (Input.KeyData[VK_SPACE] == KEY_PUSH)
			{
				num = 0;
				return true;															//Ǫ���� �ɶ����� �߻�
			}
		}

	}
	else
		return false;
}

bool Weapon::Render()
{
	BitBlt(g_offScreenDC, IX, IY, rtsrc.right, rtsrc.bottom, m_pMaskBitMap->MemDC, rtsrc.left, rtsrc.top, SRCAND);
	BitBlt(g_offScreenDC, IX, IY, rtsrc.right, rtsrc.bottom, m_pBitMap->MemDC, rtsrc.left, rtsrc.top, SRCINVERT);
	BitBlt(g_offScreenDC, IX, IY, rtsrc.right, rtsrc.bottom, m_pMaskBitMap->MemDC, rtsrc.left, rtsrc.top, SRCINVERT);

	BitMapRt.right = IX + rtsrc.right;
	BitMapRt.bottom = IY + rtsrc.bottom;
	BitMapRt.left = IX;
	BitMapRt.top = IY;
	return true;
}

bool Weapon::Release()
{
	C_Object::Release();
	C_Actor::Release();
	return true;
}


Weapon::Weapon()
{
	num = 0;
}


Weapon::~Weapon()
{
}
