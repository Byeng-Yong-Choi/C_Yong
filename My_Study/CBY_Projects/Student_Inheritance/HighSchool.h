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
	int Rank=0;		//¼øÀ§
	int Grade;		//ÇÐ³â
	int Num;		//¹Ý
	int Sum;		//ÃÑÁ¡
	double Avg;		//Æò±Õ

private:
	static int RankNumber;
};

