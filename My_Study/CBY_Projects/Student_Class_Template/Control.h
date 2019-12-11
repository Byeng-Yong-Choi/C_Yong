#pragma once
#include "LinkList.cpp"

template <class T>
class Control
{
private:
	StuNode<T> stu;
	LinkList<T> Link;
	StuNode<T>* begin;
	StuNode<T>* end;
	enum{PLUS=1,MINUS,MULTIPLY,DIVISION};		//����1,����2,����3,������4

public:
	Control<T>();
	~Control<T>();

public:
	void in();					//����
	void sak();					//��� �˻� ����
	//void Jung();				//����
	//void oper();				//����
	/*int plus(StuNode* const sub);				//����
	int minus(StuNode* const sub);				//����
	int multi(StuNode* const sub);				//����
	double division(StuNode* const sub);			//������*/

};

