#include <time.h>		
#include <stdio.h>			
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MAX_STUDENT 10

typedef struct student
{

	int num;
	char name[5];
	int kuk;
	int eng;
	int su;
	int sum;
	double avg;
	struct student* m_next;
	struct student* m_prev;
}student;
typedef struct aaa
{
	private:

	int num;
	char name[5];
	int kuk;
	int eng;
	int su;
	int sum;
	double avg;
	struct student* m_next;
	struct student* m_prev;
};

void Allmake(int a);		//��� a����ŭ ����
void one();					//�ʱⰪ
void one_1();				//���� ���� ������ 2�� ����
void one_end();				//���� ���� ����
void Nodefree();			//��� ����
void Save();				//����
void Load(int a);			//�ҷ�����
void print();				//���
void Jung();				//����
void in();					//����
void sak();					//����
void Delete(student* Node);		//��� ����
void AllDelete();			//��� ��� ����
void Name();				//�̸��� ����
void Num();					//������ ����
//void swap(int a, int b);
void swap(student* Node, student* Daum);	//��峢���� ������ ����
void swappa(student* Node, student* Daum);	//����� �ּҰ��� ���� ��ȯ�Ͽ� ������ �ٲٱ�
student* reswap(int a);				//����� �ּҰ� ��ȯ�� ���� ����Լ��� �ּ� ���ߴ� �뵵
void FrontNodein(student* newNode, student* head);	//���ο� ���� ��� ����
void BackNodein(student* newNode, student* head);	//���ο� ���� ��� ����
int Find(int a);			//��ȣ ã��
int numfind();		//������ ��ȣ ã�Ƽ� ����
student* make();				//��� ���� �����
int NodeNumber();			//��� ��带 ������ �ִ��� ����


int main()
{
	int select;
	int bun;

	one_1();
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
			Save();														//����
			break;

		case 2:
			Load(0);														//�ε�
			break;

		case 3:
			print();													//���
			break;

		case 4:															//����
			Jung();
			break;

		case 5:															//����
			in();
			break;

		case 6:															//����
			sak();
			break;

		case 7:															//����
		{
			printf("�̸�(1), ����(2) �� ���ϴ� ���Ĺ� �Ѱ����� ��� ��ȣ�� �����ּ��� : ");
			scanf_s("%d", &bun);
			switch (bun)
			{
			case 1:
				Name();
				break;

			case 2:
				Num();
				break;
			}
			break;
		}

		case 8:
			Load(1);
			break;

		case 99:														//����
			system("cls");
			printf("�ƹ�Ű�� ������ ����˴ϴ�.");
			_getch();
			Nodefree();
			one_end();
			return 0;
		}
	}
}

student* Link_Head = 0;
student* Link_Tail = 0;
int cut = MAX_STUDENT;				//�ҷ��ö� ũ�Ⱑ �ٸ� ��� ũ�� ����


void one_1()
{
	Link_Head = (student*)malloc(sizeof(student));
	memset(Link_Head, 0, sizeof(student));
	Link_Tail = (student*)malloc(sizeof(student));
	memset(Link_Tail, 0, sizeof(student));

	Link_Head->m_next = Link_Tail;
	Link_Tail->m_prev = Link_Head;
}

void one_end()
{
	free(Link_Head);
	free(Link_Tail);
}

void Nodefree()
{
	student* freeNode;
	student* freetemp;
	freeNode = Link_Head->m_next;
	for (int i = 0; i < MAX_STUDENT; i++)
	{
		freetemp = freeNode->m_next;
		free(freeNode);
		freeNode = freetemp;
	}

}


void one()
{
	//srand(time(NULL));	�ѹ��� �Է¹޴¿����� ����ҰŶ� �Ƚᵵ �ȴ�.
	int i;
	student* newNode;
	FILE* pa_one;
	fopen_s(&pa_one, "student.txt", "w");											//�ʱⰪ�� �ҷ����� ���� �����͸� ������ ���� ����
	for (i = 0; i < MAX_STUDENT; i++)
	{
		newNode = (student*)malloc(sizeof(student));
		memset(newNode, 0, sizeof(student));

		newNode->name[0] = 65 + rand() % 26;
		newNode->name[1] = 65 + rand() % 26;
		newNode->name[2] = 65 + rand() % 26;
		newNode->name[3] = '\0';
		newNode->num = i + 1;

		newNode->kuk = rand() % 101;
		newNode->eng = rand() % 101;
		newNode->su = rand() % 101;

		newNode->sum = newNode->kuk + newNode->eng + newNode->su;
		newNode->avg = (double)newNode->sum / 3;

		//FrontNodein(newNode, Link_Head);
		BackNodein(newNode, Link_Tail);
	}
	student* cho = Link_Head->m_next;
	for (i = 0; i < MAX_STUDENT; i++)
	{
		fprintf(pa_one, "%d %s %d %d %d %d %.3lf\n", cho->num, cho->name, cho->kuk, cho->eng, cho->su, cho->sum, cho->avg);
		//fwrite(cho, sizeof(stu), 1, pa_one);	//�ʱⰪ ����
		cho = cho->m_next;
	}
	fclose(pa_one);
	print();
}

