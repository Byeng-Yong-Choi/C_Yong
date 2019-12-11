#pragma once
#include "C_Monster.h"

class C_Move :public C_MonsterStateProcess
{
public:
	int root;

public:
	void Process();

public:
	C_Move(C_Monster* host);
	~C_Move();
};

