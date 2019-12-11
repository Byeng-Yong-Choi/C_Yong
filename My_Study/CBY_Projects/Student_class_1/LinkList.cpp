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
	StuNode* Node = LinkHead->m_next;				//첫 노드 입력
	int count = 1;								//몇번째 노드인지 확인할 수
	for (int i = 1; i <= NodeNumber(); i++)
	{
		if (Node->studentNode.num == a)
		{
			return count;
		}
		count++;
		Node = Node->m_next;					//다음 노드 불러내기
	}
	return 0;
}

int LinkList::NodeNumber()							//노드 개수찾기
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

int LinkList::numfind()					//없는 숫자 집어넣기
{
	StuNode* Node = LinkHead->m_next;
	int a;
	int size = NodeNumber();
	for (int i = 1; i <= size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == Node->studentNode.num)			//이미 있는 넘버일 경우
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
		Node = LinkHead->m_next;
	}
	return 0;							//값을 찾지 못한경우

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
