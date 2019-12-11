#pragma once
#include "LinkList.h"

class Control
{
private:
	StuNode stu;
	LinkList Link;
	StuNode* begin;
	StuNode* end;
	enum{PLUS=1,MINUS,MULTIPLY,DIVISION};		//µ¡¼À1,»©±â2,°ö¼À3,³ª´°¼À4

public:
	Control();
	~Control();

public:
	void print();				//Ãâ·Â
	void in();					//»ðÀÔ
	void sak();					//³ëµå °Ë»ö »èÁ¦
	void Jung();				//¼öÁ¤
	void oper();				//¿¬»ê
	/*int plus(StuNode* const sub);				//µ¡¼À
	int minus(StuNode* const sub);				//»¬¼À
	int multi(StuNode* const sub);				//°ö¼À
	double division(StuNode* const sub);			//³ª´°¼À*/

};

