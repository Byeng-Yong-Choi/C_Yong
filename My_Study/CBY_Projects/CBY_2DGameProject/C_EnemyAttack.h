#pragma once
#include "EnemyPrcess.h"

class C_EnemyAttack:public EnemyPrcess
{
public:
	void Process(std::shared_ptr<Gokussgss>& obj);

public:
	C_EnemyAttack(Enemy* host);
	~C_EnemyAttack();
};

