#pragma once
#include "C_Client.h"

class C_Clientsrc: public C_Client
{
public:
	void SetFunction();
	bool RunThread() override;

public:
	static void RecvMsg(USERPAKET& pk);

public:
	C_Clientsrc();
	~C_Clientsrc();
};

