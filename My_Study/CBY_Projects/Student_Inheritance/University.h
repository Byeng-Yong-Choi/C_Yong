#pragma once
#include "StudentMgn.h"
class University:public StudentMgn
{
public:
	University();
	~University();
	enum{Computer=0,Physics,Korean,Child,Nursing};		//0:컴퓨터 공학과, 1:물리학과, 2:국문학과, 3:유아교육학과, 4:간호학과
	enum{A=0,B,C,D,F};

public:
	void UnivGetData();
	void GetCredit(int temp);

public:
	char Credit;								//학점
	int Departmentnum;						//학과번호
	char Department[20] = { 0, };			//학과
	int SchoolNum;							//학번

};

