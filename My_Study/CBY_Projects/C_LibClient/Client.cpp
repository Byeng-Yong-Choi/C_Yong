#include "C_Clientsrc.h"
int main()
{
	C_Clientsrc m_Client;
	if (!m_Client.Connect(10005, "192.168.0.49"))
	{
		return 0;
	}
	m_Client.CreateThread();
	m_Client.SetFunction();

	while (1)
	{
		m_Client.Run();
	}
	return 0;
}
