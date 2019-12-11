#include "pch.h"
#include <iostream>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

int main()
{
	//윈속 초기화 작업
	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 2), &wsa);

	//소켓 생성
	SOCKET ListenSocket = socket(AF_INET, SOCK_STREAM, 0);			// TCP/IP로 소켓 이용 0자리에 IPPROTO_TCP가 필요하나 STREAM과 짝이라 0을 써도 적용
																	//SOCK_DGRAM은 IPPROTO_UDP와 함께 짝이다
	//BIND작업(전화의 경우 전화번호를 만드는것과 같다)			
	SOCKADDR_IN sa;
	ZeroMemory(&sa, sizeof(SOCKADDR_IN));
	sa.sin_family = AF_INET;
	sa.sin_port = htons(10005);
	sa.sin_addr.s_addr = inet_addr("192.168.0.49");
	bind(ListenSocket, (SOCKADDR*)&sa, sizeof(sa));

	//서버 접속시 알림(전화의 경우 진동, 알림음과 같다)
	listen(ListenSocket, SOMAXCONN);

	//클라이언트와 서버의 데이터 주고받기
	SOCKET ClientSocket;
	SOCKADDR_IN ClientAddr;
	int addlen = sizeof(ClientAddr);

	while (1)
	{
		ClientSocket = accept(ListenSocket, (SOCKADDR*)&ClientAddr, &addlen);

		std::cout << "접속 IP = " << inet_ntoa(ClientAddr.sin_addr)<<", "<< "Port = " << ntohs(ClientAddr.sin_port) << std::endl;

		while (1)
		{
			char recvbuf[255] = { 0, };
			int iRecvByte = recv(ClientSocket, recvbuf, sizeof(recvbuf), 0);
			if (iRecvByte <= 0)
			{
				std::cout << "상대방이 나갔습니다." << std::endl;
				std::cout << "나간 IP = " << inet_ntoa(ClientAddr.sin_addr) << ", " << "Port = " << ntohs(ClientAddr.sin_port) << std::endl;
				closesocket(ClientSocket);
				break;
			}
			std::cout << "User : " << recvbuf << std::endl;

			char sendbuf[255] = { 0, };
			std::cout << "Sever : ";
			std::cin >> sendbuf;
			int iSendByte = send(ClientSocket, sendbuf, sizeof(sendbuf), 0);
			if (iSendByte <= 0)
			{
				break;
			}
		}
	}

	//소켓 소멸
	closesocket(ListenSocket);
	//윈속 소멸
	WSACleanup();
}