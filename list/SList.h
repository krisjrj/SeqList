#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SlistDateType;
//定义链表
typedef struct SListNode
{
	SlistDateType data;
	struct SListNode* next;
}SListNode;
//尾插围删
void  SListPushBack(SListNode** pphead,SlistDateType x);
void  SListPopBack(SListNode** pphead);

//头插头删
void  SListPushFront(SListNode** pphead, SlistDateType x);
void  SListPopFront(SListNode** pphead);
//打印
void SListPrint(SListNode* phead); 
//开结点
SListNode* SListFind(SListNode* phead, SlistDateType x);

// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SlistDateType x);
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos);
// 单链表的销毁
void SListDestory(SListNode* plist);



