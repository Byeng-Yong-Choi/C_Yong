#pragma once
#include "C_Actor.h"

class Weapon:public C_Actor
{
public:
	int num;

public:
	bool EndY(float Y);
	bool Init() override;
	bool Frame() override;
	bool Render() override;									//기본 이미지 출력
	bool Release() override;

public:
	Weapon();
	~Weapon();
};

