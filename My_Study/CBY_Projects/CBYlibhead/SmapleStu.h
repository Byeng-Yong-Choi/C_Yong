#pragma once
#include <iostream>
#include <time.h>		
#include <stdio.h>			
#include <stdlib.h>
#include <conio.h>
#include <string.h>
//#include <fstream>		//c++ ���� �����

class SmapleStu
{
public:
	SmapleStu();
	SmapleStu(int a);
	~SmapleStu();

public:
	void begin(int a);		//�ʱⰪ ����

public:
	int num;
	char name[5];
	int kuk;
	int eng;
	int su;
	int sum;
	double avg;
};