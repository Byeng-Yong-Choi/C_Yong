#include "CBYCore.h"
#include "Cstd.h"
#include "C_Object.h"
#include "maskBitMap.h"
#include "Char.h"
#include "Effect.h"
#include "maskBitMap.h"
#include "Monster.h"
#include "Weapon.h"
#include "BackGround.h"
#include "Health.h"
#include "Splite.h"

#define EFFECT_TIME 200
#define DESTROYEFFECT_TIME 600

typedef std::vector<RECT> RTLIST;
class Sample :public CBYCore
{
public :
	 bool Init();
	 bool Frame();
	 bool Render();
	 bool Release();
	 bool intersection(RECT r1, RECT r2);
	float CenterX(RECT rt);
	float CenterY(RECT rt);
	void EffectData(int i);
	void EffectData2(int i);
	void EffectRender(int effect, int choice);
	bool effect=false;
	bool effect2 = false;
	bool DestroyEffectTime = false;
	/*int effect=0;
	int effect2 = 0;
	int DestroyEffectTime = 0;		//이펙트 발생시 시간을 받을 변수*/
	int effectnum = 0;
	int MonsterHit = 0;

public:
	RECT charRt = { 90, 1,41,59 };
	RECT mapRt = { 0,0,1025,7800 };
	RECT weaponRt = { 276,1,8,23 };
	RECT monsterRt = { 48,62,66,78 };
	RECT effectRt = { 0, };
	RECT healthRT = { 0, };
	int i;
	float m_IX;		//비트맵의 이동 좌표를 받을 변수
	float m_IY;
	float WX;
	float WY;
	float EX;
	float EY;
	int weaponnum=0;
	
public:
	maskBitMap Bitmap;
	std::vector<Effect> Effect_Object;
	std::vector<RTLIST> Effect_Object_Src;
	/*CBYLinkList<Effect> EffectLink;
	CBYLinkList<Effect> EffectLink2;
	CBYLinkList<Effect> DestroyEffectLink;
	CBYNode<Effect>* EffectNode;*/
	CBYLinkList<Weapon> weaponLink;
	CBYNode<Weapon>* weaponNode;
	Char m_Char;
	Monster m_Monster;
	BackGround m_Map;
	Weapon m_Weapon;
	Health m_Health;
	/*CBYNode<Effect>* Effect1;
	CBYNode<Effect>* Effect2;
	CBYNode<Effect>* DestroyEffect;*/


public:
	Sample();
	~Sample();

private:
	//static int num;
};

//int Sample::num = 0;
Sample::Sample()
{

}
Sample::~Sample()
{

}

