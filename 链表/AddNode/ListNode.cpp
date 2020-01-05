#include "ListNode.h"
#include <stack>
void AddNode(Node ** pHead, int value)
{
	Node* pNew = new Node();
	pNew->m_value = value;
	pNew->m_pNext = NULL;
	if (*pHead == NULL)
	{
		*pHead = pNew;
		return;
	}
	Node* pNode = *pHead;
	while ((pNode)->m_pNext!=NULL)
	{
		pNode = pNode->m_pNext;
	}
	pNode->m_pNext = pNew;
}

void DeleteNode(Node ** pHead, int value)
{
	Node* pNew = NULL;

	if (pHead == NULL || *pHead == NULL)
		return;
	
	pNew = *pHead;
	Node* pNode = NULL;
	while (pNew->m_value!=value)
	{
		if (pNew->m_pNext == NULL)
			return;
		pNode = pNew;
		pNew = pNew->m_pNext;
	}
	if (pNew->m_pNext != NULL)
	{
		if (pNode == NULL)
			*pHead = pNew->m_pNext;
		else
		    pNode->m_pNext = pNew->m_pNext;
	}
	else {
		if (pNode == NULL)
			*pHead = NULL;
		else
		    pNode->m_pNext = NULL;
	}
	delete pNew;
	pNew = NULL;

	
}

void PrintList(Node * pHead)
{
	cout << "PrintList starts.\n";

	Node* pNode = pHead;
	while (pNode != NULL)
	{
		cout << pNode->m_value << endl;
		pNode = pNode->m_pNext;
	}

	cout << "PrintList ends.\n";
	
}

void ReversePrintList(Node * pHead)
{
	cout << "ReversePrintList starts.\n";
	if (pHead == NULL)
	{
		cout << "ReversePrintList ends.\n";
		return;
	}
	Node * pNode = pHead;
	stack<Node *> nodes;
	// 循环把链表的节点放入栈中
	while (true)
	{
		nodes.push(pNode);
		if (pNode->m_pNext == NULL)
			break;
		pNode = pNode->m_pNext;
	}
	// 循环输出栈中的元素
	while (true)
	{
		pNode = nodes.top();
		cout << pNode->m_value << endl;
		nodes.pop();
		if (nodes.empty())
			break;
	}
	cout << "ReversePrintList ends.\n";
}
