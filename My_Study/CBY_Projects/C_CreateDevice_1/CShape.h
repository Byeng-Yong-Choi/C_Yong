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

struct PCT_VERTEX				//���̴��� ���� ����ü
{
	float x, y, z;				//��ǥ
	float r, g, b, a;			//��
	float u, v;
};

class CShape
{
	ID3D11Device*			m_pd3dDevice;		//����̽�
	ID3D11DeviceContext*	m_pContext;			//Context �������� �ʿ�

public:
	std::vector<PCT_VERTEX> m_VerTex;
	
	ID3D11Buffer* m_pVertexBuffer;
	ID3D11InputLayout* m_pVertexLayout;			//���ؽ� ���۹� ���̾ƿ�
	ID3D11SamplerState*  m_pSamplerState;
	ID3D11BlendState* m_pAlpahBlend;
	ID3D11BlendState* m_pAlpahBlendDisable;

	ID3D11VertexShader* m_pVS;					//���� ���̴�
	ID3D11PixelShader* m_pPS;					//�ȼ� ���̴�
	ID3D11PixelShader* m_pPSBlend;
	ID3D11ShaderResourceView*  m_pSRVA;
	ID3D11ShaderResourceView*  m_pSRVB;


public:
	HRESULT CreateVertexBuffer();				//���� ����
	HRESULT LoadShaderAndLayout();					//���̴��� ���̾ƿ� ������
	HRESULT LoadTexture(const TCHAR* TexFileName);	//���ϸ��� �޾Ƽ� �ؽ��� ������ �ε��Ѵ�.
	void Convert(std::vector<PCT_VERTEX>& list);		//�츮�� �Է��� ��ũ�� ��ǥ�踦 ���� ��ǥ��� �ٲپ��� �Լ�
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

