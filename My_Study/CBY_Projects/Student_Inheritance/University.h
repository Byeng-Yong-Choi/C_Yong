#pragma once
#include "StudentMgn.h"
class University:public StudentMgn
{
public:
	University();
	~University();
	enum{Computer=0,Physics,Korean,Child,Nursing};		//0:��ǻ�� ���а�, 1:�����а�, 2:�����а�, 3:���Ʊ����а�, 4:��ȣ�а�
	enum{A=0,B,C,D,F};

public:
	void UnivGetData();
	void GetCredit(int temp);

public:
	char Credit;								//����
	int Departmentnum;						//�а���ȣ
	char Department[20] = { 0, };			//�а�
	int SchoolNum;							//�й�

};

