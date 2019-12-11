#include "LinkList.h"

template <class T>
StuNode<T>* LinkList<T>::LinkHead = nullptr;
template <class T>
StuNode<T>* LinkList<T>::LinkTail = nullptr;

template <class T>
void LinkList<T>::firstNode()
{
	if (LinkHead == nullptr||LinkTail==nullptr)
	{
		LinkHead = new StuNode<T>;
		memset(LinkHead, 0, sizeof (StuNode<T>));
		LinkTail = new StuNode<T>;
		memset(LinkTail, 0, sizeof (StuNode<T>));


		LinkHead->m_next = LinkTail;
		LinkTail->m_prev = LinkHead;
	}
}

template <class T>
void LinkList<T>::Nodefree()
{
	StuNode<T>* freetemp;
	if (LinkHead != nullptr || LinkTail != nullptr)
	{
		while (1)
		{
				freetemp = LinkHead->m_next;
				if (freetemp == LinkTail)
				{
					break;
				}
				LinkHead->m_next = freetemp->m_next;
				delete freetemp;
			
		}
		delete LinkHead;
		delete LinkTail;
		LinkHead = nullptr;
		LinkTail = nullptr;
	}

}


template <class T>
int LinkList<T>::Find(int a)
{
	StuNode<T>* Node = LinkHead->m_next;				//ù ��� �Է�
	int count = 1;								//���° ������� Ȯ���� ��
	for (int i = 1; i <= NodeNumber(); i++)
	{
		if (Node->studentNode.num == a)
		{
			return count;
		}
		count++;
		Node = Node->m_next;					//���� ��� �ҷ�����
	}
	return 0;
}

template <class T>
int LinkList<T>::NodeNumber()							//��� ����ã��
{
	StuNode<T>* Node = LinkHead->m_next;
	int num = 0;

	while (1)
	{

		if (Node == LinkTail)
		{
			break;
		}
		num++;
		Node = Node->m_next;
	}

	return num;
}

//int LinkList::numfind()					//���� ���� ����ֱ�
//{
//	T* Node = LinkHead->m_next;
//	int a;
//	int size = NodeNumber();
//	for (int i = 1; i <= size; i++)
//	{
//		for (int j = 0; j < size; j++)
//		{
//			if (i == Node->studentNode.num)			//�̹� �ִ� �ѹ��� ���
//			{
//				a = 0;
//				break;
//			}
//			Node = Node->m_next;
//			a = 1;
//		}
//		if (a == 1)
//		{
//			return i;					//���� ã�� ���
//		}
//		Node = LinkHead->m_next;
//	}
//	return 0;							//���� ã�� ���Ѱ��
//
//}
//
//T* LinkList::NodeFind(int a)
//{
//	T* Node=LinkHead->m_next;
//	int num;
//	num = Find(a);
//	for (int i = 1; i < num; i++)
//	{
//		Node = Node->m_next;
//	}
//	return Node;
//}

template <class T>
LinkList<T>::LinkList()
{
	firstNode();
}

template <class T>
LinkList<T>::~LinkList()
{
	//Nodefree();
}
