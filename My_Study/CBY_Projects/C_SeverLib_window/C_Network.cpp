#include "C_Network.h"

std::list<USERPAKET> C_Network::m_RecvPool;
std::list<USERPAKET> C_Network::m_SendPool;
std::list<std::string> C_Network::m_ssSendPool;
std::stringstream C_Network::SStr;
std::map<int, Fuction> C_Network::m_fPacketFun;

bool C_Network::Run()
{
	
	return true;
}

int C_Network::PushSendPool(const char* buf, int iLength)
{
	if (iLength == 0)
	{
		return -1;
	}
	USERPAKET packet;
	ZeroMemory(&packet, sizeof(USERPAKET));
	packet.ph.len = PACKET_HEADER_SIZE + iLength;
	packet.ph.type = PACKET_CHAT_MSG;
	memcpy(packet.data, buf, iLength);
	
	SStr << packet;
	//C_Network::m_SendPool.push_back(packet);		//��Ŷ ��ü �ְ�ޱ�
	C_Network::m_ssSendPool.push_back(SStr.str());	//sstream�� �̿��� �ְ�ޱ�
	return 0;
}

int C_Network::SendMSG(SOCKET sock, const char* buf, int iLength)
{
	if (iLength == 0)
	{
		return -1;
	}
	USERPAKET packet;
	ZeroMemory(&packet, sizeof(USERPAKET));
	packet.ph.len = PACKET_HEADER_SIZE + iLength;
	packet.ph.type = PACKET_CHAT_MSG;
	memcpy(packet.data, buf, iLength);
	char* pSendBuffer = (char*)&packet;
	int iSendByte = send(sock, (char*)&packet, packet.ph.len, 0);
	while (iSendByte < packet.ph.len)
	{
		pSendBuffer += iSendByte;
		iSendByte += send(sock,pSendBuffer,packet.ph.len - iSendByte, 0);
	}

	return 0;
}

int C_Network::SendMSG(SOCKET sock, USERPAKET& data)
{

	char* pSendBuffer = (char*)&data;
	int iSendByte = send(sock, (char*)&data, data.ph.len, 0);
	while (iSendByte < data.ph.len)
	{
		pSendBuffer += iSendByte;
		iSendByte += send(sock, pSendBuffer, data.ph.len - iSendByte, 0);
	}
	return 0;
	/*int DataSize = data.ph.len - PACKET_HEADER_SIZE;
	char msgbuf[PACKET_MAX_SIZE];
	ZeroMemory(msgbuf, PACKET_MAX_SIZE);
	int iSendByte = 0;
	memcpy(msgbuf, data.data, DataSize);
	while (iSendByte < PACKET_HEADER_SIZE)
	{
		iSendByte += send(sock, (char*)&data + iSendByte, PACKET_HEADER_SIZE - iSendByte, 0);

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
		iSendByte += send(sock, msgbuf + iSendByte, DataSize - iSendByte, 0);
	}

	return 0;*/
}

int C_Network::SendMSG(SOCKET sock, std::string& data)
{
	SStr.str(data);
	USERPAKET pack;
	SStr >> pack;
	char* pSendBuffer = (char*)&pack;
	int iSendByte = send(sock, (char*)&pack, pack.ph.len, 0);
	while (iSendByte < pack.ph.len)
	{
		pSendBuffer += iSendByte;
		iSendByte += send(sock, pSendBuffer, pack.ph.len - iSendByte, 0);
	}
	return 0;
}

bool C_Network::Error()
{
	if (WSAGetLastError() != WSAEWOULDBLOCK)	//�̷��Ҷ��� �����ڰ� ������ ������ �ִ°� �ƴϴ�
	{
		return true;
	}
	return false;
}

bool C_Network::Init()
{
	//���� �ʱ�ȭ �۾�
	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 2), &wsa);
	return true;
}

bool C_Network::Release()
{
	closesocket(m_Socket);
	return true;
}

bool C_Network::CreateSock(int iSockType, unsigned long lMode)
{
	//���� ����
	m_Socket = socket(AF_INET, iSockType, 0);			// TCP/IP�� ���� �̿� 0�ڸ��� IPPROTO_TCP�� �ʿ��ϳ� STREAM�� ¦�̶� 0�� �ᵵ ����
																	//SOCK_DGRAM�� IPPROTO_UDP�� �Բ� ¦�̴�
	// �ͺ��ŷ ���� ��ȯ
	u_long on = lMode;
	ioctlsocket(m_Socket, FIONBIO, &lMode);
	std::cout.sync_with_stdio(true);
	return true;
}

bool C_Network::RunThread()
{
	return true;
}



C_Network::C_Network()
{
	Init();
}


C_Network::~C_Network()
{
	Release();
}

void C_Network::PacketProcess()
{
	std::list<USERPAKET>::iterator data;
	for (data = m_RecvPool.begin(); data != m_RecvPool.end(); data++)
	{
		USERPAKET* packet = (USERPAKET*)&(*data);
		f_iter calliter = m_fPacketFun.find(packet->ph.type);
		if (calliter != m_fPacketFun.end())
		{
			Fuction call = calliter->second;
			call(*packet);
		}
	}
	C_Network::m_RecvPool.clear();
}