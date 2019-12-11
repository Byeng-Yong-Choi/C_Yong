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
	//void swap(CBYNode<T>& Node, CBYNode<T>& Daum);					//노드 데이터 교환
	//void swappa(CBYNode<T>& Node, CBYNode<T>& Daum);				//노드의 주소값을 바꿔서 데이터 교환
	void Delete(CBYNode<T>* Node);									//노드 삭제
	CBYNode<T>* make(int num);						//노드 새로 만들기
	T getData(int i);													//자료의 데이터 받아오기
	T ShowData();

public:
	static int nodenum;								//노드의 개수
	static int index;								//고유 노드 번호
	T studentNode;
	int IndexNumber;
	CBYNode<T>* m_next;
	CBYNode<T>* m_prev;
};


