#pragma once
#include "C_Tower.h"

class C_Null :public C_TowerStateProcess
{
public:
	void Process(C_Object* obj);

public:
	C_Null(C_Tower* host);
	~C_Null();
};

