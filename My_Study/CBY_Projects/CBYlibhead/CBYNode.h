#pragma once
using namespace std;

#include <iostream>
#include <time.h>		
#include <stdio.h>			
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "SmapleStu.h"

template <class T>
class CBYNode
{
public:
	CBYNode<T>();
	~CBYNode<T>();

public:
	//void swap(CBYNode<T>& Node, CBYNode<T>& Daum);					//��� ������ ��ȯ
	//void swappa(CBYNode<T>& Node, CBYNode<T>& Daum);				//����� �ּҰ��� �ٲ㼭 ������ ��ȯ
	void Delete(CBYNode<T>* Node);									//��� ����
	CBYNode<T>* make(int num);						//��� ���� �����
	T getData(int i);													//�ڷ��� ������ �޾ƿ���
	T ShowData();

public:
	static int nodenum;								//����� ����
	static int index;								//���� ��� ��ȣ
	T studentNode;
	int IndexNumber;
	CBYNode<T>* m_next;
	CBYNode<T>* m_prev;
};


