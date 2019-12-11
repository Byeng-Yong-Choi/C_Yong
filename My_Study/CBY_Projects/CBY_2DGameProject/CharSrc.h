#pragma once
#include "CSprite.h"
#include "CBY_Input.h"
#include "CharMgr.h"

enum					//캐릭터의 상태
{
	STATE_START=0,
	STATE_NOMAL,
	STATE_MOVE,
	STATE_SIT,
	STATE_JUMP,
	STATE_DASH,
	STATE_PUNCH0,
	STATE_PUNCH0_COMBO,
	STATE_KICK,
	STATE_KICK_COMBO,
	STATE_HERODAMAGE,
	STATE_SKILL,
	STATE_HERODEATH,
	STATE_COUNT
};

class CharSrc
{
protected:
	float m_Jump;					//캐릭터의 점프력
	float m_Jumptime;				//캐릭터의 점프시간
	float m_Gravity;				//중력가속도
	float m_Jumpfpos;				//점프시 첫 위치
	float m_DamageTime;				//데미지 시간

public:
	T_STR_VECTOR m_str;
	std::vector<RECT> m_rtlist;
	std::vector<PCT_VERTEX> m_vertexdata;
	RECT rtsrc;
	int StateNUM;
	ID3D11Device* m_pd3dDevice;		
	ID3D11DeviceContext* m_pContext;

public:
	std::vector<std::shared_ptr<CSprite>> m_StateList;
	std::vector<std::shared_ptr<CSprite>> m_SkiiList;
	CSprite m_Sprite;
	std::shared_ptr<CBY_Input> m_Input;

public:
	D3DXVECTOR3 m_pos;			//캐릭터의 위치 변화량
	D3DXVECTOR3 m_Center;		//캐릭터의 센터 위치
	D3DXVECTOR3 m_Size;			//센터에서 더해줄 크기이다
	D3DXMATRIX m_mat, m_world, m_view, m_proj;
	fRECT m_fRect;
	float m_Jumppos;				//점프 이동거리
	bool JUMP;					//캐릭터가 점프 상태인지의 대한 여부
	float combotime;				//콤보가 발동되기까지 시간
	float DoubleClickTime[KEYCOUNT];
	bool DoubleClick[KEYCOUNT];
	bool Start;
	bool Revers;					//캐릭터가 반대방향으로 돌릴때 적용될 상태를 선택
	int Damage;						//데미지 입을 시 숫자가 올라간다

public:
	virtual HRESULT Create(ID3D11Device* pd3dDevice, ID3D11DeviceContext* Context);
	virtual void skill();
	virtual void SetWorldandMatrix(D3DXMATRIX* world, D3DXMATRIX* view, D3DXMATRIX* proj, D3DXVECTOR3 pos, fRECT Enemy_rt);
	virtual void VertexData();
	void RectSet(D3DXVECTOR3 pos);
	void SetState(int num);
	void SetAniTime(float Time);
	bool Frame();
	bool Render();
public:
	CharSrc();
	~CharSrc();
};

