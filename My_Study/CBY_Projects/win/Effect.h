#pragma once
#include "C_Object.h"

class Effect : public C_Object
{
public:
	

public:
	bool Init();
	bool Frame();
	bool Render();									//기본 이미지 출력
	bool Release();


public:
	Effect();
	~Effect();
};

