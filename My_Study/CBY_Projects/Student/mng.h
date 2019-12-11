#pragma once
#include <time.h>		
#include <stdio.h>			
#include <stdlib.h>
#include <conio.h>
#include<string.h>

void Save();				//����
void Load(int a);			//�ҷ�����
void print();				//���
void Jung();				//����
void in();					//����
void sak();					//����
void Name();				//�̸��� ����
void Num();					//������ ����
void swap(int a, int b);

typedef struct student
{
	int num;
	char name[5];
	int kuk;
	int eng;
	int su;
	int sum;
	double avg;
	struct student* next;
}student;

/*char* getname(stu* name, int index) { return name[index].name; }
int getkuk(stu* Kor, int index) { return Kor[index].kuk; }
int geteng(stu* Eng, int index) { return Eng[index].eng; }
int getsu(stu* Mat, int index) { return Mat[index].su; }
int getsum(stu* sumsum, int index) { return sumsum[index].sum; }
int getnum(stu* numnum, int index) { return numnum[index].num; }
double getavg(stu* avgavg, int index) { return avgavg[index].avg; }*/

int size = 10;
student* data=0;


void one()
{
	data = (student*)malloc(sizeof(student) * size);
	//srand(time(NULL));	�ѹ��� �Է¹޴¿����� ����ҰŶ� �Ƚᵵ �ȴ�.

	FILE* pa_one;
	fopen_s(&pa_one,"student.txt", "wb");											//�ʱⰪ�� �ҷ����� ���� �����͸� ������ ���� ����

	for (int i = 0; i < size; i++)
	{
		data[i].name[0] = 65 + rand() % 26;
		data[i].name[1] = 65 + rand() % 26;
		data[i].name[2] = 65 + rand() % 26;
		data[i].name[3] = '\0';
		data[i].num = i + 1;

		data[i].kuk = rand() % 101;
		data[i].eng = rand() % 101;
		data[i].su = rand() % 101;
		
		data[i].sum = data[i].kuk + data[i].eng + data[i].su;
		data[i].avg = (double) data[i].sum / 3;
	}

	fwrite(data, sizeof(student), 10,pa_one);											//�ʱⰪ ����
	fclose(pa_one);
	print();
	//free(data);
}

void Save()																			//���� �����ϱ�
{	
	int size;
	char fi[30];
	printf("�����ϱ� ����ϴ� ���ϸ��� �����ּ��� : ");								//������ ���� �Է¹޾� fopen�Լ��� �־� ���ϴ� ������ ����
	scanf_s("%s", fi,30);
	
	size = strcmp(fi, "student.txt");
	while(size==0)																	//�ʱⰪ�� �־��� ���Ͽ� ��ġ���� Ȯ��
	{
		printf("�ߺ� �Ǿ����ϴ� �ٸ� ���ϸ��� �����ּ��� : ");								
		scanf_s("%s", fi, 30);
		size = strcmp(fi, "student.txt");
	}

	FILE* pa;
	fopen_s(&pa, fi, "w");															//������ ���� �Է¹޾� fopen�Լ��� �־� ���ϴ� ������ ����
	for (int i = 0; i < 10; i++)
	{
		fprintf(pa, "%d %s %d %d %d %d %.3lf\n", data[i].num, data[i].name, data[i].kuk, data[i].eng, data[i].su, data[i].sum, data[i].avg);
	}
	fclose(pa);
}	   //����

void Load(int a)																			//����� ���� �ҷ�����
{
	//system("cls");

	switch (a)
	{
	case 0:																				//���ϴ� ���ϸ��� �Է��Ͽ� �ҷ�����
	{
		char fi2[30];
		printf("�ҷ����� �ٶ�� ���������� �����ּ��� : ");								//������ ���� �Է¹޾� fopen�Լ��� �־� ���ϴ� ������ �ҷ��´�.
		scanf_s("%s", fi2, 30);
		FILE* pas;
		fopen_s(&pas, fi2, "r");
		for (int i = 0; i < 10; i++)
		{
			fscanf_s(pas, "%d %s %d %d %d %d %lf\n", &data[i].num, data[i].name, 5, &data[i].kuk, &data[i].eng, &data[i].su, &data[i].sum, &data[i].avg);
		}
		fclose(pas);
	}

	case 1:																				//��ó�� �ʱⰪ�� ������ ������ �ҷ�����
	{
		FILE* pas_1;
		fopen_s(&pas_1, "student.txt", "rb");
		for (int i = 0; i < 10; i++)
		{
			fread(data, sizeof(student), 10, pas_1);
		}
		fclose(pas_1);

		print();
	}
	}
}	

