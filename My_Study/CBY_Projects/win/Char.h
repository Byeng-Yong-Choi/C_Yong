#pragma once
#include "C_Object.h"
#define CHARSPEED 300

class Char:public C_Object
{
public:
	

public:
	bool Init();
	bool Frame();		
	bool Render();									//�⺻ �̹��� ���
	bool Release();

public:
	Char();
	~Char();
};

