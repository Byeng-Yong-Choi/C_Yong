//논블럭 스레드를 이용한 서버

#include "pch.h"
#include <iostream>
#include "C_Protocol.h"
#include <list>
#include <string>
std::list<USERPAKET> g_Packet_List;
HANDLE   g_hMutex;
bool Error();

struct USER
{
	SOCKET sock;
	SOCKADDR_IN address;
	char m_userbuf[PACKET_MAX_SIZE];
	char* m_pWirtepos;
	int m_iWirtenum;
	int m_iReadnum;
	USERPAKET* m_pRecvPacket;

	USER()
	{
		ZeroMemory(&m_userbuf, PACKET_MAX_SIZE);
		m_iWirtenum = 0;
		m_iReadnum = 0;
		m_pWirtepos = m_userbuf;
	}

	USER(const USER& user)
	{
		sock = user.sock;
		address = user.address;
		ZeroMemory(&m_userbuf, PACKET_MAX_SIZE);
		m_iWirtenum = 0;
		m_iReadnum = 0;
		m_pWirtepos = m_userbuf;
	}

	int AddPaket()
	{
		if (m_iWirtenum < PACKET_HEADER_SIZE)
		{
			int RecvData;
			RecvData = recv(sock, m_pWirtepos, PACKET_HEADER_SIZE - m_iWirtenum, 0);
			if (RecvData == SOCKET_ERROR)
			{
				if (Error())
				{
					return 0;
				}
				else
				{
					return 1;
				}
			}
			m_iWirtenum += RecvData;
			m_pWirtepos += m_iWirtenum;
			if (m_iWirtenum == PACKET_HEADER_SIZE)
			{
				m_pRecvPacket = (USERPAKET*)m_userbuf;
			}
		}
		else
		{
			m_iWirtenum += recv(sock, m_pWirtepos, m_pRecvPacket->ph.len - PACKET_HEADER_SIZE, 0);
			m_pWirtepos += m_iWirtenum;

			if (m_iWirtenum == m_pRecvPacket->ph.len)
			{
				USERPAKET packet;
				memcpy(&packet, m_pRecvPacket, sizeof(USERPAKET));
				g_Packet_List.push_back(packet);
				std::cout << "User : " << m_userbuf + 4 << std::endl;

				ZeroMemory(&m_userbuf, PACKET_MAX_SIZE);
				m_iWirtenum = 0;
				m_iReadnum = 0;
				m_pWirtepos = m_userbuf;
			}
		}
		return 1;
	}

};

std::list<USER> g_User_List;


CRITICAL_SECTION g_UserSync;
CRITICAL_SECTION g_PacketSync;


void addUserList(SOCKET ClientSocket, SOCKADDR_IN Clientaddr);

void RecvProcess();
void SendProcess();
int SendMSG(SOCKET sock, USERPAKET& data);
DWORD WINAPI SendThread(LPVOID arg);
DWORD WINAPI RecvThread(LPVOID arg);
std::list<USER>::iterator ExitUser(SOCKET sock, std::list<USER>::iterator iter);





int main()
{
	g_hMutex = CreateMutex(NULL, FALSE,
		L"CHATSERVER");
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		CloseHandle(g_hMutex);
		MessageBox(NULL, L"이미 실행중입니다.",
			L"중복실행", MB_OK);
		return 1;
	}
	std::cout.sync_with_stdio(true);
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
	CloseHandle(g_hMutex);
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

	WaitForSingleObject(g_hMutex, INFINITE);
	g_User_List.push_back(user);
	ReleaseMutex(g_hMutex);
}

DWORD WINAPI SendThread(LPVOID arg)
{
	while (1)
	{
		WaitForSingleObject(g_hMutex, INFINITE);
		SendProcess();
		ReleaseMutex(g_hMutex);
	}
	return 0;
}

DWORD WINAPI RecvThread(LPVOID arg)
{
	while (1)
	{
		RecvProcess();
	}
	return 0;
}

std::list<USER>::iterator ExitUser(SOCKET sock, std::list<USER>::iterator iter)
{
	std::list<USER>::iterator reiter;
	SOCKET Sock = sock;
	SOCKADDR_IN ClientAddr = iter->address;
	WaitForSingleObject(g_hMutex, INFINITE);
	std::cout << "\n상대방이 나갔습니다." << std::endl;
	std::cout << "나간 IP = " << inet_ntoa(ClientAddr.sin_addr) << ", " << "Port = " << ntohs(ClientAddr.sin_port) << std::endl;
	closesocket(Sock);
	reiter = g_User_List.erase(iter);
	ReleaseMutex(g_hMutex);

	return reiter;
}

void RecvProcess()
{
	std::list<USER>::iterator iter;
	if (g_User_List.size() > 0)
	{
		for (iter = g_User_List.begin(); iter != g_User_List.end();)
		{
			SOCKET sock = iter->sock;
			if (iter->AddPaket()==0)
			{
				iter=ExitUser(sock, iter);
				continue;
			}
			iter++;
		}
	}
}

void SendProcess()
{

	std::list<USER>::iterator iter;
	std::list<USERPAKET>::iterator data;

	if (g_Packet_List.size() > 0)
	{
		for (data = g_Packet_List.begin(); data != g_Packet_List.end(); data++)
		{
			for (iter = g_User_List.begin(); iter != g_User_List.end();iter++)
			{
				SOCKET sock = iter->sock;
				int iSendByte= SendMSG(sock, *data);
			}
		}

		EnterCriticalSection(&g_PacketSync);
		g_Packet_List.clear();
		LeaveCriticalSection(&g_PacketSync);
	}
}

int SendMSG(SOCKET sock, USERPAKET& data)
{
	int DataSize = data.ph.len - PACKET_HEADER_SIZE;
	char msgbuf[PACKET_MAX_SIZE];
	ZeroMemory(msgbuf, PACKET_MAX_SIZE);
	int iSendByte=0;
	memcpy(msgbuf, data.data, DataSize);
	while (iSendByte < PACKET_HEADER_SIZE)
	{
		iSendByte = send(sock, (char*)&data+ iSendByte, PACKET_HEADER_SIZE - iSendByte, 0);

		if (iSendByte == SOCKET_ERROR)
		{
			if (Error())
			{
				return -1;
			}
			return 0;
		}
	}
	iSendByte = 0;

	while (iSendByte < DataSize)
	{	
		iSendByte += send(sock, msgbuf+ iSendByte, DataSize- iSendByte, 0);
	}

	return 0;
}