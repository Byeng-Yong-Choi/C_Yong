#pragma once
#include "Weapon.h"
class TowerWeapon: public Weapon
{
public:
	int WeaponSpeed;
	fPOINT monpt;
	int monsternum;
	//bool WeaponGO;
	bool Buu;
	bool Cold;
	float Ditance;			//���Ϳ��� �Ÿ���ŭ ����Ʈ ���
	int splitenum;
	float WeaponShowTime;
	float mondgr;
	int Power;


public:
	bool Frame();
	bool Render();
	void GetMonsterPosition(fPOINT mon);
	void GetMonsterNum(int i);

public:
	TowerWeapon();
	~TowerWeapon();
};

