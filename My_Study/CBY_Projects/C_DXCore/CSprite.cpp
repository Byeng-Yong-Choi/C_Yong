#include "CSprite.h"

void CSprite::SetEffectLength()
{
	for (int i = 0; i < m_Sprite; i++)
	{
		m_rtList[i].uv[0].x = 0;
		m_rtList[i].uv[1].x = 1.0f;
		m_rtList[i].uv[2].x = 0;
		m_rtList[i].uv[3].x = 1.0f;
	}
}

void CSprite::SetRectUV(CRECT& rtSpriteList, int Width, int Height)
{
	m_Sprite = rtSpriteList.size();
	for (int irt = 0; irt < m_Sprite; irt++)
	{
		rtSpriteList[irt].uv[0].x = rtSpriteList[irt].RT.left / (float)Width;
		rtSpriteList[irt].uv[0].y = rtSpriteList[irt].RT.top / (float)Height;
		rtSpriteList[irt].uv[1].x = rtSpriteList[irt].RT.right / (float)Width;
		rtSpriteList[irt].uv[1].y = rtSpriteList[irt].RT.top / (float)Height;

		rtSpriteList[irt].uv[2].x = (rtSpriteList[irt].RT.left) / (float)Width;
		rtSpriteList[irt].uv[2].y = rtSpriteList[irt].RT.bottom / (float)Height;

		rtSpriteList[irt].uv[3].x = rtSpriteList[irt].RT.right / (float)Width;
		rtSpriteList[irt].uv[3].y = rtSpriteList[irt].RT.bottom / (float)Height;
	}
}

void CSprite::SetRectArray(RECT_ARRAY& rtSpriteList, int Width, int Height)
{
	m_Sprite = rtSpriteList.size();
	for (int irt = 0; irt < m_Sprite; irt++)
	{
		CRect rt;
		rt.uv[0].x = rtSpriteList[irt].left / (float)Width;
		rt.uv[0].y = rtSpriteList[irt].top / (float)Height;
		rt.uv[1].x = (rtSpriteList[irt].left + rtSpriteList[irt].right) / (float)Width;
		rt.uv[1].y = (rtSpriteList[irt].top) / (float)Height;

		rt.uv[2].x = (rtSpriteList[irt].left) / (float)Width;
		rt.uv[2].y = (rtSpriteList[irt].top + rtSpriteList[irt].bottom) / (float)Height;

		rt.uv[3].x = (rtSpriteList[irt].left + rtSpriteList[irt].right) / (float)Width;
		rt.uv[3].y = (rtSpriteList[irt].top + rtSpriteList[irt].bottom) / (float)Height;
		m_rtList.push_back(rt);
	}
}
void    CSprite::SetTextureArray(T_STR_VECTOR& rtList)
{
	int i = rtList.size();
	m_Sprite = i;
	m_srvList.resize(i);
	for (int iTex = 0; iTex < rtList.size(); iTex++)
	{
		D3DX11CreateShaderResourceViewFromFile(m_obj.m_pd3dDevice,rtList[iTex].c_str(),NULL,NULL,m_srvList[iTex].GetAddressOf(),NULL);
		
	}
}
void CSprite::SetAnimation(float fLifeTime,float fAnimTime, int Width, int WidthSize, int Height, int HeightSize)
{
	m_LifeTime = fLifeTime;
	if (WidthSize == 0 && HeightSize == 0)
	{
		if (m_srvList.size() > 0)
		{
			m_Sprite = m_srvList.size();
		}
	}
	else
	{
		
		m_rt.left = Width;
		m_rt.right = WidthSize;
		m_rt.top = Height;
		m_rt.bottom = HeightSize;
		m_Sprite = Width * Height;
		
		for (int iCol = 0; iCol < Height; iCol++)
		{
			for (int iRow = 0; iRow < Width; iRow++)
			{
				CRect rt;
				rt.RT.left = iRow;
				rt.RT.right = iRow+1;
				rt.RT.top = iCol;
				rt.RT.bottom = iCol + 1;
				/*rt.uv[0].x = iCol * fOffsetU;
				rt.uv[0].y = iRow * fOffsetV;
				rt.uv[1].x = rt.uv[0].x + fOffsetU;
				rt.uv[1].y = rt.uv[0].y;

				rt.uv[2].x = rt.uv[0].x;
				rt.uv[2].y = rt.uv[1].y + fOffsetV;

				rt.uv[3].x = rt.uv[1].x;
				rt.uv[3].y = rt.uv[2].y;*/

				m_rtList.push_back(rt);
			}
		}
		SetRectUV(m_rtList, Width, Height);
	}

	m_SecPerRender = fAnimTime;
}

