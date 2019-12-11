#pragma once
#include "C_Tower.h"

class C_LevelUP :public C_TowerStateProcess
{
public:
	void Process(C_Object* obj);

public:
	C_LevelUP(C_Tower* host);
	~C_LevelUP();
};

