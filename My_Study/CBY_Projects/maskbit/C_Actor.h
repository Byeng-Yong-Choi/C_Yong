#pragma once
#include "C_Object.h"
class C_Actor:public C_Object
{
public:
	bool SetRECT(RECT rt);
	virtual bool GetRECT(vector<RECT>& rtList);

public:
	bool SetPosition(float x, float y);
	bool GetRECT(RECT rt1);

public:
	virtual bool Init();
	virtual bool Frame();
	virtual bool Render();
	virtual bool Release();

public:
	C_Actor();
	~C_Actor();
};

