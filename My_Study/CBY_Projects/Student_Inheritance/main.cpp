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
void RankDataGet()													//���
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
			printf("���ϴ� �۾��� �����ϼ���. ����(1), �ε�(2), ���(3), ����(4), ����(5), ����(6), ����(7), �ʱⰪ(8), ����(99) : ");
			scanf_s("%d", &select);

			if ((select < 1 && select>8))					//��ȣ�� �Է��ϴ� ������ �ٸ� ��� �����˻�
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
		switch (select)													//select�� ���ϴ� �۾� ��ȣ�� �ް� ����
		{
		case 1:
			//Save();														//����
			break;

		case 2:
			//Load(0);														//�ε�
			break;

		case 3:
			Con.print();													//���
			break;

		case 4:															//����
		//	Con.Jung();
			break;

		case 5:															//����
			Con.in();
			break;

		case 6:															//����
			Con.sak();
			break;

		case 7:															//����
		{
			printf("�̸�(1), ����(2) �� ���ϴ� ���Ĺ� �Ѱ����� ��� ��ȣ�� �����ּ��� : ");
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

		case 99:														//����
			system("cls");
			printf("�ƹ�Ű�� ������ ����˴ϴ�.");
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