#pragma once
#include "CBYCore.h"
#include "CShape.h"

class main:public CBYCore
{
public:
	CShape m_Shape;
	

public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();

public:
	main();
	~main();
};

CBY_RUN(main, C_DX, CBY_DX);
