#pragma once
#include "C_Actor.h"
class Monster :public C_Actor
{

public:
	HDC AlphaDC;
	HBITMAP AlphaBitMap;
	float AlphaNum;
	int Death;
	int temp;

public:
	bool Init() override;
	bool Frame() override;
	bool Render() override;									//기본 이미지 출력
	bool Release() override;

public:
	Monster();
	~Monster();
};

