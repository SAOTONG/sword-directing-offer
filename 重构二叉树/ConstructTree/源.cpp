#include <stdio.h>
#include <vector>
#include <iostream>
#include <iterator>
#include "BinaryTree.h"
using namespace std;
BinaryTreeNode* ConstructTree(const vector<int>&preorder,
	const vector<int>&inorder);
BinaryTreeNode* ConstructCore(const int * preorderBegin,
	const int * preorderEnd, const int * inorderBegin, const int * inorderEnd);

BinaryTreeNode* ConstructTree(const vector<int>&preorder,
	const vector<int>&inorder)
{
	if (preorder.size() == 0 || inorder.size() == 0)
		throw runtime_error("前序或者中序遍历结果不能为空！！\n");
	BinaryTreeNode* bt= ConstructCore(&(*(preorder.begin())), &*(preorder.end()-1)+1,
		&(*(inorder.begin())), &*(inorder.end()-1)+1);
	return bt;
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
		    throw exception("无效的中序遍历结果！！");
	}
	int num = inorderBegin - inorderBeginCopy;
	// 左子树不为空
	if (inorderBegin != inorderBeginCopy)
		node->m_pLeft = ConstructCore(preorderBegin + 1, preorderBegin + 1 + num, 
			inorderBeginCopy, inorderBegin);
	// 右子树不为空
	if(inorderBegin!=(inorderEnd-1))
		node->m_pRight = ConstructCore(preorderBegin + 1 + num, preorderEnd,
			inorderBegin + 1, inorderEnd);	
	return node;
}

// ====================测试代码====================
void Test(const char* testName, const vector<int>&preorder, const vector<int>&inorder, int length)
{
	if (testName != nullptr)
		printf("%s begins:\n", testName);

	/*printf("The preorder sequence is: ");
	for (int i = 0; i < length; ++i)
		printf("%d ", preorder[i]);
	printf("\n");

	printf("The inorder sequence is: ");
	for (int i = 0; i < length; ++i)
		printf("%d ", inorder[i]);
	printf("\n");*/
	try
	{
		BinaryTreeNode* root = ConstructTree(preorder, inorder);
		PrintTree(root);

		DestroyTree(root);
	}
	catch (std::exception& exception)
	{
		cerr << exception.what() << endl;
	}
}

// 普通二叉树
//              1
//           /     \
//          2       3  
//         /       / \
//        4       5   6
//         \         /
//          7       8
void Test1()
{
	const int length = 8;
	vector<int> inorder = { 4, 7, 2, 1, 5, 3, 8, 6 };
	vector<int> preorder = { 1, 2, 4, 7, 3, 5, 6, 8 };
	Test("Test1", preorder, inorder, length);
}

// 所有结点都没有右子结点
//            1
//           / 
//          2   
//         / 
//        3 
//       /
//      4
//     /
//    5
void Test2()
{
	const int length = 5;
	vector<int> preorder = { 1, 2, 3, 4, 5 };
	vector<int> inorder = { 5, 4, 3, 2, 1 };

	Test("Test2", preorder, inorder, length);
}

// 所有结点都没有左子结点
//            1
//             \ 
//              2   
//               \ 
//                3 
//                 \
//                  4
//                   \
//                    5
void Test3()
{
	const int length = 5;
	vector<int> preorder = { 1, 2, 3, 4, 5 };
	vector<int> inorder = { 1, 2, 3, 4, 5 };

	Test("Test3", preorder, inorder, length);
}

// 树中只有一个结点
void Test4()
{
	const int length = 1;
	vector<int> preorder = { 1 };
	vector<int> inorder = { 1 };

	Test("Test4", preorder, inorder, length);
}

// 完全二叉树
//              1
//           /     \
//          2       3  
//         / \     / \
//        4   5   6   7
void Test5()
{
	const int length = 7;
	vector<int> preorder = { 1, 2, 4, 5, 3, 6, 7 };
	vector<int> inorder = { 4, 2, 5, 1, 6, 3, 7 };

	Test("Test5", preorder, inorder, length);
}

// 输入空指针
void Test6()
{
	vector<int> preorder = {};
	vector<int> inorder = {};
	Test("Test6", preorder, inorder, 0);
}

// 输入的两个序列不匹配
void Test7()
{
	const int length = 7;
	vector<int> preorder = { 1, 2, 4, 5, 3, 6, 7 };
	vector<int> inorder = { 4, 2, 8, 1, 6, 3, 7 };

	Test("Test7: for unmatched input", preorder, inorder, length);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	system("pause");
	return 0;
}
