//논블럭 스레드를 이용한 서버

#include "pch.h"
#include <iostream>
#include <winsock2.h>
#include <list>
#include <string>
#pragma comment(lib, "ws2_32.lib")

struct USER
{
	SOCKET sock;
	SOCKADDR_IN address;
};

std::list<USER> g_User_List;
std::list<std::string> g_Packet_List;

CRITICAL_SECTION g_UserSync;
CRITICAL_SECTION g_PacketSync;

bool Error();
void addUserList(SOCKET ClientSocket, SOCKADDR_IN Clientaddr);

DWORD WINAPI SendThread(LPVOID arg);
DWORD WINAPI RecvThread(LPVOID arg);
std::list<USER>::iterator ExitUser(SOCKET sock,std::list<USER>::iterator iter);

int main()
{
	//동기화 객체 생성
	InitializeCriticalSection(&g_UserSync);
	InitializeCriticalSection(&g_PacketSync);

	//윈속 초기화 작업
	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 2), &wsa);

	//소켓 생성
	SOCKET ListenSocket = socket(AF_INET, SOCK_STREAM, 0);			// TCP/IP로 소켓 이용 0자리에 IPPROTO_TCP가 필요하나 STREAM과 짝이라 0을 써도 적용
																	//SOCK_DGRAM은 IPPROTO_UDP와 함께 짝이다
	// 넌블록킹 소켓 변환
	u_long on = TRUE;
	ioctlsocket(ListenSocket, FIONBIO, &on);

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

	DWORD dwRvThreadID;
	HANDLE hRvThread = CreateThread(0, 0, RecvThread, 0, 0, &dwRvThreadID);		//RecvThread는 생성된 스레드가 일을하게될 함수이고, sock소켓관련 생성
																							//그다음 0은 바로 실행된다는 의미이고 마지막 인자는 스레드 아이디이다.
	DWORD dwSeThreadID;
	HANDLE hSeThread = CreateThread(0, 0, SendThread, 0, 0, &dwSeThreadID);		// 위와 같고 Send스레드이다.

	while (1)
	{
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
				addUserList(ClientSocket, ClientAddr);
			}
		}
	}

	//소켓 소멸
	closesocket(ListenSocket);
	CloseHandle(hRvThread);
	CloseHandle(hSeThread);
	DeleteCriticalSection(&g_UserSync);
	DeleteCriticalSection(&g_PacketSync);
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

void addUserList(SOCKET ClientSocket, SOCKADDR_IN Clientaddr)
{
	USER user;
	user.sock = ClientSocket;
	user.address = Clientaddr;
	std::cout << "접속 IP = " << inet_ntoa(Clientaddr.sin_addr) << ", " << "Port = " << ntohs(Clientaddr.sin_port) << std::endl;
	
	EnterCriticalSection(&g_UserSync);
	g_User_List.push_back(user);
	LeaveCriticalSection(&g_UserSync);
}

DWORD WINAPI SendThread(LPVOID arg)
{
	std::list<USER>::iterator iter;
	std::list<std::string>::iterator data;

	while (1)
	{
		if (g_Packet_List.size() > 0)
		{
			for (data = g_Packet_List.begin(); data != g_Packet_List.end(); data++)
			{
				for (iter = g_User_List.begin(); iter != g_User_List.end();)
				{
					SOCKET sock = iter->sock;
					int iSendByte = send(sock, data->c_str(), data->size(), 0);
					
					if (iSendByte == SOCKET_ERROR)
					{
						if (Error())	
						{
							iter = ExitUser(sock, iter);
							continue;
						}
					}
					
					iter++;
				}
			}

			EnterCriticalSection(&g_PacketSync);
			g_Packet_List.clear();
			LeaveCriticalSection(&g_PacketSync);
		}
	}
	return 0;
}

DWORD WINAPI RecvThread(LPVOID arg)
{

	std::list<USER>::iterator iter;

	while (1)
	{
		if (g_User_List.size() > 0)
		{
			for (iter = g_User_List.begin(); iter != g_User_List.end();)
			{
				SOCKET sock = iter->sock;
				char recvbuf[255] = { 0, };
				int iRecvByte = recv(sock, recvbuf, sizeof(recvbuf), 0);

				if (iRecvByte == SOCKET_ERROR)
				{
					if (Error())
					{
						iter = ExitUser(sock, iter);
						continue;
					}
				}
				else
				{
					std::cout << "User : " << recvbuf << std::endl;
					EnterCriticalSection(&g_PacketSync);
					g_Packet_List.push_back(recvbuf);
					LeaveCriticalSection(&g_PacketSync);
				}
				iter++;
			}
		}
	}
	return 0;
}

std::list<USER>::iterator ExitUser(SOCKET sock, std::list<USER>::iterator iter)
{
	std::list<USER>::iterator reiter;
	SOCKET Sock = sock;
	SOCKADDR_IN ClientAddr = iter->address;
	EnterCriticalSection(&g_UserSync);
	std::cout << "\n상대방이 나갔습니다." << std::endl;
	std::cout << "나간 IP = " << inet_ntoa(ClientAddr.sin_addr) << ", " << "Port = " << ntohs(ClientAddr.sin_port) << std::endl;
	closesocket(Sock);
	reiter = g_User_List.erase(iter);
	LeaveCriticalSection(&g_UserSync);

	return reiter;
}