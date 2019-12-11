#include "pch.h"
#include <iostream>
#include "C_Protocol.h"
#include <tchar.h>
#include <list>

#define MAX_BUFFER_SIZE 256
std::list<USERPAKET> g_Packet_List;
HANDLE   g_hMutex;

int SendMSG(SOCKET sock);
int AddPaket(SOCKET sock);
void RecvMSG();



bool Error()
{
	if (WSAGetLastError() != WSAEWOULDBLOCK)	//이러할때는 접속자가 없을뿐 오류가 있는게 아니다
	{
		return true;
	}
	return false;
}

DWORD WINAPI SendThread(LPVOID arg)
{
	SOCKET sock = (SOCKET)arg;
	while (1)
	{
		if (SendMSG(sock) < 0)
		{

		}
	}
	closesocket(sock);
	return 0;
}

int main()
{
	std::cout.sync_with_stdio(true);

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
		if (AddPaket(sock) == 0)
		{
			break;
		}
		else
		{
			RecvMSG();
		}
	}

	closesocket(sock);
	CloseHandle(g_hMutex);
	WSACleanup();
}

int SendMSG(SOCKET sock)
{
	g_hMutex = CreateMutex(NULL, FALSE,
		L"CHATSERVER");
	char buffer[256] = { 0, };
	ZeroMemory(buffer, 256);
	fgets(buffer, 256, stdin);
	if (buffer[0] == '\n')
	{
		return -1;
	}
	int iLength = strlen(buffer);
	if (iLength == 0)
	{
		return -1;
	}

	USERPAKET packet;
	ZeroMemory(&packet, sizeof(USERPAKET));
	packet.ph.len = PACKET_HEADER_SIZE + iLength;
	packet.ph.type = PACKET_CHAT_MSG;
	memcpy(packet.data, buffer, iLength);
	char* pSendBuffer = (char*)&packet;
	int iSendByte = send(sock, (char*)&packet, packet.ph.len, 0);
	while (iSendByte < packet.ph.len)
	{
		pSendBuffer += iSendByte;
		iSendByte += send(sock,
			pSendBuffer,
			packet.ph.len - iSendByte, 0);
	}
	return 0;

}

int AddPaket(SOCKET sock)
{
	char m_userbuf[PACKET_MAX_SIZE];
	char* m_pWirtepos;
	int m_iWirtenum;
	int m_iReadnum;
	USERPAKET* m_pRecvPacket = { 0, };
	ZeroMemory(&m_userbuf, PACKET_MAX_SIZE);
	m_iWirtenum = 0;
	m_iReadnum = 0;
	m_pWirtepos = m_userbuf;

	while (m_iWirtenum < PACKET_HEADER_SIZE)
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

	while (m_iWirtenum != m_pRecvPacket->ph.len)
	{
		m_iWirtenum += recv(sock, m_pWirtepos, m_pRecvPacket->ph.len - PACKET_HEADER_SIZE, 0);
		m_pWirtepos += m_iWirtenum;
	}

	USERPAKET packet;
	WaitForSingleObject(g_hMutex, INFINITE);
	memcpy(&packet, m_pRecvPacket, sizeof(USERPAKET)); g_Packet_List.push_back(packet);
	ReleaseMutex(g_hMutex);
	
	return 1;
}

void RecvMSG()
{
	std::list<USERPAKET>::iterator data;

	for (data = g_Packet_List.begin(); data != g_Packet_List.end();data++)
	{
		std::cout << "상대방 : "<<data->data << std::endl;
	}
	WaitForSingleObject(g_hMutex, INFINITE);
	g_Packet_List.clear();
	ReleaseMutex(g_hMutex);
}
