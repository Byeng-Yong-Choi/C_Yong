#include "main.h"

bool main::Init()
{
	m_Client.Init();

	WNDCLASS WndClass;
	GetClassInfo(NULL, TEXT("edit"), &WndClass); // "edit"Ŭ������ ���� ���� ���� 
	WndClass.hInstance = g_hInstance;
	WndClass.style = CS_OWNDC;
	WndClass.lpszClassName = TEXT("SuperEdit"); // ���ο� �̸� ��� 
	WndClass.hCursor = LoadCursor(NULL, IDC_WAIT); // Ŀ�� ���� 
	RegisterClass(&WndClass); // ������ ������ ��� 

	// ������ ��Ʈ��(edit)
	DWORD style = WS_CHILD | WS_VISIBLE | ES_MULTILINE;
	//m_hEdit = CreateWindow(L"edit", NULL,style,
	m_hEdit = CreateWindow(L"SuperEdit", NULL, style,0, 570, 600, 30, g_hwnd,(HMENU)100,NULL, NULL);

	// ������ ��Ʈ��(button)
	style = WS_CHILD | WS_VISIBLE;
	m_hButton = CreateWindow(L"button", L"����",style, 600, 570, 30, 30,g_hwnd,(HMENU)200, NULL, NULL);
	return true;
}

bool main::Frame()
{
	//m_Client.SelectRun();
	return true;
}

bool main::Render()
{
	return true;
}

bool main::Release()
{
	return true;
}

void main::SendMSGClick()
{
	char buffer[MAX_PATH] = { 0 };
	SendMessageA(m_hEdit, WM_GETTEXT, MAX_PATH, (LPARAM)buffer);

	
	C_Network::SendMSG(m_Client.m_Socket,buffer, strlen(buffer));
}

main::main()
{
}


main::~main()
{
}
