#include"Slist.h"
//���ٿռ�
SListNode* BuySListNode(SlistDateType x)
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
void  SListPushBack(SListNode** pphead, SlistDateType x)
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
//ͷ��
void  SListPushFront(SListNode** pphead, SlistDateType x)
{
	SListNode* newNode = BuySListNode(x);
	newNode->next = *pphead;
	*pphead = newNode;
}
//ͷɾ
void  SListPopFront(SListNode** pphead)
{
	//1.��
	//2.һ�����
	//3.2�����Ͻ��
	if (*pphead == NULL)
	{
		return;
	}
	else 
	{
		SListNode* next = (*pphead)->next;
		free(*pphead);
		*pphead = next;
	}

}
//��������
SListNode* SListFind(SListNode* phead, SlistDateType x)
{
	SListNode* cur = phead;
	while (cur)//cur!=NULL
	{
		if ((cur->data) == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}
void SListInsertAfter(SListNode* pos, SlistDateType x)
{
	assert(pos);//��������
	//����
	SListNode* newNode = BuySListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	if (pos->next)
	{
		SListNode* next = pos->next;//��һ�����
		SListNode* nextnext = next->next;//���¸����
		pos->next = nextnext;
		free(next);
	}
}