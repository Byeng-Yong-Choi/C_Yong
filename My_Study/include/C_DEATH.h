#pragma once
#include "C_Monster.h"

class C_DEATH :public C_MonsterStateProcess
{
public:
	void Process();

public:
	C_DEATH(C_Monster* host);
	~C_DEATH();
};