void print()																			//���� ��� �Լ�
{
	printf("========================================================================================================================\n");
	printf("\t\t\t\t\t\t���� ���� ���α׷�\n\n");
	printf("========================================================================================================================\n");
	printf("\t\t\t\t��ȣ \t �̸� \t ���� \t ���� \t ���� \t ����\t ���\n");
	for (int i = 0; i < 10; i++)
	{
		if (data[i].num == 0)															//������ ����ϳ� ������ ������ �ֱ⿡ �װ� �˻��ϰ� ����ϴ� ���ǹ� 
			break;

		printf("\t\t\t\t%2d��\t%5s %6d  %6d  %6d \t %3d \t %5.3f\n", data[i].num, data[i].name, data[i].kuk, data[i].eng, data[i].su, data[i].sum, data[i].avg);
	}
	printf("\n");
}	   //���

void Jung()																				//�����͸� �����ϴ� �Լ�
{
	int sun=0;
	
	printf("������ ��ȣ 1~10������ ��ȣ�� ����ּ��� : ");
	scanf_s("%d", &sun);
	while(1 > sun || 10<sun)															//�����ʹ� 10���� �л��� �����͸� �����Ƿ� �� ���� ���� �� �� �ְ� �����˻�
	{
		printf("������ ��ȣ�� 1~10 ���� �Դϴ�. �ٽ� 1~10������ ��ȣ�� ����ּ��� : ");
		scanf_s("%d", &sun);
	}

	printf("%d���� �̸� : ",sun);
	scanf_s("%s", data[sun-1].name, 5);

	printf("%d���� �������� : ", sun);
	scanf_s("%d", &data[sun-1].kuk);

	printf("%d���� �������� : ", sun);
	scanf_s("%d", &data[sun-1].eng);

	printf("%d���� �������� : ", sun);
	scanf_s("%d", &data[sun-1].su);
	
	data[sun-1].num = sun;
	
	data[sun-1].sum = data[sun-1].kuk + data[sun-1].eng + data[sun-1].su;
	data[sun-1].avg = (double)data[sun-1].sum / 3;
}	   //����

void in()
{
	system("cls");
	int ss = 99;
	
	printf("���� ������ �л��� �̸�, ��������, ��������, ���������� �־��ּ���.\n");

	for (int i = 0; i < 10;i++)												//���� �Ǿ����� ��ȣ�� 0���� �����ǰ� �����Ƿ� �� ��ȣ�� ã�� �� �ּҿ� ���� ����
	{
		if (data[i].num == 0)
		{
			ss = i;
			break;
		}
	}

	if (ss == 99)															// �뷮�� �����Ѱ�� ���� �޼���
	{	
		printf("����� ����á���ϴ�.\n");					
		return;
	}

	printf("�̸� : ");
	scanf_s("%s", data[ss].name, 5);

	printf("�������� : ");
	scanf_s("%d", &data[ss].kuk);

	printf("�������� : ");
	scanf_s("%d", &data[ss].eng);

	printf("�������� : ");
	scanf_s("%d", &data[ss].su);

	data[ss].num = ss+1;

	data[ss].sum = data[ss].kuk + data[ss].eng + data[ss].su;
	data[ss].avg = (double)data[ss].sum / 3;
}			//����

void sak()																	//������ �����ϴ� �Լ�
{
	int sun = 0;

	printf("������ ��ȣ 1~10������ ��ȣ�� ����ּ��� : ");
	scanf_s("%d", &sun);
	while (1 > sun || 10 < sun)												//�߸��� ��ȣ�� �Է��ߴ��� Ȯ��
	{
		printf("������ ��ȣ�� 1~10 ���� �Դϴ�. �ٽ� 1~10������ ��ȣ�� ����ּ��� : ");
		scanf_s("%d", &sun);
	}

	for (int i = sun - 1; i < 10; i++)										//������ �����ϰ� �� �ڿ��ִ� �����͵��� ������ ���� �ݺ���
	{
		if (data[i + 1].num == 0 || i == 9)									//�Էµ� �������� ���� Ȯ�� �۾��ϴ� ���ǹ�
		{
			data[i].num = 0;
			break;
		}
		strcpy_s(data[i].name, 5,data[i + 1].name);
		data[i].kuk = data[i+1].kuk;
		data[i].eng = data[i+1].eng;
		data[i].su = data[i+1].su;
		data[i].num = i+1;
		data[i].sum = data[i+1].kuk + data[i+1].eng + data[i+1].su;
		data[i].avg = (double)data[i+1].sum / 3;

	}
}			//����

void Name()																	// �̸����� �����ϴ� �Լ�
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
}		//�̸��� ����

void Num()																			//�������� �����ϴ� �Լ�
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
}	   //������ ����


void swap(int a, int b)																	//������ ��ȯ �Լ�
{
	student temp;

	strcpy_s(temp.name,5,data[a].name);
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
}

