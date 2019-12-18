#include "CBYCore.h"

HRESULT CBYCore::CreateDXrc()
{
	HRESULT hr = S_OK;



	return hr;
}

HRESULT	CBYCore::DeleteDXrc()
{
	HRESULT hr = S_OK;

	float fAspect = (float)Winrt.right / (float)Winrt.bottom;

	m_pMainCamera->CreateProjMatrix(
		m_pMainCamera->m_fNear,
		m_pMainCamera->m_fFar,
		m_pMainCamera->m_fFovY,
		fAspect);

	return hr;
}

void CBYCore::SendMSGClick()
{

}

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
	GetGameRun = CoreInit();											//���Լ� ����� Init�����ϰ� Frame�� Render�Լ��� ���� ��� �̺�Ʈ�� ����� Release�� �޸𸮸� ����ְ� �����Ѵ�.
	if (GetGameRun == false)
	{
		return false;
	}

	MSG msg;															//�޼����� ���� MSG ����
	ZeroMemory(&msg, sizeof(msg));
	while (GetGameRun)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))				//PeekMessage�� �޼����� ������ �����¾��� ��� ���ư��� �߻���1 ������ 0�� ��ȯ
		{															//�׷��Ƿ� �޼���ť�� �޼����� �׿� ������ ��� �޼��� ó���ϴٰ� ������ Frame�� Render�� ���ư� 1�������� ���ư��� ��

			TranslateMessage(&msg);									//�޼���ť�� �ִ� �޼����� �޾Ƽ� Ű������ ������ �߻��� WN_CHAR�� �����ؼ� �޼���ť�� �ִ´�
			DispatchMessage(&msg);									//WndProc�� �޼���ť���ִ� �޼����� �Ѱ��ش�.
			if (msg.message == WM_QUIT)
			{
				break;
			}
		}
		else
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
	m_Timer.Init();
	if (FAILED(DeviceInit()))
	{
		return false;
	}
	CDX::CDxState::SetState(m_pd3dDevice);
	m_DebugCamera.SetViewProj();
	m_pMainCamera = &m_DebugCamera;
	return Init();
	
};
bool  CBYCore::CoreFrame()
{
	m_Timer.Frame();
	m_pMainCamera->Frame();
	if(Frame())
	{
		return true;
	}
	else
		return false;
};
bool CBYCore::PreRender()													//������ ������� ���� ������ �Ѿ�� ȭ���� �����ϰ� ������� Ŭ�������ִ� ����
{
	float ClearColor[] = { 0.0f, 0.7f, 1.0f,1 };
	m_pContext->ClearRenderTargetView(m_pRenderTargetView, ClearColor);							//���� ���۸����� preRender�� �ش��ϴ� �κ�
	m_pContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	return true;
};

bool  CBYCore::CoreRender()
{
	//PreRender();
	Render();
	//PostRender();
	return true;

};

bool CBYCore::PostRender()															
{
	m_pSwapChain->Present(0, 0);																//���������� �������� ������ �׷��ִ� �Լ��̴�.
	return true;
};

bool  CBYCore::CoreRelease()
{
	m_Timer.Release();
	Release();
	DeviceRelease();
	return true;
};

CBYCore::CBYCore()
{
	GetGameRun = false;
}


CBYCore::~CBYCore()
{
}
