#pragma once
#include "Cstd.h"
#include "CDxState.h"
#include "C_Intersection.h"

struct P_VERTEX
{
	D3DXVECTOR3 p;
};
struct PC_VERTEX
{
	D3DXVECTOR3 p;
	D3DXVECTOR4 c;
};

struct PCT_VERTEX				//���̴��� ���� ����ü
{
	D3DXVECTOR3 p;				//��ǥ
	D3DXVECTOR4 c;			//��
	D3DXVECTOR2 t;

	bool operator == (const PCT_VERTEX& v)
	{
		if (p == v.p && c == v.c && t == v.t)
		{
			return true;
		}
		return false;
	}
	PCT_VERTEX() {}
	PCT_VERTEX(D3DXVECTOR3 p, D3DXVECTOR4 c, D3DXVECTOR2 t)
	{
		this->p = p;
		this->c = c;
		this->t = t;
	}
};

struct CONDATA				//��� ������ ���� ����ü
{
	D3DXMATRIX World;
	D3DXMATRIX View;
	D3DXMATRIX Proj;
	D3DXVECTOR4 ddata;	//273/345
};

struct CRectUV
{
	D3DXVECTOR4 UV;
	RECT Rect;
};

struct CInstatnce
{
	D3DXMATRIX matWorld;
	D3DXVECTOR4 uv[4];
	D3DXVECTOR4 color;
};


class C_Model
{
public:
	CDxHelperEx m_obj;

public:
	D3DXMATRIX	m_matWorld;
	D3DXMATRIX	m_matView;
	D3DXMATRIX  m_matProj;

public:
	std::vector<PCT_VERTEX> m_VerTex;
	std::vector<DWORD> m_IndexData;				//�ε��� ������ ������
	CONDATA m_ConData;

//Splite
public:
	RECT m_Rect;
	float m_AnimTime;
	std::vector<CRectUV> m_RectList;


public:
	void SetRectAnimation(float fAnimTime, int iWidth, int iWidthSize, int iHeight, int iHeightSize);
	D3DXVECTOR4 SetUV(RECT& Rect);
//End Splite

public:
	void SetMatrix(D3DXMATRIX* world, D3DXMATRIX* view, D3DXMATRIX* proj);		//��� ����
	bool Create(ID3D11Device* pd3dDevice, ID3D11DeviceContext* Context, const TCHAR* ShaderFileName, const TCHAR* TexFileName, const CHAR* VSName = "VS", const CHAR* PSName = "PS");
	//bool Create(ID3D11Device* pd3dDevice, ID3D11DeviceContext* Context, const TCHAR* verFileName, const TCHAR* pixFileName,const TCHAR* TexFileName, const CHAR* VSName = "VS", const CHAR* PSName = "PS");
	virtual HRESULT CreateVertexData();					//���� ���� ������ ����
	virtual HRESULT CreateIndexData();					//�ε��� ���� ������ ����
	virtual void UpdateVertexData();					//���� ���� ������ ������Ʈ
	virtual HRESULT CreateVertexBuffer();				//���� ���� ����
	virtual HRESULT CreateIndexBuffer();				//�ε��� ���� ����
	virtual HRESULT CreateConstantBuffer();				//��� ���� ����

	virtual HRESULT CreateInputLayout();				//���̾ƿ� ����
	
	virtual HRESULT LoadTexture(const TCHAR* TexFileName);		//�ؽ��� �ε�
	virtual HRESULT LoadShader(const TCHAR* ShaderFileName, const CHAR* VSName = "VS", const CHAR* PSName = "PS");			//���̴� �ε�
	//virtual HRESULT LoadShader(const TCHAR* verFileName, const TCHAR* pixFileName, const CHAR* VSName = "VS", const CHAR* PSName = "PS");

	virtual void Convert(std::vector<PCT_VERTEX>& list);

public:
	virtual bool	Init();
	virtual bool	Frame();
	virtual bool	PreRender();
	virtual bool	Render();
	virtual bool	PostRender();
	virtual bool	Release();

public:
	C_Model();
	~C_Model();
};

