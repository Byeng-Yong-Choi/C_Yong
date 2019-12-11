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
	enum{PLUS=1,MINUS,MULTIPLY,DIVISION};		//µ¡¼À1,»¬¼À2,°ö¼À3,³ª´°¼À4

public:
	Control<T>();
	~Control<T>();

public:
	void in();					//»ðÀÔ
	void sak();					//³ëµå °Ë»ö »èÁ¦
	//void Jung();				//¼öÁ¤
	//void oper();				//¿¬»ê
	/*int plus(StuNode* const sub);				//µ¡¼À
	int minus(StuNode* const sub);				//»¬¼À
	int multi(StuNode* const sub);				//°ö¼À
	double division(StuNode* const sub);			//³ª´°¼À*/

};

