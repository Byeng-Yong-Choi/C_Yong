#pragma once
#include "CSprite.h"

class GameTime
{
public:
	std::vector<std::shared_ptr<CSprite>> m_Timer;
	T_STR_VECTOR m_str;
	std::vector<PCT_VERTEX> m_vertexdata;
	CSprite m_Sprite;

public:
	float m_ChangeTime;
	int m_Spritenum;

public:
	HRESULT Create(ID3D11Device* pd3dDevice, ID3D11DeviceContext* Context);
	void VertexData();
	void VertexSet(int i);
	void TextArray();
	bool Frame();
	bool Render();


public:
	GameTime();
	~GameTime();
};

