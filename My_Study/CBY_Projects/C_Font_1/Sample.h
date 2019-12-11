#pragma once
#include "CBYCore.h"
#include "C_DXWrite.h"
#pragma warning( disable:4005 )

class Sample :public CBYCore
{
public:
	C_DXWrite m_Font;


public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();

public:
	Sample();
	~Sample();
};

CBY_RUN(Sample, C_DX, CBY_DX);

