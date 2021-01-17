#include"Slist.h"
SListNode* BuySListNode(SlistDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		printf("�����ڴ�ʧ��\n");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	
	return newNode;
}

void SListPrint(SListNode* phead)
{
	SListNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
void  SListPushBack(SListNode** pphead, SlistDataType x)
{
	SListNode* newNode = BuySListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newNode;
	}
	else 
	{
		//��β
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
}
//βɾ
void  SListPopBack(SListNode** pphead)
{
	//1.����Ϊ��
	//2.һ�����
	//3.���������Ͻ��
	if (*pphead == NULL)
	{
		return;
	}
	else if ((*pphead)->next == NULL)
	{
		free(*pphead); 
		*pphead = NULL;
	}
	else
	{
		SListNode* prev = NULL;
		SListNode* tail = *pphead;
		while (tail->next!= NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
	}
}

