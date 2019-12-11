#include "CBYCore.h"


bool CBYCore::Init()
{
	return true;
}
bool CBYCore::Frame()
{
	return true;
}
bool CBYCore::Render()
{
	return true;
}
bool CBYCore::Release()
{
	return true;
}


bool CBYCore::GameRun()
{
	GetGameRun = CoreInit();
	if (GetGameRun == false)
	{
		return false;
	}

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	while (GetGameRun)
		{
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
				if (msg.message == WM_QUIT)
				{
					break;
				}
			}
		if (CoreFrame() == false)
		{
			return false;
		}
		if (CoreRender() == false)
		{
			return false;
		}
	}
	if (CoreRelease() == false)
	{
		return false;
	}
	return true;
}

bool  CBYCore::CoreInit()
{
	GetGameRun = true;
	return Init();
};
bool  CBYCore::CoreFrame()
{
	return Frame();
};
bool  CBYCore::CoreRender()
{
	return Render();
};
bool  CBYCore::CoreRelease()
{
	Release();
	Link.Nodefree();
	return true;
};

CBYCore::CBYCore()
{
	GetGameRun = false;
}


CBYCore::~CBYCore()
{
}
