#include "C_Model.h"

void C_Model::SetMatrix(D3DXMATRIX* world, D3DXMATRIX* view, D3DXMATRIX* proj)		//행렬 셋팅
{
	if (world != nullptr)
	{
		m_matWorld = *world;
	}
	if (view != nullptr)
	{
		m_matView = *view;
	}
	if (proj != nullptr)
	{
		m_matProj = *proj;
	}

	D3DXMatrixTranspose(&m_ConData.World, &m_matWorld);
	D3DXMatrixTranspose(&m_ConData.View, &m_matView);
	D3DXMatrixTranspose(&m_ConData.Proj, &m_matProj);

	D3D11_MAPPED_SUBRESOURCE mss;
	if (SUCCEEDED(m_obj.m_pContext->Map(m_obj.m_pConstantBuffer, 0,D3D11_MAP_WRITE_DISCARD,0, &mss)))
	{
		CONDATA* pData = (CONDATA*)mss.pData;
		memcpy(pData, &m_ConData, sizeof(CONDATA));
		m_obj.m_pContext->Unmap(m_obj.m_pConstantBuffer, 0);
	}

}

bool C_Model::Create(ID3D11Device* pd3dDevice, ID3D11DeviceContext* Context, const TCHAR* ShaderFileName, const TCHAR* TexFileName, const CHAR* VSName, const CHAR* PSName)
{
	m_obj.m_pd3dDevice = pd3dDevice;
	m_obj.m_pContext = Context;

	if (FAILED(LoadShader(ShaderFileName, VSName, PSName)))
	{
		return false;
	}
	if (FAILED(CreateVertexData()))
	{
		return false;
	}
	if (FAILED(CreateIndexData()))
	{
		return false;
	}
	if (FAILED(CreateVertexBuffer()))
	{
		return false;
	}
	if (FAILED(CreateIndexBuffer()))
	{
		return false;
	}
	if (FAILED(CreateConstantBuffer()))
	{
		return false;
	}

	if (FAILED(CreateInputLayout()))
	{
		return false;
	}
	if (FAILED(LoadTexture(TexFileName)))
	{
		return false;
	}
	return true;
}



HRESULT C_Model::CreateVertexData()					//정점 버퍼 데이터 생성
{
	HRESULT hr = S_OK;

	m_obj.m_VertexSize = sizeof(PCT_VERTEX);

	m_VerTex.resize(4);
	m_VerTex[0].p = D3DXVECTOR3(-1.0f, 1.0f, 0.0f);
	m_VerTex[1].p = D3DXVECTOR3(1.0f, 1.0f, 0.0f);
	m_VerTex[2].p = D3DXVECTOR3(-1.0f, -1.0f, 0.0f);
	m_VerTex[3].p = D3DXVECTOR3(1.0f, -1.0f, 0.0f);				//정점 좌표 입력

	m_VerTex[0].c = D3DXVECTOR4(1.0f, 0.0f, 1.0f, 1.0f);
	m_VerTex[1].c = D3DXVECTOR4(0.0f, 1.0f, 0.0f, 1.0f);
	m_VerTex[2].c = D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f);
	m_VerTex[3].c = D3DXVECTOR4(1.0f, 1.0f, 0.0f, 1.0f);			//정점 컬러값 입력

	m_VerTex[0].t = D3DXVECTOR2(0.0f, 0.0f);
	m_VerTex[1].t = D3DXVECTOR2(1.0f, 0.0f);
	m_VerTex[2].t = D3DXVECTOR2(0.0f, 1.0f);
	m_VerTex[3].t = D3DXVECTOR2(1.0f, 1.0f);			//정점 텍스쳐 좌표

	return hr;
}

HRESULT C_Model::CreateIndexData()					//인덱스 버퍼 데이터 생성
{
	HRESULT hr = S_OK;

	m_IndexData.resize(6);
	m_IndexData[0] = 0;
	m_IndexData[1] = 1;
	m_IndexData[2] = 2;

	m_IndexData[3] = 2;
	m_IndexData[4] = 1;
	m_IndexData[5] = 3;

	return hr;
}

void C_Model::UpdateVertexData()
{
	m_VerTex[0].p = D3DXVECTOR3(-1.0f, 1.0f, 0.0f);
	m_VerTex[1].p = D3DXVECTOR3(1.0f, 1.0f, 0.0f);
	m_VerTex[2].p = D3DXVECTOR3(-1.0f, -1.0f, 0.0f);
	m_VerTex[3].p = D3DXVECTOR3(1.0f, -1.0f, 0.0f);				//정점 좌표 입력
}

