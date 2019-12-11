#pragma once
#include "StuNode.h"


class LinkList
{
private:
	static StuNode* LinkHead;
	static StuNode* LinkTail;

public:
	StuNode* getHead() { return LinkHead; };		//헤드 반환
	StuNode* getTail() { return LinkTail; };		//꼬리 반환
	void firstNode();								//초기 메모리 생성
	void Nodefree();								//메모리 해제
	int numfind();									//삭제된 번호 찾아서 대입
	int Find(int a);								//노드 위치 찾기
	int NodeNumber();								//노드 개수 찾기

public:
	LinkList();
	~LinkList();
};

