#include "C_Seversrc.h"
DWORD WINAPI SendThread(LPVOID arg);
DWORD WINAPI RecvThread(LPVOID arg);

int main()
{
	C_Seversrc m_src;
	m_src.g_hMutex = CreateMutex(NULL, FALSE,
		L"CHATSERVER");
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		CloseHandle(m_src.g_hMutex);
		MessageBox(NULL, L"�̹� �������Դϴ�.",
			L"�ߺ�����", MB_OK);
		return 1;
	}
	m_src.Connect(10005,nullptr);


	//Ŭ���̾�Ʈ�� ������ ������ �ְ�ޱ�
	SOCKET ClientSocket;
	SOCKADDR_IN ClientAddr;
	int addlen = sizeof(ClientAddr);

	DWORD dwRvThreadID;
	HANDLE hRvThread = CreateThread(0, 0, RecvThread, &m_src, 0, &dwRvThreadID);		//RecvThread�� ������ �����尡 �����ϰԵ� �Լ��̰�, sock���ϰ��� ����
																							//�״��� 0�� �ٷ� ����ȴٴ� �ǹ��̰� ������ ���ڴ� ������ ���̵��̴�.
	DWORD dwSeThreadID;
	HANDLE hSeThread = CreateThread(0, 0, SendThread, &m_src, 0, &dwSeThreadID);		// ���� ���� Send�������̴�.

	
	while (1)
	{
		ClientSocket = accept(m_src.m_Socket, (SOCKADDR*)&ClientAddr, &addlen);		//listen�� �ͺ������ ������� accept�� ���ϵ� �ͺ��̴�.

		if (ClientSocket == SOCKET_ERROR)			//�����ڰ� ������ ������ �ߴµ� ���� ���ų� �����϶� �� �����̴�
		{
			if (C_Server::Error())
			{
				break;
			}
		}
		else
		{
			m_src.addUserList(ClientSocket, ClientAddr);
		}

		/*std::cout << "RECV : " << m_src.m_recv << std::endl;
		std::cout << "SEND : " << m_src.m_send << std::endl;
		Sleep(1000);*/
	}
	

	//���� �Ҹ�
	CloseHandle(hRvThread);
	CloseHandle(hSeThread);
	CloseHandle(m_src.g_hMutex);
	//���� �Ҹ�
	WSACleanup();
}



DWORD WINAPI SendThread(LPVOID arg)
{
	C_Seversrc* pServer = (C_Seversrc*)arg;
	while (1)
	{
		{
			C_Lock Lock(pServer);
			pServer->SendProcess();
		}
		//Sleep(1);
	}
	return 0;
}

DWORD WINAPI RecvThread(LPVOID arg)
{
	C_Seversrc* pServer = (C_Seversrc*)arg;
	while (1)
	{
		{
			C_Lock Lock(pServer);
			pServer->RecvProcess();
		}
		//Sleep(1);
	}
	return 0;
}
