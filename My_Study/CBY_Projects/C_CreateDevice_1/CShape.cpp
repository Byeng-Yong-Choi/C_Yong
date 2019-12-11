#include "CShape.h"

bool CShape::Create(ID3D11Device* pDevice, ID3D11DeviceContext* pCon, const TCHAR* TexFileName)
{
	HRESULT hr=S_OK;

	m_pd3dDevice= pDevice;
	m_pContext= pCon;

	hr = CreateVertexBuffer();
	if (FAILED(hr))
	{
		return false;
	}

	hr = LoadShaderAndLayout();
	if (FAILED(hr))
	{
		return false;
	}

	hr = LoadTexture(TexFileName);
	if (FAILED(hr))
	{
		return false;
	}

	return true;
}

HRESULT CShape::CreateVertexBuffer()
{
	HRESULT hr = S_OK;
	m_VerTex.resize(6);
	m_VerTex[0].x = -1.0f; m_VerTex[0].y = 1.0f; m_VerTex[0].z = 0.0f;
	m_VerTex[1].x = 1.0f; m_VerTex[1].y = 1.0f; m_VerTex[1].z = 0.0f;
	m_VerTex[2].x = -1.0f; m_VerTex[2].y = -1.0f; m_VerTex[2].z = 0.0f;
	m_VerTex[5].x = 1.0f; m_VerTex[5].y = -1.0f; m_VerTex[5].z = 0.0f;				//정점 좌표 입력

	m_VerTex[0].r = 1.0f; m_VerTex[0].g = 0.0f; m_VerTex[0].b = 0.0f; m_VerTex[0].a = 1.0f;
	m_VerTex[1].r = 0.0f; m_VerTex[1].g = 1.0f; m_VerTex[1].b = 0.0f; m_VerTex[1].a = 1.0f;
	m_VerTex[2].r = 0.0f; m_VerTex[2].g = 0.0f; m_VerTex[2].b = 1.0f; m_VerTex[2].a = 1.0f;
	m_VerTex[5].r = 1.0f; m_VerTex[5].g = 1.0f; m_VerTex[5].b = 0.0f; m_VerTex[5].a = 1.0f;			//정점의 컬러값 입력

	m_VerTex[0].u = 0.0f;
	m_VerTex[0].v = 0.0f;
	m_VerTex[1].u = 1.0f;
	m_VerTex[1].v = 0.0f;
	m_VerTex[2].u = 0.0f;
	m_VerTex[2].v = 1.0f;
	m_VerTex[5].u = 1.0f;
	m_VerTex[5].v = 1.0f;

	m_VerTex[3] = m_VerTex[2];
	m_VerTex[4] = m_VerTex[1];

	D3D11_BUFFER_DESC bd;										//버퍼 생성의 입력 정보를 받는다
	ZeroMemory(&bd, sizeof(D3D11_BUFFER_DESC));
	bd.ByteWidth=sizeof(PCT_VERTEX)*m_VerTex.size();				//버퍼의 크기
	bd.Usage=D3D11_USAGE_DEFAULT;								//버퍼의 읽기 쓰기 방법
	bd.BindFlags=D3D11_BIND_VERTEX_BUFFER;						//버퍼의 파이프라인 해당 위치
	
	D3D11_SUBRESOURCE_DATA InitData;
	ZeroMemory(&InitData, sizeof(D3D11_SUBRESOURCE_DATA));
	InitData.pSysMem = &m_VerTex.at(0);							//초기화 데이터에 대한 포인터

	hr = m_pd3dDevice->CreateBuffer(&bd, &InitData, &m_pVertexBuffer);			//버퍼생성

	return hr;
}

HRESULT CShape::LoadShaderAndLayout()
{
	HRESULT hr = S_OK;

	ID3DBlob* pVertexCode;		//정점에 컴파일 될 정보 입력 포인터
	ID3DBlob* pPixelCode;		//픽셀에 컴파일 될 정보 입력 포인터
	
	hr = D3DX11CompileFromFile(L"VertexShader.hlsl", NULL, NULL, "VS", "vs_5_0", 0, 0,NULL, &pVertexCode, NULL,NULL);		//정점 쉐이더 컴파일
	if (FAILED(hr))
	{
		return hr;
	}
	hr=m_pd3dDevice->CreateVertexShader(pVertexCode->GetBufferPointer(), pVertexCode->GetBufferSize(), NULL, &m_pVS);	//정점 쉐이더 생성
	if (FAILED(hr))
	{
		return hr;
	}

	hr = D3DX11CompileFromFile(L"PixelShader.hlsl", NULL, NULL, "PS", "ps_5_0", 0, 0, NULL,&pPixelCode, NULL,NULL);			//픽셀 쉐이더 컴파일
	if (FAILED(hr))
	{
		return hr;
	}
	hr=m_pd3dDevice->CreatePixelShader(pPixelCode->GetBufferPointer(), pPixelCode->GetBufferSize(), NULL, &m_pPS);		//픽셀 쉐이더 생성
	if (FAILED(hr))
	{
		return hr;
	}
	
	hr = D3DX11CompileFromFile(L"PixelShader.hlsl", NULL, NULL, "PSBlend", "ps_5_0", 0, 0, NULL, &pPixelCode, NULL, NULL);			//픽셀 쉐이더 컴파일
	if (FAILED(hr))
	{
		return hr;
	}
	hr = m_pd3dDevice->CreatePixelShader(pPixelCode->GetBufferPointer(), pPixelCode->GetBufferSize(), NULL, &m_pPSBlend);		//픽셀 쉐이더 생성
	if (FAILED(hr))
	{
		return hr;
	}

	const D3D11_INPUT_ELEMENT_DESC layout[] =
	{
		{ "POINT",  0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,  D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "COLOR",  0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12,  D3D11_INPUT_PER_VERTEX_DATA, 0 },						//레이 아웃에 쉐이더의 어떤 정보를 받을지 입력
		{ "TEXT",  0, DXGI_FORMAT_R32G32_FLOAT, 0, 28,  D3D11_INPUT_PER_VERTEX_DATA, 0 }
	};

	UINT layoutCount = sizeof(layout) /sizeof(layout[0]);
	hr=m_pd3dDevice->CreateInputLayout(layout,layoutCount,pVertexCode->GetBufferPointer(),pVertexCode->GetBufferSize(),&m_pVertexLayout);	//레이 아웃 생성
	if (FAILED(hr))
	{
		return hr;
	}

	return hr;
}

