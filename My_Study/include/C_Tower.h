#pragma once
#include "C_TowerState.h"
#include "Monster.h"

class C_Tower;

class C_TowerStateProcess
{
protected:
	C_Tower* m_pTower;

public:
	virtual void Process(C_Object* obj) {};

public:
	C_TowerStateProcess(C_Tower* host) : m_pTower(host)
	{
	};
	~C_TowerStateProcess() {};

};

class C_Tower : public Monster
{
public:
	DWORD TowerState;
	C_TowerStateProcess* m_Action;
	C_TowerStateProcess* m_ActionList[STATE_TOWERCOUNT];

public:
	bool Init() override;
	bool Frame() override;
	bool Render() override;
	void Process(C_Object* obj);
	void SetAction(DWORD Event);

public:
	C_Tower();
	~C_Tower();
};

