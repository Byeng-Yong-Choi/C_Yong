// client.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// NetClient.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <WinSock2.h>
#include <windows.h>
#include <tchar.h>
#include <conio.h>
#include <ws2tcpip.h> 
#include <process.h>
#include "TProtocol.h"

#pragma comment( lib, "ws2_32.lib")

#define MAX_BUFFER_SIZE 256
void T_ERR_EXIT(const TCHAR *msg)
{
	LPVOID lpMsgBuf;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, WSAGetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(TCHAR*)&lpMsgBuf, 0, NULL);
	MessageBox(NULL, (TCHAR*)lpMsgBuf, msg, MB_ICONERROR);
	LocalFree(lpMsgBuf);
}
int NonBlockingSocket(SOCKET sock, u_long iMode)
{
	// 넌블로킹 소켓으로 만들고
	// controls the I/O mode of a socket.
	int iResult = ioctlsocket(sock, FIONBIO, &iMode);
	if (iResult != NO_ERROR)
	{
		T_ERR_EXIT(_T("ioctlsocket"));
	}
	return iResult;
}
// 접속 시간을 timeout만큼 제한한다.
bool tConnect(SOCKET sock, int timeout)
{
	TIMEVAL Timeout;
	Timeout.tv_sec = timeout;
	Timeout.tv_usec = 0;
	struct sockaddr_in address;
	unsigned long iMode = 1;
	int iResult = ioctlsocket(sock, FIONBIO, &iMode);
	if (iResult != NO_ERROR)
	{
		printf("ioctlsocket failed with error: %ld\n", iResult);
	}

	// 넌블로킹 소켓으로 다시 전환한다.
	iMode = 0;
	iResult = ioctlsocket(sock, FIONBIO, &iMode);
	if (iResult != NO_ERROR)
	{
		printf("ioctlsocket failed with error: %ld\n", iResult);
	}

	fd_set Write, Err;
	FD_ZERO(&Write);
	FD_ZERO(&Err);
	FD_SET(sock, &Write);
	FD_SET(sock, &Err);

	// 넌블로킹 소켓으로 Timeout 만큼 대기한다.
	iResult = select(0, NULL, &Write, &Err, &Timeout);
	if (iResult == 0)
	{
		//timeout
		return true;
	}
	if (FD_ISSET(sock, &Write))
	{
		// Connected!
		return true;
	}
	if (FD_ISSET(sock, &Err))
	{
		// Error
	}
	return false;
}

DWORD WINAPI SendThread(LPVOID arg)
{
	SOCKET sock = (SOCKET)arg;
	char buf[256] = { 0, };
	while (1)
	{
		ZeroMemory(buf, 256);
		fgets(buf, 256, stdin);
		if (buf[0] == '\n')
		{
			break;
		}
		int iLength = strlen(buf);
		if (iLength == 0) break;

		UPACKET packet;
		ZeroMemory(&packet, sizeof(UPACKET));
		packet.ph.len = PACKET_HEAD_SIZE + iLength;
		packet.ph.type = PACKET_CHAT_MSG;
		memcpy(packet.msg, buf, iLength);
		char* pSendBuffer = (char*)&packet;
		int iSendByte = send(sock, (char*)&packet, packet.ph.len, 0);
		while (iSendByte < packet.ph.len)
		{
			pSendBuffer += iSendByte;
			iSendByte += send(sock,
				pSendBuffer,
				packet.ph.len - iSendByte, 0);
		}
	}
	closesocket(sock);
	return 0;
}

void main()
{
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		return;
	}
	SOCKET Sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	SOCKADDR_IN  sa;
	ZeroMemory(&sa, sizeof(sa));
	sa.sin_addr.s_addr = inet_addr("192.168.0.111");
	sa.sin_family = AF_INET;
	sa.sin_port = htons(10000);
	int iRet = connect(Sock, (SOCKADDR*)&sa, sizeof(sa));
	if (iRet == SOCKET_ERROR)
	{
		return;
	}
	DWORD dwThreadID;
	HANDLE hThread = CreateThread(
		0, 0,
		SendThread,
		(void*)Sock,
		0,
		&dwThreadID);


	char buf[MAX_BUFFER_SIZE] = { 0, };
	int iEnd = 0;
	while (1)
	{
		char bufRecv[MAX_BUFFER_SIZE] = { 0, };
		int iRecvByte = recv(Sock, bufRecv, MAX_BUFFER_SIZE - 1, 0);
		if (iRecvByte < 0) break;
		bufRecv[iRecvByte] = 0;
		printf("recv=%s\n", bufRecv);
	}

	closesocket(Sock);
	CloseHandle(hThread);
	WSACleanup();
}