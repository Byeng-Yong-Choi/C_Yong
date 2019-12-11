#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <assert.h>
#define MAX_SUBJECT 3
#define MAX_STUDENTS 10
using namespace std;

class TObject
{
public:
	int		m_ID;
	int		m_iSubject[MAX_SUBJECT];
	int     m_iTotal;
public:
	TObject operator+(const TObject& t);
	float operator/(int iCounter);
	friend float operator / (int iCounter, TObject& t);
	friend ostream& operator << (ostream& os, TObject& t);
	friend istream& operator >> (istream& os, TObject& t);
public:
	bool   Frame();
	bool   Render();
	bool   Release();
public:
	TObject() {
		m_ID = -1;
		m_iSubject[0] = 0;
		m_iSubject[1] = 0;
		m_iSubject[2] = 0;
		m_iTotal = m_iSubject[0] +
			m_iSubject[1] + m_iSubject[2];
	}
	TObject(int iID, int iKor, int iEng, int iMat)
	{
		m_ID = iID;
		m_iSubject[0] = iKor;
		m_iSubject[1] = iEng;
		m_iSubject[2] = iMat;
		m_iTotal = m_iSubject[0] +
			m_iSubject[1] + m_iSubject[2];
	}
	TObject(const TObject& node);
	~TObject() {}
};

