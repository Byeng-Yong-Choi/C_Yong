#pragma once
#include <iostream>
#include <assert.h>
template<class T>
class TNode
{
public:
	T			m_Data;
	TNode<T>*	m_pNext;
	TNode<T>*	m_pPrev;
public:
	TNode();
	TNode(const TNode<T>& node);
	~TNode();
};

template<class T>
TNode<T>::TNode(const TNode<T>& node)
{
	m_Data = node.m_Data;
}
template<class T>
TNode<T>::TNode()
{
}

template<class T>
TNode<T>::~TNode()
{
}