void Save()																			//���� �����ϱ�
{
	student* Node;
	Node = Link_Head->m_next;
	int size;
	char fi[30];
	printf("�����ϱ� ����ϴ� ���ϸ��� �����ּ��� : ");								//������ ���� �Է¹޾� fopen�Լ��� �־� ���ϴ� ������ ����
	scanf_s("%s", fi, 30);

	size = strcmp(fi, "student.txt");
	while (size == 0)																	//�ʱⰪ�� �־��� ���Ͽ� ��ġ���� Ȯ��
	{
		printf("�ߺ� �Ǿ����ϴ� �ٸ� ���ϸ��� �����ּ��� : ");
		scanf_s("%s", fi, 30);
		size = strcmp(fi, "student.txt");
	}

	FILE* pa;
	fopen_s(&pa, fi, "w");															//������ ���� �Է¹޾� fopen�Լ��� �־� ���ϴ� ������ ����
	for (int i = 0; i < NodeNumber(); i++)
	{
		if (Node == Link_Tail)
		{
			break;
		}
		fprintf(pa, "%d %s %d %d %d %d %.3lf\n", Node->num, Node->name, Node->kuk, Node->eng, Node->su, Node->sum, Node->avg);
		Node = Node->m_next;
	}
	/*fopen_s(&pa, fi, "wb");
	for (int i = 0; i < MAX_STUDENT; i++)
	{
		fwrite(Node, sizeof(stu), 1, pa);
		Node = Node->m_next;
		if (Node == Link_Tail)
		{
			break;
		}
	}*/
	fclose(pa);
}	   //����

void Load(int a)																			//����� ���� �ҷ�����
{
	//system("cls");
	student* temp;			//����Ʈ�� ���� �ޱ��
	int err;
	unsigned int er = 0;
	AllDelete();
	student* Node = make();

	switch (a)
	{
	case 0:																				//���ϴ� ���ϸ��� �Է��Ͽ� �ҷ�����
	{
		char fi2[30];
		printf("�ҷ����� �ٶ�� ���������� �����ּ��� : ");								//������ ���� �Է¹޾� fopen�Լ��� �־� ���ϴ� ������ �ҷ��´�.
		scanf_s("%s", fi2, 30);
		FILE* pas;
		fopen_s(&pas, fi2, "r");

		//fscaf ���
		while (1)
		{
			if (Node == Link_Tail)
			{
				Node = make();
				er = 1;										//0�̸� ���� 1�̸� ���� �ٴٶ��ٴ� ��
			}
			err = fscanf_s(pas, "%d %s %d %d %d %d %lf\n", &Node->num, Node->name, 5, &Node->kuk, &Node->eng, &Node->su, &Node->sum, &Node->avg);
			if (err == EOF && er)
			{
				Delete(Node);
				break;
			}
			else
			{
				Node = Node->m_next;
			}
		}													//��带 �ϳ� �ϳ� ���� ����
		/*while(1)				//fread ���
		{													//�ݺ� Ƚ���� �ѹ��� �ϸ� ���ϳ� �ݺ������� ���� ���Ҵ�.
			err=fread(Node, sizeof(stu), 1, pas);
			if (err == NULL)
			{
				Link_End->m_next = Link_Tail;		//�̹� �ε������� �������
				break;
			}
			Link_End = Node;
			Node = Node->m_next;
		}*/

		fclose(pas);
		print();
	}break;
	
	case 1:																				//��ó�� �ʱⰪ�� ������ ������ �ҷ�����
	{
		FILE* pas_1;
		student* temp;
	
		fopen_s(&pas_1, "student.txt", "r");
		while(1)
	{
		if (Node == Link_Tail)
		{
			Node = make();
			er = 1;										//0�̸� ���� 1�̸� ���� �ٴٶ��ٴ� ��
		}
		err = fscanf_s(pas_1, "%d %s %d %d %d %d %lf\n", &Node->num, Node->name, 5, &Node->kuk, &Node->eng, &Node->su, &Node->sum, &Node->avg);
		if (err == EOF && er)
		{
			Delete(Node);
			break;
		}
		else
		{
			Node = Node->m_next;
		}
	}

		/*for (int i = 0; i < MAX_STUDENT; i++)				//fscaf ���
		{
			if (Node == Link_Tail)
			{
				Node = make();
				er = 1;										//0�̸� ���� 1�̸� ���� �ٴٶ��ٴ� ��
			}
			err = fread(Node, sizeof(stu), 1, pas_1);
			if (err < sizeof(stu) && er)
			{
				Delete(Node);
				break;
			}
			
			else
			{
				Node = Node->m_next;
			}
		}*/
		fclose(pas_1);
		print();
	}break;
	}
}

