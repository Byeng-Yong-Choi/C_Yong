#pragma once
#include "C_Tower.h"

class C_Create :public C_TowerStateProcess
{
public:
	void Process(C_Object* obj);

public:
	C_Create(C_Tower* host);
	~C_Create();
};

