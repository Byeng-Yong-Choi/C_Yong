#pragma once
#include "C_Actor.h"

class Weapon:public C_Actor
{
public:
	int num;

public:
	//bool EndY(float Y);
	virtual bool Init() override;
	virtual bool Frame() override;
	virtual bool Render() override;									//�⺻ �̹��� ���
	virtual bool Release() override;
	

public:
	Weapon();
	~Weapon();
};

