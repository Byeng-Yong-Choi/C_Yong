#pragma once
#include "StuNode.cpp"

template <class T>
class LinkList
{
private:
	static StuNode<T>* LinkHead;
	static StuNode<T>* LinkTail;

public:
	StuNode<T>* getHead() { return LinkHead; };		//��� ��ȯ
	StuNode<T>* getTail() { return LinkTail; };		//���� ��ȯ
	void firstNode();								//�ʱ� �޸� ����
	void Nodefree();								//�޸� ����
//	int numfind();									//������ ��ȣ ã�Ƽ� ����
	int Find(int a);								//��� ��ġ ã��
//	T* NodeFind(int a);
	int NodeNumber();								//��� ���� ã��

public:
	LinkList();
	~LinkList();
};

