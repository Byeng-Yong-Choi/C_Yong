#pragma once
#include "C_Actor.h"

enum charstate
{
	STATE_NOMAL = 0,
	STATE_ATTACKER
};

class TowerChar:public C_Actor
{
public:
	int splitenum;
	float CharTime;
	float CharShowTime;
	bool WeaponGo;				//Ÿ�� ����� ����ü �߻�
	int state;					//Ÿ�� ����
	bool LevelUP;				//Ÿ�� ������ ����
	int power;					//Ÿ�� ���ݷ�
	int price;					//Ÿ�� ����
	fSphere charfsp;

public:
	bool Init() override;
	bool Frame() override;
	bool Render() override;
	bool Release() override;
	bool GetRECT(vector<RECT>& rtList, float showtime);
	void GetSphere(float x, float y, float i);

public:
	TowerChar();
	~TowerChar();
};

