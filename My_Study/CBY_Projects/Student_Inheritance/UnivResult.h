#pragma once
#include "University.h"
#define MAX_SUJECT 3
class UnivResult:public University
{
public:
	UnivResult();
	~UnivResult();

public:
	void UnivGetData();
	void Show();
	int StdCredit(int a);		//���� ���� ������ ����

public:
	int Subject[MAX_SUJECT] = { 0, };
};

