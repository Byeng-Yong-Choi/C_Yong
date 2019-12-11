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

void Allmake(int a);		//노드 a수만큼 생성
void one();					//초기값
void one_1();				//헤드와 꼬리 생성과 2중 연결
void one_end();				//헤드와 꼬리 해제
void Nodefree();			//노드 해제
void Save();				//저장
void Load(int a);			//불러오기
void print();				//출력
void Jung();				//수정
void in();					//삽입
void sak();					//삭제
void Delete(student* Node);		//노드 삭제
void AllDelete();			//노드 모두 삭제
void Name();				//이름순 정렬
void Num();					//성적순 정렬
//void swap(int a, int b);
void swap(student* Node, student* Daum);	//노드끼리의 데이터 스왑
void swappa(student* Node, student* Daum);	//노드의 주소값을 서로 교환하여 데이터 바꾸기
student* reswap(int a);				//노드의 주소값 교환을 위해 재귀함수로 주소 맞추는 용도
void FrontNodein(student* newNode, student* head);	//새로운 후위 노드 삽입
void BackNodein(student* newNode, student* head);	//새로운 전위 노드 삽입
int Find(int a);			//번호 찾기
int numfind();		//삭제된 번호 찾아서 대입
student* make();				//노드 새로 만들기
int NodeNumber();			//몇개의 노드를 가지고 있는지 측정


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

student* Link_Head = 0;
student* Link_Tail = 0;
int cut = MAX_STUDENT;				//불러올때 크기가 다를 경우 크기 측정


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
	//srand(time(NULL));	한번만 입력받는용으로 사용할거라 안써도 된다.
	int i;
	student* newNode;
	FILE* pa_one;
	fopen_s(&pa_one, "student.txt", "w");											//초기값을 불러오기 위해 데이터를 저장할 파일 생성
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
		//fwrite(cho, sizeof(stu), 1, pa_one);	//초기값 저장
		cho = cho->m_next;
	}
	fclose(pa_one);
	print();
}

void Save()																			//파일 저장하기
{
	student* Node;
	Node = Link_Head->m_next;
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
	fopen_s(&pa, fi, "w");															//파일의 명을 입력받아 fopen함수에 넣어 원하는 파일을 생성
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
}	   //저장