bool Sample::Init()
{	
	m_IX = (float)Winrt.right / 2;
	m_IY = (float)Winrt.bottom / 2;
	
	
	m_Char.GetRECT(charRt);
	m_Monster.GetRECT(monsterRt);
	m_Map.GetRECT(mapRt);

	m_Char.SetPosition(m_IX, m_IY);
	m_Monster.SetPosition(m_IX, Winrt.top);
	m_Map.SetPosition(0, 0);
	

	m_IX = m_Monster.IX+ (monsterRt.right/2);
	m_IY = m_Monster.IY + monsterRt.bottom;

	healthRT.right = monsterRt.right;
	healthRT.bottom = 5;

	m_Health.GetRECT(healthRT);
	m_Health.SetPosition(m_IX, m_IY);

	m_Char.Init();
	m_Map.Init();
	m_Monster.Init();
	m_Health.Init();
	

	m_Char.Load(L"../../data/bitmap/bitmap1.bmp", L"../../data/bitmap/bitmap1mask.bmp");			//비트맵 이미지 로드
	m_Monster.Load(L"../../data/bitmap/bitmap1.bmp", L"../../data/bitmap/bitmap1mask.bmp");
	m_Map.Load(L"../../data/bitmap/map.bmp");
	
	Effect_Object.resize(3);
	Effect_Object_Src.resize(2);
	Effect_Object_Src[0].resize(9);
	Effect_Object_Src[1].resize(12);
	
	for (i = 0; i < 9; i++)
	{
		EffectData(i);
		Effect_Object_Src[0][i] = effectRt;
	}
		Effect_Object[0].Load(L"../../data/bitmap/bitmap1.bmp", L"../../data/bitmap/bitmap1mask.bmp");
		EX = m_Monster.IX + (m_Monster.rtsrc.right / 2);
		EY = m_Monster.IY + m_Monster.rtsrc.bottom / 2 + 15;
		Effect_Object[0].GetRECT(Effect_Object_Src[0],1.0f);
		Effect_Object[0].SetPosition(EX, EY);

		EffectData(i);
		Effect_Object[1].Load(L"../../data/bitmap/bitmap1.bmp", L"../../data/bitmap/bitmap1mask.bmp");
		EX -= 15;
		EY -= 15;
		Effect_Object[1].GetRECT(Effect_Object_Src[0],1.0f);
		Effect_Object[1].SetPosition(EX, EY);

		//Effect1 = EffectNode->make();
		//Effect1->NodeData.Init();
		//Effect1->NodeData.Load(L"../../data/bitmap/bitmap1.bmp", L"../../data/bitmap/bitmap1mask.bmp");
		//EffectData(i);
		//EX = m_Monster.IX+ (m_Monster.rtsrc.right / 2);
		//EY = m_Monster.IY+m_Monster.rtsrc.bottom/2+15;
		//Effect1->NodeData.GetRECT(effectRt);
		//Effect1->NodeData.SetPosition(EX, EY);
		//EffectLink.BackNodein(Effect1);
		////Effect2
		//Effect2 = EffectNode->make();
		//Effect2->NodeData.Load(L"../../data/bitmap/bitmap1.bmp", L"../../data/bitmap/bitmap1mask.bmp");
		//EX -= 15;
		//EY -= 15;
		//Effect2->NodeData.GetRECT(effectRt);
		//Effect2->NodeData.SetPosition(EX, EY);
		//EffectLink2.BackNodein(Effect2);
	//}
		for (i = 0; i < 12; i++)
		{
			EffectData2(i);
			Effect_Object_Src[1][i] = effectRt;
		}
		Effect_Object[2].Load(L"../../data/bitmap/bitmap1.bmp", L"../../data/bitmap/bitmap1mask.bmp");
		EX = m_Monster.IX + (m_Monster.rtsrc.right / 2);
		EY = m_Monster.IY + m_Monster.rtsrc.bottom / 2;
		Effect_Object[2].GetRECT(Effect_Object_Src[1],1.0f);
		Effect_Object[2].SetPosition(EX, EY);
		
		/*DestroyEffect = EffectNode->make();
		DestroyEffect->NodeData.Init();
		DestroyEffect->NodeData.Load(L"../../data/bitmap/bitmap1.bmp", L"../../data/bitmap/bitmap1mask.bmp");
		EffectData2(i);
		EX = m_Monster.IX + (m_Monster.rtsrc.right / 2);
		EY = m_Monster.IY + m_Monster.rtsrc.bottom / 2;
		DestroyEffect->NodeData.GetRECT(effectRt);
		DestroyEffect->NodeData.SetPosition(EX, EY);
		DestroyEffectLink.BackNodein(DestroyEffect);*/
	//}
	return true;
}
bool Sample::Frame()
{
	m_Char.Frame();
	m_Monster.Frame();
	m_Health.Frame();
	m_Health.IX = m_Monster.BitMapRt.left;
	if (m_Monster.Death==1)
	{
		MonsterHit = 0;
		m_Health.Hit = MonsterHit;
	}
	else
	{
		m_Health.Death = 0;
	}
	if (m_Weapon.Frame())													//인풋으로 무기 발사인 space bar를 입력 받을 실행이 되고 미사일은 한개가 아닌 여러개가 발사 되고 출력이 될 수 있으므로
	{																	//연결리스트를 사용하여 여러 미사일을 발사한다.
		weaponNode = weaponNode->make();									//무기의 노드를 하나 생성
		weaponNode->NodeData.Load(L"../../data/bitmap/bitmap1.bmp",L"../../data/bitmap/bitmap1mask.bmp");						//미사일 이미지 로드
		WX = m_Char.BitMapRt.left +(m_Char.rtsrc.right / 2);						//미사일이 주인공객체의 중간 위에서 발사되게 주인공의 위치 받는중
		WY = m_Char.BitMapRt.top;
		weaponNode->NodeData.GetRECT(weaponRt);				//rect함수를 통해 무기의 비트맵 이미지에서 얼마만큼 로드해서 출력할지를 정보를 받아낸다
		weaponNode->NodeData.SetPosition(WX,WY);
		weaponLink.BackNodein(weaponNode);
		weaponnum++;
	}


	EX= m_Monster.IX + (m_Monster.rtsrc.right / 2);
	EY = m_Monster.IY + m_Monster.rtsrc.bottom / 2 + 15;
	Effect_Object[0].SetPosition(EX, EY);
	
	EX -= 15;
	EY -= 15;
	Effect_Object[1].SetPosition(EX, EY);

	EX = m_Monster.IX + (m_Monster.rtsrc.right / 2);
	EY = m_Monster.IY + m_Monster.rtsrc.bottom / 2;
	Effect_Object[2].SetPosition(EX, EY);

	if (effect)
	{
		effect = Effect_Object[0].Frame();
	}
	if (effect2)
	{
		effect2 = Effect_Object[1].Frame();
	}
	if (DestroyEffectTime)
	{
		DestroyEffectTime = Effect_Object[2].Frame();
	}

	

	//Effect1 = EffectLink.getHead()->m_next;
	//Effect2 = EffectLink2.getHead()->m_next;
	//DestroyEffect= DestroyEffectLink.getHead()->m_next;
	//for (i = 0; i < 9; i++)
	//{
	//	Effect1->NodeData.IX= m_Monster.IX + (m_Monster.rtsrc.right/2);
	//	//Effect2
	//	Effect2->NodeData.IX = m_Monster.IX + (m_Monster.rtsrc.right / 2) -15;

	//	Effect1 = Effect1->m_next;
	//	Effect2 = Effect2->m_next;
	//}

	//for (i = 0; i < 12; i++)
	//{
	//	DestroyEffect->NodeData.IX = m_Monster.IX;// + (m_Monster.rtsrc.right / 4);
	//	DestroyEffect = DestroyEffect->m_next;
	//}
	return true;
}

