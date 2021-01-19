#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int QDataType;
typedef struct QueueNode
{
	struct QueueNode* _next;
	QDataType _data;
}QueueNode;

typedef struct Queue
{
	QueueNode* _head;
	QueueNode* _tail;
}Queue;
void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
//队尾插入
void QueuePush(Queue* pq, QDataType x);
//队头删除
void QueuePop(Queue* pq);
//取队头数据
QDataType QueueFront(Queue* pq);
//取队尾数据
QDataType QueueBack(Queue* pq);
//返回1是空，返回0飞空
int QueueEmpty(Queue* pq);
//获取数据个数
void QueueSize(Queue* pq);