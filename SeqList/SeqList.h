#pragma once
#include<stdio.h>
#include <stdlib.h>
#include<assert.h>
//顺序表有效数字在数组中必须是连续的
//typedef int SLDataType;
//#define N 10
//struct SeqList
//{
//	SLDataType a[N];
//	int size;
//};
//
//void SeqListPushBack(struct SeqList* ps, SLDataType x);//尾插
//void SeqListPopBack(struct SeqList* ps);//尾删
//void SeqListPushFront(struct SeqList* ps, SLDataType x);//头插
//void SeqListPopFront(struct SeqList* ps);//头删
//

//动态顺序表设计（大小可变）
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;
	int size;		//有效数据的个数
	int capacity;	//容量
}SeqList;

void SeqListInit(SeqList* ps);//初始化
void SeqListPushBack(struct SeqList* ps, SLDataType x);//尾插
void SeqListPopBack(struct SeqList* ps);//尾删
void SeqListPushFront(struct SeqList* ps, SLDataType x);//头插
void SeqListPopFront(struct SeqList* ps);//头删
//任意位置的插入删除
void SeqListInsert(struct SeqList* ps, int pos, SLDataType x);//结构体，位置，数据
void SeqListErase(struct SeqList* ps, int pos);
void SeqListprint(struct SeqList* ps);//打印函数
void SeqListCheckCapacity(SeqList* ps);//检查容量