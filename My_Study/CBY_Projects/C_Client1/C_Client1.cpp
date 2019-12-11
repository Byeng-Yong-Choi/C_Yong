
#include "pch.h"
#include <iostream>
#include <WinSock2.h>
#include <tchar.h>
#pragma comment( lib, "ws2_32.lib")
#define MAX_BUFFER_SIZE 256

DWORD WINAPI SendThread(LPVOID arg)
{
	SOCKET sock = (SOCKET)arg;
	char buffer[256] = { 0, };
	while (1)
	{
		ZeroMemory(buffer, 256);
		//std::cout << "User : ";
		fgets(buffer, 256, stdin);
		if (buffer[0] == '\n')
		{
			break;
		}
		int iLength = strlen(buffer);
		if (iLength == 0) break;
		send(sock, buffer, iLength -1, 0);
	}
	closesocket(sock);
	return 0;
}

int main()
{
	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 2), &wsa);
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN sa;
	ZeroMemory(&sa, sizeof(SOCKADDR_IN));
	sa.sin_family = AF_INET;
	sa.sin_port = htons(10005);
	sa.sin_addr.s_addr = inet_addr("192.168.0.49");

	int iRet = connect(sock, (SOCKADDR*)&sa, sizeof(sa));
	if (iRet == SOCKET_ERROR)
	{
		return 1;
	}
	DWORD dwThreadID;
	HANDLE hThread = CreateThread(0, 0, SendThread, (void*)sock, 0, &dwThreadID);		//SendThread는 생성된 스레드가 일을하게될 함수이고, sock소켓관련 생성
																						//그다음 0은 바로 실행된다는 의미이고 마지막 인자는 스레드 아이디이다.

	char buf[255] = { 0, };
	while (1)
	{
		char Recvbuffer[255] = { 0, };
		int iRecvByte = recv(sock, Recvbuffer, 255, 0);
		if (iRecvByte < 0) break;
		//Recvbuffer[iRecvByte] = 0;
		std::cout << "Server : " << Recvbuffer << std::endl;
	}

	closesocket(sock);
	WSACleanup();
}

