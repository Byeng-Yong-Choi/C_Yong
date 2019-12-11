#include "StuNode.h"

int StuNode::nodenum = 0;

StuNode::StuNode()
{
}

void StuNode::oneone(StuNode& const tail)
{
	StuNode* newNode;
	int i;
	for (i = 0; i < MAX_STUDENT; i++)
	{
		newNode = new StuNode;
		newNode->studentNode = *new student(i+1);
		BackNodein(newNode, tail);
		nodenum++;
	}
}

StuNode* StuNode::make(StuNode& tail, int num)
{
	StuNode* Newp = new StuNode;
	Newp->studentNode = *new student(num);
	BackNodein(Newp, tail);
	nodenum++;
	return Newp;
}

void StuNode::FrontNodein(StuNode* newNode, StuNode& const head)
{
	//next 연결
	StuNode* temp = head.m_next;
	head.m_next = newNode;
	newNode->m_next = temp;

	//prev 연결
	newNode->m_prev = &head;
	temp->m_prev = newNode;
}

void StuNode::BackNodein(StuNode* newNode, StuNode& const tail)
{
	StuNode* temp = tail.m_prev;
	tail.m_prev = newNode;
	newNode->m_next = &tail;

	newNode->m_prev = temp;
	temp->m_next = newNode;
}

void StuNode::Delete(StuNode* Node)
{
	StuNode* temp = Node->m_prev;
	StuNode* temp_2 = Node->m_next;
	temp->m_next = temp_2;
	temp_2->m_prev = temp;
	delete Node;							//삭제
	nodenum--;
}


//int StuNode::NodeNumber()					//노드 개수찾기
//{
//	StuNode* Node = Link_Head->m_next;
//	int num = 0;
//
//	while (1)
//	{
//
//		if (Node == Link_Tail)
//		{
//			break;
//		}
//		num++;
//		Node = Node->m_next;
//	}
//
//	return num;
//}

/*void StuNode::swap(StuNode& Node, StuNode& Daum)
{
	StuNode* temp = new StuNode;

	strcpy_s(temp->name, 5, Node.name);
	strcpy_s(Node.name, 5, Daum.name);
	strcpy_s(Daum.name, 5, temp->name);

	temp->kuk = Node.kuk;
	Node.kuk = Daum.kuk;
	Daum.kuk = temp->kuk;

	temp->eng = Node.eng;
	Node.eng = Daum.eng;
	Daum.eng = temp->eng;

	temp->su = Node.su;
	Node.su = Daum.su;
	Daum.su = temp->su;

	temp->sum = Node.sum;
	Node.sum = Daum.sum;
	Daum.sum = temp->sum;

	temp->avg = Node.avg;
	Node.avg = Daum.avg;
	Daum.avg = temp->avg;

	delete temp;
}

void student::swappa(student& Node, student& Daum)
{
	student* temp;
	student* swap;

	//바꾸는 노드들의 앞 주소 교환
	temp = Node.m_prev;
	swap = Daum.m_prev;
	temp->m_next = &Daum;
	swap->m_next = &Node;
	Daum.m_prev = temp;
	Node.m_prev = swap;

	//바꾸는 노드들의 뒷 주소 교환
	temp = Node.m_next;
	swap = Daum.m_next;
	temp->m_prev = &Daum;
	swap->m_prev = &Node;
	Node.m_next = swap;
	Daum.m_next = temp;
}*/


StuNode::~StuNode()
{
}

