#pragma once
#include "C_Monster.h"

class C_Damage:public C_MonsterStateProcess
{
public:
	void Process();

public:
	C_Damage(C_Monster* host);
	~C_Damage();
};

