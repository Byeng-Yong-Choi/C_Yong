#pragma once
#include "C_Tower.h"

class C_ATTACK:public C_TowerStateProcess
{
public:
	void Process(C_Object* obj);

public:
	C_ATTACK(C_Tower* host);
	~C_ATTACK();
};

