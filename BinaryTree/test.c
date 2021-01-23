#include<stdio.h>
#include<stdlib.h>
//���������
//����ڵ��ŵ�ֵ
typedef char BTDataType;
//�������Ľṹ��
//����������������ڵ�
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

//�������
void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	//��->��->��
	printf("%c ", root->_data);
	PrevOrder(root->_left);
	PrevOrder(root->_right);
	 
}
//�������
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	//�󡢸�����
	InOrder(root->_left);
	printf("%c ", root->_data);
	InOrder(root->_right);
}

//�������
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	//���ҽڵ㡢���ڵ�
	PostOrder(root->_left);
	PostOrder(root->_right);
	printf("%c ", root->_data);
}
//��������ڵ�
int TreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + TreeSize(root->_left) + TreeSize(root->_right);
	}
}

//α��
BTNode* CreateNode(int x)
{
	//���ռ�
	BTNode* Node = (BTNode*)malloc(sizeof(BTNode));
	Node->_data = x;
	Node->_left = NULL;
	Node->_right = NULL;
	return Node;
}

//��Ҷ�ӽڵ����
//int TreeleafSize(BTNode* root)
//{
//	/*int leafsize = 0;*/
//	if (root == NULL)
//		return 0;
//	else
//	{
//		if (root->_left == NULL && root->_right == NULL)
//		{
//			return 1 + TreeleafSize(root->_left) + TreeleafSize(root->_right);
//		}
//		else
//			return 0 + TreeleafSize(root->_left) + TreeleafSize(root->_right);
//	}
//}
int TreeleafSize(BTNode* root)
{
	/*int leafsize = 0;*/
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return TreeleafSize(root->_left) + TreeleafSize(root->_right);
}
int TreeDepth(BTNode* root)
{
	return 0;
}

int main()
{
	BTNode* A = CreateNode('A');
	BTNode* B = CreateNode('B');
	BTNode* C = CreateNode('C');
	BTNode* D = CreateNode('D');
	BTNode* E = CreateNode('E');
	A->_left = B;
	A->_right = C;
	B->_left = D;
	B->_right = E;
	PrevOrder(A);
	printf("\n");
	InOrder(A);
	printf("\n");
	PostOrder(A);
	printf("\n");
	printf("Treesize = %d\n", TreeSize(A));
	printf("Treeleafsize = %d\n", TreeleafSize(A));
	return 0;
}