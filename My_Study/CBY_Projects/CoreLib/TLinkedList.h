#pragma once
#include "TNode.h"
// ���Ḯ��Ʈ ����
/*
T�� ������ ������ id�� ���´�.
*/
template<class T>
class TLinkedList
{
private:
	int		 m_iNumNode;
	TNode<T>*   m_pHead;
	TNode<T>*   m_pTail;
public:
	TNode<T>*   head()	{	return m_pHead;				}
	TNode<T>*   start(){	return m_pHead->m_pNext;	}
	TNode<T>*   end()	{	return m_pTail->m_pPrev;	}
	TNode<T>*   tail() {	return m_pTail;				}
	int		 Size()	{	return m_iNumNode;			}
	
	/*iID�� �˻��Ͽ� �ش� ��带 ��ȯ�Ѵ�.*/
	TNode<T>*	 FindNodeID(int iID);

	/*pCurrent����� �տ� pNode�� �����Ѵ�.
  ��,pCurrent == nullptr ���� �տ� �߰��ȴ�.
  ���� pNode==nullptr �̸� �ʱ�ȭ�� T�� �����Ͽ� �����Ѵ�.
*/
	TNode<T>* FrontInsert(
		TNode<T>* pNode,
		TNode<T>* pCurrent = nullptr);
	
	/*pCurrent����� �ڿ� pNode�� �����Ѵ�.
	��,pCurrent == nullptr ���� �ڿ� �߰��ȴ�.
	���� pNode==nullptr �̸� �ʱ�ȭ�� T�� �����Ͽ� �����Ѵ�.
	*/
	TNode<T>* BackInsert(
		TNode<T>* pNode, 
		TNode<T>* pLinkNode = nullptr);
	TNode<T>* BackInsertData(
		T* pNewNode, 
		TNode<T>* pLinkNode = nullptr);
	/*�ʱ�ȭ*/
	void Init();

	/*pNode�� �����Ѵ�.*/
	TNode<T>* Delete(TNode<T>* pNode);
	
	/*��ü ��� ����*/
	void Clear();
public:
	TLinkedList();
	~TLinkedList();
};

template<class T>
TNode<T>* TLinkedList<T>::Delete(TNode<T>* pDelNode)
{
	TNode<T>* pPrev = pDelNode->m_pPrev;
	TNode<T>* pNext = pDelNode->m_pNext;
	delete pDelNode;
	pPrev->m_pNext = pNext;
	pNext->m_pPrev = pPrev;

	m_iNumNode--;
	return pNext;
}
template<class T>
TNode<T>* TLinkedList<T>::FrontInsert(
	TNode<T>* pNewNode, TNode<T>* pCurrent)
{
	if (pNewNode == nullptr)
	{
		pNewNode = new TNode<T>;
		memset(pNewNode, 0, sizeof(T));
		assert(pNewNode);
	}
	if (pCurrent == m_pHead) return nullptr;

	if (pCurrent == nullptr)
	{
		pCurrent = m_pHead->m_pNext;
	}
	// A<-New<-C
	TNode<T>* pCurrentPrev = pCurrent->m_pPrev;
	pNewNode->m_pPrev = pCurrentPrev;
	pCurrent->m_pPrev = pNewNode;

	// A(g_pPrevFind)->New->C(pCurrent)
	pCurrentPrev->m_pNext = pNewNode;
	pNewNode->m_pNext = pCurrent;

	m_iNumNode++;
	return pNewNode;
}
template<class T>
TNode<T>* TLinkedList<T>::BackInsertData(
	T* pNewData, 
	TNode<T>* pLinkNode)
{
	TNode<T>* pNewNode = nullptr;

	if (pNewData == nullptr)
	{
		pNewData = new T();
		memset(pNewData, 0, sizeof(T));
		assert(pNewData);			
	}
	if (pLinkNode == m_pTail) return nullptr;

	if (pLinkNode == nullptr)
	{
		pLinkNode = m_pTail->m_pPrev;
		assert(pLinkNode);
	}

	pNewNode = new TNode<T>();
	assert(pNewNode);
	pNewNode->m_Data = *pNewData;

	//// H->new->A->T
	TNode<T>* pNext = pLinkNode->m_pNext;
	pLinkNode->m_pNext = pNewNode;
	pNewNode->m_pNext = pNext;

	//// H<-new<-A<-T
	pNewNode->m_pPrev = pLinkNode;
	pNext->m_pPrev = pNewNode;

	m_iNumNode++;
	return pNewNode;
}

template<class T>
TNode<T>* TLinkedList<T>::BackInsert(
	TNode<T>* pNewNode, TNode<T>* pCurrent)
{
	if (pNewNode == nullptr)
	{
		pNewNode = new TNode<T>;
		memset(pNewNode, 0, sizeof(T));
		assert(pNewNode);
	}
	if (pCurrent == m_pTail) return nullptr;

	if (pCurrent == nullptr)
	{
		pCurrent = m_pTail->m_pPrev;
		assert(pCurrent);
	}
	//// H->new->A->T
	TNode<T>* pNext = pCurrent->m_pNext;
	pCurrent->m_pNext = pNewNode;
	pNewNode->m_pNext = pNext;

	//// H<-new<-A<-T
	pNewNode->m_pPrev = pCurrent;
	pNext->m_pPrev = pNewNode;

	m_iNumNode++;
	return pNewNode;
}
template<class T>
// ��ȯ��= �˻����
TNode<T>* TLinkedList<T>::FindNodeID(int iID)
{
	for (TNode<T>* pNode = m_pHead->m_pNext;
		pNode != m_pTail;
		pNode = pNode->m_pNext)
	{
		if (iID == pNode->m_Data.m_ID)
		{
			return pNode;
		}
	}
	return nullptr;
}
template<class T>
void TLinkedList<T>::Clear()
{
	if (m_pHead == nullptr) return;
	TNode<T>* pNode = m_pHead->m_pNext;
	while (pNode != m_pTail)
	{
		pNode = Delete(pNode);
	}
	delete m_pHead;
	delete m_pTail;
	m_pHead = nullptr;
	m_pTail = nullptr;
}
template<class T>
void TLinkedList<T>::Init()
{
	m_iNumNode = 0;
	if (m_pHead == nullptr)	m_pHead = new TNode<T>();
	if (m_pTail == nullptr) m_pTail = new TNode<T>();
	memset(m_pTail, 0, sizeof(TNode<T>));
	m_pHead->m_pNext = m_pTail;
	m_pTail->m_pPrev = m_pHead;
}
template<class T>
TLinkedList<T>::TLinkedList() :
	m_pHead(nullptr),
	m_pTail(nullptr)
{
	Init();
}
template<class T>
TLinkedList<T>::~TLinkedList()
{
	Clear();
}
