#include "University.h"


void University::UnivGetData()
{
	Departmentnum = rand() % 5;
	switch (Departmentnum)						//enum{Computer=0,Physics,Korean,Child,Nursing};		//0:��ǻ�� ���а�, 1:�����а�, 2:�����а�, 3:���Ʊ����а�, 4:��ȣ�а�
	{	
		case Computer:
			strcpy(Department, "��ǻ�Ͱ��а�");
			break;

		case Physics:
			strcpy(Department, "�����а�");
			break;
		
		case Korean:
			strcpy(Department, "�����а�");
			break;

		case Child:
			strcpy(Department, "���Ʊ�����");
		
		case Nursing:
			strcpy(Department, "��ȣ�а�");
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
