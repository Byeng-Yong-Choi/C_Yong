#pragma once
#define _CRT_SECURE_NO_WARNINGS				//2019에서 strcpy가 보안때문에 오류가 떠서
#include <iostream>
#include <string.h>
#include <time.h>


class StudentMgn
{
public:
	StudentMgn();
	~StudentMgn();
	enum {Man=0,Woman};				//성별 0:남자, 1:여자
	void HighGetData();				//고등학교 데이터
	void UnivGetData();				//대학교 데이터

public:
	char Name[5] = { 0, };		//이름
	int Age;					//나이
	char Gender;					//성별
};

