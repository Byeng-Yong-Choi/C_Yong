#pragma once
#include "CBYNode.cpp"

template <class T>
class CBYLinkList
{
private:
	static CBYNode<T>* LinkHead;
	static CBYNode<T>* LinkTail;

public:
	CBYNode<T>* getHead() { return LinkHead; };		//��� ��ȯ
	CBYNode<T>* getTail() { return LinkTail; };		//���� ��ȯ
	void firstNode();								//�ʱ� �޸� ����
	void Nodefree();								//�޸� ����
	void FrontNodein(CBYNode<T>* newNode);
	void BackNodein(CBYNode<T>* newNode);
//	int numfind();									//������ ��ȣ ã�Ƽ� ����
	int Find(int a);								//��� ��ġ ã��
//	T* NodeFind(int a);
	int NodeNumber();								//��� ���� ã��

public:
	CBYLinkList();
	~CBYLinkList();
};