void print()																			//���� ��� �Լ�
{
	student* Node = Link_Head->m_next;
	printf("========================================================================================================================\n");
	printf("\t\t\t\t\t\t���� ���� ���α׷�\n\n");
	printf("========================================================================================================================\n");
	printf("\t\t\t\t��ȣ \t �̸� \t ���� \t ���� \t ���� \t ����\t ���\n");
	for (int i = 1; i <= NodeNumber(); i++)
	{

		printf("\t\t\t\t%2d��\t%5s %6d  %6d  %6d \t %3d \t %5.3f\n", Node->num, Node->name, Node->kuk, Node->eng, Node->su, Node->sum, Node->avg);
		Node = Node->m_next;
		if (Node == Link_Tail)																		//������ ����ϳ� ������ ������ �ֱ⿡ �װ� �˻��ϰ� ����ϴ� ���ǹ� 
		{
			break;
		}


	}
	printf("\n");
}	   //���

void Jung()																				//�����͸� �����ϴ� �Լ�
{
	student* Node = Link_Head->m_next;
	int sun = 0;
	int num;

	printf("������ ��ȣ 1~%d������ ��ȣ�� ����ּ��� : ", NodeNumber());
	scanf_s("%d", &sun);
	while (1 > sun || NodeNumber() < sun)															//�����ʹ� 10���� �л��� �����͸� �����Ƿ� �� ���� ���� �� �� �ְ� �����˻�
	{
		printf("������ ��ȣ�� 1~%d ���� �Դϴ�. �ٽ� 1~%d������ ��ȣ�� ����ּ��� : ", NodeNumber(),NodeNumber());
		scanf_s("%d", &sun);
	}

	num=Find(sun);

	for (int i = 1; i < num; i++)
	{
		Node = Node->m_next;
	}

	printf("%d���� �̸� : ", num);
	scanf_s("%s", Node->name, 5);

	printf("%d���� �������� : ", num);
	scanf_s("%d", &Node->kuk);

	printf("%d���� �������� : ", num);
	scanf_s("%d", &Node->eng);

	printf("%d���� �������� : ", num);
	scanf_s("%d", &Node->su);

	Node->sum = Node->kuk + Node->eng + Node->su;
	Node->avg = (double)Node->sum / 3;
}	   //����*/

void in()											//������ ����
{
	student* Node = Link_Head->m_next;
	student* temp;
	int a, b;
	//system("cls");
	do
	{
		printf("�����ϰ� ���� ���� ��ȣ�� �Է��ϼ��� : ");
		scanf_s("%d", &a);
		b = Find(a);
	} while (b == 0);


	for (int i = 1; i < b; i++)
	{
		Node = Node->m_next;
	}
	temp = (student*)calloc(1, sizeof(student));
	printf("���� ������ �л��� �̸�, ��������, ��������, ���������� �־��ּ���.\n");


	printf("�̸� : ");
	scanf_s("%s", temp->name, 5);

	printf("�������� : ");
	scanf_s("%d", &temp->kuk);

	printf("�������� : ");
	scanf_s("%d", &temp->eng);

	printf("�������� : ");
	scanf_s("%d", &temp->su);

	if (MAX_STUDENT > NodeNumber())
	{
		temp->num = numfind();
	}
	else
	{
		temp->num = NodeNumber()+1;
	}

	temp->sum = temp->kuk + temp->eng + temp->su;
	temp->avg = (double)temp->sum / 3;

	//FrontNodein(temp, Node);
	BackNodein(temp, Node);
}

