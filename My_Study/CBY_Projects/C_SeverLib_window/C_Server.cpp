#include "C_Server.h"

bool C_Server::Connect(int iPort, const char* ip, int iSockType, int iMode)
{
	if (!CreateSock(iSockType, iMode))
	{
		return false;
	}

	//BIND�۾�(��ȭ�� ��� ��ȭ��ȣ�� ����°Ͱ� ����)			
	SOCKADDR_IN sa;
	ZeroMemory(&sa, sizeof(SOCKADDR_IN));
	sa.sin_family = AF_INET;
	sa.sin_port = htons(iPort);
	if (ip == nullptr)
	{
		sa.sin_addr.s_addr = htonl(INADDR_ANY);
	}
	else
	{
		inet_pton(AF_INET, ip, &sa.sin_addr);
		//sa.sin_addr.s_addr = inet_addr(ip);
	}
	bind(m_Socket, (SOCKADDR*)&sa, sizeof(sa));
	//���� ���ӽ� �˸�(��ȭ�� ��� ����, �˸����� ����)
	listen(m_Socket, SOMAXCONN);

	if (ip != nullptr)
	{
		m_szAddress = ip;
	}
	m_iPort = iPort;
	m_bConnect = true;

	return true;
}

C_Server::C_Server()
{
	Init();
}


C_Server::~C_Server()
{
}
