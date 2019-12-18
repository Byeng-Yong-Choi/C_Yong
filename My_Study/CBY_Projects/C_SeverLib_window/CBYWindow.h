#pragma once
#include "C_NetStd.h"

class CBYWindow
{
public:
	WNDCLASSEX wn;				//������ Ŭ���� Ȯ������� �̿��� ����
	HWND C_hwnd;				//������ �������� �ڵ�(���� �Ѱ��� �����츸 �̿��ϹǷ� ��ü���� ���� �Ѱ��� �ڵ鸸 ����)
	HINSTANCE hInstance;		//�����쿡 ���� �ν��Ͻ� �������� �����ѹ�

public:
	bool InitWindow(const TCHAR* WindowClass, const TCHAR* WindowName);
	virtual bool ResizeDevice(UINT width,UINT height);
	virtual LRESULT WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	virtual void SendMSGClick();
	


public:
	CBYWindow();
	virtual ~CBYWindow();
};