void sak()																	//������ �����ϴ� �Լ�
{
	student* Node = Link_Head->m_next;
	int sun = 0;
	int num;

	printf("������ ��ȣ�� ����ּ���: ");
	scanf_s("%d", &sun);
	/*while (1 > sun || NodeNumber() < sun)												//�߸��� ��ȣ�� �Է��ߴ��� Ȯ��
	{
		printf("������ ��ȣ�� 1~%d ���� �Դϴ�. �ٽ� 1~%d������ ��ȣ�� ����ּ��� : ", NodeNumber(), NodeNumber());
		scanf_s("%d", &sun);
	}*/
	num = Find(sun);
	if (num == 0)
	{
		printf("�´� ��ȣ�� �����ϴ�.\n");
	}
	for (int i = 1; i < num; i++)
	{
		Node = Node->m_next;
	}

	Delete(Node);

}			//����

void Name()																	// �̸����� �����ϴ� �Լ�
{
	int se;				//���̽��� ������ ���� �Է¹ޱ� ���� ���� ����
	int cu;				//���ڿ� �񱳿� ���� ����
	int i, j;			//�ݺ����� ���� ����
	int NodeNum;
	student* Node=Link_Head->m_next;
	student* NodeComparison=Node->m_next;					//���� ���ϱ� ���� ���� ����� ���� ��带 �����Ѵ�


	printf("������ �̸��� ��������(1), ��������(2) �������ּ���(�̸��� ������� ����,����,���� ������ �����մϴ�) : ");
	scanf_s("%d", &se);

	NodeNum = NodeNumber();			//��� ������ �����ϴ� �Լ��� �̿��Ͽ� ���� ������ ����

	for (i = 0; i < NodeNum; i++)
	{

		for (j = i; j < NodeNum; j++)
		{
			if (NodeComparison != Link_Tail)
			{
				cu = strcmp(Node->name, NodeComparison->name);		//�̸��� ���Ͽ� ���� �ڿ� ������ 1�� ��ȯ�޾� �����Լ��� ������ ��ȯ


				switch (se)																//������ �Է¹޾� ���������� ���� ���������� ���� ����
				{

				case 1:														//��������
				{
					if (cu == 1)
					{
						swap(Node, NodeComparison);
					}
					else if (cu == 0)											//�̸��� ���� ��� �������� �������� ���ϴ� ���ǹ�
					{
						if (Node->kuk > NodeComparison->kuk)
						{
							swap(Node, NodeComparison);
						}
						else if (Node->kuk = NodeComparison->kuk)
						{
							if (Node->eng > NodeComparison->eng)
							{
								swap(Node, NodeComparison);
							}
							else if (Node->eng = NodeComparison->eng)
							{
								if ((Node->su > NodeComparison->su))
								{
									swap(Node, NodeComparison);
								}
							}
						}
					}
					break;
				}

				case 2:														//��������
				{
					if (cu == -1)
					{
						swap(Node, NodeComparison);
					}
					else if (cu == 0)											//�̸��� ���� ��� �������� �������� ���ϴ� ���ǹ�
					{
						if (Node->kuk < NodeComparison->kuk)
						{
							swap(Node, NodeComparison);
						}
						else if (Node->kuk = NodeComparison->kuk)
						{
							if (Node->eng < NodeComparison->eng)
							{
								swap(Node, NodeComparison);
							}
							else if (Node->eng = NodeComparison->eng)
							{
								if ((Node->su < NodeComparison->su))
								{
									swap(Node, NodeComparison);
								}
							}
						}
					}
					break;
				}
				}

				if (i == NodeNum - 2)
				{
					break;
				}

				NodeComparison = NodeComparison->m_next;
			}
			
			else
				break;
		}
		if (Node->m_next != Link_Tail)
		{
			Node = Node->m_next;
			NodeComparison = Node->m_next;			//NodeComparison ������ Node �����ſ� ���ڿ��� ���ؾ� �ϹǷ� ���� ������ ����Ű�� �Ѵ�
		}
		else
			break;
		

	}
}

