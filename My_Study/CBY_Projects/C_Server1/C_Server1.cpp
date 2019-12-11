//논블럭 윈속으로 만든 서버


#include "pch.h"
#include <iostream>
#include <winsock2.h>
#include <list>
#pragma comment(lib, "ws2_32.lib")
std::list<SOCKET> User_List;

bool Error();
void addUserList(SOCKET ClientSocket);
bool Recv();
bool Send();


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
	u_long on = TRUE;
	ioctlsocket(ListenSocket, FIONBIO, &on);
	//서버 접속시 알림(전화의 경우 진동, 알림음과 같다)
	listen(ListenSocket, SOMAXCONN);

	//클라이언트와 서버의 데이터 주고받기
	SOCKET ClientSocket;
	SOCKADDR_IN ClientAddr;
	int addlen = sizeof(ClientAddr);

	while (1)
	{
		ClientSocket = accept(ListenSocket, (SOCKADDR*)&ClientAddr, &addlen);		//listen이 넌블록으로 만들어져 accept된 소켓도 넌블럭이다.

		if (ClientSocket == SOCKET_ERROR)			//접속자가 없으면 에러로 뜨는데 접속 없거나 에러일때 두 가지이다
		{
			if (Error())
			{
				break;
			}
		}
		else
		{
			addUserList(ClientSocket);
			std::cout << "접속 IP = " << inet_ntoa(ClientAddr.sin_addr) << ", " << "Port = " << ntohs(ClientAddr.sin_port) << std::endl;
		}

		Recv();
	}

	//소켓 소멸
	closesocket(ListenSocket);
	//윈속 소멸
	WSACleanup();
}


bool Error()
{
	if (WSAGetLastError() != WSAEWOULDBLOCK)	//이러할때는 접속자가 없을뿐 오류가 있는게 아니다
	{
		return true;
	}
	return false;
}

void addUserList(SOCKET ClientSocket)
{
	User_List.push_back(ClientSocket);
}

bool Recv()
{
	if (User_List.size()<0)
	{
		return false;
	}

	std::list<SOCKET>::iterator iter;
	for (iter = User_List.begin(); iter != User_List.end();)
	{
		SOCKET sock = *iter;
		char recvbuf[255] = { 0, };
		int iRecvByte = recv(sock, recvbuf, sizeof(recvbuf), 0);

		if (iRecvByte == SOCKET_ERROR)
		{
			if (Error())	//이러할때는 접속자가 없을뿐 오류가 있는게 아니다
			{
				std::cout << "상대방이 나갔습니다." << std::endl;
				closesocket(sock);
				iter = User_List.erase(iter);
				continue;
			}
		}
		else
		{
			std::cout << "User : " << recvbuf << std::endl;
		}

		int iSendByte = send(sock, recvbuf, iRecvByte, 0);

		iter++;
	}
	return true;
}
bool Send()
{
	return true;
}