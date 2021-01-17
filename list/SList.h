#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef int SlistDataType;
//定义链表
typedef struct SListNode
{
	SlistDataType data;
	struct SListNode* next;
}SListNode;
//尾插围删
void  SListPushBack(SListNode** pphead,SlistDataType x);
void  SListPopBack(SListNode** pphead);

//头插头删
void  SListPushFront(SListNode* phead, SlistDataType x);
void  SListPushFront(SListNode* phead);
//打印
void SListPrint(SListNode* phead); 
//开结点




