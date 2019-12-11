#pragma once
#include "Cstd.h"

class CBYWindow
{
public:
	WNDCLASSEX wn;
	HWND C_hwnd;
	HINSTANCE hInstance;

public:
	bool InitWindow(const TCHAR* WindowClass, const TCHAR* WindowName);
	


public:
	CBYWindow();
	virtual ~CBYWindow();
};

