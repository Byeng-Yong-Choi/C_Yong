#pragma once
#include "Cstd.h"

struct P_VERTEX
{
	float x, y, z;
};
struct PC_VERTEX
{
	float x, y, z;
	float r, g, b, a;
};

struct PCT_VERTEX				//쉐이더의 정보 구조체
{
	float x, y, z;				//좌표
	float r, g, b, a;			//색
	float u, v;
};

class CShape
{
	ID3D11Device*			m_pd3dDevice;		//디바이스
	ID3D11DeviceContext*	m_pContext;			//Context 랜더링에 필요

public:
	std::vector<PCT_VERTEX> m_VerTex;
	
	ID3D11Buffer* m_pVertexBuffer;
	ID3D11InputLayout* m_pVertexLayout;			//버텍스 버퍼및 레이아웃
	ID3D11SamplerState*  m_pSamplerState;
	ID3D11BlendState* m_pAlpahBlend;
	ID3D11BlendState* m_pAlpahBlendDisable;

	ID3D11VertexShader* m_pVS;					//정적 쉐이더
	ID3D11PixelShader* m_pPS;					//픽셀 쉐이더
	ID3D11PixelShader* m_pPSBlend;
	ID3D11ShaderResourceView*  m_pSRVA;
	ID3D11ShaderResourceView*  m_pSRVB;


public:
	HRESULT CreateVertexBuffer();				//버퍼 생성
	HRESULT LoadShaderAndLayout();					//쉐이더와 레이아웃 컴파일
	HRESULT LoadTexture(const TCHAR* TexFileName);	//파일명을 받아서 텍스쳐 파일을 로드한다.
	void Convert(std::vector<PCT_VERTEX>& list);		//우리가 입력한 스크린 좌표계를 직각 좌표계로 바꾸어줄 함수
	bool Create(ID3D11Device* pDevice, ID3D11DeviceContext* pCon, const TCHAR* TexFileName);

public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();

public:
	CShape();
	~CShape();
};

