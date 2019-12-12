#pragma once
#include "C_Server.h"

typedef std::list<C_User>::iterator C_Uiter;

class C_Seversrc:public C_Server
{
public:
	int m_recv;
	int m_send;
	std::list<USERPAKET> g_Packet_List;
	std::list<C_User> g_User_List;
	HANDLE   g_hMutex;
	C_Server m_Net;

public:
	void addUserList(SOCKET ClientSocket, SOCKADDR_IN Clientaddr);
	C_Uiter ExitUser(SOCKET sock, C_Uiter iter);
	void RecvProcess();
	void SendProcess();
public:
	C_Seversrc();
	~C_Seversrc();
};

