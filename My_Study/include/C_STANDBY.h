#pragma once
#include "C_Monster.h"

class C_STANDBY :public C_MonsterStateProcess
{
public:
	void Process();

public:
	C_STANDBY(C_Monster* host);
	~C_STANDBY();
};

