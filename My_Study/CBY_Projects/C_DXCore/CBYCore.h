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
	virtual HRESULT CreateDXrc();		//리사이즈시 DX소스의 변경후 생성
	virtual HRESULT	DeleteDXrc();		//리사이즈시 DX소스 변경을 위해 삭제

public:
	CBYCore();
	virtual ~CBYCore();
};