bool Sample::Render()
{
	int num = 0;
	m_Map.Render();
	m_Monster.Render();
	m_Health.Render();
	m_Char.Render();
	
	if (weaponnum > 0)
	{
		weaponNode = weaponLink.getHead()->m_next;
		for (i = 0; i < weaponnum; i++)
		{
			if (weaponNode == weaponLink.getTail())
			{
				break;
			}
			WY = g_SecondTime * 500;
			if (weaponNode->NodeData.EndY(WY))
			{
				weaponNode->NodeData.Render();
				weaponNode=weaponNode->Delete(weaponNode);
				continue;
			}
			weaponNode->NodeData.Render();
			if (intersection(weaponNode->NodeData.BitMapRt, m_Monster.BitMapRt))
			{
				MonsterHit++;					//얼마나 적중했는지 히트수 계산
				if (MonsterHit == 5)
				{
					m_Monster.Death = 1;
					m_Health.Death = 1;
					MonsterHit = 0;
					DestroyEffectTime = DESTROYEFFECT_TIME;
				}
				m_Health.Hit = MonsterHit;
				effect = true;
				
				weaponNode = weaponNode->Delete(weaponNode);
				continue;
			}
			weaponNode=weaponNode->m_next;
		}
	}

	if (effect)
	{
		Effect_Object[0].Render();
		effectnum++;
		if (effectnum == EFFECT_TIME * 2)
		{
			effect2 = EFFECT_TIME;
			effectnum = 0;
		}
	}

	if (effect2)
	{
		Effect_Object[1].Render();
	}

	if (DestroyEffectTime)
	{
		Effect_Object[2].Render(monsterRt.right, monsterRt.bottom);
	}
	else if(!DestroyEffectTime && Effect_Object[2].endeffect)
	{
		m_Monster.Death = 2;
		Effect_Object[2].endeffect = false;
	}

	/*if (effect > 1)
	{
		EffectRender(effect,1);
		effect--;
		effectnum++;
		if (effectnum == EFFECT_TIME*2)
		{
			effect2 = EFFECT_TIME;
			effectnum = 0;
		}
	}
	
	if (effect2 > 1)
	{
		EffectRender(effect2, 2);
		effect2--;
	}
	
	if (DestroyEffectTime > 1)
	{
		EffectRender(DestroyEffectTime, 3);
		DestroyEffectTime--;
	}
	else
	{
		m_Monster.Death = 2;
	}
*/
	return true;
}
bool Sample::Release()
{
	for (int iObj = 0; iObj < Effect_Object.size(); iObj++)
	{
		Effect_Object[iObj].Release();
	}
	/*for (i = 0; i < 9; i++)
	{
		Effect1 = EffectLink.getHead()->m_next;
		Effect1->NodeData.Release();
		Effect1 = Effect1->m_next;
		
		Effect2 = EffectLink.getHead()->m_next;
		Effect2->NodeData.Release();
		Effect2 = Effect1->m_next;
	}
	for (i = 0; i < 12; i++)
	{
		DestroyEffect = DestroyEffectLink.getHead()->m_next;
		DestroyEffect->NodeData.Release();
		DestroyEffect = DestroyEffect->m_next;
	}*/

	m_Char.Release();
	m_Map.Release();
	m_Monster.Release();
	m_Health.Release();
	/*EffectLink.Nodefree();
	EffectLink2.Nodefree();
	DestroyEffectLink.Nodefree();*/
	Bitmap.Release();
	return true;
}

