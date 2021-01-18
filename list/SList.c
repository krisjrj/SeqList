#include"Slist.h"
//开辟空间
SListNode* BuySListNode(SlistDateType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		printf("申请内存失败\n");
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
		//找尾
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
}
//尾删
void  SListPopBack(SListNode** pphead)
{
	//1.链表为空
	//2.一个结点
	//3.两个或以上结点
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
//头插
void  SListPushFront(SListNode** pphead, SlistDateType x)
{
	SListNode* newNode = BuySListNode(x);
	newNode->next = *pphead;
	*pphead = newNode;
}
//头删
void  SListPopFront(SListNode** pphead)
{
	//1.空
	//2.一个结点
	//3.2个以上结点
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
//单链表查改
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
	assert(pos);//声明存在
	//插入
	SListNode* newNode = BuySListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	if (pos->next)
	{
		SListNode* next = pos->next;//下一个结点
		SListNode* nextnext = next->next;//下下个结点
		pos->next = nextnext;
		free(next);
	}
}