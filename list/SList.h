#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SlistDateType;
//��������
typedef struct SListNode
{
	SlistDateType data;
	struct SListNode* next;
}SListNode;
//β��Χɾ
void  SListPushBack(SListNode** pphead,SlistDateType x);
void  SListPopBack(SListNode** pphead);

//ͷ��ͷɾ
void  SListPushFront(SListNode** pphead, SlistDateType x);
void  SListPopFront(SListNode** pphead);
//��ӡ
void SListPrint(SListNode* phead); 
//�����
SListNode* SListFind(SListNode* phead, SlistDateType x);

// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SListNode* pos, SlistDateType x);
// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SListNode* pos);
// �����������
void SListDestory(SListNode* plist);



