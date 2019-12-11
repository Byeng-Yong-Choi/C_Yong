#pragma once
#include "CBYNode.cpp"

template <class T>
class CBYLinkList
{
private:
	static CBYNode<T>* LinkHead;
	static CBYNode<T>* LinkTail;

public:
	CBYNode<T>* getHead() { return LinkHead; };		//헤드 반환
	CBYNode<T>* getTail() { return LinkTail; };		//꼬리 반환
	void firstNode();								//초기 메모리 생성
	void Nodefree();								//메모리 해제
	void FrontNodein(CBYNode<T>* newNode);
	void BackNodein(CBYNode<T>* newNode);
//	int numfind();									//삭제된 번호 찾아서 대입
	int Find(int a);								//노드 위치 찾기
//	T* NodeFind(int a);
	int NodeNumber();								//노드 개수 찾기

public:
	CBYLinkList();
	~CBYLinkList();
};

