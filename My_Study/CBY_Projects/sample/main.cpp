#include "CBYCore.h"
#include "Cstd.h"

#define EFFECT_TIME 200

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
	void Effect(int i);
	void EffectRender(int effect, int choice);
	int effect=0;
	int effect2 = 0;
	int effectnum = 0;

public:
	RECT charRt1 = { 0,0,41,59 };
	RECT charRt2= { 90, 1, 0, 0 };
	RECT mapRt1 = { 0,0,1025,780 };
	RECT mapRt2 = { 0,0,0,0 };
	RECT weaponRt1 = { 0,0,8,23 };
	RECT weaponRt2 = { 276,1,0,0 };
	RECT monsterRt1 = { 0,0,66,78 };
	RECT monsterRt2 = { 48,62,0,0 };
	RECT effect1Rt1;
	RECT effect1Rt2;
	float IX;		//비트맵의 이동 좌표를 받을 변수
	float IY;
	float WX;
	float WY;
	int weaponnum=0;
	CBYNode<CBYBitMap>* Char;
	CBYNode<CBYBitMap>* Monster;
	CBYNode<CBYBitMap>* Map;
	CBYNode<CBYBitMap>* weapon;
	CBYNode<CBYBitMap>* Effect1;
	CBYNode<CBYBitMap>* Effect2;


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
	int i;
	Char = new CBYNode<CBYBitMap>;
	Map = new CBYNode<CBYBitMap>;
	Monster = new CBYNode<CBYBitMap>;
	//Bitmap.Load(L"bitmap1.bmp");			//비트맵 이미지 로드
	Char->NodeData.Load(L"bitmap1.bmp");			//비트맵 이미지 로드
	Monster->NodeData.Load(L"bitmap1.bmp");
	Map->NodeData.Load(L"map.bmp");
	IX = (float)Winrt.right/2;
	IY = (float)Winrt.bottom/2;
	monsterRt1.left = Winrt.right / 2;
	
	for (i = 0; i < 9; i++)
	{
		Effect1 = EffectNode->make();
		Effect1->NodeData.Load(L"bitmap1.bmp");
		Effect(i);
		effect1Rt1.left = monsterRt1.left + monsterRt1.right / 2;
		effect1Rt1.top = monsterRt1.top + monsterRt1.bottom / 2;
		Effect1->NodeData.rect(effect1Rt1, effect1Rt2);
		EffectLink.BackNodein(Effect1);
		//Effect2
		Effect2 = EffectNode->make();
		Effect2->NodeData.Load(L"bitmap1.bmp");
		effect1Rt1.left = (monsterRt1.left + monsterRt1.right / 2)-15;
		effect1Rt1.top = (monsterRt1.top + monsterRt1.bottom / 2)-15;
		Effect2->NodeData.rect(effect1Rt1, effect1Rt2);
		EffectLink2.BackNodein(Effect2);
	}
	charRt1.left = IX;	//데스크의 RECT (윈도우창 어디서 부터 시작해서 얼마만큼 그릴껀지의 대한 정보)
	charRt1.top = IY;
	//Bitmap.rect(charRt1, charRt2);
	Char->NodeData.rect(charRt1, charRt2);
	Monster->NodeData.rect(monsterRt1, monsterRt2);
	Map->NodeData.rect(mapRt1, mapRt2);
	return true;
}
bool Sample::Frame()
{ 
	IX += Input.X;				//키보드 입력을 받아 캐릭터가 이동할 좌표를 받는다.
	IY += Input.Y;
	if (IX <= Winrt.left)		//캐릭터가 화면 밖으로 이동하는것을 제한하는 조건문들이다.
	{
		IX = Winrt.left;
	}
	if (IX >= Winrt.right - Char->NodeData.rtdesk.right)
	{
		IX = Winrt.right - Char->NodeData.rtdesk.right;			//IX가 right좌표로 가면 화면 밖으로 나가므로 그 폭만큼 빼서 좌표를 넣으면 더 나가지 않고 딱 맞게 들어간다.
	}
	if (IY <= Winrt.top)
	{
		IY = Winrt.top;
	}
	if (IY >= Winrt.bottom - Char->NodeData.rtdesk.bottom)
	{
		IY = Winrt.bottom - Char->NodeData.rtdesk.bottom;
	}
	
	if (Input.Weapon())													//인풋으로 무기 발사인 space bar를 입력 받을 실행이 되고 미사일은 한개가 아닌 여러개가 발사 되고 출력이 될 수 있으므로
																		//연결리스트를 사용하여 여러 미사일을 발사한다.
	{
		weapon = weaponNode->make();									//무기의 노드를 하나 생성
		weapon->NodeData.Load(L"bitmap1.bmp");						//미사일 이미지 로드
		weaponRt1.left = IX + (charRt1.right / 2);						//미사일이 주인공객체의 중간 위에서 발사되게 주인공의 위치 받는중
		weapon->NodeData.weIX = weaponRt1.left;
		weaponRt1.top = IY;
		weapon->NodeData.weIY = IY;
		weapon->NodeData.rect(weaponRt1, weaponRt2);				//rect함수를 통해 무기의 비트맵 이미지에서 얼마만큼 로드해서 출력할지를 정보를 받아낸다
		weaponLink.BackNodein(weapon);
		weaponnum++;
	}
	return true;
}
bool Sample::Render()
{
	int i;
	int effectchoice;
	int num = 0;
	//Bitmap.Render(IX, IY);
	Map->NodeData.Render();
	Monster->NodeData.Render();
	Char->NodeData.Render(IX,IY);
	
	if (weaponnum > 0)
	{
		weapon = weaponLink.getHead()->m_next;
		for (i = 0; i < weaponnum; i++)
		{
			if (weapon == weaponLink.getTail())
			{
				break;
			}
			WY = g_SecondTime * 500;
			if (!weapon->NodeData.weaponRender(WY))
			{
				weapon=weaponNode->Delete(weapon);
				continue;
			}
			if (intersection(weapon->NodeData.BitMapRt, Monster->NodeData.BitMapRt))
			{
				effect = EFFECT_TIME;
				
				weapon = weaponNode->Delete(weapon);
				continue;
			}
			weapon=weapon->m_next;
		}
	}
	if (effect > 1)
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


	return true;
}
bool Sample::Release()
{
	delete Char;
	delete Map;
	delete Monster;
	delete Effect2;

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

void Sample::Effect(int i)
{
	switch (i)
	{
	case 0:
		effect1Rt1 = { 0,0,11,12 };
		effect1Rt2 = { 161,85,0,0 };
		break;
	case 1:
		effect1Rt1 = { 0,0,22,20 };
		effect1Rt2 = { 173,85,0,0 };
		break;
	case 2:
		effect1Rt1 = { 0,0,26,24 };
		effect1Rt2 = { 196,85,0,0 };
		break;
	case 3:
		effect1Rt1 = { 0,0,28,24 };
		effect1Rt2 = { 223,85,0,0 };
		break;
	case 4:
		effect1Rt1 = { 0,0,30,24 };
		effect1Rt2 = { 252,85,0,0 };
		break;
	case 5:
		effect1Rt1 = { 0,0,29,22 };
		effect1Rt2 = { 283,85,0,0 };
		break;
	case 6:
		effect1Rt1 = { 0,0,22,20 };
		effect1Rt2 = { 313,85,0,0 };
		break;
	case 7:
		effect1Rt1 = { 0,0,16,15 };
		effect1Rt2 = { 336,85,0,0 };
		break;
	case 8:
		effect1Rt1 = { 0,0,4,6 };
		effect1Rt2 = { 353,85,0,0 };
		break;
	}
}

void Sample::EffectRender(int effect,int choice)
{
	int num = 0;
	switch (choice)
	{
	case 1:
		Effect1 = EffectLink.getHead();
		if (effect > EFFECT_TIME - 16 * (++num))
		{
			for (int j = 0; j < num; j++)
			{
				Effect1 = Effect1->m_next;
			}
			Effect1->NodeData.Render();
		}
		else if (effect > EFFECT_TIME - 16 * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				Effect1 = Effect1->m_next;
			}
			Effect1->NodeData.Render();
		}
		else if (effect > EFFECT_TIME - 16 * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				Effect1 = Effect1->m_next;
			}
			Effect1->NodeData.Render();
		}
		else if (effect > EFFECT_TIME - 16 * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				Effect1 = Effect1->m_next;
			}
			Effect1->NodeData.Render();
		}
		else if (effect > EFFECT_TIME - 16 * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				Effect1 = Effect1->m_next;
			}
			Effect1->NodeData.Render();
		}
		else if (effect > EFFECT_TIME - 16 * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				Effect1 = Effect1->m_next;
			}
			Effect1->NodeData.Render();
		}
		else if (effect > EFFECT_TIME - 16 * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				Effect1 = Effect1->m_next;
			}
			Effect1->NodeData.Render();
		}
		else if (effect > EFFECT_TIME - 16 * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				Effect1 = Effect1->m_next;
			}
			Effect1->NodeData.Render();
		}
		else if (effect > EFFECT_TIME - 16 * ++num)
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
		if (effect > EFFECT_TIME - 16 * (++num))
		{
			for (int j = 0; j < num; j++)
			{
				Effect2 = Effect2->m_next;
			}
			Effect2->NodeData.Render();
		}
		else if (effect > EFFECT_TIME - 16 * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				Effect2 = Effect2->m_next;
			}
			Effect2->NodeData.Render();
		}
		else if (effect > EFFECT_TIME - 16 * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				Effect2 = Effect2->m_next;
			}
			Effect2->NodeData.Render();
		}
		else if (effect > EFFECT_TIME - 16 * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				Effect2 = Effect2->m_next;
			}
			Effect2->NodeData.Render();
		}
		else if (effect > EFFECT_TIME - 16 * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				Effect2 = Effect2->m_next;
			}
			Effect2->NodeData.Render();
		}
		else if (effect > EFFECT_TIME - 16 * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				Effect2 = Effect2->m_next;
			}
			Effect2->NodeData.Render();
		}
		else if (effect > EFFECT_TIME - 16 * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				Effect2 = Effect2->m_next;
			}
			Effect2->NodeData.Render();
		}
		else if (effect > EFFECT_TIME - 16 * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				Effect2 = Effect2->m_next;
			}
			Effect2->NodeData.Render();
		}
		else if (effect > EFFECT_TIME - 16 * ++num)
		{
			for (int j = 0; j < num; j++)
			{
				Effect2 = Effect2->m_next;
			}
			Effect2->NodeData.Render();
		}
		break;
	}
	
}