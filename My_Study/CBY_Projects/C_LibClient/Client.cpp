#include "C_Clientsrc.h"
int main()
{
	C_Clientsrc m_Client;
	m_Client.Init();
	m_Client.CreateThread();
	m_Client.SetFunction();

	m_Client.Run();
	
	return 0;
}
