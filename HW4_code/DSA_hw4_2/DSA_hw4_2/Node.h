#ifndef NODE_H
#define NODE_H
#include<iostream>

template<typename Key,typename Value>
class Node
{
public:
	Key m_key;
	Value m_value;
	Node* p_lNext;
	Node* p_rNext;
	int m_subN;
public:
	Node(Key key,Value val);
};

template<typename Key,typename Value>
Node<Key,Value>::Node(Key key,Value val)
{
	m_key = key;
	m_value = val;
	p_lNext = NULL;
	p_rNext = NULL;
}
#endif
