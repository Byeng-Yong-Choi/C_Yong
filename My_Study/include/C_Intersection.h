#pragma once
#include "Cstd.h"

class C_Intersection
{
public:
	fPOINT Center(fRECT rt1);									//RECT�� �޾� �߽����� ���ϴ� �Լ�
	float Distance(fPOINT pt1, fPOINT pt2);						//�� ���� �Ÿ��� ���ϴ� �Լ�
	float GetDistance(float ax, float ay, float bx, float by);		//������ �Ÿ��� ���ϴ� �Լ�
	bool collision(fRECT rt1, fRECT rt2);						//�� RECT�� �浹�ϴ��� Ȯ���ϴ� �Լ�

public:
	fSphere RecttoSphere(fRECT rt1);							//RECT�� ������ �ٲٴ� �Լ�
	bool Spherecollision(fSphere sh1, fSphere sh2);				//�� ���� �浹 Ȯ���Լ�

public:
	static C_Intersection& Get()
	{
		static C_Intersection mgr;
		return mgr;
	}

public:
	C_Intersection();
	~C_Intersection();
};

#define I_Col C_Intersection::Get()
