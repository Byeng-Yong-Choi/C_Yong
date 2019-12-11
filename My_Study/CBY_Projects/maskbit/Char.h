#pragma once
#include "C_Actor.h"
#define CHARSPEED 300

class Char:public C_Actor
{
public:
	HBITMAP RotatBit;
	HBITMAP MaskRotatBit;
	RECT LeftRt1;
	RECT LeftRt2;
	RECT Left2Rt1;
	RECT Left2Rt2;
	RECT RightRt1;
	RECT RightRt2;
	RECT Right2Rt1;
	RECT Right2Rt2;
	RECT EngineRt1;
	RECT EngineRt2;
	int pose;
	int num;
	float EX;
	float EY;

public:
	bool Init() override;
	bool Frame() override;
	bool Render() override;									//기본 이미지 출력
	bool Release() override;

public:
	Char();
	~Char();
};

