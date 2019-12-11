#pragma once
#include "C_Object.h"
#define CHARSPEED 300

class Char:public C_Object
{
public:
	

public:
	bool Init();
	bool Frame();		
	bool Render();									//기본 이미지 출력
	bool Release();

public:
	Char();
	~Char();
};

