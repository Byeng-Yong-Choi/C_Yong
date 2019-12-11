#pragma once
#include "CBYWindow.h"
#include "CBYLinkList.cpp"

class CBYCore:public CBYWindow
{
protected:
	bool GetGameRun;
	CBYLinkList<SmapleStu> Link;
	CBYNode<SmapleStu>* Node;
	SmapleStu stu;

public:
	virtual bool Init();
	virtual bool Frame();
	virtual bool Render();
	virtual bool Release();
	bool CoreInit();
	bool CoreFrame();
	bool CoreRender();
	bool CoreRelease();
	bool GameRun();

public:
	CBYCore();
	virtual ~CBYCore();
};
