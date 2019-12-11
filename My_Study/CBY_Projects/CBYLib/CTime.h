#pragma once
#include "Cstd.h"

class CTime
{
public:
	int CFPS=0;
	float SecondTime;
	DWORD NowTime;		//DWORD->unsigned long�̴�
	float GameTime=0;
	float TotalFrameTime = 0.0f;
	TCHAR Buffer[256];

public:
	bool Init();
	bool Render();
	bool Frame();
	bool Release();

public:
	CTime();
	~CTime();
};

