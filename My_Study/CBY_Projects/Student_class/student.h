#pragma once
#include <time.h>		
#include <stdio.h>			
#include <stdlib.h>
#include <conio.h>
#include <string.h>
//#include <fstream>		//c++ ���� �����
#define MAX_STUDENT 10

class student
{
public:
	student();
	student(int a);
	~student();

public:
	void begin(int a);		//�ʱⰪ ����
	student operator+(student& plus);

public:
	int num;
	char name[5];
	int kuk;
	int eng;
	int su;
	int sum;
	double avg;
};

