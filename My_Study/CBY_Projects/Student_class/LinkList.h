#pragma once
#include "StuNode.h"


class LinkList
{
private:
	static StuNode* LinkHead;
	static StuNode* LinkTail;

public:
	StuNode* getHead() { return LinkHead; };		//��� ��ȯ
	StuNode* getTail() { return LinkTail; };		//���� ��ȯ
	void firstNode();								//�ʱ� �޸� ����
	void Nodefree();								//�޸� ����
	int numfind();									//������ ��ȣ ã�Ƽ� ����
	int Find(int a);								//��� ��ġ ã��
	int NodeNumber();								//��� ���� ã��

public:
	LinkList();
	~LinkList();
};

