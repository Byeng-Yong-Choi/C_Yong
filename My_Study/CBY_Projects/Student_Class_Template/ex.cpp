#include "Control.cpp"
#include "student.h"



//void Allmake(int a);		//노드 a수만큼 생성
void print();
void one();					//초기값
//void Save();				//저장
//void Load(int a);			//불러오기
//void AllDelete();			//노드 모두 삭제
//void Name();				//이름순 정렬
//void Num();					//성적순 정렬
//StuNode<student>* reswap(int a);				//노드의 주소값 교환을 위해 재귀함수로 주소 맞추는 용도
//StuNode<student>* make();				//노드 새로 만들기

LinkList<student> Link;		//링크리스트 호출
StuNode<student>* Head=Link.getHead();
StuNode<student>* Tail=Link.getTail();
Control<student> Con;		//컨트롤 클래스 호출

int main()
{
	int select;
	int bun;
	StuNode<student> one_1;

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
			//Save();														//저장
			break;

		case 2:
			//Load(0);														//로드
			break;

		case 3:
			print();													//출력
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
	StuNode<student> cho;
	cho.oneone(Tail);
	//int i;
//	FILE* pa_one;
	/*fopen_s(&pa_one, "student.txt", "w");											//초기값을 불러오기 위해 데이터를 저장할 파일 생성
	StuNode<student>* cho = Head->m_next;
	for (i = 0; i < MAX_STUDENT; i++)
	{
		fprintf(pa_one, "%d %s %d %d %d %d %.3lf\n", cho->stuNode->num, cho.stuNode->name, cho.stuNode->kuk, cho.stuNode->eng, cho.stuNode->su, cho.stuNode->sum, cho.stuNode->avg);
		//fwrite(cho, sizeof(stu), 1, pa_one);	//초기값 저장
		cho = cho->m_next;
	}
	/*copy->num = 15;
	printf("%d번 이름:%s, 국어:%d,영어:%d,수학:%d, 총점:%d, 평균 :%.3lf \n", copy->num, copy->name, copy->kuk, copy->eng, copy->su, copy->sum, copy->avg);
	printf("%d번 이름:%s, 국어:%d,영어:%d,수학:%d, 총점:%d, 평균 :%.3lf \n", copy.num, copy.name, copy.kuk, copy.eng, copy.su, copy.sum, copy.avg);
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
	printf("\t\t\t\t\t\t성적 관리 프로그램\n\n");
	printf("========================================================================================================================\n");
	printf("\t\t\t\t번호 \t 이름 \t 국어 \t 영어 \t 수학 \t 총점\t 평균\n");
	for (i = 1; i <= Link.NodeNumber(); i++)
	{
		out=Node->ShowData();
		out.Show();
		Node = Node->m_next;
	}
}
//
//void Save()																			//파일 저장하기
//{
//	StuNode<student>* Node;
//	Node = Link_Head->m_next;
//	int size;
//	char fi[30];
//	printf("저장하기 희망하는 파일명을 적어주세요 : ");								//파일의 명을 입력받아 fopen함수에 넣어 원하는 파일을 생성
//	scanf_s("%s", fi, 30);
//
//	size = strcmp(fi, "student.txt");
//	while (size == 0)																	//초기값이 넣어진 파일에 겹치는지 확인
//	{
//		printf("중복 되었습니다 다른 파일명을 적어주세요 : ");
//		scanf_s("%s", fi, 30);
//		size = strcmp(fi, "student.txt");
//	}
//
//	FILE* pa;
//	fopen_s(&pa, fi, "w");															//파일의 명을 입력받아 fopen함수에 넣어 원하는 파일을 생성
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
//}	   //저장
//
//void Load(int a)																			//저장된 파일 불러오기
//{
//	//system("cls");
//	int err;
//	unsigned int er = 0;
//	AllDelete();
//	StuNode<student>* Node = make();
//
//	switch (a)
//	{
//	case 0:																				//원하는 파일명을 입력하여 불러오기
//	{
//		char fi2[30];
//		printf("불러오길 바라는 저장파일을 적어주세요 : ");								//파일의 명을 입력받아 fopen함수에 넣어 원하는 파일을 불러온다.
//		scanf_s("%s", fi2, 30);
//		FILE* pas;
//		fopen_s(&pas, fi2, "r");
//
//		//fscaf 사용
//		while (1)
//		{
//			if (Node == Link_Tail)
//			{
//				Node = make();
//				er = 1;										//0이면 진행 1이면 끝에 다다랐다는 뜻
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
//		}														//노드를 하나 하나 생성 삭제
//		/*while(1)				//fread 사용
//		{													//반복 횟수를 한번에 하면 편하나 반복문으로 적어 보았다.
//			err=fread(Node, sizeof(stu), 1, pas);
//			if (err == NULL)
//			{
//				Link_End->m_next = Link_Tail;		//이번 로드파일은 여기까지
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
//	case 1:																				//맨처음 초기값을 저장한 파일을 불러오기
//	{
//		FILE* pas_1;
//
//		fopen_s(&pas_1, "student.txt", "r");
//		while (1)
//		{
//			if (Node == Link_Tail)
//			{
//				Node = make();
//				er = 1;										//0이면 진행 1이면 끝에 다다랐다는 뜻
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
//		/*for (int i = 0; i < MAX_STUDENT; i++)				//fscaf 사용
//		{
//			if (Node == Link_Tail)
//			{
//				Node = make();
//				er = 1;										//0이면 진행 1이면 끝에 다다랐다는 뜻
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
//void sak()																	//데이터 삭제하는 함수
//{
//	StuNode<student>* Node = Link_Head->m_next;
//	int sun = 0;
//	int num;
//
//	printf("삭제할 번호를 골라주세요: ");
//	scanf_s("%d", &sun);
//	/*while (1 > sun || NodeNumber() < sun)												//잘못된 번호를 입력했는지 확인
//	{
//		printf("삭제할 번호는 1~%d 사이 입니다. 다시 1~%d사이의 번호를 골라주세요 : ", NodeNumber(), NodeNumber());
//		scanf_s("%d", &sun);
//	}*/
//	num = Find(sun);
//	if (num == 0)
//	{
//		printf("맞는 번호가 없습니다.\n");
//	}
//	for (int i = 1; i < num; i++)
//	{
//		Node = Node->m_next;
//	}
//
//	Delete(Node);
//
//}			//삭제
//
//void Name()																	// 이름으로 정렬하는 함수
//{
//	int se;				//케이스문 선택을 위해 입력받기 위해 쓰일 변수
//	int cu;				//문자열 비교에 쓰일 변수
//	int i, j;			//반복문에 쓰일 변수
//	int NodeNum;
//	StuNode<student>* Node = Link_Head->m_next;
//	StuNode<student>* NodeComparison = Node->m_next;	//노드와 비교하기 위한 선언 노드의 다음 노드를 대입한다
//	StuNode<student> sw;
//
//
//	printf("정렬할 이름의 오름차순(1), 내림차순(2) 선택해주세요(이름이 같을경우 국어,영어,수학 순으로 정렬합니다) : ");
//	scanf_s("%d", &se);
//
//	NodeNum = NodeNumber();			//노드 개수를 측정하는 함수를 이용하여 개수 측정후 대입
//
//	for (i = 0; i < NodeNum; i++)
//	{
//
//		for (j = i; j < NodeNum; j++)
//		{
//			if (NodeComparison != Link_Tail)
//			{
//				cu = strcmp(Node->name, NodeComparison->name);		//이름을 비교하여 사전 뒤에 나오면 1을 반환받아 스왑함수로 데이터 교환
//
//
//				switch (se)																//선택을 입력받아 오름차순을 할지 내림차순을 할지 결정
//				{
//
//				case 1:														//오름차순
//				{
//					if (cu == 1)
//					{
//						sw.swap(*Node, *NodeComparison);
//					}
//					else if (cu == 0)											//이름이 같을 경우 성적으로 오름차순 정하는 조건문
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
//				case 2:														//내림차순
//				{
//					if (cu == -1)
//					{
//						sw.swap(*Node, *NodeComparison);
//					}
//					else if (cu == 0)											//이름이 같을 경우 성적으로 내림차순 정하는 조건문
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
//			NodeComparison = Node->m_next;			//NodeComparison 변수는 Node 다음거와 문자열을 비교해야 하므로 다음 노드것을 가르키게 한다
//		}
//		else
//			break;
//
//
//	}
//}
//
//void Num()																			//총점으로 정렬하는 함수
//{
//	int se;
//	int cu;
//	int NodeNum;
//	StuNode<student>* Node = Link_Head->m_next;
//	StuNode<student>* NodeComparison = Node->m_next;
//	StuNode<student> sw;
//
//
//	NodeNum = NodeNumber();			//노드 개수를 측정하는 함수를 이용하여 개수 측정후 대입
//
//	printf("정렬할 총점의 오름차순(1), 내림차순(2) 선택해주세요(총점이 같을경우 이름순으로 정렬합니다) : ");
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
//				cu = strcmp(Node->name, NodeComparison->name);								//총점이 같을경우 이름으로 비교하기위해 계산하는 식
//				switch (se)																//선택을 입력받아 오름차순을 할지 내림차순을 할지 결정
//				{
//				case 1:																	//오름차순
//				{
//					if (Node->sum > NodeComparison->sum)
//					{
//						swap(Node, NodeComparison);
//					}
//					else if (Node->sum == NodeComparison->sum)											//성적이 같을 경우 이름으로 오름차순 정하는 조건문
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
//				case 2:																	//내림차순
//				{
//					if (Node->sum < NodeComparison->sum)
//					{
//						swap(Node, NodeComparison);
//					}
//					else if (Node->sum == NodeComparison->sum)											//성적이 같을 경우 이름으로 내림차순 정하는 조건문
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
//	for (int i = 0; i < NodeNum; i++)					//주소값을 바꿀때
//	{
//		for (int j = i; j < NodeNum; j++)
//		{
//			if (NodeComparison != Link_Tail)
//			{
//				if (i == 0)						// i==0일때 주소값이 헤드가 되기에 설정해준 조건문
//				{
//					Node = Link_Head->m_next;
//				}
//				else
//				{
//					Node = reswap(i);
//				}
//				NodeComparison = reswap(j + 1);
//				cu = strcmp(Node->name, NodeComparison->name);								//총점이 같을경우 이름으로 비교하기위해 계산하는 식
//
//				switch (se)																//선택을 입력받아 오름차순을 할지 내림차순을 할지 결정
//				{
//				case 1:																	//오름차순
//				{
//					if (Node->sum > NodeComparison->sum)
//					{
//						sw.swappa(*Node, *NodeComparison);
//					}
//					else if (Node->sum == NodeComparison->sum)											//성적이 같을 경우 이름으로 오름차순 정하는 조건문
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
//				case 2:																	//내림차순
//				{
//					if (Node->sum < NodeComparison->sum)
//					{
//						sw.swappa(*Node, *NodeComparison);
//					}
//					else if (Node->sum == NodeComparison->sum)											//성적이 같을 경우 이름으로 내림차순 정하는 조건문
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
//	//주소값을 바꿀때
//
//}	   //성적순 정렬


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
//		delete Node;							//모두삭제
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