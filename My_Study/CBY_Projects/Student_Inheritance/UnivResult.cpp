#include "UnivResult.h"

void UnivResult::UnivGetData()
{
	StudentMgn::UnivGetData();		//이름 성별 나이
	University::UnivGetData();		//학과
	Subject[0] = rand() % 101;
	Subject[1] = rand() % 101;
	Subject[2] = rand() % 101;
}

int UnivResult::StdCredit(int a)
{
	if (a <= 100 && a >= 80)
	{
		return 0;
	}
	else if (a < 80 && a >= 60)
	{
		return 1;
	}
	else if (a < 60 && a >= 40)
	{
		return 2;
	}
	else if (a < 40 && a >= 20)
	{
		return 3;
	}
	else
	{
		return 4;
	}
}

void UnivResult::Show()
{
	int i;
	std::cout << Department << "\t"<< SchoolNum << " \t" << Name << " \t" << Age << "살 \t" << Gender << "\t\t" << Subject[0] <<"점 \t" << Subject[1] << "점 \t" << Subject[2] << "점"<<"\t";
	for (i = 0; i < MAX_SUJECT; i++)
	{
		University::GetCredit(StdCredit(Subject[i]));
		std::cout <<"  "<<Credit;
	}
	std::cout << std::endl;



}

UnivResult::UnivResult()
{
	UnivGetData();
}


UnivResult::~UnivResult()
{
}