HRESULT C_Model::CreateVertexBuffer()				//정점 버퍼 생성
{
	HRESULT hr = S_OK;

	m_obj.m_Vertexnum = m_VerTex.size();

	D3D11_BUFFER_DESC bd;										//버퍼 생성의 입력 정보를 받는다
	ZeroMemory(&bd, sizeof(D3D11_BUFFER_DESC));
	bd.ByteWidth = m_obj.m_VertexSize * m_VerTex.size();				//버퍼의 크기
	bd.Usage = D3D11_USAGE_DEFAULT;								//버퍼의 읽기 쓰기 방법
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;						//버퍼의 파이프라인 해당 위치

	D3D11_SUBRESOURCE_DATA InitData;
	ZeroMemory(&InitData, sizeof(D3D11_SUBRESOURCE_DATA));
	InitData.pSysMem = &m_VerTex.at(0);							//초기화 데이터에 대한 포인터

	hr = m_obj.m_pd3dDevice->CreateBuffer(&bd, &InitData, &m_obj.m_pVertexBuffer);			//버퍼생성

	return hr;
}

HRESULT C_Model::CreateIndexBuffer()					//인덱스 버퍼 생성
{
	HRESULT hr = S_OK;

	m_obj.m_Indexnum = m_IndexData.size();

	D3D11_BUFFER_DESC bd;										//버퍼 생성의 입력 정보를 받는다
	ZeroMemory(&bd, sizeof(D3D11_BUFFER_DESC));
	bd.ByteWidth = sizeof(DWORD)*m_IndexData.size();				//버퍼의 크기
	bd.Usage = D3D11_USAGE_DEFAULT;								//버퍼의 읽기 쓰기 방법
	bd.BindFlags = D3D11_BIND_INDEX_BUFFER;						//버퍼의 파이프라인 해당 위치 //버퍼의 용도

	D3D11_SUBRESOURCE_DATA InitData;
	ZeroMemory(&InitData, sizeof(D3D11_SUBRESOURCE_DATA));
	InitData.pSysMem = &m_IndexData.at(0);							//초기화 데이터에 대한 포인터

	hr = m_obj.m_pd3dDevice->CreateBuffer(&bd, &InitData, &m_obj.m_pIndexBuffer);			//버퍼생성

	return hr;
}

HRESULT C_Model::CreateConstantBuffer()				//상수 버퍼 생성
{
	HRESULT hr = S_OK;

	ZeroMemory(&m_ConData, sizeof(CONDATA));		//상수버퍼에 들어갈 데이터 정보 초기화
	D3DXMatrixIdentity(&m_ConData.World);
	D3DXMatrixIdentity(&m_ConData.View);
	D3DXMatrixIdentity(&m_ConData.Proj);
	m_ConData.ddata = D3DXVECTOR4(1, 1, 1, 1);

	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(D3D11_BUFFER_DESC));
	bd.ByteWidth = sizeof(CONDATA);								//버퍼의 크기
	bd.Usage = D3D11_USAGE_DYNAMIC;								//버퍼의 읽기 쓰기 방법, Usage를 DYNAMIC으로 설정을 해야 cpu가 접근 가능하다
	bd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;					//cpu가 접근하여 쓸수 있다.

	D3D11_SUBRESOURCE_DATA InitData;
	ZeroMemory(&InitData, sizeof(D3D11_SUBRESOURCE_DATA));
	InitData.pSysMem = &m_ConData;							//초기화 데이터에 대한 포인터

	hr = m_obj.m_pd3dDevice->CreateBuffer(&bd, &InitData, &m_obj.m_pConstantBuffer);			//버퍼생성

	return hr;
}


HRESULT C_Model::CreateInputLayout()					//레이아웃 생성
{
	HRESULT hr = S_OK;

	const D3D11_INPUT_ELEMENT_DESC layout[] =
	{
		{ "POINT",  0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,  D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "COLOR",  0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12,  D3D11_INPUT_PER_VERTEX_DATA, 0 },						//레이 아웃에 쉐이더의 어떤 정보를 받을지 입력
		{ "TEXT",  0, DXGI_FORMAT_R32G32_FLOAT, 0, 28,  D3D11_INPUT_PER_VERTEX_DATA, 0 }
	};

	UINT layoutCount = sizeof(layout) / sizeof(layout[0]);
	hr = m_obj.m_pd3dDevice->CreateInputLayout(layout, layoutCount, m_obj.m_pVertexCode->GetBufferPointer(), m_obj.m_pVertexCode->GetBufferSize(), &m_obj.m_pVertexLayout);	//레이 아웃 생성
	if (FAILED(hr))
	{
		return hr;
	}

	return hr;
}


HRESULT C_Model::LoadTexture(const TCHAR* TexFileName)		//텍스쳐 로드
{
	HRESULT hr = S_OK;
	if (TexFileName == NULL) return S_OK;
	hr = D3DX11CreateShaderResourceViewFromFile(m_obj.m_pd3dDevice, TexFileName, NULL, NULL, &m_obj.m_pSRV, NULL);

	return hr;
}

