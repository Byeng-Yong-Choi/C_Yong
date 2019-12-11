#include "HighSchool.h"


void HighSchool::HighGetData()
{
	if (Age == 17)
		Grade = 1;
	else if (Age == 18)
		Grade = 2;
	else
		Grade = 3;					//학년

		Num = 1+rand() % 10;	//반은 10반까지
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
