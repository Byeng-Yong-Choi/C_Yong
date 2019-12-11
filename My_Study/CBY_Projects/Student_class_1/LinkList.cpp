#include "LinkList.h"

StuNode* LinkList::LinkHead = nullptr;
StuNode* LinkList::LinkTail = nullptr;


void LinkList::firstNode()
{
	if (LinkHead == nullptr||LinkTail==nullptr)
	{
		LinkHead = new StuNode;
		LinkTail = new StuNode;


		LinkHead->m_next = LinkTail;
		LinkTail->m_prev = LinkHead;
	}
}

void LinkList::Nodefree()
{
	StuNode* freetemp;
	if (LinkHead != nullptr || LinkTail != nullptr)
	{
		while (1)
		{
			freetemp = LinkHead->m_next;
			LinkHead->m_next = freetemp->m_next;
			delete freetemp;
		}
		delete LinkHead;
		delete LinkTail;
		LinkHead = nullptr;
		LinkTail = nullptr;
	}

}

int LinkList::Find(int a)
{
	StuNode* Node = LinkHead->m_next;				//ù ��� �Է�
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

int LinkList::NodeNumber()							//��� ����ã��
{
	StuNode* Node = LinkHead->m_next;
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

int LinkList::numfind()					//���� ���� ����ֱ�
{
	StuNode* Node = LinkHead->m_next;
	int a;
	int size = NodeNumber();
	for (int i = 1; i <= size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == Node->studentNode.num)			//�̹� �ִ� �ѹ��� ���
			{
				a = 0;
				break;
			}
			Node = Node->m_next;
			a = 1;
		}
		if (a == 1)
		{
			return i;					//���� ã�� ���
		}
		Node = LinkHead->m_next;
	}
	return 0;							//���� ã�� ���Ѱ��

}

StuNode* LinkList::NodeFind(int a)
{
	StuNode* Node=LinkHead->m_next;
	int num;
	num = Find(a);
	for (int i = 1; i < num; i++)
	{
		Node = Node->m_next;
	}
	return Node;
}

LinkList::LinkList()
{
	firstNode();
}


LinkList::~LinkList()
{
	//Nodefree();
}
