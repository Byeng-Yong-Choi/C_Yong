#include "CBYBitMap.h"

bool CBYBitMap::Load(const TCHAR* FileName)
{
	c_HBitmap = (HBITMAP)LoadImage(g_hInstance, FileName, IMAGE_BITMAP, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);		//��Ʈ�� �̹�������Ʈ���ڵ���·� �޾Ƽ� �ڵ鿡 �����Ѵ�
	MemDC = CreateCompatibleDC(g_ScreenDC);																				//�����쿡 ����ϱ� ���� ScreenDC�� ȣȯ�Ǵ� �޸�DC�� MemDC�� �����
	SelectObject(MemDC, c_HBitmap);																						//�޸�DC�� ��Ʈ�� �ڵ��� SelectObject�ؼ� ������ �ִ´�

	//GetObject(c_HBitmap, sizeof(BITMAP), &c_Bitmap);			//��Ʈ���� ������ �޾Ƴ���

	return true;
}

void CBYBitMap::rect(RECT charRt1,RECT charRt2)																			//��Ʈ�� �̹������� ��¹����� �޾Ƴ��� �Լ�
{
	rtdesk = charRt1;
	rtsrc = charRt2;
}

bool CBYBitMap::Init()
{
	return true;
}
bool CBYBitMap::Frame()
{
	return true;
}

bool CBYBitMap::weaponRender(float XY)																	//���� �߻�� ��µǴ� ������ ��½��۵� ��ġ���� y������ ���� �ö󰡱⸸ �Ѵ�
{
	weIY -= XY;
	if (weIY <= 0)																						//���Ⱑ �߻�ǰ� Ŭ���̾�Ʈ ȭ�� �ٱ����� �������ϸ� false�� ��ȯ�Ͽ� ���� ����		
	{
		return false;
	}
	//BitBlt(g_offScreenDC, weIX, weIY, rtdesk.right, rtdesk.bottom, MemDC, rtsrc.left, rtsrc.top, SRCCOPY);
	TransparentBlt(g_offScreenDC, weIX, weIY, rtdesk.right, rtdesk.bottom, MemDC, rtsrc.left, rtsrc.top, rtdesk.right, rtdesk.bottom, RGB(255, 255, 255));
	BitMapRt.right = weIX + rtdesk.right;
	BitMapRt.bottom = weIY + rtdesk.bottom;
	BitMapRt.left = weIX;
	BitMapRt.top = weIY;
	return true;
}


bool CBYBitMap::Render()																				//�⺻���� ��Ʈ�� ������� ������ rect�Լ��� ������ �ް� ���
{																														
	//BitBlt(g_offScreenDC, rtdesk.left, rtdesk.top, rtdesk.right, rtdesk.bottom, MemDC, rtsrc.left, rtsrc.top, SRCCOPY);
	TransparentBlt(g_offScreenDC, rtdesk.left, rtdesk.top, rtdesk.right, rtdesk.bottom, MemDC, rtsrc.left, rtsrc.top, rtdesk.right, rtdesk.bottom, RGB(255, 255, 255));
	BitMapRt.right = rtdesk.left+rtdesk.right;
	BitMapRt.bottom = rtdesk.top+rtdesk.bottom;
	BitMapRt.left = rtdesk.left;
	BitMapRt.top = rtdesk.top;
	return true;
}

bool CBYBitMap::Render(float IX, float IY)																				//�⺻���� ��Ʈ�� ������� ������ rect�Լ��� ��ġ�� �޾Ƴ��� ����ϱ� ���ϳ�
{																														//�ð��� ����ȭ�� x,y��ǥ�� �Ǽ��� ������ ��츦 ���� ����
	//BitBlt(g_offScreenDC, IX, IY, rtdesk.right, rtdesk.bottom, MemDC, rtsrc.left, rtsrc.top, SRCCOPY);
	TransparentBlt(g_offScreenDC, IX, IY, rtdesk.right, rtdesk.bottom, MemDC, rtsrc.left, rtsrc.top, rtdesk.right, rtdesk.bottom, RGB(255, 255, 255));
	BitMapRt.right = IX+rtdesk.right;
	BitMapRt.bottom= IY+rtdesk.bottom;
	BitMapRt.left = IX;
	BitMapRt.top = IY;
	return true;
}

bool CBYBitMap::Release()
{
	DeleteObject(c_HBitmap);
	ReleaseDC(g_hwnd,MemDC);
	return true;
}

CBYBitMap::CBYBitMap()
{
}


CBYBitMap::~CBYBitMap()
{
}
