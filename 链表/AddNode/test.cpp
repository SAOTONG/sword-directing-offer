#include"ListNode.h"

// ====================���Դ���====================
void Test(Node* pHead)
{
	cout << "�����ӡ����ڵ�\n";
	PrintList(pHead);
	cout << "�����ӡ����ڵ�\n";
	ReversePrintList(pHead);
}

// ���������ӽڵ�
void Test1()
{
	printf("\nTest1 begins.\n");
	Node * pNode = NULL;
	AddNode(&pNode, 1);
	Test(pNode);
}

// ��ǿ�������ӽڵ�
void Test2()
{
	printf("\nTest2 begins.\n");
	Node * pNode = new Node();
	AddNode(&pNode, 1);
	Test(pNode);
}

// �ӿ�������ɾ���ڵ�
void Test3()
{
	printf("\nTest3 begins.\n");
	Node * pNode = NULL;
	DeleteNode(&pNode, 1);
	Test(pNode);
}

// ��ֻ��1���ڵ��������ɾ���ڵ㣬����ڵ��value��������Ҫɾ����ֵ
void Test4()
{
	printf("\nTest4 begins.\n");
	Node * pNode = new Node();
	DeleteNode(&pNode, 1);
	Test(pNode);
}

// ��ֻ��1���ڵ��������ɾ���ڵ㣬����ڵ��value����Ҫɾ����ֵ
void Test5()
{
	printf("\nTest5 begins.\n");
	Node * pNode = new Node();
	DeleteNode(&pNode, 0);
	Test(pNode);
}

// ��2���ڵ��������ɾ��ͷ�ڵ�
void Test6()
{
	printf("\nTest6 begins.\n");
	Node * pNode = new Node();
	AddNode(&pNode, 1);
	DeleteNode(&pNode, 0);
	Test(pNode);
}

// ��2���ڵ��������ɾ��β�ڵ�
void Test7()
{
	printf("\nTest7 begins.\n");
	Node * pNode = new Node();
	AddNode(&pNode, 1);
	DeleteNode(&pNode, 1);
	Test(pNode);
}

// ��3���ڵ��������ɾ���м�ڵ�
void Test8()
{
	printf("\nTest8 begins.\n");
	Node * pNode = new Node();
	AddNode(&pNode, 1);
	AddNode(&pNode, 2);
	DeleteNode(&pNode, 1);
	Test(pNode);
}

// ���4���ڵ�����
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