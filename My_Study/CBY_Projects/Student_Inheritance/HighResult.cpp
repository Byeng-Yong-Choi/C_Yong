#include "HighResult.h"


void HighResult::HighGetData()
{
	StudentMgn::HighGetData();
	HighSchool::HighGetData();
	Kor = rand() % 101;
	Eng = rand() % 101;
	Mat = rand() % 101;
	Sum = Kor + Eng + Mat;
	Avg = Sum / (double)3;
}

void HighResult::Show()
{
	std::cout << std::fixed;
	std::cout.precision(1);
	std::cout << Grade << "학년 \t" << Num << "반 \t" <<Name<<" \t"<< Age << "살 \t" << Gender << "\t" << Kor << "점 \t" << Eng << "점 \t" << Mat << "점 \t" << Sum << "점 \t" << Avg << "점 \t" << Rank << std::endl;
	
}


HighResult::HighResult()
{
	HighGetData();
}


HighResult::~HighResult()
{
}
