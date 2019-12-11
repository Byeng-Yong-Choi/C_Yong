#pragma once
#include "CBYCore.h"
#include "Town.h"
#include "CharMove.h"
#include "GameTime.h"
#include "HP.h"


class GameMain:public CBYCore
{
public:
	std::shared_ptr<Town> m_Map;
	std::shared_ptr<Gokussgss> m_Hero;
	std::shared_ptr<Enemy> m_Enemy;
	std::shared_ptr<GameTime> m_Time;
	std::vector<std::shared_ptr<HP>> m_HpList;
	//D3DXVECTOR3 m_pos;
	//bool zoom;
	D3DXVECTOR3 Heropos;		
	D3DXVECTOR3 Enemypos;
	bool ShowTimebool;
	D3DXMATRIX matWorld;
	D3DXMATRIX matMon;
	D3DXMATRIX EnemyWorld,HPWorld;
	float jump;
	bool Hight;
	float DoubleClickTime;	//����Ŭ�� üũŸ��
	bool DoubleClick;		//����Ŭ�� ����

public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();
	HRESULT CreateDXrc();		//��������� DX�ҽ��� ������ ����
	HRESULT	DeleteDXrc();		//��������� DX�ҽ� ������ ���� ����

public:
	GameMain();
	~GameMain();
};

CBY_RUN(GameMain, C_DX, CBY_DX);