#pragma once
#include "Gokussgss.h"
#include "EnemyFSM.h"

class Enemy;

class EnemyPrcess
{
protected:
	Enemy* m_pEnemy;

public:
	virtual void Process(std::shared_ptr<Gokussgss>& obj) {};
	float StateTime;

public:
	EnemyPrcess(Enemy* host) : m_pEnemy(host)
	{
		StateTime = 0.0f;
	};
	~EnemyPrcess() {};

};


class Enemy : public Gokussgss
{
public:
	DWORD EnemyrState;
	EnemyPrcess* m_Action;
	EnemyPrcess* m_ActionList[STATE_NUM];
	int StateValue;


public:
	void Process(std::shared_ptr<Gokussgss>& obj);
	void SetAction(DWORD Event);
	bool Init();
	bool Frame();
	bool Render();
	bool Release();
	void VertexData();
	void skillvertex(int i);
	

public:
	Enemy();
	~Enemy();
};


