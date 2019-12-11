#include "UnivResult.h"

void UnivResult::UnivGetData()
{
	StudentMgn::UnivGetData();		//�̸� ���� ����
	University::UnivGetData();		//�а�
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
	std::cout << Department << "\t"<< SchoolNum << " \t" << Name << " \t" << Age << "�� \t" << Gender << "\t\t" << Subject[0] <<"�� \t" << Subject[1] << "�� \t" << Subject[2] << "��"<<"\t";
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