CBY_RUN(Sample,C_EX,C_Windows);


bool Sample::intersection(RECT r1, RECT r2)
{
	float width;			//기준거리
	float height;
	float distanceX;		//실제거리
	float distanceY;

	distanceX = abs(CenterX(r1) - CenterX(r2));
	distanceY = abs(CenterY(r1) - CenterY(r2));
	width = (((float)r1.right - (float)r1.left) / 2)+ (((float)r2.right - (float)r2.left) / 2);
	height = (((float)r1.bottom - (float)r1.top) / 2) + (((float)r2.bottom - (float)r2.top) / 2);
	
	if (width > distanceX && height > distanceY)
	{
		return true;
	}
	else
		return false;

}

float Sample::CenterX(RECT rt)
{
	float PointX = rt.left+(float)(rt.right - rt.left) / 2;

	return PointX;
}

float Sample::CenterY(RECT rt)
{
	float PointY = rt.top+(float)(rt.bottom - rt.top) / 2;

	return PointY;
}

void Sample::EffectData(int i)
{
	switch (i)
	{
	case 0:
		effectRt = { 161,85,11,12 };
		break;
	case 1:
		effectRt = { 173,85,22,20 };
		break;
	case 2:
		effectRt = { 196,85,26,24 };
		break;
	case 3:
		effectRt = { 223,85,28,24 };
		break;
	case 4:
		effectRt = { 252,85,30,24 };
		break;
	case 5:
		effectRt = { 283,85,29,22 };
		break;
	case 6:
		effectRt = { 313,85,22,20 };
		break;
	case 7:
		effectRt = { 336,85,16,15 };
		break;
	case 8:
		effectRt = { 353,85,4,6 };
		break;
	}
}

void Sample::EffectData2(int i)
{
	switch (i)
	{
	case 0:
		effectRt = { 1,142,39,40 };
		break;
	case 1:
		effectRt = { 43,142,36,41 };
		break;
	case 2:
		effectRt = { 83,142,34,41 };
		break;
	case 3:
		effectRt = { 120,142,33,44 };
		break;
	case 4:
		effectRt = { 156,142,32,45 };
		break;
	case 5:
		effectRt = { 192,142,32,41 };
		break;
	case 6:
		effectRt = { 226,142,31,37 };
		break;
	case 7:
		effectRt = { 261,142,28,35 };
		break;
	case 8:
		effectRt = { 292,142,27,31 };
		break;
	case 9:
		effectRt = { 323,142,25,25 };
		break;
	case 10:
		effectRt = { 350,142,22,23 };
		break;
	case 11:
		effectRt = { 375,142,20,17 };
		break;
	}
}

