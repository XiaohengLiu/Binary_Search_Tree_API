#ifndef BST_H
#define BST_H
#include"Node.h"
#include<iostream>

template<typename Key,typename Value>
class BST
{
private:
	Node<Key,Value>* p_head;
private:
	int size(Node<Key,Value>* pNode);
	int rank(Key key,Node<Key,Value>* pNode);
	Node<Key,Value>* select(Node<Key,Value>* pNode,int k);
	Node<Key,Value>* put(Node<Key,Value>* pNode,Key key,Value val);
public:
	BST();
public:
	int size();
	int rank(Key key);
	Key select(int k);
	void insert(Key key,Value val);//put key-value pair into the table
};

template<typename Key,typename Value>
BST<Key,Value>::BST()
{
	p_head = NULL;
}

template<typename Key,typename Value>
int BST<Key,Value>::size(Node<Key,Value>* pNode)
{
	if (pNode == NULL)
		return 0;
	return pNode->m_subN;
}

template<typename Key,typename Value>
int BST<Key,Value>::size()
{
	return size(p_head);
}

template<typename Key,typename Value>
Node<Key,Value>* BST<Key,Value>::put(Node<Key,Value>* pNode,Key key,Value val)
{
	if (pNode == NULL)	
		return new Node<Key,Value>(key,val);
	
	if (key < pNode->m_key)
		pNode->p_lNext = put(pNode->p_lNext,key,val);
	else if(key > pNode->m_key)
		pNode->p_rNext = put(pNode->p_rNext,key,val);
	else
		pNode->m_value = val;

	pNode->m_subN = 1 + size(pNode->p_lNext) + size(pNode->p_rNext);
	return pNode;
}

template<typename Key,typename Value>
void BST<Key,Value>::insert(Key key,Value val)
{
	p_head = put(p_head,key,val);
}

template<typename Key,typename Value>
int BST<Key,Value>::rank(Key key,Node<Key,Value>* pNode)
{
	if (pNode == NULL) 
		return 0;
	if (pNode->m_key > key)
		return rank(key,pNode->p_lNext);
	else if (pNode->m_key < key)
		return 1+rank(key,pNode->p_lNext)+rank(key,pNode->p_rNext);
	else
		return size(pNode->p_lNext);
}

template<typename Key,typename Value>
int BST<Key,Value>::rank(Key key)
{
	return rank(key,p_head);
}

template<typename Key,typename Value>
Node<Key,Value>* BST<Key,Value>::select(Node<Key,Value>* pNode,int k)
{
	if (pNode == NULL) return NULL;
	int tmp = size(pNode->p_lNext);
	if (tmp > k)
		return select(pNode->p_lNext,k);
	else if (tmp < k)
		return select(pNode->p_rNext,k-tmp-1);
	else 
		return pNode;
}

template<typename Key,typename Value>
Key BST<Key,Value>::select(int k)
{
	if (k<0 || k>=size())
		return NULL;
	Node<Key,Value>* tempNode = select(p_head,k);
	return tempNode->m_key;
}

#endif