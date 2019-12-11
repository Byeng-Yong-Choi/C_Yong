#include "StuNode.h"

template <class T>
int StuNode<T>::index=0;			//생성시 부여되는 고유 노드 넘버
template <class T>
int StuNode<T>::nodenum=0;			//노드의 개수

template <class T>
StuNode<T>::StuNode()
{
}

template <class T>
void StuNode<T>::oneone(StuNode<T>* const tail)
{
	StuNode<T>* newNode;
	int i;
	for (i = 0; i < MAX_STUDENT; i++)
	{
		index++;
		nodenum++;
		newNode = new StuNode<T>;
		newNode->getData();
		BackNodein(newNode, tail);
	}
}


template <class T>
T StuNode<T>::getData()
{
	T a(index);
	studentNode = a;
	return studentNode;
}

template <class T>
StuNode<T>* StuNode<T>::make(StuNode<T>* front)
{
	index++;
	nodenum++;
	StuNode<T>* Newp = new StuNode<T>;
	Newp->studentNode = Newp->getData();
	FrontNodein(Newp, front);
	return Newp;
}

template <class T>
void StuNode<T>::FrontNodein(StuNode<T>* newNode, StuNode<T>* const head)
{
	//next 연결
	StuNode<T>* temp = head->m_next;
	head->m_next = newNode;
	newNode->m_next = temp;

	//prev 연결
	newNode->m_prev = head;
	temp->m_prev = newNode;
}

template <class T>
void StuNode<T>::BackNodein(StuNode<T>* newNode, StuNode<T>* const tail)
{
	StuNode<T>* temp = tail->m_prev;
	tail->m_prev = newNode;
	newNode->m_next = tail;

	newNode->m_prev = temp;
	temp->m_next = newNode;
}

template <class T>
void StuNode<T>::Delete(StuNode<T>* Node)
{
	StuNode<T>* temp = Node->m_prev;
	StuNode<T>* temp_2 = Node->m_next;
	temp->m_next = temp_2;
	temp_2->m_prev = temp;
	delete Node;							//삭제
	nodenum--;
}

template <class T>
T StuNode<T>::ShowData()
{
	return studentNode;
}

//template <class T>
//int StuNode<T>::NodeNumber()					//노드 개수찾기
//{
//	StuNode<T>* Node = Link_Head->m_next;
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

//template <class T>
/*void StuNode<T>::swap(StuNode<T>& Node, StuNode<T>& Daum)
{
	StuNode<T>* temp = new StuNode<T>;

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

//template <class T>
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

template <class T>
StuNode<T>::~StuNode()
{
}