void Num()																			//�������� �����ϴ� �Լ�
{
	int se;
	int cu;
	int NodeNum;
	student* Node = Link_Head->m_next;
	student* NodeComparison = Node->m_next;
	

	NodeNum = NodeNumber();			//��� ������ �����ϴ� �Լ��� �̿��Ͽ� ���� ������ ����

	printf("������ ������ ��������(1), ��������(2) �������ּ���(������ ������� �̸������� �����մϴ�) : ");
	scanf_s("%d", &se);

	/*for (int i = 0; i < NodeNum; i++)
	{
		for (int j = i; j < NodeNum; j++)
		{
			if (NodeComparison != Link_Tail)
			{
				Node = reswap(i);
				NodeComparison = reswap(j);
				cu = strcmp(Node->name, NodeComparison->name);								//������ ������� �̸����� ���ϱ����� ����ϴ� ��
				switch (se)																//������ �Է¹޾� ���������� ���� ���������� ���� ����
				{
				case 1:																	//��������
				{
					if (Node->sum > NodeComparison->sum)
					{
						swap(Node, NodeComparison);
					}
					else if (Node->sum == NodeComparison->sum)											//������ ���� ��� �̸����� �������� ���ϴ� ���ǹ�
					{
						if (cu == 1)
						{
							swap(Node, NodeComparison);
						}
					}

					break;
				}

				case 2:																	//��������
				{
					if (Node->sum < NodeComparison->sum)
					{
						swap(Node, NodeComparison);
					}
					else if (Node->sum == NodeComparison->sum)											//������ ���� ��� �̸����� �������� ���ϴ� ���ǹ�
					{
						if (cu == -1)
						{
							swap(Node, NodeComparison);
						}
					}

					break;
				}

				}
				NodeComparison = NodeComparison->m_next;
			}
			else
				break;
		}
		Node = reswap(i);
		if (Node->m_next == Link_Tail)
		{
			break;
		}
		else
		{
			Node = Node->m_next;
			NodeComparison = Node->m_next;
		}

	}*/
	
	for (int i = 0; i < NodeNum; i++)					//�ּҰ��� �ٲܶ�
	{
		for (int j = i; j < NodeNum; j++)
		{
			if (NodeComparison != Link_Tail)
			{
				if (i == 0)						// i==0�϶� �ּҰ��� ��尡 �Ǳ⿡ �������� ���ǹ�
				{
					Node = Link_Head->m_next;
				}
				else
				{
					Node = reswap(i);
				}
				NodeComparison = reswap(j+1);
				cu = strcmp(Node->name, NodeComparison->name);								//������ ������� �̸����� ���ϱ����� ����ϴ� ��
				
				switch (se)																//������ �Է¹޾� ���������� ���� ���������� ���� ����
				{
				case 1:																	//��������
				{
					if (Node->sum > NodeComparison->sum)
					{
						swappa(Node, NodeComparison);
					}
					else if (Node->sum == NodeComparison->sum)											//������ ���� ��� �̸����� �������� ���ϴ� ���ǹ�
					{
						if (cu == 1)
						{
							swappa(Node, NodeComparison);
						}
					}

					break;
				}

				case 2:																	//��������
				{
					if (Node->sum < NodeComparison->sum)
					{
						swappa(Node, NodeComparison);
					}
					else if (Node->sum == NodeComparison->sum)											//������ ���� ��� �̸����� �������� ���ϴ� ���ǹ�
					{
						if (cu == -1)
						{
							swappa(Node, NodeComparison);
						}
					}

					break;
				}

				}
				
			}
			else
				break;
		}
		Node = reswap(i);
		if (Node->m_next == Link_Tail)
		{
			break;
		}

	}
				//�ּҰ��� �ٲܶ�

}	   //������ ����


/*void swap(int a, int b)																	//������ ��ȯ �Լ�
{
	stu temp;

	strcpy_s(temp.name, 5, data[a].name);
	strcpy_s(data[a].name, 5, data[b].name);
	strcpy_s(data[b].name, 5, temp.name);

	temp.kuk = data[a].kuk;
	data[a].kuk = data[b].kuk;
	data[b].kuk = temp.kuk;

	temp.eng = data[a].eng;
	data[a].eng = data[b].eng;
	data[b].eng = temp.eng;

	temp.su = data[a].su;
	data[a].su = data[b].su;
	data[b].su = temp.su;

	temp.sum = data[a].sum;
	data[a].sum = data[b].sum;
	data[b].sum = temp.sum;

	temp.avg = data[a].avg;
	data[a].avg = data[b].avg;
	data[b].avg = temp.avg;
}*/

