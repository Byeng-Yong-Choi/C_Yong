#include "CBYNode.h"

template <class T>
int CBYNode<T>::index;			//생성시 부여되는 고유 노드 넘버
template <class T>
int CBYNode<T>::nodenum;			//노드의 개수

template <class T>
CBYNode<T>::CBYNode()
{
}

template <class T>
T CBYNode<T>::getData(int i)
{
	T a(i);
	studentNode = a;
	return studentNode;
}

template <class T>
CBYNode<T>* CBYNode<T>::make(int num)
{
	index++;
	nodenum++;
	CBYNode<T>* Newp;
	Newp=new CBYNode<T>;
	Newp->getData(num);
	Newp->IndexNumber = index;
	return Newp;
}

template <class T>
void CBYNode<T>::Delete(CBYNode<T>* Node)
{
	CBYNode<T>* temp = Node->m_prev;
	CBYNode<T>* temp_2 = Node->m_next;
	temp->m_next = temp_2;
	temp_2->m_prev = temp;
	delete Node;							//삭제
	nodenum--;
}

template <class T>
T CBYNode<T>::ShowData()
{
	return studentNode;
}

//template <class T>
//int CBYNode<T>::NodeNumber()					//노드 개수찾기
//{
//	CBYNode<T>* Node = Link_Head->m_next;
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
/*void CBYNode<T>::swap(CBYNode<T>& Node, CBYNode<T>& Daum)
{
	CBYNode<T>* temp = new CBYNode<T>;

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
CBYNode<T>::~CBYNode()
{
}

