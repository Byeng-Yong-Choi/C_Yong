#pragma once
#include "HighSchool.h"

class HighResult :public HighSchool
{
public:
	int Kor;			
	int Eng;
	int Mat;

public:
	void HighGetData();
	void Show();

public:
	HighResult();
	~HighResult();
};

