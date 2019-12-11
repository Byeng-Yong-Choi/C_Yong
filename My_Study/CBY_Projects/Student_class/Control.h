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
	void print();				//출력
	void in();					//삽입
	void sak();					//노드 검색 삭제
	void Jung();				//수정

};

