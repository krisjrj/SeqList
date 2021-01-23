#include<stdio.h>
#include<stdlib.h>
//定义二叉树
//定义节点存放的值
typedef char BTDataType;
//定义树的结构体
//存放左右子树、根节点
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

//先序遍历
void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	//根->左->右
	printf("%c ", root->_data);
	PrevOrder(root->_left);
	PrevOrder(root->_right);
	 
}
//中序遍历
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	//左、根、右
	InOrder(root->_left);
	printf("%c ", root->_data);
	InOrder(root->_right);
}

//后序遍历
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	//左、右节点、根节点
	PostOrder(root->_left);
	PostOrder(root->_right);
	printf("%c ", root->_data);
}
//求二叉树节点
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

//伪树
BTNode* CreateNode(int x)
{
	//开空间
	BTNode* Node = (BTNode*)malloc(sizeof(BTNode));
	Node->_data = x;
	Node->_left = NULL;
	Node->_right = NULL;
	return Node;
}

//求叶子节点个数
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