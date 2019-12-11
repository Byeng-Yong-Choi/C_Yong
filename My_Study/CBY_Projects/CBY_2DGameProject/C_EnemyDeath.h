#pragma once
#include "EnemyPrcess.h"

class C_EnemyDeath :public EnemyPrcess
{
public:
	void Process(std::shared_ptr<Gokussgss>& obj);

public:
	C_EnemyDeath(Enemy* host);
	~C_EnemyDeath();
};

