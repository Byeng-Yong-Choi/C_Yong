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
		MessageBox(NULL, L"이미 실행중입니다.",
			L"중복실행", MB_OK);
		return 1;
	}
	C_Server m_Sever;
	m_Sever.Connect(10005,nullptr);


	//클라이언트와 서버의 데이터 주고받기
	SOCKET ClientSocket;
	SOCKADDR_IN ClientAddr;
	int addlen = sizeof(ClientAddr);

	DWORD dwRvThreadID;
	HANDLE hRvThread = CreateThread(0, 0, RecvThread, &m_src, 0, &dwRvThreadID);		//RecvThread는 생성된 스레드가 일을하게될 함수이고, sock소켓관련 생성
																							//그다음 0은 바로 실행된다는 의미이고 마지막 인자는 스레드 아이디이다.
	DWORD dwSeThreadID;
	HANDLE hSeThread = CreateThread(0, 0, SendThread, &m_src, 0, &dwSeThreadID);		// 위와 같고 Send스레드이다.

	
	while (1)
	{
		ClientSocket = accept(m_Sever.m_Socket, (SOCKADDR*)&ClientAddr, &addlen);		//listen이 넌블록으로 만들어져 accept된 소켓도 넌블럭이다.

		if (ClientSocket == SOCKET_ERROR)			//접속자가 없으면 에러로 뜨는데 접속 없거나 에러일때 두 가지이다
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
	}
	

	//소켓 소멸
	CloseHandle(hRvThread);
	CloseHandle(hSeThread);
	CloseHandle(m_src.g_hMutex);
	//윈속 소멸
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
	}
	return 0;
}
