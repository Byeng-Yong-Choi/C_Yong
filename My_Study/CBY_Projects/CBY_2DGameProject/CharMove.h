#pragma once
#include "Gokussgss.h"
#include "EnemyPrcess.h"

class CharMove
{
public:
	D3DXVECTOR3 HeroMove;				//이동 거리
	D3DXVECTOR3 EnemyMove;				//AI의 이동

public:
	bool CharCol();
	static D3DXVECTOR3 move(std::shared_ptr<Gokussgss> Hero, std::shared_ptr<Gokussgss> Enmey);

public:
	CharMove();
	~CharMove();
};

