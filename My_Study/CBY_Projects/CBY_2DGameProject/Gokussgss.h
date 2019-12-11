#pragma once
#include "CharSrc.h"

class Gokussgss :public CharSrc
{
public:
	D3DXVECTOR3 m_skillpos;			//스킬의 월드행렬

public:
	HRESULT Create(ID3D11Device* pd3dDevice, ID3D11DeviceContext* Context);
	void TextSrc();
	void TextArray(int i);
	void SetWorldandMatrix(D3DXMATRIX* world, D3DXMATRIX* view, D3DXMATRIX* proj, D3DXVECTOR3 pos, fRECT Enemy_rt);
	
	virtual void skillvertex(int i);
	void skill();

public:
	Gokussgss();
	~Gokussgss();
};

