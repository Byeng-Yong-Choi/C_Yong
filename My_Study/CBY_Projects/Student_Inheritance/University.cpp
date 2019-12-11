#include "University.h"


void University::UnivGetData()
{
	Departmentnum = rand() % 5;
	switch (Departmentnum)						//enum{Computer=0,Physics,Korean,Child,Nursing};		//0:컴퓨터 공학과, 1:물리학과, 2:국문학과, 3:유아교육학과, 4:간호학과
	{	
		case Computer:
			strcpy(Department, "컴퓨터공학과");
			break;

		case Physics:
			strcpy(Department, "물리학과");
			break;
		
		case Korean:
			strcpy(Department, "국문학과");
			break;

		case Child:
			strcpy(Department, "유아교육과");
		
		case Nursing:
			strcpy(Department, "간호학과");
			break;

	}
	SchoolNum = 190000 + rand() % 91;
}


void University::GetCredit(int temp)
{
	switch (temp)
	{
	case A:
		Credit = 'A';
		break;

	case B:
		Credit = 'B';
		break;

	case C:
		Credit = 'C';
		break;

	case D:
		Credit = 'D';
		break;

	case F:
		Credit = 'F';
		break;
	}
}

University::University()
{
}


University::~University()
{
}
