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
	//void swap(StuNode<T>& Node, StuNode<T>& Daum);					//노드 데이터 교환
	//void swappa(StuNode<T>& Node, StuNode<T>& Daum);				//노드의 주소값을 바꿔서 데이터 교환
	void oneone(StuNode<T>* const tail);							//초기값
	void FrontNodein(StuNode<T>* newNode, StuNode<T>* const head);	//새로운 후위 노드 삽입
	void BackNodein(StuNode<T>* newNode, StuNode<T>* const tail);		//새로운 전위 노드 삽입
	void Delete(StuNode<T>* Node);									//노드 삭제
	StuNode<T>* make(StuNode<T>* front);						//노드 새로 만들기
	T getData();													//자료의 데이터 받아오기
	T ShowData();

public:
	static int nodenum;								//노드의 개수
	static int index;								//고유 노드 번호
	T studentNode;
	int IndexNumber;
	StuNode<T>* m_next;
	StuNode<T>* m_prev;
};


