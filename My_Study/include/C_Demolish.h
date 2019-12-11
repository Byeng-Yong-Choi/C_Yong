#pragma once
#include "C_Tower.h"

class C_Demolish :public C_TowerStateProcess
{
public:
	void Process(C_Object* obj);

public:
	C_Demolish(C_Tower* host);
	~C_Demolish();
};

