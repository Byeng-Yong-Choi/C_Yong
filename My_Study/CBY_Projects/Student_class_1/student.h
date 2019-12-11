#pragma once
#include <iostream>
#include <time.h>		
#include <stdio.h>			
#include <stdlib.h>
#include <conio.h>
#include <string.h>
//#include <fstream>		//c++ 파일 입출력

using namespace std;
#define MAX_STUDENT 10

class student
{
public:
	student();
	student(int a);
	~student();

public:
	void begin(int a);		//초기값 생성
	int operator+(student& const plus);
	int operator-(student& const plus);
	double operator/(student& const plus);
	int operator*(student& const plus);
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

