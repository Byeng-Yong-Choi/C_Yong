#pragma once
#include <iostream>
#include <time.h>		
#include <stdio.h>			
#include <stdlib.h>
#include <conio.h>
#include <string.h>
//#include <fstream>		//c++ 파일 입출력

using namespace std;

class student
{
public:
	student();
	student(int i);
	~student();

	static int number;
public:
	//void begin(int i);		//초기값 생성
	void makedata(int i);		//데이터 생성
	void Show();			//출력

	/*int operator+(student& const plus);
	int operator-(student& const plus);
	double operator/(student& const plus);
	int operator*(student& const plus);*/
	/*student operator+=(student& const plus);
	student operator-=(student& const plus);
	student operator*=(student& const plus);
	student operator/=(student& const plus);*/


public:
	int num;
	char name[5];
	int kuk;
	int eng;
	int su;
	int sum;
	double avg;
};

