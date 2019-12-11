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
	bool  CoreInit();	 // �ʱ�ȭ
	bool  CoreFrame();   // ���
	bool  CoreRender();  // ��ο�
	bool  CoreRelease(); // �Ҹ�
	bool  Run();
public:
	TCore();
	virtual ~TCore();
};

