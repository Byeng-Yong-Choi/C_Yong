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
	// �ھ� �ʱ�ȭ �۾�
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
	// ��� ��ü ���� �� �Ҹ� �۾�
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
