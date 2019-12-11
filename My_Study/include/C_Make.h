#pragma once
#include "C_Monster.h"

class C_Make :public C_MonsterStateProcess
{
public:
	void Process();

public:
	C_Make(C_Monster* host);
	~C_Make();
};

