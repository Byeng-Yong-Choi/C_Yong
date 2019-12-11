#pragma once
#include "C_Object.h"
#include "TowerCoice.h"
#include "TowerChar.h"
#include "C_Intersection.h"
#include "TowerScope.h"
#include "TowerWeapon.h"
#include "TowerEffect.h"
#include "GameMgr.h"


typedef std::vector<RECT> RTLIST;

class TowerPosition: public C_Object
{
public:
	std::vector<TowerScope> Scope;
	std::vector<TowerCoice> m_Choice;
	std::vector<TowerCoice> m_LVChoice;
	std::vector<TowerChar> m_Tower;
	std::vector<TowerChar> m_LVTower;
	std::vector<TowerWeapon> m_Weapon;
	std::list<TowerWeapon*> m_WeaponList;
	std::list<TowerEffect*> m_EffectList;
	std::vector<RTLIST> m_EffectrtList;
	std::vector<TowerEffect> m_Effect;
	std::vector<RTLIST> m_rtList;
	std::vector<RTLIST> m_WeaponEffectList;
	RECT ChoiceRt;
	RECT TowerWeaponRT;
	fPOINT CenterPT;
	float Ren;							//Ÿ�� �������� ������ ����
	float LvRen;
	bool MakeTower;						//Ÿ�� ���� ����
	int MakeTowerNum;					//������� Ÿ�� ��ȣ
	int TowerNumber;	
	float ClickTime;
	int TowerStateNumber;						//0:�븻, 1:����
	float ScopeScaleSize;
	float WEAPONSPEED;
	bool MakeLvTower;
	int MakeLVTowerNum;
	float BuuAttackTime;


public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();
	void TowerRtsrc();
	void LVTowerRtsrc();
	void TowerChoicert(int i);
	void TowerLVChoicert(int i);
	void ScopeSize(int i);				//���� ���� ����
	void TowerWeaponrt(int i);
	void Weaponspeed(int i);
	void EffectSrc();
	void buueffect();

public:
	bool Click;

public:
	TowerPosition();
	~TowerPosition();
};
