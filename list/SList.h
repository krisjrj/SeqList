#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef int SlistDataType;
//��������
typedef struct SListNode
{
	SlistDataType data;
	struct SListNode* next;
}SListNode;
//β��Χɾ
void  SListPushBack(SListNode** pphead,SlistDataType x);
void  SListPopBack(SListNode** pphead);

//ͷ��ͷɾ
void  SListPushFront(SListNode* phead, SlistDataType x);
void  SListPushFront(SListNode* phead);
//��ӡ
void SListPrint(SListNode* phead); 
//�����




