#pragma once
#include "LinkList.h"

class Control
{
private:
	StuNode stu;
	LinkList Link;
	StuNode* begin;
	StuNode* end;

public:
	Control();
	~Control();

public:
	void print();				//���
	void in();					//����
	void sak();					//��� �˻� ����
	void Jung();				//����

};