HRESULT CShape::LoadTexture(const TCHAR* TexFileName)
{
	HRESULT hr = S_OK;
	hr = D3DX11CreateShaderResourceViewFromFile(m_pd3dDevice, TexFileName, NULL, NULL, &m_pSRVA, NULL);
	if (FAILED(hr))
	{
		return hr;
	}

	hr = D3DX11CreateShaderResourceViewFromFile(m_pd3dDevice, L"../../data/bitmap/vegita.bmp", NULL, NULL, &m_pSRVB, NULL);

	return hr;
}

void CShape::Convert(std::vector<PCT_VERTEX>& list)
{
	for (int i = 0; i < list.size(); i++)
	{
		list[i].x = (list[i].x / Winrt.right) * 2 - 1.0f;
		list[i].y = ((list[i].y / Winrt.bottom) * 2 - 1.0f)*(-1.0f);
		list[i].z = 0.0f;
	}
}

bool CShape::Init()
{
	HRESULT hr;
	/*D3D11_SAMPLER_DESC Samp;
	ZeroMemory(&Samp, sizeof(D3D11_SAMPLER_DESC));
	Samp.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	Samp.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	Samp.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	Samp.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;*/

	D3D11_BLEND_DESC bs;
	ZeroMemory(&bs, sizeof(D3D11_BLEND_DESC));
	
	bs.IndependentBlendEnable = TRUE;						//독립적으로 두겠다
	bs.RenderTarget[0].BlendEnable = TRUE;					//알파 연산을 하겠다 안하겠다
	
	bs.RenderTarget[0].SrcBlend =D3D11_BLEND_SRC_ALPHA;				//소스 알파
	bs.RenderTarget[0].DestBlend =D3D11_BLEND_INV_SRC_ALPHA;		//데스크 알파
	bs.RenderTarget[0].BlendOp =D3D11_BLEND_OP_ADD;					//알파 연산 방식 (+로 선언)
	
	bs.RenderTarget[0].SrcBlendAlpha =D3D11_BLEND_ONE;				//소스 알파 값
	bs.RenderTarget[0].DestBlendAlpha =D3D11_BLEND_ZERO;			//데스크 알파값
	bs.RenderTarget[0].BlendOpAlpha =D3D11_BLEND_OP_ADD;			//알파값 연산
	//SRCAlpha*1+DEST*0


	bs.RenderTarget[0].RenderTargetWriteMask =D3D11_COLOR_WRITE_ENABLE_ALL;			//색 전부

	hr = m_pd3dDevice->CreateBlendState(&bs, &m_pAlpahBlend);						//알파 블랜드의 정보를 담은 스테이트 생성
	if (FAILED(hr))
	{
		return false;
	}

	bs.RenderTarget[0].BlendEnable = FALSE;
	hr = m_pd3dDevice->CreateBlendState(&bs,&m_pAlpahBlendDisable);
	if (FAILED(hr))
	{
		return false;
	}

	return true;
}

bool CShape::Frame()
{
	return true;
}

bool CShape::Render()
{
	UINT offset = 0;
	UINT stride = sizeof(PCT_VERTEX);
	m_pContext->IASetVertexBuffers(0, 1, &m_pVertexBuffer, &stride, &offset);			//vertexbuffer를 셋팅, 정점버퍼 시작슬롯, 갯수, 주소, 배열의 주소, 오프셋 배열거리
	m_pContext->VSSetShader(m_pVS, NULL, 0);											//정점 쉐이더 셋팅
	//m_pContext->PSSetShaderResources(0, 1, &m_pSRVA);
	/*m_pContext->PSSetSamplers(0, 1,
		&m_pSamplerState);*/

	m_pContext->OMSetBlendState(
		m_pAlpahBlend, 0, -1);
	m_pContext->PSSetShaderResources(0, 1,
		&m_pSRVA);
	m_pContext->PSSetShaderResources(1, 1,
		&m_pSRVB);
	m_pContext->PSSetShader(
		m_pPSBlend, NULL, 0);

	//m_pContext->PSSetShader(m_pPS, NULL, 0);											//픽셀 쉐이더 셋팅
	m_pContext->IASetInputLayout(m_pVertexLayout);
	

	m_pContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);			//어떤식으로 그릴지 입력
	m_pContext->Draw(m_VerTex.size(), 0);												//드로우 할때 정점 몇개를 어느 정점부터 시작해서 뿌릴지 입력
	return true;
}

bool CShape::Release()
{
	m_VerTex.clear();	
	m_pd3dDevice->Release();		
	m_pContext->Release();
	m_pVertexBuffer->Release();
	m_pVertexLayout->Release();
	m_pVS->Release();
	m_pPS->Release();
	m_pPSBlend->Release();
	m_pSRVA->Release();
	m_pSRVB->Release();
	m_pSamplerState->Release();
	m_pAlpahBlend->Release();
	m_pAlpahBlendDisable->Release();

	return true;
}


CShape::CShape()
{
}


CShape::~CShape()
{
}
