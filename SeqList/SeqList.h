#pragma once
#include<stdio.h>
#include <stdlib.h>
#include<assert.h>
//˳�����Ч�����������б�����������
//typedef int SLDataType;
//#define N 10
//struct SeqList
//{
//	SLDataType a[N];
//	int size;
//};
//
//void SeqListPushBack(struct SeqList* ps, SLDataType x);//β��
//void SeqListPopBack(struct SeqList* ps);//βɾ
//void SeqListPushFront(struct SeqList* ps, SLDataType x);//ͷ��
//void SeqListPopFront(struct SeqList* ps);//ͷɾ
//

//��̬˳�����ƣ���С�ɱ䣩
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;
	int size;		//��Ч���ݵĸ���
	int capacity;	//����
}SeqList;

void SeqListInit(SeqList* ps);//��ʼ��
void SeqListPushBack(struct SeqList* ps, SLDataType x);//β��
void SeqListPopBack(struct SeqList* ps);//βɾ
void SeqListPushFront(struct SeqList* ps, SLDataType x);//ͷ��
void SeqListPopFront(struct SeqList* ps);//ͷɾ
//����λ�õĲ���ɾ��
void SeqListInsert(struct SeqList* ps, int pos, SLDataType x);//�ṹ�壬λ�ã�����
void SeqListErase(struct SeqList* ps, int pos);
void SeqListprint(struct SeqList* ps);//��ӡ����
void SeqListCheckCapacity(SeqList* ps);//�������