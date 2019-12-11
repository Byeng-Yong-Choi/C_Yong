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
	m_VerTex[5].x = 1.0f; m_VerTex[5].y = -1.0f; m_VerTex[5].z = 0.0f;				//���� ��ǥ �Է�

	m_VerTex[0].r = 1.0f; m_VerTex[0].g = 0.0f; m_VerTex[0].b = 0.0f; m_VerTex[0].a = 1.0f;
	m_VerTex[1].r = 0.0f; m_VerTex[1].g = 1.0f; m_VerTex[1].b = 0.0f; m_VerTex[1].a = 1.0f;
	m_VerTex[2].r = 0.0f; m_VerTex[2].g = 0.0f; m_VerTex[2].b = 1.0f; m_VerTex[2].a = 1.0f;
	m_VerTex[5].r = 1.0f; m_VerTex[5].g = 1.0f; m_VerTex[5].b = 0.0f; m_VerTex[5].a = 1.0f;			//������ �÷��� �Է�

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

	D3D11_BUFFER_DESC bd;										//���� ������ �Է� ������ �޴´�
	ZeroMemory(&bd, sizeof(D3D11_BUFFER_DESC));
	bd.ByteWidth=sizeof(PCT_VERTEX)*m_VerTex.size();				//������ ũ��
	bd.Usage=D3D11_USAGE_DEFAULT;								//������ �б� ���� ���
	bd.BindFlags=D3D11_BIND_VERTEX_BUFFER;						//������ ���������� �ش� ��ġ
	
	D3D11_SUBRESOURCE_DATA InitData;
	ZeroMemory(&InitData, sizeof(D3D11_SUBRESOURCE_DATA));
	InitData.pSysMem = &m_VerTex.at(0);							//�ʱ�ȭ �����Ϳ� ���� ������

	hr = m_pd3dDevice->CreateBuffer(&bd, &InitData, &m_pVertexBuffer);			//���ۻ���

	return hr;
}

HRESULT CShape::LoadShaderAndLayout()
{
	HRESULT hr = S_OK;

	ID3DBlob* pVertexCode;		//������ ������ �� ���� �Է� ������
	ID3DBlob* pPixelCode;		//�ȼ��� ������ �� ���� �Է� ������
	
	hr = D3DX11CompileFromFile(L"VertexShader.hlsl", NULL, NULL, "VS", "vs_5_0", 0, 0,NULL, &pVertexCode, NULL,NULL);		//���� ���̴� ������
	if (FAILED(hr))
	{
		return hr;
	}
	hr=m_pd3dDevice->CreateVertexShader(pVertexCode->GetBufferPointer(), pVertexCode->GetBufferSize(), NULL, &m_pVS);	//���� ���̴� ����
	if (FAILED(hr))
	{
		return hr;
	}

	hr = D3DX11CompileFromFile(L"PixelShader.hlsl", NULL, NULL, "PS", "ps_5_0", 0, 0, NULL,&pPixelCode, NULL,NULL);			//�ȼ� ���̴� ������
	if (FAILED(hr))
	{
		return hr;
	}
	hr=m_pd3dDevice->CreatePixelShader(pPixelCode->GetBufferPointer(), pPixelCode->GetBufferSize(), NULL, &m_pPS);		//�ȼ� ���̴� ����
	if (FAILED(hr))
	{
		return hr;
	}
	
	hr = D3DX11CompileFromFile(L"PixelShader.hlsl", NULL, NULL, "PSBlend", "ps_5_0", 0, 0, NULL, &pPixelCode, NULL, NULL);			//�ȼ� ���̴� ������
	if (FAILED(hr))
	{
		return hr;
	}
	hr = m_pd3dDevice->CreatePixelShader(pPixelCode->GetBufferPointer(), pPixelCode->GetBufferSize(), NULL, &m_pPSBlend);		//�ȼ� ���̴� ����
	if (FAILED(hr))
	{
		return hr;
	}

	const D3D11_INPUT_ELEMENT_DESC layout[] =
	{
		{ "POINT",  0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,  D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "COLOR",  0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12,  D3D11_INPUT_PER_VERTEX_DATA, 0 },						//���� �ƿ��� ���̴��� � ������ ������ �Է�
		{ "TEXT",  0, DXGI_FORMAT_R32G32_FLOAT, 0, 28,  D3D11_INPUT_PER_VERTEX_DATA, 0 }
	};

	UINT layoutCount = sizeof(layout) /sizeof(layout[0]);
	hr=m_pd3dDevice->CreateInputLayout(layout,layoutCount,pVertexCode->GetBufferPointer(),pVertexCode->GetBufferSize(),&m_pVertexLayout);	//���� �ƿ� ����
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
	
	bs.IndependentBlendEnable = TRUE;						//���������� �ΰڴ�
	bs.RenderTarget[0].BlendEnable = TRUE;					//���� ������ �ϰڴ� ���ϰڴ�
	
	bs.RenderTarget[0].SrcBlend =D3D11_BLEND_SRC_ALPHA;				//�ҽ� ����
	bs.RenderTarget[0].DestBlend =D3D11_BLEND_INV_SRC_ALPHA;		//����ũ ����
	bs.RenderTarget[0].BlendOp =D3D11_BLEND_OP_ADD;					//���� ���� ��� (+�� ����)
	
	bs.RenderTarget[0].SrcBlendAlpha =D3D11_BLEND_ONE;				//�ҽ� ���� ��
	bs.RenderTarget[0].DestBlendAlpha =D3D11_BLEND_ZERO;			//����ũ ���İ�
	bs.RenderTarget[0].BlendOpAlpha =D3D11_BLEND_OP_ADD;			//���İ� ����
	//SRCAlpha*1+DEST*0


	bs.RenderTarget[0].RenderTargetWriteMask =D3D11_COLOR_WRITE_ENABLE_ALL;			//�� ����

	hr = m_pd3dDevice->CreateBlendState(&bs, &m_pAlpahBlend);						//���� ������ ������ ���� ������Ʈ ����
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
	m_pContext->IASetVertexBuffers(0, 1, &m_pVertexBuffer, &stride, &offset);			//vertexbuffer�� ����, �������� ���۽���, ����, �ּ�, �迭�� �ּ�, ������ �迭�Ÿ�
	m_pContext->VSSetShader(m_pVS, NULL, 0);											//���� ���̴� ����
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

	//m_pContext->PSSetShader(m_pPS, NULL, 0);											//�ȼ� ���̴� ����
	m_pContext->IASetInputLayout(m_pVertexLayout);
	

	m_pContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);			//������� �׸��� �Է�
	m_pContext->Draw(m_VerTex.size(), 0);												//��ο� �Ҷ� ���� ��� ��� �������� �����ؼ� �Ѹ��� �Է�
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
