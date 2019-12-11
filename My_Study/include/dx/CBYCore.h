#pragma once
#include "C_Device.h"
#include "CCamera.h"
#include "C_Model.h"
#include "CBY_Input.h"


class CBYCore:public C_Device
{
protected:
	bool GetGameRun;
	CTime	m_Timer;
	CCamera m_DebugCamera;
	CCamera* m_pMainCamera;
	CBY_Input m_Input;

public:
	virtual bool Init();
	virtual bool Frame();
	virtual bool Render();
	virtual bool Release();
	bool CoreInit();
	bool CoreFrame();
	bool PreRender();
	bool CoreRender();
	bool PostRender();
	bool CoreRelease();
	bool GameRun();
	virtual HRESULT CreateDXrc();		//��������� DX�ҽ��� ������ ����
	virtual HRESULT	DeleteDXrc();		//��������� DX�ҽ� ������ ���� ����

public:
	CBYCore();
	virtual ~CBYCore();
};
