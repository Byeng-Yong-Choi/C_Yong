#pragma once
#include "CDxHelper.h"

class CDxHelperEx
{
public:
	ID3D11Device*			m_pd3dDevice;		//����̽�
	ID3D11DeviceContext*	m_pContext;			//Context �������� �ʿ�

public:

	ID3D11Buffer* m_pVertexBuffer;				//���ؽ� ����
	ID3D11Buffer* m_pIndexBuffer;				//�ε��� ����
	ID3D11Buffer* m_pConstantBuffer;			//��� ����

	ID3D11InputLayout* m_pVertexLayout;			//���ؽ� ���۹� ���̾ƿ�
	ID3D11SamplerState*  m_pSamplerState;


	ID3D11VertexShader* m_pVS;					//���� ���̴�
	ID3D11VertexShader* m_pVSmat;					//���� ���̴�
	ID3D11PixelShader* m_pPS;					//�ȼ� ���̴�
	ID3D11PixelShader* m_pPSBlend;
	ID3D11ShaderResourceView*  m_pSRV;

	ID3DBlob* m_pVertexCode;
	ID3DBlob* m_pPixelCode;

public:
	UINT m_VertexSize;				//���� ũ��
	UINT m_Vertexnum;				//���� ����
	UINT m_Indexnum;				//�ε��� ����
	int m_StartIndex;				//��ο� �ε����� �ε��� ���� ��ȣ

public:
	void PrePender();
	void Pender();
	void PostPender();

public:
	CDxHelperEx();
	~CDxHelperEx();
};

