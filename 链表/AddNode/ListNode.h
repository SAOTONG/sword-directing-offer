#ifndef LISTNODE_H
#define LISTNODE_H
#include <stdio.h>
#include <iostream>
using namespace std;

struct Node
{
	int m_value;
	Node * m_pNext =NULL;
};

void AddNode(Node ** pHead, int value);
void DeleteNode(Node ** pHead, int value);
void PrintList(Node* pHead);
void ReversePrintList(Node* pHead);
#endif // !LISTNODE_H


