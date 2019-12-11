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
void Save();				//저장
void Load(int a);			//불러오기
void print();				//출력
void Jung();				//수정
void in();					//삽입
void sak();					//삭제
void Delete(student* Node);
//void Name();				//이름순 정렬
//void Num();					//성적순 정렬
void swap(int a, int b);
void FrontNodein(student* newNode, student* end);	//새로운 노드 삽입
int Find(int a);			//번호 찾기
int numfind();		//삭제된 번호 찾아서 대입

int main()
{
	int select;
	int bun;

	one_1();
	one();

	while (1)
	{
		printf("원하는 작업을 선택하세요. 저장(1), 로드(2), 출력(3), 수정(4), 삽입(5), 삭제(6), 정렬(7), 초기값(8), 종료(99) : ");
		scanf_s("%d", &select);

		if ((select < 1 || select>8) && (select != 99))					//번호를 입력하는 범위와 다를 경우 오류검사
		{
			printf("잘못 선택하셨습니다. 다시 골라주세요\n");
		}

		switch (select)													//select에 원하는 작업 번호를 받고 실행
		{
		case 1:
			Save();														//저장
			break;

		case 2:
			Load(0);														//로드
			break;

		case 3:
			print();													//출력
			break;

		case 4:															//수정
			Jung();
			break;

		case 5:															//삽입
			in();
			break;

		case 6:															//삭제
			sak();
			break;

		case 7:															//정렬
		{
			printf("이름(1), 총점(2) 중 원하는 정렬법 한가지를 골라 번호를 적어주세요 : ");
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

		case 99:														//종료
			system("cls");
			printf("아무키나 누르면 종료됩니다.");
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
int NodeInOut=0;			//노드 삭제와 생성으로 생긴 공백용량 측정
int cut = MAX_STUDENT;				//불러올때 크기가 다를 경우 크기 측정


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
	Link_End = 0;								//메모리 해제는 시작주소를 반환해야한다
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
	//srand(time(NULL));	한번만 입력받는용으로 사용할거라 안써도 된다.
	int i;
	student* newNode;
	FILE* pa_one;
	fopen_s(&pa_one, "student.txt", "wb");											//초기값을 불러오기 위해 데이터를 저장할 파일 생성
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
	fwrite(cho, sizeof(student), 1, pa_one);											//초기값 저장
	fclose(pa_one);
	print();
}

void Save()																			//파일 저장하기
{
	student* Node = Link_Head->m_next;
	int size;
	char fi[30];
	printf("저장하기 희망하는 파일명을 적어주세요 : ");								//파일의 명을 입력받아 fopen함수에 넣어 원하는 파일을 생성
	scanf_s("%s", fi, 30);

	size = strcmp(fi, "student.txt");
	while (size == 0)																	//초기값이 넣어진 파일에 겹치는지 확인
	{
		printf("중복 되었습니다 다른 파일명을 적어주세요 : ");
		scanf_s("%s", fi, 30);
		size = strcmp(fi, "student.txt");
	}

	FILE* pa;
	/*fopen_s(&pa, fi, "w");															//파일의 명을 입력받아 fopen함수에 넣어 원하는 파일을 생성
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
}	   //저장

void Load(int a)																			//저장된 파일 불러오기
{
	//system("cls");
	student* Node = Link_Head->m_next;
	int err;

	switch (a)
	{
	case 0:																				//원하는 파일명을 입력하여 불러오기
	{
		char fi2[30];
		printf("불러오길 바라는 저장파일을 적어주세요 : ");								//파일의 명을 입력받아 fopen함수에 넣어 원하는 파일을 불러온다.
		scanf_s("%s", fi2, 30);
		FILE* pas;
		fopen_s(&pas, fi2, "r");
		for (int i = 0; i < MAX_STUDENT; i++)				//fscaf 사용
		{
			err=fscanf_s(pas, "%d %s %d %d %d %d %lf\n", &Node->num, Node->name, 5, &Node->kuk, &Node->eng, &Node->su, &Node->sum, &Node->avg);
			if (err==EOF)							//파일에서 더이상 받아오는 자료가 없을시
			{
				Link_End->m_next = Link_Tail;		//이번 로드파일은 여기까지
				break;
			}
			Link_End = Node;
			Node = Node->m_next;
		}
		/*for (int i = 0; i < MAX_STUDENT; i++)				//fread 사용
		{													//반복 횟수를 한번에 하면 편하나 반복문으로 적어 보았다.
			err=fread(Node, sizeof(stu), 1, pas);
			if (err == NULL)
			{
				Link_End->m_next = Link_Tail;		//이번 로드파일은 여기까지
				break;
			}
			Link_End = Node;
			Node = Node->m_next;
		}*/

		fclose(pas);
		print();
		break;
	}

	case 1:																				//맨처음 초기값을 저장한 파일을 불러오기
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
		for (int i = 0; i < MAX_STUDENT; i++)				//fread 사용
		{										
			if (Node == Link_Tail)
			{
				Link_End->m_next = Link_Tail;		//이번 로드파일은 여기까지
				break;
			}
																		//반복 횟수를 한번에 하면 편하나 반복문으로 적어 보았다.
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

void print()																			//파일 출력 함수
{
	student* Node = Link_Head->m_next;
	printf("========================================================================================================================\n");
	printf("\t\t\t\t\t\t성적 관리 프로그램\n\n");
	printf("========================================================================================================================\n");
	printf("\t\t\t\t번호 \t 이름 \t 국어 \t 영어 \t 수학 \t 총점\t 평균\n");
	for (int i = 1; i <= MAX_STUDENT; i++)
	{

		printf("\t\t\t\t%2d번\t%5s %6d  %6d  %6d \t %3d \t %5.3f\n", Node->num, Node->name, Node->kuk, Node->eng, Node->su, Node->sum, Node->avg);
		Node = Node->m_next;
		if (Node == Link_Tail)																		//파일을 출력하나 삭제와 삽입이 있기에 그걸 검사하고 출력하는 조건문 
		{
			break;
		}
	
		
	}
	printf("\n");
}	   //출력

void Jung()																				//데이터를 수정하는 함수
{
	student* Node = Link_Head->m_next;
	int sun = 0;

	printf("수정할 번호 1~10사이의 번호를 골라주세요 : ");
	scanf_s("%d", &sun);
	while (1 > sun || 10 < sun)															//데이터는 10명의 학생의 데이터만 받으므로 그 안의 수를 고를 수 있게 오류검사
	{
		printf("수정할 번호는 1~10 사이 입니다. 다시 1~10사이의 번호를 골라주세요 : ");
		scanf_s("%d", &sun);
	}

	for (int i = 1; i < sun; i++)
	{
		Node = Node->m_next;
	}

	printf("%d번의 이름 : ", sun);
	scanf_s("%s", Node->name, 5);

	printf("%d번의 국어점수 : ", sun);
	scanf_s("%d", &Node->kuk);

	printf("%d번의 영어점수 : ", sun);
	scanf_s("%d", &Node->eng);

	printf("%d번의 수학점수 : ", sun);
	scanf_s("%d", &Node->su);

	Node->sum = Node->kuk + Node->eng + Node->su;
	Node->avg = (double)Node->sum / 3;
}	   //수정*/

void in()
{
	student* Node=Link_Head->m_next;
	student* temp;
	int a,b;
	system("cls");
	do
	{
		printf("삽입하고 싶은 곳의 번호를 입력하세요 : ");
		scanf_s("%d", &a);
		b = Find(a);
	} while (b == 0);


	for (int i = 1; i < b; i++)
	{
		Node = Node->m_next;
	}
	temp = (student*)calloc(1, sizeof(student));
	printf("새로 삽입할 학생의 이름, 국어점수, 영어점수, 수학점수를 넣어주세요.\n");


	printf("이름 : ");
	scanf_s("%s", temp->name, 5);

	printf("국어점수 : ");
	scanf_s("%d", &temp->kuk);

	printf("영어점수 : ");
	scanf_s("%d", &temp->eng);

	printf("수학점수 : ");
	scanf_s("%d", &temp->su);

	temp->num = numfind();

	temp->sum = temp->kuk + temp->eng + temp->su;
	temp->avg = (double)temp->sum / 3;

	FrontNodein(temp, Node);
}

void sak()																	//데이터 삭제하는 함수
{
	student* Node = Link_Head->m_next;
	int sun = 0;
	int num;

	printf("삭제할 번호 1~%d사이의 번호를 골라주세요 : ",MAX_STUDENT);
	scanf_s("%d", &sun);
	while (1 > sun || MAX_STUDENT < sun)												//잘못된 번호를 입력했는지 확인
	{
		printf("삭제할 번호는 1~%d 사이 입니다. 다시 1~%d사이의 번호를 골라주세요 : ",MAX_STUDENT, MAX_STUDENT);
		scanf_s("%d", &sun);
	}
	num = Find(sun);
	if (num == 0)
	{
		printf("맞는 번호가 없습니다.");
	}
	for (int i = 1; i < num; i++)
	{
		Node = Node->m_next;
	}

	Delete(Node);
	
}			//삭제

/*void Name()																	// 이름으로 정렬하는 함수
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
}*/

/*void Num()																			//총점으로 정렬하는 함수
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
}	   //성적순 정렬*/


/*void swap(int a, int b)																	//데이터 교환 함수
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

/*void swap(stu* Node, stu* Daum)																	//데이터 교환 함수
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
	student* Node = Link_Head->m_next;				//첫 노드 입력
	int count = 1;								//몇번째 노드인지 확인할 수
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
		Link_End = Node;						//Link_End에 현재 노드위치 저장
		Node = Node->m_next;					//다음 노드 불러내기
	}
	return 0;
}

void Delete(student* Node)
{
	student* temp=Node->m_next;				//삭제할 노드의 뒷 노드의 위치를 temp에 전달
	Link_End->m_next=temp;				//Link_End가 Find함수를 통해 삭제할 노드 앞 노드와 같은 위치였으니 그 다음 주소를 삭제 노드 뒷 위치의 노드로 연결
	
	free(Node);							//삭제

	NodeInOut++;						//노드 삭제와 추가로 생긴 용량 공백
}

int numfind()					//없는 숫자 집어넣기
{
	student* Node = Link_Head->m_next;
	int a;
	int size = MAX_STUDENT - NodeInOut;	//반복해서 돌아갈때 NULL값을 받는 일이 없도록 가진 값이 얼마인지 측정
	for (int i = 1; i <= MAX_STUDENT; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == Node->num)			//이미 있는 넘버일 경우
			{
				a = 0;
				break;
			}
			Node = Node->m_next;
			a = 1;
		}
		if(a==1)
		{
			return i;					//값을 찾은 경우
		}
		Node = Link_Head->m_next;
	}
	return 0;							//값을 찾지 못한경우

}