/*void Sample::EffectRender(int effect,int choice)
{
	int num = 0;
	int frameeffect = EFFECT_TIME / 9;
	int destroyframeeffect = DESTROYEFFECT_TIME/12;

	switch (choice)
	{
	case 1:
		Effect1 = EffectLink.getHead();
		if (effect > EFFECT_TIME - frameeffect * (++num))
		{
			for (int j = 0; j < num; j++)
			{
				Effect1 = Effect1->m_next;
			}
			Effect1->NodeData.Render();
		}
		else if (effect > EFFECT_TIME - frameeffect * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				Effect1 = Effect1->m_next;
			}
			Effect1->NodeData.Render();
		}
		else if (effect > EFFECT_TIME - frameeffect * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				Effect1 = Effect1->m_next;
			}
			Effect1->NodeData.Render();
		}
		else if (effect > EFFECT_TIME - frameeffect * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				Effect1 = Effect1->m_next;
			}
			Effect1->NodeData.Render();
		}
		else if (effect > EFFECT_TIME - frameeffect * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				Effect1 = Effect1->m_next;
			}
			Effect1->NodeData.Render();
		}
		else if (effect > EFFECT_TIME - frameeffect * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				Effect1 = Effect1->m_next;
			}
			Effect1->NodeData.Render();
		}
		else if (effect > EFFECT_TIME - frameeffect * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				Effect1 = Effect1->m_next;
			}
			Effect1->NodeData.Render();
		}
		else if (effect > EFFECT_TIME - frameeffect * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				Effect1 = Effect1->m_next;
			}
			Effect1->NodeData.Render();
		}
		else if (effect > EFFECT_TIME - frameeffect * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				Effect1 = Effect1->m_next;
			}
			Effect1->NodeData.Render();
		}
		break;

	case 2:
		Effect2 = EffectLink2.getHead();
		if (effect > EFFECT_TIME - frameeffect * (++num))
		{
			for (int j = 0; j < num; j++)
			{
				Effect2 = Effect2->m_next;
			}
			Effect2->NodeData.Render();
		}
		else if (effect > EFFECT_TIME - frameeffect * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				Effect2 = Effect2->m_next;
			}
			Effect2->NodeData.Render();
		}
		else if (effect > EFFECT_TIME - frameeffect * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				Effect2 = Effect2->m_next;
			}
			Effect2->NodeData.Render();
		}
		else if (effect > EFFECT_TIME - frameeffect * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				Effect2 = Effect2->m_next;
			}
			Effect2->NodeData.Render();
		}
		else if (effect > EFFECT_TIME - frameeffect * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				Effect2 = Effect2->m_next;
			}
			Effect2->NodeData.Render();
		}
		else if (effect > EFFECT_TIME - frameeffect * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				Effect2 = Effect2->m_next;
			}
			Effect2->NodeData.Render();
		}
		else if (effect > EFFECT_TIME - frameeffect * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				Effect2 = Effect2->m_next;
			}
			Effect2->NodeData.Render();
		}
		else if (effect > EFFECT_TIME - frameeffect * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				Effect2 = Effect2->m_next;
			}
			Effect2->NodeData.Render();
		}
		else if (effect > EFFECT_TIME - frameeffect * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				Effect2 = Effect2->m_next;
			}
			Effect2->NodeData.Render();
		}
		break;

	case 3:
		DestroyEffect = DestroyEffectLink.getHead();
		if (effect > DESTROYEFFECT_TIME - destroyframeeffect * (++num))
		{
			for (int j = 0; j < num; j++)
			{
				DestroyEffect = DestroyEffect->m_next;
			}
			DestroyEffect->NodeData.Render(monsterRt.right,monsterRt.bottom);
		}
		else if (effect > DESTROYEFFECT_TIME - destroyframeeffect * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				DestroyEffect = DestroyEffect->m_next;
			}
			DestroyEffect->NodeData.Render(monsterRt.right,monsterRt.bottom);
		}
		else if (effect > DESTROYEFFECT_TIME - destroyframeeffect * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				DestroyEffect = DestroyEffect->m_next;
			}
			DestroyEffect->NodeData.Render(monsterRt.right,monsterRt.bottom);
		}
		else if (effect > DESTROYEFFECT_TIME - destroyframeeffect * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				DestroyEffect = DestroyEffect->m_next;
			}
			DestroyEffect->NodeData.Render(monsterRt.right,monsterRt.bottom);
		}
		else if (effect > DESTROYEFFECT_TIME - destroyframeeffect * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				DestroyEffect = DestroyEffect->m_next;
			}
			DestroyEffect->NodeData.Render(monsterRt.right,monsterRt.bottom);
		}
		else if (effect > DESTROYEFFECT_TIME - destroyframeeffect * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				DestroyEffect = DestroyEffect->m_next;
			}
			DestroyEffect->NodeData.Render(monsterRt.right,monsterRt.bottom);
		}
		else if (effect > DESTROYEFFECT_TIME - destroyframeeffect * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				DestroyEffect = DestroyEffect->m_next;
			}
			DestroyEffect->NodeData.Render(monsterRt.right,monsterRt.bottom);
		}
		else if (effect > DESTROYEFFECT_TIME - destroyframeeffect * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				DestroyEffect = DestroyEffect->m_next;
			}
			DestroyEffect->NodeData.Render(monsterRt.right,monsterRt.bottom);
		}
		else if (effect > DESTROYEFFECT_TIME - destroyframeeffect * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				DestroyEffect = DestroyEffect->m_next;
			}
			DestroyEffect->NodeData.Render(monsterRt.right,monsterRt.bottom);
		}
		else if (effect > DESTROYEFFECT_TIME - destroyframeeffect * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				DestroyEffect = DestroyEffect->m_next;
			}
			DestroyEffect->NodeData.Render(monsterRt.right,monsterRt.bottom);
		}
		else if (effect > DESTROYEFFECT_TIME - destroyframeeffect * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				DestroyEffect = DestroyEffect->m_next;
			}
			DestroyEffect->NodeData.Render(monsterRt.right,monsterRt.bottom);
		}
		else if (effect > DESTROYEFFECT_TIME - destroyframeeffect * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				DestroyEffect = DestroyEffect->m_next;
			}
			DestroyEffect->NodeData.Render(monsterRt.right,monsterRt.bottom);
		}
		break;
	}
	
}*/