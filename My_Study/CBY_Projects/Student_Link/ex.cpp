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
}student;

void one();
void one_1();
void one_end();
void Nodefree();
void Save();				//����
void Load(int a);			//�ҷ�����
void print();				//���
void Jung();				//����
void in();					//����
void sak();					//����
void Delete(student* Node);
//void Name();				//�̸��� ����
//void Num();					//������ ����
void swap(int a, int b);
void FrontNodein(student* newNode, student* end);	//���ο� ��� ����
int Find(int a);			//��ȣ ã��
int numfind();		//������ ��ȣ ã�Ƽ� ����

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
		//		Name();
				break;

			case 2:
			//	Num();
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

student* Link_Head=0;
student* Link_Tail=0;
student* Link_End=0;
int NodeInOut=0;			//��� ������ �������� ���� ����뷮 ����
int cut = MAX_STUDENT;				//�ҷ��ö� ũ�Ⱑ �ٸ� ��� ũ�� ����


void one_1()
{
	Link_Head = (student*)calloc(1, sizeof(student));
	Link_Tail = (student*)calloc(1, sizeof(student));
	Link_End = (student*)calloc(1, sizeof(student));
	
	Link_Head->m_next = Link_Tail;
	Link_End = Link_Head;
}

void one_end()
{
	Link_End = 0;								//�޸� ������ �����ּҸ� ��ȯ�ؾ��Ѵ�
	free(Link_Head);
	free(Link_Tail);
	free(Link_End);
}

void Nodefree()
{
	student* freeNode;
	student* freetemp;
		freeNode = Link_Head->m_next;
		for (int i = 0; i < MAX_STUDENT ; i++)
		{
			freetemp= freeNode->m_next;
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
	fopen_s(&pa_one, "student.txt", "wb");											//�ʱⰪ�� �ҷ����� ���� �����͸� ������ ���� ����
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

		FrontNodein(newNode,Link_Tail);
	}
	student* cho = Link_Head->m_next;
	fwrite(cho, sizeof(student), 1, pa_one);											//�ʱⰪ ����
	fclose(pa_one);
	print();
}

void Save()																			//���� �����ϱ�
{
	student* Node = Link_Head->m_next;
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
	/*fopen_s(&pa, fi, "w");															//������ ���� �Է¹޾� fopen�Լ��� �־� ���ϴ� ������ ����
	for (int i = 0; i < MAX_STUDENT; i++)
	{
		fprintf(pa, "%d %s %d %d %d %d %.3lf\n", Node->num, Node->name, Node->kuk, Node->eng, Node->su, Node->sum, Node->avg);
		Node = Node->m_next;
		if(Node==Link_Tail)
		{
			break;
		}
	}*/
	fopen_s(&pa, fi, "wb");
	for (int i = 0; i < MAX_STUDENT; i++)
	{
		fwrite(Node, sizeof(student), 1, pa);
		Node = Node->m_next;
		if (Node == Link_Tail)
		{
			break;
		}
	}
	fclose(pa);
}	   //����

