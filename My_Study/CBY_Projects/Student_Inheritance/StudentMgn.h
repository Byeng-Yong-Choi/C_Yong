#pragma once
#define _CRT_SECURE_NO_WARNINGS				//2019���� strcpy�� ���ȶ����� ������ ����
#include <iostream>
#include <string.h>
#include <time.h>


class StudentMgn
{
public:
	StudentMgn();
	~StudentMgn();
	enum {Man=0,Woman};				//���� 0:����, 1:����
	void HighGetData();				//����б� ������
	void UnivGetData();				//���б� ������

public:
	char Name[5] = { 0, };		//�̸�
	int Age;					//����
	char Gender;					//����
};

