#include "Sample.h"



bool Sample::Init()
{
	IDXGISurface*  pSurface;
	m_pSwapChain->GetBuffer(0, __uuidof(IDXGISurface), (void**)&pSurface);
	m_Font.Set(g_hwnd, 0, 0, pSurface);
	pSurface->Release();
	return true;
}

bool Sample::Frame()
{
	m_Font.Frame();
	return true;
}

bool Sample::Render()
{

	
	m_Font.TextDraw(Winrt,L"¿ë¿ë¿ë",D2D1::ColorF(0.0f,0.0f,1.0f,1.0f));
	return true;
}

bool Sample::Release()
{
	m_Font.Release();

	return true;
}


Sample::Sample()
{
}


Sample::~Sample()
{
}
