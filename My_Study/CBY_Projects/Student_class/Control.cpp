#include "Control.h"


void Control::print()
{
	StuNode* Node = begin->m_next;
	student sum;
	int i;
	printf("========================================================================================================================\n");
	printf("\t\t\t\t\t\t성적 관리 프로그램\n\n");
	printf("========================================================================================================================\n");
	printf("\t\t\t\t번호 \t 이름 \t 국어 \t 영어 \t 수학 \t 총점\t 평균\n");
	for (i = 1; i <= Link.NodeNumber(); i++)
	{

		printf("\t\t\t\t%2d번\t%5s %6d  %6d  %6d \t %3d \t %5.3f\n", Node->studentNode->num, Node->studentNode->name, Node->studentNode->kuk, Node->studentNode->eng, Node->studentNode->su, Node->studentNode->sum, Node->studentNode->avg);
		sum = *Node->studentNode + sum;
		Node = Node->m_next;
		if (Node == end)																		//파일을 출력하나 삭제와 삽입이 있기에 그걸 검사하고 출력하는 조건문 
		{
			break;
		}

	}
	printf("총합	:	%5d",sum.sum);
	printf("\n");

}	   //출력

void Control::in()//데이터 삽입
{
	StuNode* Node =begin->m_next;
	StuNode* temp;
	int number;
	int a, b;
	//system("cls");
	do
	{
		printf("삽입하고 싶은 곳의 번호를 입력하세요 : ");
		scanf_s("%d", &a);
		b = Link.Find(a);
	} while (b == 0);


	for (int i = 1; i < b; i++)
	{
		Node = Node->m_next;
	}

	printf("새로 삽입할 학생의 이름, 국어점수, 영어점수, 수학점수를 넣어주세요.\n");

	if (MAX_STUDENT > Link.NodeNumber())
	{
		number= Link.numfind();
	}
	else
	{
		number= Link.numfind();
	}
	temp = stu.make(Node,number);

	temp->studentNode->num = number;

	printf("이름 : ");
	scanf_s("%s", temp->studentNode->name, 5);

	printf("국어점수 : ");
	scanf_s("%d", &temp->studentNode->kuk);

	printf("영어점수 : ");
	scanf_s("%d", &temp->studentNode->eng);

	printf("수학점수 : ");
	scanf_s("%d", &temp->studentNode->su);


	temp->studentNode->sum = temp->studentNode->kuk + temp->studentNode->eng + temp->studentNode->su;
	temp->studentNode->avg = (double)temp->studentNode->sum / 3;

}

void Control::sak()//데이터 삭제하는 함수
{
	StuNode* Node = begin->m_next;
	int sun = 0;

	int num;

	printf("삭제할 번호를 골라주세요: ");
	scanf_s("%d", &sun);
	/*while (1 > sun || NodeNumber() < sun)												//잘못된 번호를 입력했는지 확인
	{
		printf("삭제할 번호는 1~%d 사이 입니다. 다시 1~%d사이의 번호를 골라주세요 : ", NodeNumber(), NodeNumber());
		scanf_s("%d", &sun);
	}*/
	num = Link.Find(sun);
	if (num == 0)
	{
		printf("맞는 번호가 없습니다.\n");
	}
	for (int i = 1; i < num; i++)
	{
		Node = Node->m_next;
	}

	Node->Delete(Node);

}			//삭제


void Control::Jung()																				//데이터를 수정하는 함수
{
	StuNode* Node = begin->m_next;
	int sun = 0;
	int num;
	int Number = Link.NodeNumber();

	printf("수정할 번호 1~%d사이의 번호를 골라주세요 : ", Number);
	scanf_s("%d", &sun);
	while (1 > sun || Number < sun)															//데이터는 10명의 학생의 데이터만 받으므로 그 안의 수를 고를 수 있게 오류검사
	{
		printf("수정할 번호는 1~%d 사이 입니다. 다시 1~%d사이의 번호를 골라주세요 : ", Number,Number);
		scanf_s("%d", &sun);
	}

	num = Link.Find(sun);

	for (int i = 1; i < num; i++)
	{
		Node = Node->m_next;
	}

	printf("%d번의 이름 : ", num);
	scanf_s("%s", Node->studentNode->name, 5);

	printf("%d번의 국어점수 : ", num);
	scanf_s("%d", &Node->studentNode->kuk);

	printf("%d번의 영어점수 : ", num);
	scanf_s("%d", &Node->studentNode->eng);

	printf("%d번의 수학점수 : ", num);
	scanf_s("%d", &Node->studentNode->su);

	Node->studentNode->sum = Node->studentNode->kuk + Node->studentNode->eng + Node->studentNode->su;
	Node->studentNode->avg = (double)Node->studentNode->sum / 3;
}	   //수정*/


Control::Control()
{
	begin = Link.getHead();
	end = Link.getTail();
}


Control::~Control()
{
}
