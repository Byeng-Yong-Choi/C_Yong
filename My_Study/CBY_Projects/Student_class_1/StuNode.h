#pragma once
#include "student.h"


class StuNode
{
public:
	student studentNode;
	StuNode();
	~StuNode();

public:
	//void swap(StuNode& Node, StuNode& Daum);					//노드 데이터 교환
	//void swappa(StuNode& Node, StuNode& Daum);				//노드의 주소값을 바꿔서 데이터 교환
	void oneone(StuNode& const tail);							//초기값
	void FrontNodein(StuNode* newNode, StuNode& const head);	//새로운 후위 노드 삽입
	void BackNodein(StuNode* newNode, StuNode& const head);		//새로운 전위 노드 삽입
	void Delete(StuNode* Node);									//노드 삭제
	StuNode* make(StuNode& tail,int num);						//노드 새로 만들기

public:
	static int nodenum;
	StuNode* m_next;
	StuNode* m_prev;
};


