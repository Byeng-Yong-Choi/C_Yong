#pragma once
#include "CBYWindow.h"


class C_Device:public CBYWindow
{
public:
	ID3D11Device* m_pd3dDevice;
	ID3D11DeviceContext* m_pContext;
	IDXGISwapChain* m_pSwapChain;
	ID3D11RenderTargetView* m_pRenderTargetView;
	ID3D11DepthStencilView* m_pDepthStencilView;
	IDXGIFactory* m_pGIFactory;
	DXGI_SWAP_CHAIN_DESC m_SwapChainDesc;

public:
	HRESULT CreateDevice();
	HRESULT CreateGIFactory();
	HRESULT CreateSwapChain();
	HRESULT SetRenderTargetView();
	void SetViewPort();
	bool ResizeDevice(UINT width, UINT height);		//������ ȭ�� ũ�Ⱑ �ٲ𶧸��� ����۵� ���� ũ�� �������� �� �ְ� ���ִ� �Լ�
	virtual HRESULT CreateDXrc();
	virtual HRESULT	DeleteDXrc();
	virtual void SendMSGClick() override;
		

public:
	bool DeviceInit();
	bool DeviceRelease();

public:
	C_Device();
	~C_Device();
};

