#include "CDxHelperEx.h"

void CDxHelperEx::PrePender()
{
	UINT offset = 0;
	UINT stride = m_VertexSize;
	m_pContext->IASetVertexBuffers(0, 1, &m_pVertexBuffer, &stride, &offset);			//vertexbuffer�� ����, �������� ���۽���, ����, �ּ�, �迭�� �ּ�, ������ �迭�Ÿ�
	m_pContext->IASetIndexBuffer(m_pIndexBuffer, DXGI_FORMAT_R32_UINT, 0);			//�ε��� ���� ���� �ε��� ���۴� ���� ���۸� �ѱ�°� �ƴ϶� ����s�� �ƴϰ� �ּҸ� ���� �ʿ䵵 ����


	m_pContext->VSSetShader(m_pVS, NULL, 0);
	m_pContext->PSSetShader(m_pPS, NULL, 0);

	m_pContext->VSSetConstantBuffers(0, 1, &m_pConstantBuffer);
	m_pContext->IASetInputLayout(m_pVertexLayout);

	//m_pContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);			//������� �׸��� �Է�

	m_pContext->PSSetShaderResources(0, 1, &m_pSRV);

}

void CDxHelperEx::Pender()
{
	PrePender();
	PostPender();
}

void CDxHelperEx::PostPender()
{
	if (m_Indexnum > 0)
	{
		m_pContext->DrawIndexed(m_Indexnum, m_StartIndex, 0);									//�ε��� ���۷� �׸����� �ε��� ������ �ε��� ������ �����ּ�, ���ؽ� ���� ���� �ָ� �ȴ�.
	}
	else
	{
		m_pContext->Draw(m_Vertexnum, 0);
	}
}


CDxHelperEx::CDxHelperEx()
{
	m_StartIndex = 0;
	m_VertexSize = 0;
	m_Vertexnum = 0;
	m_Indexnum = 0;
	m_pVertexBuffer = nullptr;
	m_pIndexBuffer = nullptr;
	m_pVertexLayout = nullptr;
	m_pConstantBuffer = nullptr;
	m_pVS = nullptr;
	m_pPS = nullptr;
	m_pSRV = nullptr;
	m_pVertexCode = nullptr;
	m_pPixelCode = nullptr;
}


CDxHelperEx::~CDxHelperEx()
{
	if (m_pVertexBuffer) m_pVertexBuffer->Release();
	if (m_pIndexBuffer)m_pIndexBuffer->Release();
	if (m_pVertexLayout)m_pVertexLayout->Release();
	if (m_pConstantBuffer)m_pConstantBuffer->Release();
	if (m_pVS)m_pVS->Release();
	if (m_pPS)m_pPS->Release();
	if (m_pSRV)m_pSRV->Release();
	if (m_pVertexCode)m_pVertexCode->Release();
	if (m_pPixelCode)m_pPixelCode->Release();
}
