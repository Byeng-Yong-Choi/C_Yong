#pragma once
#include "EnemyPrcess.h"

class C_EnemyStandby :public EnemyPrcess
{
public:
	void Process(std::shared_ptr<Gokussgss>& obj);

public:
	C_EnemyStandby(Enemy* host);
	~C_EnemyStandby();
};

