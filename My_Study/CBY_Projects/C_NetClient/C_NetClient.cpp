// C_NetClient.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

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

	int iLoop = 3;
	while (iLoop>0)
	{
		char buffer[256] = {0,};
		std::cout << "User : ";
		std::cin >> buffer;
		int iSendByte = send(sock, buffer, strlen(buffer), 0);

		char revbuffer[256] = { 0, };
		int iRecvByte = recv(sock, revbuffer, 256, 0);
		if (iRecvByte == 0)
		{
			break;
		}
		std::cout << "Sever : "<<revbuffer << std::endl;

		Sleep(1000);
		iLoop--;
	}

	closesocket(sock);
	WSACleanup();
}