void FrontNodein(student* newNode, student* head)
{
	//next ����
	student* temp = head->m_next;
	head->m_next = newNode;
	newNode->m_next = temp;
	
	//prev ����
	newNode->m_prev = head;
	temp->m_prev = newNode;
}

void BackNodein(student* newNode, student* tail)
{
	student* temp = tail->m_prev;
	tail->m_prev = newNode;
	newNode->m_next = tail;

	newNode->m_prev = temp;
	temp->m_next = newNode;
}

void swap(student* Node, student* Daum)																	//������ ��ȯ �Լ�
{
	student* temp = (student*)calloc(1, sizeof(student));

	strcpy_s(temp->name, 5, Node->name);
	strcpy_s(Node->name, 5, Daum->name);
	strcpy_s(Daum->name, 5, temp->name);

	temp->kuk = Node->kuk;
	Node->kuk = Daum->kuk;
	Daum->kuk = temp->kuk;

	temp->eng = Node->eng;
	Node->eng = Daum->eng;
	Daum->eng = temp->eng;

	temp->su = Node->su;
	Node->su = Daum->su;
	Daum->su = temp->su;

	temp->sum = Node->sum;
	Node->sum = Daum->sum;
	Daum->sum = temp->sum;

	temp->avg = Node->avg;
	Node->avg = Daum->avg;
	Daum->avg = temp->avg;

	free(temp);
}

void swappa(student* Node, student* Daum)				//����� �ּҸ� �ٲ� �� �ٲٱ�
{
	student* temp;
	student* swap;

	//�ٲٴ� ������ �� �ּ� ��ȯ
	temp = Node->m_prev;
	swap = Daum->m_prev;
	temp->m_next = Daum;
	swap->m_next = Node;
	Daum->m_prev = temp;
	Node->m_prev = swap;

	//�ٲٴ� ������ �� �ּ� ��ȯ
	temp = Node->m_next;
	swap = Daum->m_next;
	temp->m_prev = Daum;
	swap->m_prev = Node;
	Node->m_next = swap;
	Daum->m_next = temp;

}

int Find(int a)
{
	student* Node = Link_Head->m_next;				//ù ��� �Է�
	int count = 1;								//���° ������� Ȯ���� ��
	for (int i = 1; i <= NodeNumber(); i++)
	{
		if (Node->num == a)
		{
			return count;
		}
		count++;
		Node = Node->m_next;					//���� ��� �ҷ�����
	}
	return 0;
}

void Delete(student* Node)
{
	student* temp = Node->m_prev;
	student* temp_2 = Node->m_next;
	temp->m_next = temp_2;
	temp_2->m_prev = temp;
	free(Node);							//����
}

void AllDelete()
{
	student* Node = Link_Head->m_next;
	while (1)
	{
		if (Node == Link_Tail)
		{
			break;
		}
		student* temp = Node->m_prev;
		student* temp_2 = Node->m_next;
		temp->m_next = temp_2;
		temp_2->m_prev = temp;
		free(Node);							//��λ���
		Node = temp_2;
	}
}

int numfind()					//���� ���� ����ֱ�
{
	student* Node = Link_Head->m_next;
	int a;
	int size = NodeNumber();
	for (int i = 1; i <=size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == Node->num)			//�̹� �ִ� �ѹ��� ���
			{
				a = 0;
				break;
			}
			Node = Node->m_next;
			a = 1;
		}
		if (a == 1)
		{
			return i;					//���� ã�� ���
		}
		Node = Link_Head->m_next;
	}
	return 0;							//���� ã�� ���Ѱ��

}

student* make()
{
		student* Newp = (student*)malloc(sizeof(student));
		memset(Newp, 0, sizeof(student));

		BackNodein(Newp, Link_Tail);
		return Newp;
}

void Allmake(int a)
{
	for (int i = 0; i < a; i++)
	{
		student* Newp = (student*)malloc(sizeof(student));
		memset(Newp, 0, sizeof(student));

		BackNodein(Newp, Link_Tail);
	}
}

int NodeNumber()					//��� ����ã��
{
	student* Node=Link_Head->m_next;
	int num=0;

	while (1)
	{
		
		if (Node == Link_Tail)
		{
			break;
		}
		num++;
		Node = Node->m_next;
	}

	return num;
}

student* reswap(int a)
{
	student* rere;
	if (a == 0)
	{
		student* rere = Link_Head;
		return rere;
	}
	rere = reswap(a - 1);
	return rere->m_next;
}