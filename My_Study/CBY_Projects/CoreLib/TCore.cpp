#include "TCore.h"

bool  TCore::Init()
{
	return true;
}
bool  TCore::Frame()
{
	return true;
}
bool  TCore::Render()
{
	return true;
}
bool  TCore::Release()
{
	return true;
}
bool  TCore::Run()
{
	// 코어 초기화 작업
	if (CoreInit()==false)
	{
		return false;
	}
	while (m_bGameRun)
	{
		if (CoreFrame() == false)
		{
			return false;
		}
		if (CoreRender() == false)
		{
			return false;
		}
	}
	// 모든 객체 해제 및 소멸 작업
	if (CoreRelease() == false)
	{
		return false;
	}
	return true;
}
bool  TCore::CoreInit()
{
	m_bGameRun = true;
	return Init();
};	 
bool  TCore::CoreFrame() 
{
	return Frame();
};
bool  TCore::CoreRender() 
{
	return Render();
};
bool  TCore::CoreRelease() 
{
	Release();
	for (TNode<TObject>* pNext =
		m_ObjectList.start();
		pNext != m_ObjectList.tail();
		pNext = pNext->m_pNext)
	{
		pNext->m_Data.Release();
	}
	m_ObjectList.Clear();
	return true;
};
TCore::TCore()
{
	m_bGameRun = false;
}


TCore::~TCore()
{
}