void Load(int a)																			//����� ���� �ҷ�����
{
	//system("cls");
	student* Node = Link_Head->m_next;
	int err;

	switch (a)
	{
	case 0:																				//���ϴ� ���ϸ��� �Է��Ͽ� �ҷ�����
	{
		char fi2[30];
		printf("�ҷ����� �ٶ�� ���������� �����ּ��� : ");								//������ ���� �Է¹޾� fopen�Լ��� �־� ���ϴ� ������ �ҷ��´�.
		scanf_s("%s", fi2, 30);
		FILE* pas;
		fopen_s(&pas, fi2, "r");
		for (int i = 0; i < MAX_STUDENT; i++)				//fscaf ���
		{
			err=fscanf_s(pas, "%d %s %d %d %d %d %lf\n", &Node->num, Node->name, 5, &Node->kuk, &Node->eng, &Node->su, &Node->sum, &Node->avg);
			if (err==EOF)							//���Ͽ��� ���̻� �޾ƿ��� �ڷᰡ ������
			{
				Link_End->m_next = Link_Tail;		//�̹� �ε������� �������
				break;
			}
			Link_End = Node;
			Node = Node->m_next;
		}
		/*for (int i = 0; i < MAX_STUDENT; i++)				//fread ���
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
		break;
	}

	case 1:																				//��ó�� �ʱⰪ�� ������ ������ �ҷ�����
	{
		FILE* pas_1;
		student* temp;
		for (int i = 0; i < MAX_STUDENT; i++)
		{
			if (Node == Link_Tail)
			{
				temp = (student*)calloc(1, sizeof(student));
				FrontNodein(temp, Link_Tail);
				Node = temp;
			}
			Link_End = Node;
			Node = Node->m_next;
		}
		Node = Link_Head->m_next;
		fopen_s(&pas_1, "student.txt", "rb");
		for (int i = 0; i < MAX_STUDENT; i++)				//fread ���
		{										
			if (Node == Link_Tail)
			{
				Link_End->m_next = Link_Tail;		//�̹� �ε������� �������
				break;
			}
																		//�ݺ� Ƚ���� �ѹ��� �ϸ� ���ϳ� �ݺ������� ���� ���Ҵ�.
			fread(Node, sizeof(student), 1, pas_1);
			Link_End = Node;
			Node = Node->m_next;
		}
		fclose(pas_1);
		print();
		break;
	}
	}
}

void print()																			//���� ��� �Լ�
{
	student* Node = Link_Head->m_next;
	printf("========================================================================================================================\n");
	printf("\t\t\t\t\t\t���� ���� ���α׷�\n\n");
	printf("========================================================================================================================\n");
	printf("\t\t\t\t��ȣ \t �̸� \t ���� \t ���� \t ���� \t ����\t ���\n");
	for (int i = 1; i <= MAX_STUDENT; i++)
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

	printf("������ ��ȣ 1~10������ ��ȣ�� ����ּ��� : ");
	scanf_s("%d", &sun);
	while (1 > sun || 10 < sun)															//�����ʹ� 10���� �л��� �����͸� �����Ƿ� �� ���� ���� �� �� �ְ� �����˻�
	{
		printf("������ ��ȣ�� 1~10 ���� �Դϴ�. �ٽ� 1~10������ ��ȣ�� ����ּ��� : ");
		scanf_s("%d", &sun);
	}

	for (int i = 1; i < sun; i++)
	{
		Node = Node->m_next;
	}

	printf("%d���� �̸� : ", sun);
	scanf_s("%s", Node->name, 5);

	printf("%d���� �������� : ", sun);
	scanf_s("%d", &Node->kuk);

	printf("%d���� �������� : ", sun);
	scanf_s("%d", &Node->eng);

	printf("%d���� �������� : ", sun);
	scanf_s("%d", &Node->su);

	Node->sum = Node->kuk + Node->eng + Node->su;
	Node->avg = (double)Node->sum / 3;
}	   //����*/

void in()
{
	student* Node=Link_Head->m_next;
	student* temp;
	int a,b;
	system("cls");
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

	temp->num = numfind();

	temp->sum = temp->kuk + temp->eng + temp->su;
	temp->avg = (double)temp->sum / 3;

	FrontNodein(temp, Node);
}

void sak()																	//������ �����ϴ� �Լ�
{
	student* Node = Link_Head->m_next;
	int sun = 0;
	int num;

	printf("������ ��ȣ 1~%d������ ��ȣ�� ����ּ��� : ",MAX_STUDENT);
	scanf_s("%d", &sun);
	while (1 > sun || MAX_STUDENT < sun)												//�߸��� ��ȣ�� �Է��ߴ��� Ȯ��
	{
		printf("������ ��ȣ�� 1~%d ���� �Դϴ�. �ٽ� 1~%d������ ��ȣ�� ����ּ��� : ",MAX_STUDENT, MAX_STUDENT);
		scanf_s("%d", &sun);
	}
	num = Find(sun);
	if (num == 0)
	{
		printf("�´� ��ȣ�� �����ϴ�.");
	}
	for (int i = 1; i < num; i++)
	{
		Node = Node->m_next;
	}

	Delete(Node);
	
}			//����

/*void Name()																	// �̸����� �����ϴ� �Լ�
{
	int se;
	int cu;

	printf("������ �̸��� ��������(1), ��������(2) �������ּ���(�̸��� ������� ����,����,���� ������ �����մϴ�) : ");
	scanf_s("%d", &se);

	for (int i = 0; i < 10; i++)
	{
		for (int j = i; j < 10; j++)
		{
			cu = strcmp(data[i].name, data[j].name);					//�̸��� ���Ͽ� ���� �ڿ� ������ 1�� ��ȯ�޾� �����Լ��� ������ ��ȯ
			switch (se)																//������ �Է¹޾� ���������� ���� ���������� ���� ����
			{

			case 1:														//��������
			{
				if (cu == 1)
				{
					swap(i, j);
				}
				else if (cu == 0)											//�̸��� ���� ��� �������� �������� ���ϴ� ���ǹ�
				{
					if (data[i].kuk > data[j].kuk)
					{
						swap(i, j);
					}
					else if (data[i].kuk = data[j].kuk)
					{
						if (data[i].eng > data[j].eng)
						{
							swap(i, j);
						}
						else if (data[i].eng > data[j].eng)
						{
							if ((data[i].su > data[j].su))
							{
								swap(i, j);
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
					swap(i, j);
				}
				else if (cu == 0)											//�̸��� ���� ��� �������� �������� ���ϴ� ���ǹ�
				{
					if (data[i].kuk < data[j].kuk)
					{
						swap(i, j);
					}
					else if (data[i].kuk = data[j].kuk)
					{
						if (data[i].eng < data[j].eng)
						{
							swap(i, j);
						}
						else if (data[i].eng < data[j].eng)
						{
							if ((data[i].su < data[j].su))
							{
								swap(i, j);
							}
						}
					}
				}
				break;
			}
			}
		}

	}
}*/

/*void Num()																			//�������� �����ϴ� �Լ�
{
	int se;
	int cu;

	printf("������ ������ ��������(1), ��������(2) �������ּ���(������ ������� �̸������� �����մϴ�) : ");
	scanf_s("%d", &se);

	for (int i = 0; i < 10; i++)
	{
		for (int j = i; j < 10; j++)
		{
			cu = strcmp(data[i].name, data[j].name);								//������ ������� �̸����� ���ϱ����� ����ϴ� ��
			switch (se)																//������ �Է¹޾� ���������� ���� ���������� ���� ����
			{
			case 1:																	//��������
			{
				if (data[i].sum > data[j].sum)
				{
					swap(i, j);
				}
				else if (data[i].sum == data[j].sum)											//������ ���� ��� �̸����� �������� ���ϴ� ���ǹ�
				{
					if (cu == 1)
					{
						swap(i, j);
					}
				}

				break;
			}

			case 2:																	//��������
			{
				if (data[i].sum < data[j].sum)
				{
					swap(i, j);
				}
				else if (data[i].sum == data[j].sum)											//������ ���� ��� �̸����� �������� ���ϴ� ���ǹ�
				{
					if (cu == -1)
					{
						swap(i, j);
					}
				}

				break;
			}

			}

		}
	}
}	   //������ ����*/


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

void FrontNodein(student* newNode,student* end)
{
	Link_End->m_next = newNode;
	newNode->m_next = end;
	Link_End = newNode;
}

/*void swap(stu* Node, stu* Daum)																	//������ ��ȯ �Լ�
{
	stu* temp;

	strcpy_s(temp->name, 5, Node->name);
	strcpy_s(data[a].name, 5, Node->name);
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

int Find(int a)
{
	student* Node = Link_Head->m_next;				//ù ��� �Է�
	int count = 1;								//���° ������� Ȯ���� ��
	for (int i = 1; i <= MAX_STUDENT; i++)										
	{
		if (Node->num == a)
		{
			if (Node->num == 1)
			{
				Link_End = Link_Head;
			}
			return count;
		}
		count++;								
		Link_End = Node;						//Link_End�� ���� �����ġ ����
		Node = Node->m_next;					//���� ��� �ҷ�����
	}
	return 0;
}

void Delete(student* Node)
{
	student* temp=Node->m_next;				//������ ����� �� ����� ��ġ�� temp�� ����
	Link_End->m_next=temp;				//Link_End�� Find�Լ��� ���� ������ ��� �� ���� ���� ��ġ������ �� ���� �ּҸ� ���� ��� �� ��ġ�� ���� ����
	
	free(Node);							//����

	NodeInOut++;						//��� ������ �߰��� ���� �뷮 ����
}

int numfind()					//���� ���� ����ֱ�
{
	student* Node = Link_Head->m_next;
	int a;
	int size = MAX_STUDENT - NodeInOut;	//�ݺ��ؼ� ���ư��� NULL���� �޴� ���� ������ ���� ���� ������ ����
	for (int i = 1; i <= MAX_STUDENT; i++)
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
		if(a==1)
		{
			return i;					//���� ã�� ���
		}
		Node = Link_Head->m_next;
	}
	return 0;							//���� ã�� ���Ѱ��

}