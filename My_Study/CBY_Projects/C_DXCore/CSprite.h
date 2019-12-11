#pragma once
#include "CShapeObject.h"

struct CRect
{
	D3DXVECTOR2 uv[4];
	fRECT RT;
};
typedef std::vector<CRect> CRECT;
typedef std::vector<RECT>  RECT_ARRAY;

class CSprite : public CShapeObject
{
public:
	Microsoft::WRL::ComPtr < ID3D11ShaderResourceView>  m_pMaskSRV;
	std::vector<Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>> m_srvList;
	CRECT m_rtList;
	fRECT m_rt;
	int m_Index;
	float m_LifeTime;
	float m_SecPerRender;
	float m_ChangeTime;
	int	m_Sprite;
	bool Attack;
	bool End;
	bool Jump;
	bool Skill;
	bool Death;
	bool DeathJump;

public:
	void SetRectArray(RECT_ARRAY& rtSpriteList, int iWidth, int iHeight);
	void SetRectUV(CRECT& rtSpriteList, int Width, int Height);
	void SetTextureArray(T_STR_VECTOR& rtList);
	void SetAnimation(float fLifeTime,float fAnimTime, int Width=0, int WidthSize=0, int Height=0, int HeightSize=0);
	void SetEffectLength();
	virtual void UpdateVertexData(std::vector<PCT_VERTEX>& list);					//정점 버퍼 데이터 업데이트
	virtual bool PostRender();
	virtual bool Frame();

public:
	CSprite();
	~CSprite();
};

