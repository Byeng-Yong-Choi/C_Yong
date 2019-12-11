#include "C_DXWrite.h"

bool C_DXWrite::Set(HWND hWnd, int Width, int Height, IDXGISurface* pSurface)
{
	HRESULT hr=S_OK;

	hr = CreateDeviceIndependentResources();										//��ü ����
	if (FAILED(hr))
	{
		return false;
	}

	hr = CreateDeviceResources(pSurface);										//����̽� ���� ��ü ����
	if (FAILED(hr))
	{
		return false;
	}

	return true;
}

HRESULT C_DXWrite::CreateDeviceResources(IDXGISurface* pSurface)
{
	HRESULT hr = S_OK;

	D2D1_RENDER_TARGET_PROPERTIES sr;
	ZeroMemory(&sr, sizeof(D2D1_RENDER_TARGET_PROPERTIES));		//���� Ÿ�ٿ� �Էµ� ����
	sr.type = D2D1_RENDER_TARGET_TYPE_DEFAULT;
	sr.pixelFormat.format = DXGI_FORMAT_UNKNOWN;
	sr.pixelFormat.alphaMode = D2D1_ALPHA_MODE_PREMULTIPLIED;
	sr.dpiX = m_fdpiX;
	sr.dpiY = m_fdpiY;
	sr.usage = D2D1_RENDER_TARGET_USAGE_NONE;
	sr.minLevel = D2D1_FEATURE_LEVEL_DEFAULT;

	hr = m_pD2DFactory->CreateDxgiSurfaceRenderTarget(pSurface, &sr, &m_pRT);
	if (FAILED(hr))
	{
		return hr;
	}
	m_pRT->CreateSolidColorBrush(D2D1::ColorF(0, 0, 0, 1), &m_pBlackBrush);			//������ ����Ʈ ���� �귯���� ���� �Է»���

	return hr;

}

HRESULT C_DXWrite::CreateDeviceIndependentResources()
{
	HRESULT hr = S_OK;

	hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_MULTI_THREADED, &m_pD2DFactory);		//D2D���丮�� ��Ƽ������ �������� ����
	if (FAILED(hr))
	{
		return hr;
	}

	m_pD2DFactory->GetDesktopDpi(&m_fdpiX, &m_fdpiY);								//���� �ý����� DPI�� ���� �޴´�
	m_fDPIScaleX = m_fdpiX / 96.0f;													//
	m_fDPIScaleY = m_fdpiY / 96.0f;

	hr = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), (IUnknown**)&m_pWriteFactory);	//
	if (FAILED(hr))
	{
		return hr;
	}

	//���� ���� ����
	hr = m_pWriteFactory->CreateTextFormat(L"�ü�", NULL, DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 30, L"ko-kr", &m_pTextFormat);
	if (FAILED(hr))
	{
		return hr;
	}

	return hr;
}

void C_DXWrite::DiscardDeviceResources()
{
	m_pBlackBrush->Release();
	m_pRT->Release();
}

void C_DXWrite::DiscardDeviceIndependentResources()
{
	m_pTextFormat->Release();
	m_pWriteFactory->Release();
	m_pD2DFactory->Release();
}


bool C_DXWrite::Begin()
{
	if (m_pRT)				//���µ� ����Ǹ� �̻��ϴ� ���� �˻�
	{
		m_pRT->BeginDraw();
		D2D1::Matrix3x2F matWorld = D2D1::Matrix3x2F::Identity();
		m_pRT->SetTransform(matWorld);
	}
	return true;
}

bool C_DXWrite::End()
{
	m_pRT->EndDraw();
	return true;
}

bool C_DXWrite::TextDraw(RECT rt, const TCHAR* Text, D2D1::ColorF color)
{
	Begin();

	D2D_RECT_F textRt;
	textRt.left = (float)rt.left / m_fDPIScaleX;
	textRt.right = (float)rt.right / m_fDPIScaleX;
	textRt.top = (float)rt.top / m_fDPIScaleY;
	textRt.bottom = (float)rt.bottom / m_fDPIScaleY;

	m_pBlackBrush->SetColor(color);

	m_pRT->DrawText(Text, wcslen(Text), m_pTextFormat, textRt, m_pBlackBrush);

	End();
	return true;
}


bool C_DXWrite::Init()
{
	return true;
}

bool C_DXWrite::Frame()
{
	return true;
}

bool C_DXWrite::Render()
{
	return true;
}

bool C_DXWrite::Release()
{
	DiscardDeviceResources();
	DiscardDeviceIndependentResources();
	
	return true;
}


C_DXWrite::C_DXWrite()
{
}


C_DXWrite::~C_DXWrite()
{
}
