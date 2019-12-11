#include "C_Clientsrc.h"

void C_Clientsrc::RecvMsg(USERPAKET& pk)
{
	std::cout << "»ó´ë¹æ : " << pk.data << std::endl;
}

bool C_Clientsrc::RunThread()
{
	char buf[256] = { 0, };
	while (1)
	{
		ZeroMemory(buf, 256);
		fgets(buf, 256, stdin);
		if (buf[0] == '\n')
		{
			break;
		}
		C_Client::SendMSG(m_Socket, buf, strlen(buf) - 1);
		Sleep(1);
	}
	closesocket(m_Socket);
	return 0;
}

void C_Clientsrc::SetFunction()
{
	m_fPacketFun[PACKET_CHAT_MSG] = RecvMsg;
}

C_Clientsrc::C_Clientsrc()
{
}


C_Clientsrc::~C_Clientsrc()
{
}
