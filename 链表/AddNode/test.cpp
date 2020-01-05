#include"ListNode.h"

// ====================测试代码====================
void Test(Node* pHead)
{
	cout << "正向打印链表节点\n";
	PrintList(pHead);
	cout << "反向打印链表节点\n";
	ReversePrintList(pHead);
}

// 向空链表添加节点
void Test1()
{
	printf("\nTest1 begins.\n");
	Node * pNode = NULL;
	AddNode(&pNode, 1);
	Test(pNode);
}

// 向非空链表添加节点
void Test2()
{
	printf("\nTest2 begins.\n");
	Node * pNode = new Node();
	AddNode(&pNode, 1);
	Test(pNode);
}

// 从空链表中删除节点
void Test3()
{
	printf("\nTest3 begins.\n");
	Node * pNode = NULL;
	DeleteNode(&pNode, 1);
	Test(pNode);
}

// 从只有1个节点的链表中删除节点，这个节点的value并不是需要删除的值
void Test4()
{
	printf("\nTest4 begins.\n");
	Node * pNode = new Node();
	DeleteNode(&pNode, 1);
	Test(pNode);
}

// 从只有1个节点的链表中删除节点，这个节点的value是需要删除的值
void Test5()
{
	printf("\nTest5 begins.\n");
	Node * pNode = new Node();
	DeleteNode(&pNode, 0);
	Test(pNode);
}

// 从2个节点的链表中删除头节点
void Test6()
{
	printf("\nTest6 begins.\n");
	Node * pNode = new Node();
	AddNode(&pNode, 1);
	DeleteNode(&pNode, 0);
	Test(pNode);
}

// 从2个节点的链表中删除尾节点
void Test7()
{
	printf("\nTest7 begins.\n");
	Node * pNode = new Node();
	AddNode(&pNode, 1);
	DeleteNode(&pNode, 1);
	Test(pNode);
}

// 从3个节点的链表中删除中间节点
void Test8()
{
	printf("\nTest8 begins.\n");
	Node * pNode = new Node();
	AddNode(&pNode, 1);
	AddNode(&pNode, 2);
	DeleteNode(&pNode, 1);
	Test(pNode);
}

// 输出4个节点链表
void Test9()
{
	printf("\nTest9 begins.\n");
	Node * pNode = new Node();
	AddNode(&pNode, 1);
	AddNode(&pNode, 2);
	AddNode(&pNode, 3);
	Test(pNode);
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
	Test8();
	Test9();
	system("pause");
	return 0;
}