#include "CBYWindow.h"

HWND g_hwnd;
HINSTANCE g_hInstance;
RECT Winrt;
CBYWindow* g_CBYWindow=nullptr;

LRESULT CALLBACK StaticWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)				//���� �Լ��� �����Ͽ� WndProc�����ϴ� ������� �� ���̺귯���� �ҷ����� �ٸ�������
{																									//���ϴ� ������� �޼����� ó���� �� �ְ� �ϱ� ���� �̷��� ���δ�.
	return g_CBYWindow->WndProc(hWnd,message,wParam,lParam );
}

LRESULT CBYWindow::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_SIZE:
		if (SIZE_MINIMIZED != wParam)
		{
			UINT width = LOWORD(lParam);
			UINT height = HIWORD(lParam);
			GetClientRect(g_hwnd, &Winrt);
			g_CBYWindow->ResizeDevice(width, height);
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_COMMAND:
	{
		// id�� �ش��ϴ� ��Ʈ��
		switch (LOWORD(wParam))
		{
		case 200:		//��ư Ŭ��
			g_CBYWindow->SendMSGClick();
			break;
		}
	}
	break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}

bool CBYWindow::ResizeDevice(UINT width, UINT height)
{
	return true;
}

void CBYWindow::SendMSGClick()
{
	
}

bool CBYWindow::InitWindow(const TCHAR* WindowClass,const TCHAR* WindowName)
{
	wn.cbSize=sizeof(WNDCLASSEX);				//������ ũ��(������ Ȯ������ ������̹Ƿ� �� ũ�⸸ŭ �����ָ� �ȴ� ���� ����)
	wn.style=CS_HREDRAW|CS_VREDRAW;				//������ ���� ��Ÿ��(���� �Ʒ��� �ѷ��ش� ���ߴ�)
	wn.lpfnWndProc = &StaticWndProc;			//�����찡 �����ǰ� �̺�Ʈ �߻��� �޼����� ������ ó���� �� ����
	wn.cbClsExtra=0;							
	wn.cbWndExtra=0;
	wn.hInstance= hInstance;					//������ �ν��Ͻ� ���� �ν��Ͻ��� Ŭ���� ������ �޴´�
	wn.hIcon=NULL;								//������ ������, NULL������ ����Ʈ������ ������ �������� �������ɷ� �޴´�
	wn.hCursor= LoadCursor(NULL, IDC_ARROW);							//������ ���콺 Ŀ��, �����ܰ� ����
	wn.hbrBackground=(HBRUSH)(COLOR_WINDOW+1);	//������ ����																		//������, Ŀ��, ��� ���� ���μ��� ���忡���� ���� �ϳ��ϳ�
	wn.lpszMenuName=NULL;																											//������� ���⿡ �ڵ��� �ʿ��ϴ�.
	wn.lpszClassName=WindowClass;				//������ Ŭ���� �̸�

	g_hInstance = hInstance;					//�����쿡 �ο��� �ν��Ͻ��� �������� �ΰ� ����� Ŭ�����鿡�� �̿�

	if (!RegisterClassEx(&wn))					//RegisterClassEx�Լ��� ���� ������ ������ ����ü�� ����ϴ� �Լ��̴�
	{
		return false;
	}
	Winrt = { 0,0,1280,720 };					//����������� ���� Ŭ���̾�Ʈ ũ�⸦ �����ϴ� RECT�̴�, �ٸ� ���� ������ ��ü�� ũ�⸦ �Է��ѻ��¶� �̴�� �Է½� Ŭ���̾�Ʈȭ���� ���������� �۰Եȴ�.
	AdjustWindowRect(&Winrt, WS_OVERLAPPEDWINDOW, FALSE);		//Winrt�� ������ �޾� �� ũ�⸦ ������ ��Ÿ�ϰ� �޴� ���η� �Ǵ��ϰ� Ŭ���̾�Ʈ ������ Winrt�� ���ϴ� ��ŭ ������ֱ����� �۾����ִ� �Լ�
	C_hwnd = CreateWindowExW(WS_EX_APPWINDOW, WindowClass, WindowName, WS_OVERLAPPEDWINDOW, 0, 0,
		Winrt.right - Winrt.left, Winrt.bottom - Winrt.top, NULL, NULL, hInstance, NULL);				//�۾��� Winrt�� ũ�� ������ �ް� �����츦 �����Ͽ� �ڵ鿡 �Է�
	GetClientRect(C_hwnd, &Winrt);																		//������ �������� ũ�⸦ �ڵ��� ���� Winrt�� �Է¹޴´�.
	g_hwnd = C_hwnd;																					//������ ������ �ڵ��� �ٸ� Ŭ������ �Բ� �������� �������� �޴���
	ShowWindow(C_hwnd, SW_SHOW);																		//������� �����Ǿ��ٰ� �ƴϱ⿡ �����츦 ȣ���ؼ� ȭ�鿡 ���� �Լ�.
	return true;
}

CBYWindow::CBYWindow()
{
	g_CBYWindow = this;																					//�����쿡 ����� �̺�Ʈ�� �����ϰ� �޼����� ó���ϱ� ���� WndProc�Լ��� ���̴µ�
																										//�� ���̺귯���� �پ��Ѱ����� �������� WndProc�� �����Լ��� ����Ͽ� ������������
																										//���� ������ �ϳ� �����Ͽ� �� Ŭ������ ����Ű�� �ϰ� ��� �����Լ��� �ҷ�����
																										//�޼��� ó���� ���ϴ� ������� ó���� �� �ְ� ���´�.
}


CBYWindow::~CBYWindow()
{
}
