#pragma once
#include "CSprite.h"
#include "CBY_Input.h"
#include "CharMgr.h"

enum					//ĳ������ ����
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
	float m_Jump;					//ĳ������ ������
	float m_Jumptime;				//ĳ������ �����ð�
	float m_Gravity;				//�߷°��ӵ�
	float m_Jumpfpos;				//������ ù ��ġ
	float m_DamageTime;				//������ �ð�

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
	D3DXVECTOR3 m_pos;			//ĳ������ ��ġ ��ȭ��
	D3DXVECTOR3 m_Center;		//ĳ������ ���� ��ġ
	D3DXVECTOR3 m_Size;			//���Ϳ��� ������ ũ���̴�
	D3DXMATRIX m_mat, m_world, m_view, m_proj;
	fRECT m_fRect;
	float m_Jumppos;				//���� �̵��Ÿ�
	bool JUMP;					//ĳ���Ͱ� ���� ���������� ���� ����
	float combotime;				//�޺��� �ߵ��Ǳ���� �ð�
	float DoubleClickTime[KEYCOUNT];
	bool DoubleClick[KEYCOUNT];
	bool Start;
	bool Revers;					//ĳ���Ͱ� �ݴ�������� ������ ����� ���¸� ����
	int Damage;						//������ ���� �� ���ڰ� �ö󰣴�

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

