#pragma once
#include "CBYNode.h"

template <class T>
class CBYLinkList
{
private:
	CBYNode<T>* LinkHead;
	CBYNode<T>* LinkTail;

public:
	CBYNode<T>* getHead() { return LinkHead; };		//��� ��ȯ
	CBYNode<T>* getTail() { return LinkTail; };		//���� ��ȯ
	void firstNode();								//�ʱ� �޸� ����
	void Nodefree();								//�޸� ����
	void FrontNodein(CBYNode<T>* newNode);
	void BackNodein(CBYNode<T>* newNode);
//	int numfind();									//������ ��ȣ ã�Ƽ� ����
	int Find(int a);								//��� ��ġ ã��
//	T* NodeFind(int a);
	int NodeNumber();								//��� ���� ã��

public:
	CBYLinkList();
	~CBYLinkList();
};

/*template <class T>
CBYNode<T>* CBYLinkList<T>::LinkHead = nullptr;
template <class T>
CBYNode<T>* CBYLinkList<T>::LinkTail = nullptr;*/

template <class T>
void CBYLinkList<T>::firstNode()
{
	if (LinkHead == nullptr || LinkTail == nullptr)
	{
		LinkHead = new CBYNode<T>;
		memset(LinkHead, 0, sizeof(CBYNode<T>));
		LinkTail = new CBYNode<T>;
		memset(LinkTail, 0, sizeof(CBYNode<T>));


		LinkHead->m_next = LinkTail;
		LinkTail->m_prev = LinkHead;
	}
}

template <class T>
void CBYLinkList<T>::Nodefree()
{
	CBYNode<T>* freetemp;
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
int CBYLinkList<T>::Find(int a)
{
	CBYNode<T>* Node = LinkHead->m_next;				//ù ��� �Է�
	int count = 1;								//���° ������� Ȯ���� ��
	for (int i = 1; i <= NodeNumber(); i++)
	{
		if (Node->IndexNumber == a)
		{
			return count;
		}
		count++;
		Node = Node->m_next;					//���� ��� �ҷ�����
	}
	return 0;
}

template <class T>
int CBYLinkList<T>::NodeNumber()							//��� ����ã��
{
	CBYNode<T>* Node = LinkHead->m_next;
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

template <class T>
void CBYLinkList<T>::FrontNodein(CBYNode<T>* newNode)
{
	//next ����
	CBYNode<T>* temp = LinkHead->m_next;
	LinkHead->m_next = newNode;
	newNode->m_next = temp;

	//prev ����
	newNode->m_prev = LinkHead;
	temp->m_prev = newNode;
}

template <class T>
void CBYLinkList<T>::BackNodein(CBYNode<T>* newNode)
{
	CBYNode<T>* temp = LinkTail->m_prev;
	LinkTail->m_prev = newNode;
	newNode->m_next = LinkTail;

	newNode->m_prev = temp;
	temp->m_next = newNode;
}

//int CBYLinkList::numfind()					//���� ���� ����ֱ�
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
//T* CBYLinkList::NodeFind(int a)
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
CBYLinkList<T>::CBYLinkList()
{
	firstNode();
}

template <class T>
CBYLinkList<T>::~CBYLinkList()
{
	//Nodefree();
}
