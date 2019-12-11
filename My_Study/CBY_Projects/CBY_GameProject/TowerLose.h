#pragma once
#include "C_Object.h"

class TowerLose : public C_Object
{
public:
	HDC AlphaDC;
	HBITMAP AlphaBitMap;
	float AlphaNum;
	int Death;
	int ShowTime;

public:
	bool Init();
	bool Frame();
	bool Render();									//�⺻ �̹��� ���
	bool Release();

public:
	TowerLose();
	~TowerLose();
};

