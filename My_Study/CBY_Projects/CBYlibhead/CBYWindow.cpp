#include "CBYWindow.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}

bool CBYWindow::InitWindow(const TCHAR* WindowClass,const TCHAR* WindowName)
{
	wn.cbSize=sizeof(WNDCLASSEX);
	wn.style=CS_HREDRAW|CS_VREDRAW;
	wn.lpfnWndProc = WndProc;
	wn.cbClsExtra=0;
	wn.cbWndExtra=0;
	wn.hInstance= hInstance;
	wn.hIcon=NULL;
	wn.hCursor=LoadCursor(NULL,IDC_ARROW);
	wn.hbrBackground=(HBRUSH)(COLOR_WINDOW+1);
	wn.lpszMenuName=NULL;
	wn.lpszClassName=WindowClass;


	if (!RegisterClassEx(&wn))
	{
		return false;
	}
	C_hwnd = CreateWindowExW(WS_EX_APPWINDOW, WindowClass, WindowName, WS_OVERLAPPEDWINDOW, 0, 0, 800, 600, NULL, NULL, hInstance, NULL);

	ShowWindow(C_hwnd, SW_SHOW);
	return true;
}

CBYWindow::CBYWindow()
{
}


CBYWindow::~CBYWindow()
{
}