HRESULT C_Model::LoadShader(const TCHAR* ShaderFileName, const CHAR* VSName, const CHAR* PSName)			//쉐이더 로드
{
	HRESULT hr = S_OK;


	hr = D3DX11CompileFromFile(ShaderFileName, NULL, NULL, VSName, "vs_5_0", 0, 0, NULL, &m_obj.m_pVertexCode, NULL, NULL);		//정점 쉐이더 컴파일
	if (FAILED(hr))
	{
		return hr;
	}
	hr = m_obj.m_pd3dDevice->CreateVertexShader(m_obj.m_pVertexCode->GetBufferPointer(), m_obj.m_pVertexCode->GetBufferSize(), NULL, &m_obj.m_pVS);	//정점 쉐이더 생성
	if (FAILED(hr))
	{
		return hr;
	}

	hr = D3DX11CompileFromFile(ShaderFileName, NULL, NULL, PSName, "ps_5_0", 0, 0, NULL, &m_obj.m_pPixelCode, NULL, NULL);			//픽셀 쉐이더 컴파일
	if (FAILED(hr))
	{
		return hr;
	}
	hr = m_obj.m_pd3dDevice->CreatePixelShader(m_obj.m_pPixelCode->GetBufferPointer(), m_obj.m_pPixelCode->GetBufferSize(), NULL, &m_obj.m_pPS);		//픽셀 쉐이더 생성
	if (FAILED(hr))
	{
		return hr;
	}	

	return hr;
}


void C_Model::Convert(std::vector<PCT_VERTEX>& list)
{
	for (int i = 0; i < list.size(); i++)
	{
		PCT_VERTEX v = list[i];
		list[i].p.x = (v.p.x / Winrt.right) * 2.0f - 1.0f;
		list[i].p.y = ((v.p.y / Winrt.bottom) * 2.0f - 1.0f)*-1.0f;
		list[i].p.z = v.p.z;
	}
}

bool	C_Model::Init()
{
	return true;
}
bool	C_Model::Frame()
{
	return true;
}

bool	C_Model::PreRender()
{
	m_obj.PrePender();
	return true;
}


bool	C_Model::Render()
{
	PreRender();
	PostRender();
	return true;
}

bool	C_Model::PostRender()
{
	m_obj.PostPender();
	return true;
}

bool	C_Model::Release()
{
	return true;
}

C_Model::C_Model()
{
	D3DXMatrixIdentity(&m_matWorld);
	D3DXMatrixIdentity(&m_matView);
	D3DXMatrixIdentity(&m_matProj);
}


C_Model::~C_Model()
{
}


//Splite
void C_Model::SetRectAnimation(float AnimTime, int Width, int WidthSize, int Height, int HeightSize)
{
	m_AnimTime = AnimTime;

	m_Rect.left = Width;
	m_Rect.right = WidthSize; // 텍스쳐 가로 셋 갯수 및 크기	
	m_Rect.top = Height;
	m_Rect.bottom = HeightSize; // 텍스쳐 세로 셋 갯수 및 크기

	/*if (Width*Height <= 1)
	{
		m_fSecPerRender = AnimTime / m_iNumTexture;
		return;
	}
	else
	{
		m_fSecPerRender = AnimTime / (Width*Height);
		m_iNumTexture = Width * Height;
	}*/

	for (int iHeight = 0; iHeight < m_Rect.left; iHeight++)
	{
		for (int iWidth = 0; iWidth < m_Rect.top; iWidth++)
		{
			CRectUV  Rect;
			Rect.Rect.left = iWidth * m_Rect.right;
			Rect.Rect.right = (iWidth + 1) * m_Rect.right;
			Rect.Rect.top = iHeight * m_Rect.bottom;
			Rect.Rect.bottom = (iHeight + 1)* m_Rect.bottom;

			Rect.UV = SetUV(Rect.Rect);
			m_RectList.push_back(Rect);
		}
	}
}

D3DXVECTOR4 C_Model::SetUV(RECT& Rect)
{
	D3DXVECTOR4 UV;
	float OffSetX = 0.0f;
	if (Rect.left > 0)
	{
		OffSetX = (float)Rect.left / (float)(m_Rect.left*m_Rect.right);
	}
	float OffSetY = 0.0f;
	if (Rect.top > 0)
	{
		OffSetY = (float)Rect.top / (float)(m_Rect.top*m_Rect.bottom);
	}

	UV.x = OffSetX;
	UV.y = OffSetY;

	OffSetX = 1.0f;
	if (Rect.right > 0)
	{
		OffSetX = (float)Rect.right / (float)(m_Rect.left*m_Rect.right);
	}
	OffSetY = 1.0f;
	if (Rect.bottom > 0)
	{
		OffSetY = (float)Rect.bottom / (float)(m_Rect.top*m_Rect.bottom);
	}
	UV.z = OffSetX;
	UV.w = OffSetY;
	return UV;
}

