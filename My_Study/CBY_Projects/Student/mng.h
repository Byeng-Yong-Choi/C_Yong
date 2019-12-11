#pragma once
#include <time.h>		
#include <stdio.h>			
#include <stdlib.h>
#include <conio.h>
#include<string.h>

void Save();				//저장
void Load(int a);			//불러오기
void print();				//출력
void Jung();				//수정
void in();					//삽입
void sak();					//삭제
void Name();				//이름순 정렬
void Num();					//성적순 정렬
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
	//srand(time(NULL));	한번만 입력받는용으로 사용할거라 안써도 된다.

	FILE* pa_one;
	fopen_s(&pa_one,"student.txt", "wb");											//초기값을 불러오기 위해 데이터를 저장할 파일 생성

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

	fwrite(data, sizeof(student), 10,pa_one);											//초기값 저장
	fclose(pa_one);
	print();
	//free(data);
}

void Save()																			//파일 저장하기
{	
	int size;
	char fi[30];
	printf("저장하기 희망하는 파일명을 적어주세요 : ");								//파일의 명을 입력받아 fopen함수에 넣어 원하는 파일을 생성
	scanf_s("%s", fi,30);
	
	size = strcmp(fi, "student.txt");
	while(size==0)																	//초기값이 넣어진 파일에 겹치는지 확인
	{
		printf("중복 되었습니다 다른 파일명을 적어주세요 : ");								
		scanf_s("%s", fi, 30);
		size = strcmp(fi, "student.txt");
	}

	FILE* pa;
	fopen_s(&pa, fi, "w");															//파일의 명을 입력받아 fopen함수에 넣어 원하는 파일을 생성
	for (int i = 0; i < 10; i++)
	{
		fprintf(pa, "%d %s %d %d %d %d %.3lf\n", data[i].num, data[i].name, data[i].kuk, data[i].eng, data[i].su, data[i].sum, data[i].avg);
	}
	fclose(pa);
}	   //저장

