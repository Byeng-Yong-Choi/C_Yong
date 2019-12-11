#pragma once
using namespace std;

#include <iostream>
#include <time.h>		
#include <stdio.h>			
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define MAX_STUDENT 10

template <class T>
class StuNode
{
public:
	StuNode<T>();
	~StuNode<T>();

public:
	//void swap(StuNode<T>& Node, StuNode<T>& Daum);					//��� ������ ��ȯ
	//void swappa(StuNode<T>& Node, StuNode<T>& Daum);				//����� �ּҰ��� �ٲ㼭 ������ ��ȯ
	void oneone(StuNode<T>* const tail);							//�ʱⰪ
	void FrontNodein(StuNode<T>* newNode, StuNode<T>* const head);	//���ο� ���� ��� ����
	void BackNodein(StuNode<T>* newNode, StuNode<T>* const tail);		//���ο� ���� ��� ����
	void Delete(StuNode<T>* Node);									//��� ����
	StuNode<T>* make(StuNode<T>* front);						//��� ���� �����
	T getData();													//�ڷ��� ������ �޾ƿ���
	T ShowData();

public:
	static int nodenum;								//����� ����
	static int index;								//���� ��� ��ȣ
	T studentNode;
	int IndexNumber;
	StuNode<T>* m_next;
	StuNode<T>* m_prev;
};


