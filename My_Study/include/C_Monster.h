#pragma once
#include "Monster.h"
#include "Health.h"
#include "C_MonsterState.h"

class C_Monster;

class C_MonsterStateProcess
{
protected:
	C_Monster* m_pMonster;

public:
	virtual void Process() {};

public:
	C_MonsterStateProcess(C_Monster* host) : m_pMonster(host)
	{
	};
	//C_MonsterStateProcess();
	~C_MonsterStateProcess() {};

};

class C_Monster: public Monster
{
public:
	DWORD MonsterState;
	Health* HPbar;
	C_MonsterStateProcess* m_Action;
	C_MonsterStateProcess* m_ActionList[STATE_COUNT];

public:
	bool Init() override;
	bool Frame() override;
	bool Render() override;
	void Process();
	void SetAction(DWORD Event);

public:
	C_Monster();
	~C_Monster();
};

