#include "C_Clientsrc.h"

bool C_Clientsrc::Init()
{
	if (!Connect(10005, "192.168.0.49"))	//������
	//if (!Connect(10000, "192.168.0.111"))		//������ ����
	{
		return false;
	}
	return true;
}

void C_Clientsrc::RecvMsg(USERPAKET& pk)
{
	std::cout << "���� : " << pk.data << std::endl;
}

bool C_Clientsrc::SelectRun()
{
	FD_ZERO(&rSet);
	FD_ZERO(&wSet);

	FD_SET(m_Socket, &rSet);
	//FD_SET(m_Socket, &wSet);
	//if (C_Network::m_SendPool.size() != 0)		//��Ŷ ���� �ְ������
	if (C_Network::m_ssSendPool.size() != 0)		//��Ʈ�� �̿�
	{
		FD_SET(m_Socket, &wSet);
	}

	timeval time;
	time.tv_sec = 0;
	time.tv_usec = 1;
  	int iRet = select(0, &rSet, &wSet, NULL, &time);
	if (iRet == 0)		//Ÿ�Ӿƿ��� ���
	{
		return true;
	}

	if (FD_ISSET(m_Socket, &rSet))
	{
		if (m_Packet.AddPaket(m_Socket) > 0)
		{
			PacketProcess();
		}
	}

	if (FD_ISSET(m_Socket, &wSet))
	{
		{
			C_Lock Lock(&m_Lock);
		//for (auto& packet : C_Network::m_SendPool)	//��Ŷ�� ���� ������
			for (auto& sspacket : C_Network::m_ssSendPool)	//��Ʈ���� �̿��� ��Ŷ �ְ�ޱ� ����
			{
				C_Network::SendMSG(m_Socket, sspacket);
			}

		
			//C_Network::m_SendPool.clear();		//��Ŷ �����̿��
			C_Network::m_ssSendPool.clear();			//��Ʈ�� �̿�
		}
	}

	return true;
}

bool C_Clientsrc::Run()
{
	while (1)
	{
		SelectRun();
	}
	return true;
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
		{
			C_Lock Lock(&m_Lock);
			PushSendPool(buf, strlen(buf) - 1);
		}
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
