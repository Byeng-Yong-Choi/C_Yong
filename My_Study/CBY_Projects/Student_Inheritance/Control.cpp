#include "Control.h"


template <class T>
void Control<T>::print()
{
	StuNode<T>* Node = begin->m_next;
	T out;
	//T sum;

	int i;
	/*printf("========================================================================================================================\n");
	printf("\t\t\t\t\t\t���� ���� ���α׷�\n\n");
	printf("========================================================================================================================\n");
	printf("\t\t\t\t��ȣ \t �̸� \t ���� \t ���� \t ���� \t ����\t ���\n");*/
	//std::cout << "�г�" << "\t" << "��" << "\t" << "�̸�" << "\t" << "����" << "\t" << "����" << "\t" << "����" << "\t" << "����" << "\t" << "����" << "\t" << "����" << "\t" << "���" << "\t" << "���" << std::endl;
	std::cout << "�а�" << "\t\t" << "�й�" << " \t" << "�̸�" << " \t" << "����" << "�� \t" << "����" << "\t\t" << "����" << " \t" << "����" << " \t" << "����" <<"\t" <<" ���� "<<std::endl;
	for (i = 1; i <= Link.NodeNumber(); i++)
	{
		out = Node->ShowData();
		out.Show();
		Node = Node->m_next;
	}
}
	//	printf("\t\t\t\t%2d��\t%5s %6d  %6d  %6d \t %3d \t %5.3f\n", Node->studentNode.num, Node->studentNode.name, Node->studentNode.kuk, Node->studentNode.eng, Node->studentNode.su, Node->studentNode.sum, Node->studentNode.avg);
	//	//sum = Node->studentNode + sum;
	//	Node = Node->m_next;
	//	if (Node == end)																		//������ ����ϳ� ������ ������ �ֱ⿡ �װ� �˻��ϰ� ����ϴ� ���ǹ� 
	//	{
	//		break;
	//	}

	//}
	////printf("����	:	%5d",sum.sum);

	//printf("\n");
	////oper();

	   //���

template <class T>
void Control<T>::in()//������ ����
{
	StuNode<T>* Node =begin->m_next;
	StuNode<T>* temp;
	int a, b;
	//system("cls");
	do
	{
		printf("�����ϰ� ���� ���� ��ȣ�� �Է��ϼ��� : ");
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
void Control<T>::sak()//������ �����ϴ� �Լ�
{
	StuNode<T>* Node = begin->m_next;
	int sun = 0;

	int num;

	printf("������ ��ȣ�� ����ּ���: ");
	scanf_s("%d", &sun);
	/*while (1 > sun || NodeNumber() < sun)												//�߸��� ��ȣ�� �Է��ߴ��� Ȯ��
	{
		printf("������ ��ȣ�� 1~%d ���� �Դϴ�. �ٽ� 1~%d������ ��ȣ�� ����ּ��� : ", NodeNumber(), NodeNumber());
		scanf_s("%d", &sun);
	}*/
	num = Link.Find(sun);
	if (num == 0)
	{
		printf("�´� ��ȣ�� �����ϴ�.\n");
		return;
	}
	for (int i = 1; i < num; i++)
	{
		Node = Node->m_next;
	}

	Node->Delete(Node);

}			//����
//
//
//template <class T>
//void Control<T>::Jung()																				//�����͸� �����ϴ� �Լ�
//{
//	StuNode<T>* Node = begin->m_next;
//	int sun = 0;
//	int num;
//	int Number = Link.NodeNumber();
//
//	printf("������ ��ȣ 1~%d������ ��ȣ�� ����ּ��� : ", Number);
//	scanf_s("%d", &sun);
//	while (1 > sun || Number < sun)															//�����ʹ� 10���� �л��� �����͸� �����Ƿ� �� ���� ���� �� �� �ְ� �����˻�
//	{
//		printf("������ ��ȣ�� 1~%d ���� �Դϴ�. �ٽ� 1~%d������ ��ȣ�� ����ּ��� : ", Number,Number);
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
//	printf("%d���� �̸� : ", num);
//	scanf_s("%s", Node->studentNode.name, 5);
//
//	printf("%d���� �������� : ", num);
//	scanf_s("%d", &Node->studentNode.kuk);
//
//	printf("%d���� �������� : ", num);
//	scanf_s("%d", &Node->studentNode.eng);
//
//	printf("%d���� �������� : ", num);
//	scanf_s("%d", &Node->studentNode.su);
//
//	Node->studentNode.sum = Node->studentNode.kuk + Node->studentNode.eng + Node->studentNode.su;
//	Node->studentNode.avg = (double)Node->studentNode.sum / 3;
//}	   //����*/

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
		cout << "������ ���� ���� ���α׷��Դϴ�. ���ϴ� ���� �����ϼ���." << endl;
		cout << "����(1), ����(2), ����(3), ������(4), ����(99)";
		cin >> choice;
		switch (choice)							//enum{PLUS=1,MINUS,MULTIPLY,DIVISION};		//����1,����2,����3,������4
		{
		case PLUS:
			
			cout << "������ ���ϰ� ���� �л� �θ��� ��ȣ�� �Է��ϼ��� : ";
			cin >> a>> b;
			astu = Link.NodeFind(a);
			bstu = Link.NodeFind(b);
			sum = astu->studentNode + bstu->studentNode;
			cout << "��� ���� : " << sum << endl;
			break;

		case MINUS:
			
			cout << "������ ���� ���� �л� �θ��� ��ȣ�� �Է��ϼ��� : ";
			cin >> a>> b;
			astu = Link.NodeFind(a);
			bstu = Link.NodeFind(b);
			sum = astu->studentNode - bstu->studentNode;
			cout << "��� ���� : " << sum << endl;
			break;

		case MULTIPLY:
			
			cout << "������ ���ϰ� ���� �л� �θ��� ��ȣ�� �Է��ϼ��� : ";
			cin >> a>> b;
			astu = Link.NodeFind(a);
			bstu = Link.NodeFind(b);
			sum = astu->studentNode * bstu->studentNode;
			cout << "��� ���� : " << sum << endl;
			break;

		case DIVISION:
			
			cout << "������ ������ ���� �л� �θ��� ��ȣ�� �Է��ϼ��� : ";
			cin >> a>> b;
			astu = Link.NodeFind(a);
			bstu = Link.NodeFind(b);
			mbc = astu->studentNode / bstu->studentNode;
			cout << "��� ���� : " << mbc << endl;
			break;

		case 99:
			return;
		}
	}

}*/

/*int Control::plus(StuNode<T>* const sub)				//����
{
	int plus;
	plus=stu.studentNode + sub;
	return plus;
}
int Control::minus(StuNode<T>* const sub)				//����
{
	int minus;
	minus=stu.studentNode - sub;
	return minus;
}
int Control::multi(StuNode<T>* const sub)				//����
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
