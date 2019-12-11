#include "main.h"

bool main::Init()
{
	
	m_Shape.Create(m_pd3dDevice,m_pContext,L"../../data/bitmap/map.bmp");
	m_Shape.Init();


	return true;
}

bool main::Frame()
{
	m_Shape.Frame();
	return true;
}

bool main::Render()
{

	//m_pContext->PSSetSamplers(0, 1, &m_pSamplerState);
	m_Shape.Render();
	//bool full = false;
	//m_pSwapChain->GetFullscreenState(&full, NULL);			//풀스크린 정보를 가져와서 변경
	//m_pSwapChain->SetFullscreenState(full, NULL);			//참이면 전체화면, 거짓이면 윈도우
	return true;
}

bool main::Release()
{
	m_Shape.Release();
	
	return true;
}


main::main()
{
}


main::~main()
{
}
