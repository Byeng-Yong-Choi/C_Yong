#include "C_Seversrc.h"

void C_Seversrc::addUserList(SOCKET ClientSocket, SOCKADDR_IN Clientaddr)
{
	C_User user;
	user.sock = ClientSocket;
	user.address = Clientaddr;
	std::cout << "접속 IP = " << inet_ntoa(Clientaddr.sin_addr) << ", " << "Port = " << ntohs(Clientaddr.sin_port) << std::endl;

	WaitForSingleObject(g_hMutex, INFINITE);
	g_User_List.push_back(user);
	ReleaseMutex(g_hMutex);
}

C_Uiter C_Seversrc::ExitUser(SOCKET sock, C_Uiter iter)
{
	C_Uiter reiter;
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

void C_Seversrc::RecvProcess()
{
	C_Uiter iter;
	if (g_User_List.size() > 0)
	{
		for (iter = g_User_List.begin(); iter != g_User_List.end();)
		{
			SOCKET sock = iter->sock;
			if (iter->AddPaket(sock) < 0)
			{
				iter = ExitUser(sock, iter);
				continue;
			}
			iter++;
		}
	}
}

void C_Seversrc::SendProcess()
{
	C_Uiter iter;
	std::list<USERPAKET>::iterator data;

	for (data = C_Server::m_RecvPool.begin(); data != C_Server::m_RecvPool.end(); data++)
	{
		for (iter = g_User_List.begin(); iter != g_User_List.end(); iter++)
		{
			SOCKET sock = iter->sock;
			int iSendByte = C_Server::SendMSG(sock, *data);
			std::cout << "보냄 : " << data->data << std::endl;
		}
		//std::cout << "보냄 : "<<data->data << std::endl;
	}
	C_Server::m_RecvPool.clear();
}

C_Seversrc::C_Seversrc()
{
}


C_Seversrc::~C_Seversrc()
{
}
