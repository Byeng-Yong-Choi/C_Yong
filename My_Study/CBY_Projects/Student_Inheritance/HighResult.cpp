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
	std::cout << Grade << "�г� \t" << Num << "�� \t" <<Name<<" \t"<< Age << "�� \t" << Gender << "\t" << Kor << "�� \t" << Eng << "�� \t" << Mat << "�� \t" << Sum << "�� \t" << Avg << "�� \t" << Rank << std::endl;
	
}


HighResult::HighResult()
{
	HighGetData();
}


HighResult::~HighResult()
{
}