void Load(int a)																			//저장된 파일 불러오기
{
	//system("cls");

	switch (a)
	{
	case 0:																				//원하는 파일명을 입력하여 불러오기
	{
		char fi2[30];
		printf("불러오길 바라는 저장파일을 적어주세요 : ");								//파일의 명을 입력받아 fopen함수에 넣어 원하는 파일을 불러온다.
		scanf_s("%s", fi2, 30);
		FILE* pas;
		fopen_s(&pas, fi2, "r");
		for (int i = 0; i < 10; i++)
		{
			fscanf_s(pas, "%d %s %d %d %d %d %lf\n", &data[i].num, data[i].name, 5, &data[i].kuk, &data[i].eng, &data[i].su, &data[i].sum, &data[i].avg);
		}
		fclose(pas);
	}

	case 1:																				//맨처음 초기값을 저장한 파일을 불러오기
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

void print()																			//파일 출력 함수
{
	printf("========================================================================================================================\n");
	printf("\t\t\t\t\t\t성적 관리 프로그램\n\n");
	printf("========================================================================================================================\n");
	printf("\t\t\t\t번호 \t 이름 \t 국어 \t 영어 \t 수학 \t 총점\t 평균\n");
	for (int i = 0; i < 10; i++)
	{
		if (data[i].num == 0)															//파일을 출력하나 삭제와 삽입이 있기에 그걸 검사하고 출력하는 조건문 
			break;

		printf("\t\t\t\t%2d번\t%5s %6d  %6d  %6d \t %3d \t %5.3f\n", data[i].num, data[i].name, data[i].kuk, data[i].eng, data[i].su, data[i].sum, data[i].avg);
	}
	printf("\n");
}	   //출력

void Jung()																				//데이터를 수정하는 함수
{
	int sun=0;
	
	printf("수정할 번호 1~10사이의 번호를 골라주세요 : ");
	scanf_s("%d", &sun);
	while(1 > sun || 10<sun)															//데이터는 10명의 학생의 데이터만 받으므로 그 안의 수를 고를 수 있게 오류검사
	{
		printf("수정할 번호는 1~10 사이 입니다. 다시 1~10사이의 번호를 골라주세요 : ");
		scanf_s("%d", &sun);
	}

	printf("%d번의 이름 : ",sun);
	scanf_s("%s", data[sun-1].name, 5);

	printf("%d번의 국어점수 : ", sun);
	scanf_s("%d", &data[sun-1].kuk);

	printf("%d번의 영어점수 : ", sun);
	scanf_s("%d", &data[sun-1].eng);

	printf("%d번의 수학점수 : ", sun);
	scanf_s("%d", &data[sun-1].su);
	
	data[sun-1].num = sun;
	
	data[sun-1].sum = data[sun-1].kuk + data[sun-1].eng + data[sun-1].su;
	data[sun-1].avg = (double)data[sun-1].sum / 3;
}	   //수정

void in()
{
	system("cls");
	int ss = 99;
	
	printf("새로 삽입할 학생의 이름, 국어점수, 영어점수, 수학점수를 넣어주세요.\n");

	for (int i = 0; i < 10;i++)												//삭제 되었을때 번호가 0으로 지정되게 했으므로 그 번호를 찾고 그 주소에 값을 대입
	{
		if (data[i].num == 0)
		{
			ss = i;
			break;
		}
	}

	if (ss == 99)															// 용량이 가득한경우 오류 메세지
	{	
		printf("목록이 가득찼습니다.\n");					
		return;
	}

	printf("이름 : ");
	scanf_s("%s", data[ss].name, 5);

	printf("국어점수 : ");
	scanf_s("%d", &data[ss].kuk);

	printf("영어점수 : ");
	scanf_s("%d", &data[ss].eng);

	printf("수학점수 : ");
	scanf_s("%d", &data[ss].su);

	data[ss].num = ss+1;

	data[ss].sum = data[ss].kuk + data[ss].eng + data[ss].su;
	data[ss].avg = (double)data[ss].sum / 3;
}			//삽입

void sak()																	//데이터 삭제하는 함수
{
	int sun = 0;

	printf("삭제할 번호 1~10사이의 번호를 골라주세요 : ");
	scanf_s("%d", &sun);
	while (1 > sun || 10 < sun)												//잘못된 번호를 입력했는지 확인
	{
		printf("삭제할 번호는 1~10 사이 입니다. 다시 1~10사이의 번호를 골라주세요 : ");
		scanf_s("%d", &sun);
	}

	for (int i = sun - 1; i < 10; i++)										//삭제를 진행하고 그 뒤에있던 데이터들을 앞으로 당기는 반복문
	{
		if (data[i + 1].num == 0 || i == 9)									//입력된 데이터의 끝을 확인 작업하는 조건문
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
}			//삭제

void Name()																	// 이름으로 정렬하는 함수
{
	int se;
	int cu;

	printf("정렬할 이름의 오름차순(1), 내림차순(2) 선택해주세요(이름이 같을경우 국어,영어,수학 순으로 정렬합니다) : ");
	scanf_s("%d", &se);

	for (int i = 0; i < 10; i++)
	{
		for (int j = i; j < 10; j++)									
		{
			cu = strcmp(data[i].name, data[j].name);					//이름을 비교하여 사전 뒤에 나오면 1을 반환받아 스왑함수로 데이터 교환
			switch (se)																//선택을 입력받아 오름차순을 할지 내림차순을 할지 결정
			{

			case 1:														//오름차순
			{
				if (cu == 1)
				{
					swap(i, j);
				}
				else if (cu == 0)											//이름이 같을 경우 성적으로 오름차순 정하는 조건문
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
			
			case 2:														//내림차순
				{
				if (cu == -1)
				{
					swap(i, j);
				}
				else if (cu == 0)											//이름이 같을 경우 성적으로 내림차순 정하는 조건문
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
}		//이름순 정렬

void Num()																			//총점으로 정렬하는 함수
{
	int se;
	int cu;

	printf("정렬할 총점의 오름차순(1), 내림차순(2) 선택해주세요(총점이 같을경우 이름순으로 정렬합니다) : ");
	scanf_s("%d", &se);

	for (int i = 0; i < 10; i++)
	{
		for (int j = i; j < 10; j++)
		{
			cu = strcmp(data[i].name, data[j].name);								//총점이 같을경우 이름으로 비교하기위해 계산하는 식
			switch (se)																//선택을 입력받아 오름차순을 할지 내림차순을 할지 결정
			{
			case 1:																	//오름차순
			{
				if (data[i].sum > data[j].sum)
				{
					swap(i, j);
				}
				else if (data[i].sum == data[j].sum)											//성적이 같을 경우 이름으로 오름차순 정하는 조건문
				{
					if (cu == 1)
					{
						swap(i, j);
					}
				}
					
				break;
			}

			case 2:																	//내림차순
			{
				if (data[i].sum < data[j].sum)
				{
					swap(i, j);
				}
				else if (data[i].sum == data[j].sum)											//성적이 같을 경우 이름으로 내림차순 정하는 조건문
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
}	   //성적순 정렬


void swap(int a, int b)																	//데이터 교환 함수
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

