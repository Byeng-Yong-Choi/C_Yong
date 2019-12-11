#pragma once
#include "Cstd.h"
class CBY_Input
{
private:
	//static int num;						//������ ���
	int num;

public:
	enum { KEY_FREE, KEY_UP, KEY_HOLD, KEY_PUSH };
	enum { UP=0, DOWN, LEFT, RIGHT };
	DWORD KeyData[256];
	RECT rt{400,300,800,600};							
	float X;
	float Y;
	bool weaponbool = false;		//���� �߻� ����
	POINT m_Mouse;


public:
	bool GetKeyCheck(DWORD inkey);
	bool Init();
	bool Frame();
	bool Render();
	bool Release();
	DWORD KeyCheck(DWORD inKey);			//Ű �Է½� �� Ű�� ������ �Է� ������ FREE(������ �������ʰ� ���ݵ� ������ �ʴ´�), UP(������ �����ְ� ���� ��������)
											//HOLD(������ ���Ȱ� ���ݵ� ���ȴ�),PUSH(������ ������ �ʰ� ������ ���ȴ�) 4������ Ű ������ �ѱ�� �Լ�

public:
	CBY_Input();
	~CBY_Input();
};