bool CSprite::Frame()
{
	//if (m_LifeTime <= 0.0f) return true;
	//m_LifeTime -= g_SecondTime;
	if(Death)
	{	
		m_ChangeTime += g_SecondTime;

		if (!DeathJump)
		{
			if (m_ChangeTime >= m_SecPerRender)
			{
				m_Index++;
				m_ChangeTime = 0;
				if (m_Index == 2)
				{
					m_Index = 1;
				}
			}
		}
		else
		{
			m_Index = 3;
			if (m_ChangeTime >= m_SecPerRender)
			{
				m_Index++;
				m_ChangeTime = 0;
				if (m_Index > m_Sprite - 1)
				{
					m_Index= m_Sprite-1;
				}
			}
			End = true;
		}
	}	
	else	
	{
		m_ChangeTime += g_SecondTime;
		Attack = false;
		if (m_Index == m_Sprite - 2)
		{
			Attack = true;
		}

		if (m_ChangeTime >= m_SecPerRender)
		{
			m_Index++;
			m_ChangeTime = 0;
			if (m_Index >= m_Sprite - 1)
			{
				if (Skill || Jump)
				{
					m_Index = m_Sprite - 2;
				}
				else
				{
					m_Index = 0;
				}

				Attack = true;
				End = true;
			}
		}
	}

	//m_ConData.ddata.x = m_ChangeTime / m_SecPerRender;
	return true;
}

bool CSprite::PostRender()
{
	//if (m_LifeTime <= 0.0f) return true;
	if (m_srvList.size() > 0)
	{
		m_obj.m_pContext->PSSetShaderResources(0, 1, m_srvList[m_Index].GetAddressOf());
		//m_obj.m_pContext->PSSetShaderResources(1, 1, m_srvList[m_Index + 1].GetAddressOf());
	}
	else
	{
		//m_obj.m_pContext->PSSetShaderResources(1, 1, m_pMaskSRV.GetAddressOf());

		m_VerTex[0].t = m_rtList[m_Index].uv[0];
		m_VerTex[1].t = m_rtList[m_Index].uv[1];
		m_VerTex[2].t = m_rtList[m_Index].uv[2];
		m_VerTex[3].t = m_rtList[m_Index].uv[3];
		m_obj.m_pContext->UpdateSubresource(m_obj.m_pVertexBuffer, 0 , nullptr, &m_VerTex.at(0), 0, 0);
	}
	m_obj.PostPender();
	return true;
}
CSprite::CSprite()
{
	m_Index = 0;
	m_ChangeTime = 0.0f;
	m_LifeTime = 10.0f;
	m_SecPerRender = 0.1f;
	End = false;
	Jump = false;
	Attack = false;
	Skill = false;
	Death = false;
	DeathJump = false;
}


CSprite::~CSprite()
{
}

void CSprite::UpdateVertexData(std::vector<PCT_VERTEX>& list)
{
	int size = list.size();
	m_VerTex.clear();
	m_VerTex.resize(size);
	
	for (int i = 0; i < size; i++)
	{
		m_VerTex[i] = list[i];
	}


	m_obj.m_pContext->UpdateSubresource(m_obj.m_pVertexBuffer, 0, nullptr, &m_VerTex.at(0), 0, 0);
}