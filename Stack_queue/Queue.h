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
//��β����
void QueuePush(Queue* pq, QDataType x);
//��ͷɾ��
void QueuePop(Queue* pq);
//ȡ��ͷ����
QDataType QueueFront(Queue* pq);
//ȡ��β����
QDataType QueueBack(Queue* pq);
//����1�ǿգ�����0�ɿ�
int QueueEmpty(Queue* pq);
//��ȡ���ݸ���
void QueueSize(Queue* pq);