#include "Control.cpp"
#include "HighResult.h"
#include "UnivResult.h"
#include "err.h"
#define MAX_STUDENT 10
#define Univ
//#undef Univ

#ifdef Univ
#define CHOICE UnivResult

#else
#define CHOICE HighResult
void RankDataGet()													//고등
{
	StuNode<HighResult>* a = Head->m_next;
	StuNode<HighResult>* b;
	int i, j;

	for (i = 1; i <= MAX_STUDENT; i++)
	{
		a = Head->m_next;
		b = a;
		for (j = 0; j < MAX_STUDENT; j++)
		{
			while (a->studentNode.Rank != 0)
			{
				a = a->m_next;
			}
			b = b->m_next;
			if (b == Tail)
			{
				break;
			}
			if (b->studentNode.Rank != 0)
			{
				continue;
			}
			a = a->studentNode.Sum > b->studentNode.Sum ? a : b;
		}
		a->studentNode.GetRank(i);
	}
}

#endif

Control<CHOICE> Con;
LinkList<CHOICE> Link;
StuNode<CHOICE>* Head = Link.getHead();
StuNode<CHOICE>* Tail = Link.getTail();
void one();

int main()
{
	int select;
	int bun;

	one();

	while (1)
	{
		try {
			printf("원하는 작업을 선택하세요. 저장(1), 로드(2), 출력(3), 수정(4), 삽입(5), 삭제(6), 정렬(7), 초기값(8), 종료(99) : ");
			scanf_s("%d", &select);

			if ((select < 1 && select>8))					//번호를 입력하는 범위와 다를 경우 오류검사
				throw err(0);
			else if (select == 85)
				throw err(1);
			else if (select != 99)
				throw err(0);
		}

		catch (err a)
		{
			a.WroongChoice();
		}
		switch (select)													//select에 원하는 작업 번호를 받고 실행
		{
		case 1:
			//Save();														//저장
			break;

		case 2:
			//Load(0);														//로드
			break;

		case 3:
			Con.print();													//출력
			break;

		case 4:															//수정
		//	Con.Jung();
			break;

		case 5:															//삽입
			Con.in();
			break;

		case 6:															//삭제
			Con.sak();
			break;

		case 7:															//정렬
		{
			printf("이름(1), 총점(2) 중 원하는 정렬법 한가지를 골라 번호를 적어주세요 : ");
			scanf_s("%d", &bun);
			switch (bun)
			{
			case 1:
				//	Name();
				break;

			case 2:
				//	Num();
				break;
			}
			break;
		}

		case 8:
			//Load(1);
			break;

		case 99:														//종료
			system("cls");
			printf("아무키나 누르면 종료됩니다.");
			_getch();
			Link.Nodefree();
			return 0;
		}
	}
}

void one()
{
	StuNode<CHOICE>* Node=Head->m_next;
	int i;

	for (i = 0; i < MAX_STUDENT; i++)
	{
		Node->make(Tail);
	}
}