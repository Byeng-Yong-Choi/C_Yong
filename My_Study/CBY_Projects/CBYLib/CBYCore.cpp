#include "CBYCore.h"

HDC g_ScreenDC;
HDC g_offScreenDC;


bool CBYCore::Init()
{
	return true;
}
bool CBYCore::Frame()
{
	return true;
}
bool CBYCore::Render()
{
	return true;
}
bool CBYCore::Release()
{
	return true;
}


bool CBYCore::GameRun()
{
	GetGameRun = CoreInit();											//���Լ� ����� Init�����ϰ� Frame�� Render�Լ��� ���� ��� �̺�Ʈ�� ����� Release�� �޸𸮸� ����ְ� �����Ѵ�.
	if (GetGameRun == false)
	{
		return false;
	}

	MSG msg;															//�޼����� ���� MSG ����
	ZeroMemory(&msg, sizeof(msg));
	while (GetGameRun)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))				//PeekMessage�� �޼����� ������ �����¾��� ��� ���ư��� �߻���1 ������ 0�� ��ȯ
		{															//�׷��Ƿ� �޼���ť�� �޼����� �׿� ������ ��� �޼��� ó���ϴٰ� ������ Frame�� Render�� ���ư� 1�������� ���ư��� ��

			TranslateMessage(&msg);									//�޼���ť�� �ִ� �޼����� �޾Ƽ� Ű������ ������ �߻��� WN_CHAR�� �����ؼ� �޼���ť�� �ִ´�
			DispatchMessage(&msg);									//WndProc�� �޼���ť���ִ� �޼����� �Ѱ��ش�.
			if (msg.message == WM_QUIT)
			{
				break;
			}
		}
		else
		{
			if (CoreFrame() == false)
			{
				return false;
			}
			if (CoreRender() == false)
			{
				return false;
			}
		}
	}
	if (CoreRelease() == false)
	{
		return false;
	}
	return true;
}

bool  CBYCore::CoreInit()
{
	if (time.Init()|| Input.Init())
	{
		GetGameRun = true;
		ScreenDC = GetDC(g_hwnd);														//������ ȭ�鿡 ��� DC�� ������� �������� �ڵ������� �޾� ScreenDC�� ����
		offScreenDC = CreateCompatibleDC(ScreenDC);										//���� ���۸� ������ ���� offScreenDC�� ScreenDC�� ȣȯ�Ǵ� DC�� ����
		offScreenDCBitMap=CreateCompatibleBitmap(ScreenDC, Winrt.right, Winrt.bottom);	//offScreen�� ��� ��Ʈ���ڵ��� ����
		SelectObject(offScreenDC, offScreenDCBitMap);									//offScreenDC�� ���� ���� offScreen��Ʈ�� �ڵ��� SelectObject�Ѵ�

		COLORREF BkColor = RGB(125, 126, 200);												// �����쿡 ������ ǥ���ϱ� ���� ���� ����
		BackColor = CreateSolidBrush(BkColor);											// �����쿡 �Ѹ� ���� �����ڵ��� �����Ѵ�
		SelectObject(offScreenDC, BackColor);											// offScreenDC�� ���� ���� �����ڵ��� SelectObject�Ѵ�.

		g_ScreenDC = ScreenDC;															//�ٸ� Ŭ�������� �̿��ϱ� ���ϰ� �������� �д�
		g_offScreenDC = offScreenDC;													//�ٸ� Ŭ�������� �̿��ϱ� ���ϰ� �������� �д�

		return Init();
	}
	else
	return false;
};
bool  CBYCore::CoreFrame()
{
	if (time.Frame())
	{
		if (Input.Frame())
		{
			Bitmap.Frame();
			return Frame();
		}
	}
	else
		return false;
};
bool CBYCore::PreRender()													//������ ������� ���� ������ �Ѿ�� ȭ���� �����ϰ� ������� Ŭ�������ִ� ����
{
	PatBlt(offScreenDC, 0, 0, Winrt.right, Winrt.bottom, PATCOPY);		//PatBlt�� ������ȭ���� DC�� ����(�귯��)�� ĥ�Ѵ�
	return true;
};

bool  CBYCore::CoreRender()
{
	PreRender();
	Render();
  	time.Render();
	PostRender();
	return true;

};

bool CBYCore::PostRender()															//����� g_offScreenDC������ �Ѱܹ޾� ���� DC���� ����ϴ°�
{
	BitBlt(ScreenDC,0,0, Winrt.right, Winrt.bottom,g_offScreenDC,0,0, SRCCOPY);		//g_offScreenDC�� �Էµ� ���۳����� ScreenDC�� Copy�Ͽ� ����Ѵ�.
	return true;
};

bool  CBYCore::CoreRelease()
{
	DeleteObject(BackColor);
	DeleteObject(offScreenDCBitMap);
	ReleaseDC(g_hwnd, ScreenDC);
	ReleaseDC(g_hwnd, offScreenDC);
	time.Release();
	Input.Release();
	Release();
	return true;
};

CBYCore::CBYCore()
{
	GetGameRun = false;
}


CBYCore::~CBYCore()
{
}
