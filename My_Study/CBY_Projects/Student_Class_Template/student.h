#pragma once
#include <iostream>
#include <time.h>		
#include <stdio.h>			
#include <stdlib.h>
#include <conio.h>
#include <string.h>
//#include <fstream>		//c++ ���� �����

using namespace std;

class student
{
public:
	student();
	student(int i);
	~student();

	static int number;
public:
	//void begin(int i);		//�ʱⰪ ����
	void makedata(int i);		//������ ����
	void Show();			//���

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

