#include "Control.h"


template <class T>
void Control<T>::print()
{
	StuNode<T>* Node = begin->m_next;
	T out;
	//T sum;

	int i;
	/*printf("========================================================================================================================\n");
	printf("\t\t\t\t\t\t성적 관리 프로그램\n\n");
	printf("========================================================================================================================\n");
	printf("\t\t\t\t번호 \t 이름 \t 국어 \t 영어 \t 수학 \t 총점\t 평균\n");*/
	//std::cout << "학년" << "\t" << "반" << "\t" << "이름" << "\t" << "나이" << "\t" << "성별" << "\t" << "국어" << "\t" << "영어" << "\t" << "수학" << "\t" << "총합" << "\t" << "평균" << "\t" << "등수" << std::endl;
	std::cout << "학과" << "\t\t" << "학번" << " \t" << "이름" << " \t" << "나이" << "살 \t" << "성별" << "\t\t" << "국어" << " \t" << "영어" << " \t" << "수학" <<"\t" <<" 학점 "<<std::endl;
	for (i = 1; i <= Link.NodeNumber(); i++)
	{
		out = Node->ShowData();
		out.Show();
		Node = Node->m_next;
	}
}
	//	printf("\t\t\t\t%2d번\t%5s %6d  %6d  %6d \t %3d \t %5.3f\n", Node->studentNode.num, Node->studentNode.name, Node->studentNode.kuk, Node->studentNode.eng, Node->studentNode.su, Node->studentNode.sum, Node->studentNode.avg);
	//	//sum = Node->studentNode + sum;
	//	Node = Node->m_next;
	//	if (Node == end)																		//파일을 출력하나 삭제와 삽입이 있기에 그걸 검사하고 출력하는 조건문 
	//	{
	//		break;
	//	}

	//}
	////printf("총합	:	%5d",sum.sum);

	//printf("\n");
	////oper();

	   //출력

template <class T>
void Control<T>::in()//데이터 삽입
{
	StuNode<T>* Node =begin->m_next;
	StuNode<T>* temp;
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

	temp = stu.make(Node);


}

template <class T>
void Control<T>::sak()//데이터 삭제하는 함수
{
	StuNode<T>* Node = begin->m_next;
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
		return;
	}
	for (int i = 1; i < num; i++)
	{
		Node = Node->m_next;
	}

	Node->Delete(Node);

}			//삭제
//
//
//template <class T>
//void Control<T>::Jung()																				//데이터를 수정하는 함수
//{
//	StuNode<T>* Node = begin->m_next;
//	int sun = 0;
//	int num;
//	int Number = Link.NodeNumber();
//
//	printf("수정할 번호 1~%d사이의 번호를 골라주세요 : ", Number);
//	scanf_s("%d", &sun);
//	while (1 > sun || Number < sun)															//데이터는 10명의 학생의 데이터만 받으므로 그 안의 수를 고를 수 있게 오류검사
//	{
//		printf("수정할 번호는 1~%d 사이 입니다. 다시 1~%d사이의 번호를 골라주세요 : ", Number,Number);
//		scanf_s("%d", &sun);
//	}
//
//	num = Link.Find(sun);
//
//	for (int i = 1; i < num; i++)
//	{
//		Node = Node->m_next;
//	}
//
//	printf("%d번의 이름 : ", num);
//	scanf_s("%s", Node->studentNode.name, 5);
//
//	printf("%d번의 국어점수 : ", num);
//	scanf_s("%d", &Node->studentNode.kuk);
//
//	printf("%d번의 영어점수 : ", num);
//	scanf_s("%d", &Node->studentNode.eng);
//
//	printf("%d번의 수학점수 : ", num);
//	scanf_s("%d", &Node->studentNode.su);
//
//	Node->studentNode.sum = Node->studentNode.kuk + Node->studentNode.eng + Node->studentNode.su;
//	Node->studentNode.avg = (double)Node->studentNode.sum / 3;
//}	   //수정*/

/*template <class T>
void Control::oper()
{
	StuNode<T>* astu;
	StuNode<T>* bstu;
	int a, b;
	int choice;
	int sum;
	double mbc;

	while (1)
	{
		cout << "총점에 대한 연산 프로그램입니다. 원하는 것을 선택하세요." << endl;
		cout << "덧셈(1), 뺄셈(2), 곱셈(3), 나눗셈(4), 종료(99)";
		cin >> choice;
		switch (choice)							//enum{PLUS=1,MINUS,MULTIPLY,DIVISION};		//덧셈1,빼기2,곱셈3,나눗셈4
		{
		case PLUS:
			
			cout << "총점을 더하고 싶은 학생 두명의 번호를 입력하세요 : ";
			cin >> a>> b;
			astu = Link.NodeFind(a);
			bstu = Link.NodeFind(b);
			sum = astu->studentNode + bstu->studentNode;
			cout << "계산 값은 : " << sum << endl;
			break;

		case MINUS:
			
			cout << "총점을 빼고 싶은 학생 두명의 번호를 입력하세요 : ";
			cin >> a>> b;
			astu = Link.NodeFind(a);
			bstu = Link.NodeFind(b);
			sum = astu->studentNode - bstu->studentNode;
			cout << "계산 값은 : " << sum << endl;
			break;

		case MULTIPLY:
			
			cout << "총점을 곱하고 싶은 학생 두명의 번호를 입력하세요 : ";
			cin >> a>> b;
			astu = Link.NodeFind(a);
			bstu = Link.NodeFind(b);
			sum = astu->studentNode * bstu->studentNode;
			cout << "계산 값은 : " << sum << endl;
			break;

		case DIVISION:
			
			cout << "총점을 나누고 싶은 학생 두명의 번호를 입력하세요 : ";
			cin >> a>> b;
			astu = Link.NodeFind(a);
			bstu = Link.NodeFind(b);
			mbc = astu->studentNode / bstu->studentNode;
			cout << "계산 값은 : " << mbc << endl;
			break;

		case 99:
			return;
		}
	}

}*/

/*int Control::plus(StuNode<T>* const sub)				//덧셈
{
	int plus;
	plus=stu.studentNode + sub;
	return plus;
}
int Control::minus(StuNode<T>* const sub)				//뺄셈
{
	int minus;
	minus=stu.studentNode - sub;
	return minus;
}
int Control::multi(StuNode<T>* const sub)				//곱셈
{
	int mult;
	mult=stu.studentNode * sub;
	return mult;
}
double Control::division(StuNode<T>* const sub)
{
	int divi;
	divi= stu.studentNode / (double) sub;
	return divi;
}*/

template <class T>
Control<T>::Control()
{
	begin = Link.getHead();
	end = Link.getTail();
}

template <class T>
Control<T>::~Control()
{
}
