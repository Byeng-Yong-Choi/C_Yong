#pragma once
#include "student.h"


class StuNode
{
public:
	student studentNode;
	StuNode();
	~StuNode();

public:
	//void swap(StuNode& Node, StuNode& Daum);					//��� ������ ��ȯ
	//void swappa(StuNode& Node, StuNode& Daum);				//����� �ּҰ��� �ٲ㼭 ������ ��ȯ
	void oneone(StuNode& const tail);							//�ʱⰪ
	void FrontNodein(StuNode* newNode, StuNode& const head);	//���ο� ���� ��� ����
	void BackNodein(StuNode* newNode, StuNode& const head);		//���ο� ���� ��� ����
	void Delete(StuNode* Node);									//��� ����
	StuNode* make(StuNode& tail,int num);						//��� ���� �����

public:
	static int nodenum;
	StuNode* m_next;
	StuNode* m_prev;
};


