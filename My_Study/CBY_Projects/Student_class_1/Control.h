#pragma once
#include "LinkList.h"

class Control
{
private:
	StuNode stu;
	LinkList Link;
	StuNode* begin;
	StuNode* end;
	enum{PLUS=1,MINUS,MULTIPLY,DIVISION};		//����1,����2,����3,������4

public:
	Control();
	~Control();

public:
	void print();				//���
	void in();					//����
	void sak();					//��� �˻� ����
	void Jung();				//����
	void oper();				//����
	/*int plus(StuNode* const sub);				//����
	int minus(StuNode* const sub);				//����
	int multi(StuNode* const sub);				//����
	double division(StuNode* const sub);			//������*/

};

