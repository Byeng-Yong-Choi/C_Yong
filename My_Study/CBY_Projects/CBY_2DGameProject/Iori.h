#pragma once
#include "CharSrc.h"

class Iori :public CharSrc
{
public:
	HRESULT Create(ID3D11Device* pd3dDevice, ID3D11DeviceContext* Context);
	void TextSrc(int i);

public:
	Iori();
	~Iori();
};

