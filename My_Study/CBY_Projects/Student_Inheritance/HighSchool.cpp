#include "HighSchool.h"


void HighSchool::HighGetData()
{
	if (Age == 17)
		Grade = 1;
	else if (Age == 18)
		Grade = 2;
	else
		Grade = 3;					//�г�

		Num = 1+rand() % 10;	//���� 10�ݱ���
}

void HighSchool::GetRank(int i)
{
	Rank = i;
}


HighSchool::HighSchool()
{
}


HighSchool::~HighSchool()
{
}
