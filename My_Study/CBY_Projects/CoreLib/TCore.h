#pragma once
#include "TWindow.h"
#include "TLinkedList.h"
#include "TObject.h"
class TCore : public TWindow
{
protected:
	bool			m_bGameRun;
	TLinkedList<TObject>	m_ObjectList;
public:
	virtual bool  Init();
	virtual bool  Frame();
	virtual bool  Render();
	virtual bool  Release();
public:
	bool  CoreInit();	 // 초기화
	bool  CoreFrame();   // 계산
	bool  CoreRender();  // 드로우
	bool  CoreRelease(); // 소멸
	bool  Run();
public:
	TCore();
	virtual ~TCore();
};

