#pragma once
#include "C_Tower.h"

class C_TowerStandBy :public C_TowerStateProcess
{
public:
	void Process(C_Object* obj);

public:
	C_TowerStandBy(C_Tower* host);
	~C_TowerStandBy();
};

