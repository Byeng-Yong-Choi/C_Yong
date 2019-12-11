#pragma once
#include "EnemyPrcess.h"

class C_EnemyPatrol :public EnemyPrcess
{
public:
	void Process(std::shared_ptr<Gokussgss>& obj);

public:
	C_EnemyPatrol(Enemy* host);
	~C_EnemyPatrol();
};

