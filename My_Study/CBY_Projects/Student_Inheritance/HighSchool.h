#pragma once
#include "StudentMgn.h"

class HighSchool : public StudentMgn
{
public:
	HighSchool();
	~HighSchool();

public:
	void HighGetData();
	void GetRank(int i);

public:
	int Rank=0;		//����
	int Grade;		//�г�
	int Num;		//��
	int Sum;		//����
	double Avg;		//���

private:
	static int RankNumber;
};

