#pragma once
#include "C_Object.h"
class BackGround:public C_Object
{

public:
	bool Init();
	bool Frame();
	bool Render();									//�⺻ �̹��� ���
	bool Release();

public:
	BackGround();
	~BackGround();
};

