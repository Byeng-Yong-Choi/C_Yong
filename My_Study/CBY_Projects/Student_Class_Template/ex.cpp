#include "Control.cpp"
#include "student.h"



//void Allmake(int a);		//��� a����ŭ ����
void print();
void one();					//�ʱⰪ
//void Save();				//����
//void Load(int a);			//�ҷ�����
//void AllDelete();			//��� ��� ����
//void Name();				//�̸��� ����
//void Num();					//������ ����
//StuNode<student>* reswap(int a);				//����� �ּҰ� ��ȯ�� ���� ����Լ��� �ּ� ���ߴ� �뵵
//StuNode<student>* make();				//��� ���� �����

LinkList<student> Link;		//��ũ����Ʈ ȣ��
StuNode<student>* Head=Link.getHead();
StuNode<student>* Tail=Link.getTail();
Control<student> Con;		//��Ʈ�� Ŭ���� ȣ��

int main()
{
	int select;
	int bun;
	StuNode<student> one_1;

	one();

	while (1)
	{
		printf("���ϴ� �۾��� �����ϼ���. ����(1), �ε�(2), ���(3), ����(4), ����(5), ����(6), ����(7), �ʱⰪ(8), ����(99) : ");
		scanf_s("%d", &select);

		if ((select < 1 || select>8) && (select != 99))					//��ȣ�� �Է��ϴ� ������ �ٸ� ��� �����˻�
		{
			printf("�߸� �����ϼ̽��ϴ�. �ٽ� ����ּ���\n");
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
			print();													//���
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
	StuNode<student> cho;
	cho.oneone(Tail);
	//int i;
//	FILE* pa_one;
	/*fopen_s(&pa_one, "student.txt", "w");											//�ʱⰪ�� �ҷ����� ���� �����͸� ������ ���� ����
	StuNode<student>* cho = Head->m_next;
	for (i = 0; i < MAX_STUDENT; i++)
	{
		fprintf(pa_one, "%d %s %d %d %d %d %.3lf\n", cho->stuNode->num, cho.stuNode->name, cho.stuNode->kuk, cho.stuNode->eng, cho.stuNode->su, cho.stuNode->sum, cho.stuNode->avg);
		//fwrite(cho, sizeof(stu), 1, pa_one);	//�ʱⰪ ����
		cho = cho->m_next;
	}
	/*copy->num = 15;
	printf("%d�� �̸�:%s, ����:%d,����:%d,����:%d, ����:%d, ��� :%.3lf \n", copy->num, copy->name, copy->kuk, copy->eng, copy->su, copy->sum, copy->avg);
	printf("%d�� �̸�:%s, ����:%d,����:%d,����:%d, ����:%d, ��� :%.3lf \n", copy.num, copy.name, copy.kuk, copy.eng, copy.su, copy.sum, copy.avg);
	fclose(pa_one);*/
	print();
}

void print()
{
	StuNode<student>* Node = Head->m_next;
	student out;
	//T sum;

	int i;
	printf("========================================================================================================================\n");
	printf("\t\t\t\t\t\t���� ���� ���α׷�\n\n");
	printf("========================================================================================================================\n");
	printf("\t\t\t\t��ȣ \t �̸� \t ���� \t ���� \t ���� \t ����\t ���\n");
	for (i = 1; i <= Link.NodeNumber(); i++)
	{
		out=Node->ShowData();
		out.Show();
		Node = Node->m_next;
	}
}
//
//void Save()																			//���� �����ϱ�
//{
//	StuNode<student>* Node;
//	Node = Link_Head->m_next;
//	int size;
//	char fi[30];
//	printf("�����ϱ� ����ϴ� ���ϸ��� �����ּ��� : ");								//������ ���� �Է¹޾� fopen�Լ��� �־� ���ϴ� ������ ����
//	scanf_s("%s", fi, 30);
//
//	size = strcmp(fi, "student.txt");
//	while (size == 0)																	//�ʱⰪ�� �־��� ���Ͽ� ��ġ���� Ȯ��
//	{
//		printf("�ߺ� �Ǿ����ϴ� �ٸ� ���ϸ��� �����ּ��� : ");
//		scanf_s("%s", fi, 30);
//		size = strcmp(fi, "student.txt");
//	}
//
//	FILE* pa;
//	fopen_s(&pa, fi, "w");															//������ ���� �Է¹޾� fopen�Լ��� �־� ���ϴ� ������ ����
//	for (int i = 0; i < NodeNumber(); i++)
//	{
//		if (Node == Link_Tail)
//		{
//			break;
//		}
//		fprintf(pa, "%d %s %d %d %d %d %.3lf\n", Node->num, Node->name, Node->kuk, Node->eng, Node->su, Node->sum, Node->avg);
//		Node = Node->m_next;
//	}
//	/*fopen_s(&pa, fi, "wb");
//	for (int i = 0; i < MAX_STUDENT; i++)
//	{
//		fwrite(Node, sizeof(stu), 1, pa);
//		Node = Node->m_next;
//		if (Node == Link_Tail)
//		{
//			break;
//		}
//	}*/
//	fclose(pa);
//}	   //����
//
//void Load(int a)																			//����� ���� �ҷ�����
//{
//	//system("cls");
//	int err;
//	unsigned int er = 0;
//	AllDelete();
//	StuNode<student>* Node = make();
//
//	switch (a)
//	{
//	case 0:																				//���ϴ� ���ϸ��� �Է��Ͽ� �ҷ�����
//	{
//		char fi2[30];
//		printf("�ҷ����� �ٶ�� ���������� �����ּ��� : ");								//������ ���� �Է¹޾� fopen�Լ��� �־� ���ϴ� ������ �ҷ��´�.
//		scanf_s("%s", fi2, 30);
//		FILE* pas;
//		fopen_s(&pas, fi2, "r");
//
//		//fscaf ���
//		while (1)
//		{
//			if (Node == Link_Tail)
//			{
//				Node = make();
//				er = 1;										//0�̸� ���� 1�̸� ���� �ٴٶ��ٴ� ��
//			}
//			err = fscanf_s(pas, "%d %s %d %d %d %d %lf\n", &Node->num, Node->name, 5,&Node->kuk, &Node->eng, &Node->su, &Node->sum, &Node->avg);
//			if (err == EOF && er)
//			{
//				Delete(Node);
//				break;
//			}
//			else
//			{
//				Node = Node->m_next;
//			}
//		}														//��带 �ϳ� �ϳ� ���� ����
//		/*while(1)				//fread ���
//		{													//�ݺ� Ƚ���� �ѹ��� �ϸ� ���ϳ� �ݺ������� ���� ���Ҵ�.
//			err=fread(Node, sizeof(stu), 1, pas);
//			if (err == NULL)
//			{
//				Link_End->m_next = Link_Tail;		//�̹� �ε������� �������
//				break;
//			}
//			Link_End = Node;
//			Node = Node->m_next;
//		}*/
//
//		fclose(pas);
//		print();
//	}break;
//
//	case 1:																				//��ó�� �ʱⰪ�� ������ ������ �ҷ�����
//	{
//		FILE* pas_1;
//
//		fopen_s(&pas_1, "student.txt", "r");
//		while (1)
//		{
//			if (Node == Link_Tail)
//			{
//				Node = make();
//				er = 1;										//0�̸� ���� 1�̸� ���� �ٴٶ��ٴ� ��
//			}
//			err = fscanf_s(pas_1, "%d %s %d %d %d %d %lf\n", &Node->num, Node->name, 5, &Node->kuk, &Node->eng, &Node->su, &Node->sum, &Node->avg);
//			if (err == EOF && er)
//			{
//				Delete(Node);
//				break;
//			}
//			else
//			{
//				Node = Node->m_next;
//			}
//		}
//
//		/*for (int i = 0; i < MAX_STUDENT; i++)				//fscaf ���
//		{
//			if (Node == Link_Tail)
//			{
//				Node = make();
//				er = 1;										//0�̸� ���� 1�̸� ���� �ٴٶ��ٴ� ��
//			}
//			err = fread(Node, sizeof(stu), 1, pas_1);
//			if (err < sizeof(stu) && er)
//			{
//				Delete(Node);
//				break;
//			}
//
//			else
//			{
//				Node = Node->m_next;
//			}
//		}*/
//		fclose(pas_1);
//		print();
//	}break;
//	}
//}
//
//
//
//void sak()																	//������ �����ϴ� �Լ�
//{
//	StuNode<student>* Node = Link_Head->m_next;
//	int sun = 0;
//	int num;
//
//	printf("������ ��ȣ�� ����ּ���: ");
//	scanf_s("%d", &sun);
//	/*while (1 > sun || NodeNumber() < sun)												//�߸��� ��ȣ�� �Է��ߴ��� Ȯ��
//	{
//		printf("������ ��ȣ�� 1~%d ���� �Դϴ�. �ٽ� 1~%d������ ��ȣ�� ����ּ��� : ", NodeNumber(), NodeNumber());
//		scanf_s("%d", &sun);
//	}*/
//	num = Find(sun);
//	if (num == 0)
//	{
//		printf("�´� ��ȣ�� �����ϴ�.\n");
//	}
//	for (int i = 1; i < num; i++)
//	{
//		Node = Node->m_next;
//	}
//
//	Delete(Node);
//
//}			//����
//
//void Name()																	// �̸����� �����ϴ� �Լ�
//{
//	int se;				//���̽��� ������ ���� �Է¹ޱ� ���� ���� ����
//	int cu;				//���ڿ� �񱳿� ���� ����
//	int i, j;			//�ݺ����� ���� ����
//	int NodeNum;
//	StuNode<student>* Node = Link_Head->m_next;
//	StuNode<student>* NodeComparison = Node->m_next;	//���� ���ϱ� ���� ���� ����� ���� ��带 �����Ѵ�
//	StuNode<student> sw;
//
//
//	printf("������ �̸��� ��������(1), ��������(2) �������ּ���(�̸��� ������� ����,����,���� ������ �����մϴ�) : ");
//	scanf_s("%d", &se);
//
//	NodeNum = NodeNumber();			//��� ������ �����ϴ� �Լ��� �̿��Ͽ� ���� ������ ����
//
//	for (i = 0; i < NodeNum; i++)
//	{
//
//		for (j = i; j < NodeNum; j++)
//		{
//			if (NodeComparison != Link_Tail)
//			{
//				cu = strcmp(Node->name, NodeComparison->name);		//�̸��� ���Ͽ� ���� �ڿ� ������ 1�� ��ȯ�޾� �����Լ��� ������ ��ȯ
//
//
//				switch (se)																//������ �Է¹޾� ���������� ���� ���������� ���� ����
//				{
//
//				case 1:														//��������
//				{
//					if (cu == 1)
//					{
//						sw.swap(*Node, *NodeComparison);
//					}
//					else if (cu == 0)											//�̸��� ���� ��� �������� �������� ���ϴ� ���ǹ�
//					{
//						if (Node->kuk > NodeComparison->kuk)
//						{
//							sw.swap(*Node, *NodeComparison);
//						}
//						else if (Node->kuk = NodeComparison->kuk)
//						{
//							if (Node->eng > NodeComparison->eng)
//							{
//								sw.swap(*Node, *NodeComparison);
//							}
//							else if (Node->eng = NodeComparison->eng)
//							{
//								if ((Node->su > NodeComparison->su))
//								{
//									sw.swap(*Node, *NodeComparison);
//								}
//							}
//						}
//					}
//					break;
//				}
//
//				case 2:														//��������
//				{
//					if (cu == -1)
//					{
//						sw.swap(*Node, *NodeComparison);
//					}
//					else if (cu == 0)											//�̸��� ���� ��� �������� �������� ���ϴ� ���ǹ�
//					{
//						if (Node->kuk < NodeComparison->kuk)
//						{
//							sw.swap(*Node, *NodeComparison);
//
//						}
//						else if (Node->kuk = NodeComparison->kuk)
//						{
//							if (Node->eng < NodeComparison->eng)
//							{
//								sw.swap(*Node, *NodeComparison);
//							}
//							else if (Node->eng = NodeComparison->eng)
//							{
//								if ((Node->su < NodeComparison->su))
//								{
//									sw.swap(*Node, *NodeComparison);
//								}
//							}
//						}
//					}
//					break;
//				}
//				}
//
//				if (i == NodeNum - 2)
//				{
//					break;
//				}
//
//				NodeComparison = NodeComparison->m_next;
//			}
//
//			else
//				break;
//		}
//		if (Node->m_next != Link_Tail)
//		{
//			Node = Node->m_next;
//			NodeComparison = Node->m_next;			//NodeComparison ������ Node �����ſ� ���ڿ��� ���ؾ� �ϹǷ� ���� ������ ����Ű�� �Ѵ�
//		}
//		else
//			break;
//
//
//	}
//}
//
//void Num()																			//�������� �����ϴ� �Լ�
//{
//	int se;
//	int cu;
//	int NodeNum;
//	StuNode<student>* Node = Link_Head->m_next;
//	StuNode<student>* NodeComparison = Node->m_next;
//	StuNode<student> sw;
//
//
//	NodeNum = NodeNumber();			//��� ������ �����ϴ� �Լ��� �̿��Ͽ� ���� ������ ����
//
//	printf("������ ������ ��������(1), ��������(2) �������ּ���(������ ������� �̸������� �����մϴ�) : ");
//	scanf_s("%d", &se);
//
//	/*for (int i = 0; i < NodeNum; i++)
//	{
//		for (int j = i; j < NodeNum; j++)
//		{
//			if (NodeComparison != Link_Tail)
//			{
//				Node = reswap(i);
//				NodeComparison = reswap(j);
//				cu = strcmp(Node->name, NodeComparison->name);								//������ ������� �̸����� ���ϱ����� ����ϴ� ��
//				switch (se)																//������ �Է¹޾� ���������� ���� ���������� ���� ����
//				{
//				case 1:																	//��������
//				{
//					if (Node->sum > NodeComparison->sum)
//					{
//						swap(Node, NodeComparison);
//					}
//					else if (Node->sum == NodeComparison->sum)											//������ ���� ��� �̸����� �������� ���ϴ� ���ǹ�
//					{
//						if (cu == 1)
//						{
//							swap(Node, NodeComparison);
//						}
//					}
//
//					break;
//				}
//
//				case 2:																	//��������
//				{
//					if (Node->sum < NodeComparison->sum)
//					{
//						swap(Node, NodeComparison);
//					}
//					else if (Node->sum == NodeComparison->sum)											//������ ���� ��� �̸����� �������� ���ϴ� ���ǹ�
//					{
//						if (cu == -1)
//						{
//							swap(Node, NodeComparison);
//						}
//					}
//
//					break;
//				}
//
//				}
//				NodeComparison = NodeComparison->m_next;
//			}
//			else
//				break;
//		}
//		Node = reswap(i);
//		if (Node->m_next == Link_Tail)
//		{
//			break;
//		}
//		else
//		{
//			Node = Node->m_next;
//			NodeComparison = Node->m_next;
//		}
//
//	}*/
//
//	for (int i = 0; i < NodeNum; i++)					//�ּҰ��� �ٲܶ�
//	{
//		for (int j = i; j < NodeNum; j++)
//		{
//			if (NodeComparison != Link_Tail)
//			{
//				if (i == 0)						// i==0�϶� �ּҰ��� ��尡 �Ǳ⿡ �������� ���ǹ�
//				{
//					Node = Link_Head->m_next;
//				}
//				else
//				{
//					Node = reswap(i);
//				}
//				NodeComparison = reswap(j + 1);
//				cu = strcmp(Node->name, NodeComparison->name);								//������ ������� �̸����� ���ϱ����� ����ϴ� ��
//
//				switch (se)																//������ �Է¹޾� ���������� ���� ���������� ���� ����
//				{
//				case 1:																	//��������
//				{
//					if (Node->sum > NodeComparison->sum)
//					{
//						sw.swappa(*Node, *NodeComparison);
//					}
//					else if (Node->sum == NodeComparison->sum)											//������ ���� ��� �̸����� �������� ���ϴ� ���ǹ�
//					{
//						if (cu == 1)
//						{
//							sw.swappa(*Node, *NodeComparison);
//						}
//					}
//
//					break;
//				}
//
//				case 2:																	//��������
//				{
//					if (Node->sum < NodeComparison->sum)
//					{
//						sw.swappa(*Node, *NodeComparison);
//					}
//					else if (Node->sum == NodeComparison->sum)											//������ ���� ��� �̸����� �������� ���ϴ� ���ǹ�
//					{
//						if (cu == -1)
//						{
//							sw.swappa(*Node, *NodeComparison);
//						}
//					}
//
//					break;
//				}
//
//				}
//
//			}
//			else
//				break;
//		}
//		Node = reswap(i);
//		if (Node->m_next == Link_Tail)
//		{
//			break;
//		}
//
//	}
//	//�ּҰ��� �ٲܶ�
//
//}	   //������ ����


//void AllDelete()
//{
//	StuNode<student>* Node = Link_Head->m_next;
//	while (1)
//	{
//		if (Node == Link_Tail)
//		{
//			break;
//		}
//		StuNode<student>* temp = Node->m_prev;
//		StuNode<student>* temp_2 = Node->m_next;
//		temp->m_next = temp_2;
//		temp_2->m_prev = temp;
//		delete Node;							//��λ���
//		Node = temp_2;
//	}
//}
//

//
//StuNode<student>* reswap(int a)
//{
//	StuNode<student>* rere;
//	if (a == 0)
//	{
//		StuNode<student>* rere = Link_Head;
//		return rere;
//	}
//	rere = reswap(a - 1);
//	return rere->m_next;
//}