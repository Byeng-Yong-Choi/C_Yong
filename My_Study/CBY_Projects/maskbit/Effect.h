#pragma once
#include "C_Actor.h"
#define EFFECT_SIZE 10

class Effect : public C_Actor
{
public:
	HDC EffectDC;
	HBITMAP h_Effect;
	int splitenum;
	bool endeffect;
	float EffectTime;
	float EffectShowTime;

public:
	bool GetRECT(vector<RECT>& rtList,float showtime);
	bool Init() override;
	bool Frame() override;
	bool Render() override;									//기본 이미지 출력
	bool Render(LONG width, LONG height);
	bool Release() override;


public:
	Effect();
	~Effect();
};

