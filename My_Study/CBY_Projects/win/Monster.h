#pragma once
#include "C_Object.h"
class Monster :public C_Object
{
public:
	

public:
	bool Init();
	bool Frame();
	bool Render();									//�⺻ �̹��� ���
	bool Release();

public:
	Monster();
	~Monster();
};