void Load(int a)																			//저장된 파일 불러오기
{
	//system("cls");
	student* temp;			//딜리트를 위해 받기용
	int err;
	unsigned int er = 0;
	AllDelete();
	student* Node = make();

	switch (a)
	{
	case 0:																				//원하는 파일명을 입력하여 불러오기
	{
		char fi2[30];
		printf("불러오길 바라는 저장파일을 적어주세요 : ");								//파일의 명을 입력받아 fopen함수에 넣어 원하는 파일을 불러온다.
		scanf_s("%s", fi2, 30);
		FILE* pas;
		fopen_s(&pas, fi2, "r");

		//fscaf 사용
		while (1)
		{
			if (Node == Link_Tail)
			{
				Node = make();
				er = 1;										//0이면 진행 1이면 끝에 다다랐다는 뜻
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
		}													//노드를 하나 하나 생성 삭제
		/*while(1)				//fread 사용
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
	}break;
	
	case 1:																				//맨처음 초기값을 저장한 파일을 불러오기
	{
		FILE* pas_1;
		student* temp;
	
		fopen_s(&pas_1, "student.txt", "r");
		while(1)
	{
		if (Node == Link_Tail)
		{
			Node = make();
			er = 1;										//0이면 진행 1이면 끝에 다다랐다는 뜻
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

		/*for (int i = 0; i < MAX_STUDENT; i++)				//fscaf 사용
		{
			if (Node == Link_Tail)
			{
				Node = make();
				er = 1;										//0이면 진행 1이면 끝에 다다랐다는 뜻
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

void print()																			//파일 출력 함수
{
	student* Node = Link_Head->m_next;
	printf("========================================================================================================================\n");
	printf("\t\t\t\t\t\t성적 관리 프로그램\n\n");
	printf("========================================================================================================================\n");
	printf("\t\t\t\t번호 \t 이름 \t 국어 \t 영어 \t 수학 \t 총점\t 평균\n");
	for (int i = 1; i <= NodeNumber(); i++)
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
	int num;

	printf("수정할 번호 1~%d사이의 번호를 골라주세요 : ", NodeNumber());
	scanf_s("%d", &sun);
	while (1 > sun || NodeNumber() < sun)															//데이터는 10명의 학생의 데이터만 받으므로 그 안의 수를 고를 수 있게 오류검사
	{
		printf("수정할 번호는 1~%d 사이 입니다. 다시 1~%d사이의 번호를 골라주세요 : ", NodeNumber(),NodeNumber());
		scanf_s("%d", &sun);
	}

	num=Find(sun);

	for (int i = 1; i < num; i++)
	{
		Node = Node->m_next;
	}

	printf("%d번의 이름 : ", num);
	scanf_s("%s", Node->name, 5);

	printf("%d번의 국어점수 : ", num);
	scanf_s("%d", &Node->kuk);

	printf("%d번의 영어점수 : ", num);
	scanf_s("%d", &Node->eng);

	printf("%d번의 수학점수 : ", num);
	scanf_s("%d", &Node->su);

	Node->sum = Node->kuk + Node->eng + Node->su;
	Node->avg = (double)Node->sum / 3;
}	   //수정*/

void in()											//데이터 삽입
{
	student* Node = Link_Head->m_next;
	student* temp;
	int a, b;
	//system("cls");
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

void sak()																	//데이터 삭제하는 함수
{
	student* Node = Link_Head->m_next;
	int sun = 0;
	int num;

	printf("삭제할 번호를 골라주세요: ");
	scanf_s("%d", &sun);
	/*while (1 > sun || NodeNumber() < sun)												//잘못된 번호를 입력했는지 확인
	{
		printf("삭제할 번호는 1~%d 사이 입니다. 다시 1~%d사이의 번호를 골라주세요 : ", NodeNumber(), NodeNumber());
		scanf_s("%d", &sun);
	}*/
	num = Find(sun);
	if (num == 0)
	{
		printf("맞는 번호가 없습니다.\n");
	}
	for (int i = 1; i < num; i++)
	{
		Node = Node->m_next;
	}

	Delete(Node);

}			//삭제

void Name()																	// 이름으로 정렬하는 함수
{
	int se;				//케이스문 선택을 위해 입력받기 위해 쓰일 변수
	int cu;				//문자열 비교에 쓰일 변수
	int i, j;			//반복문에 쓰일 변수
	int NodeNum;
	student* Node=Link_Head->m_next;
	student* NodeComparison=Node->m_next;					//노드와 비교하기 위한 선언 노드의 다음 노드를 대입한다


	printf("정렬할 이름의 오름차순(1), 내림차순(2) 선택해주세요(이름이 같을경우 국어,영어,수학 순으로 정렬합니다) : ");
	scanf_s("%d", &se);

	NodeNum = NodeNumber();			//노드 개수를 측정하는 함수를 이용하여 개수 측정후 대입

	for (i = 0; i < NodeNum; i++)
	{

		for (j = i; j < NodeNum; j++)
		{
			if (NodeComparison != Link_Tail)
			{
				cu = strcmp(Node->name, NodeComparison->name);		//이름을 비교하여 사전 뒤에 나오면 1을 반환받아 스왑함수로 데이터 교환


				switch (se)																//선택을 입력받아 오름차순을 할지 내림차순을 할지 결정
				{

				case 1:														//오름차순
				{
					if (cu == 1)
					{
						swap(Node, NodeComparison);
					}
					else if (cu == 0)											//이름이 같을 경우 성적으로 오름차순 정하는 조건문
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

				case 2:														//내림차순
				{
					if (cu == -1)
					{
						swap(Node, NodeComparison);
					}
					else if (cu == 0)											//이름이 같을 경우 성적으로 내림차순 정하는 조건문
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
			NodeComparison = Node->m_next;			//NodeComparison 변수는 Node 다음거와 문자열을 비교해야 하므로 다음 노드것을 가르키게 한다
		}
		else
			break;
		

	}
}

void Num()																			//총점으로 정렬하는 함수
{
	int se;
	int cu;
	int NodeNum;
	student* Node = Link_Head->m_next;
	student* NodeComparison = Node->m_next;
	

	NodeNum = NodeNumber();			//노드 개수를 측정하는 함수를 이용하여 개수 측정후 대입

	printf("정렬할 총점의 오름차순(1), 내림차순(2) 선택해주세요(총점이 같을경우 이름순으로 정렬합니다) : ");
	scanf_s("%d", &se);

	/*for (int i = 0; i < NodeNum; i++)
	{
		for (int j = i; j < NodeNum; j++)
		{
			if (NodeComparison != Link_Tail)
			{
				Node = reswap(i);
				NodeComparison = reswap(j);
				cu = strcmp(Node->name, NodeComparison->name);								//총점이 같을경우 이름으로 비교하기위해 계산하는 식
				switch (se)																//선택을 입력받아 오름차순을 할지 내림차순을 할지 결정
				{
				case 1:																	//오름차순
				{
					if (Node->sum > NodeComparison->sum)
					{
						swap(Node, NodeComparison);
					}
					else if (Node->sum == NodeComparison->sum)											//성적이 같을 경우 이름으로 오름차순 정하는 조건문
					{
						if (cu == 1)
						{
							swap(Node, NodeComparison);
						}
					}

					break;
				}

				case 2:																	//내림차순
				{
					if (Node->sum < NodeComparison->sum)
					{
						swap(Node, NodeComparison);
					}
					else if (Node->sum == NodeComparison->sum)											//성적이 같을 경우 이름으로 내림차순 정하는 조건문
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
	
	for (int i = 0; i < NodeNum; i++)					//주소값을 바꿀때
	{
		for (int j = i; j < NodeNum; j++)
		{
			if (NodeComparison != Link_Tail)
			{
				if (i == 0)						// i==0일때 주소값이 헤드가 되기에 설정해준 조건문
				{
					Node = Link_Head->m_next;
				}
				else
				{
					Node = reswap(i);
				}
				NodeComparison = reswap(j+1);
				cu = strcmp(Node->name, NodeComparison->name);								//총점이 같을경우 이름으로 비교하기위해 계산하는 식
				
				switch (se)																//선택을 입력받아 오름차순을 할지 내림차순을 할지 결정
				{
				case 1:																	//오름차순
				{
					if (Node->sum > NodeComparison->sum)
					{
						swappa(Node, NodeComparison);
					}
					else if (Node->sum == NodeComparison->sum)											//성적이 같을 경우 이름으로 오름차순 정하는 조건문
					{
						if (cu == 1)
						{
							swappa(Node, NodeComparison);
						}
					}

					break;
				}

				case 2:																	//내림차순
				{
					if (Node->sum < NodeComparison->sum)
					{
						swappa(Node, NodeComparison);
					}
					else if (Node->sum == NodeComparison->sum)											//성적이 같을 경우 이름으로 내림차순 정하는 조건문
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
				//주소값을 바꿀때

}	   //성적순 정렬


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

void FrontNodein(student* newNode, student* head)
{
	//next 연결
	student* temp = head->m_next;
	head->m_next = newNode;
	newNode->m_next = temp;
	
	//prev 연결
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

void swap(student* Node, student* Daum)																	//데이터 교환 함수
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

void swappa(student* Node, student* Daum)				//노드의 주소를 바꿔 값 바꾸기
{
	student* temp;
	student* swap;

	//바꾸는 노드들의 앞 주소 교환
	temp = Node->m_prev;
	swap = Daum->m_prev;
	temp->m_next = Daum;
	swap->m_next = Node;
	Daum->m_prev = temp;
	Node->m_prev = swap;

	//바꾸는 노드들의 뒷 주소 교환
	temp = Node->m_next;
	swap = Daum->m_next;
	temp->m_prev = Daum;
	swap->m_prev = Node;
	Node->m_next = swap;
	Daum->m_next = temp;

}

int Find(int a)
{
	student* Node = Link_Head->m_next;				//첫 노드 입력
	int count = 1;								//몇번째 노드인지 확인할 수
	for (int i = 1; i <= NodeNumber(); i++)
	{
		if (Node->num == a)
		{
			return count;
		}
		count++;
		Node = Node->m_next;					//다음 노드 불러내기
	}
	return 0;
}

void Delete(student* Node)
{
	student* temp = Node->m_prev;
	student* temp_2 = Node->m_next;
	temp->m_next = temp_2;
	temp_2->m_prev = temp;
	free(Node);							//삭제
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
		free(Node);							//모두삭제
		Node = temp_2;
	}
}

int numfind()					//없는 숫자 집어넣기
{
	student* Node = Link_Head->m_next;
	int a;
	int size = NodeNumber();
	for (int i = 1; i <=size; i++)
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
		if (a == 1)
		{
			return i;					//값을 찾은 경우
		}
		Node = Link_Head->m_next;
	}
	return 0;							//값을 찾지 못한경우

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

int NodeNumber()					//노드 개수찾기
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