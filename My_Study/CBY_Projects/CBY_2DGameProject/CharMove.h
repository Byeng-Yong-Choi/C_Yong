#pragma once
#include "Gokussgss.h"
#include "EnemyPrcess.h"

class CharMove
{
public:
	D3DXVECTOR3 HeroMove;				//�̵� �Ÿ�
	D3DXVECTOR3 EnemyMove;				//AI�� �̵�

public:
	bool CharCol();
	static D3DXVECTOR3 move(std::shared_ptr<Gokussgss> Hero, std::shared_ptr<Gokussgss> Enmey);

public:
	CharMove();
	~CharMove();
};

