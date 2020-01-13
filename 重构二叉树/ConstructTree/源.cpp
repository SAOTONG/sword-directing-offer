#include <stdio.h>
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;
BinaryTreeNode* ConstructTree(const vector<int>&preorder,
	const vector<int>&inorder);
BinaryTreeNode* ConstructCore(const int * preorderBegin,
	const int * preorderEnd, const int * inorderBegin, const int * inorderEnd);
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode * m_pLeft;
	BinaryTreeNode * m_pRight;
};


BinaryTreeNode* ConstructTree(const vector<int>&preorder,
	const vector<int>&inorder)
{
	if (preorder.size() == 0 || inorder.size() == 0)
		cout << "ǰ�������������������Ϊ�գ���\n";
	ConstructCore(&(*preorder.begin()), &(*preorder.end()),
		&(*inorder.begin()), &(*inorder.end()));
}

BinaryTreeNode * ConstructCore(const int * preorderBegin, 
	const int * preorderEnd, const int * inorderBegin, const int * inorderEnd)
{
	BinaryTreeNode* node = new BinaryTreeNode();
	node->m_nValue = *preorderBegin;
	node->m_pLeft = node->m_pRight = NULL;
	const int * inorderBeginCopy = inorderBegin;
	while (true)
	{
		if (inorderBegin != inorderEnd)
		{
			if (*preorderBegin == *inorderBegin)
				break;
			inorderBegin++;
		}
		else
		    throw runtime_error("��Ч����������������");
	}
	int num = inorderBegin - inorderBeginCopy;
	// ��������Ϊ��
	if (inorderBegin != inorderBeginCopy)
		node->m_pLeft = ConstructCore(preorderBegin + 1, preorderBegin + 1 + num, 
			inorderBeginCopy, inorderBegin);
	// ��������Ϊ��
	if(inorderBegin!=(inorderEnd-1))
		node->m_pRight = ConstructCore(preorderBegin + 1 + num, preorderEnd,
			inorderBegin + 1, inorderEnd);


	return node;
}
