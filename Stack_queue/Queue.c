#include"Queue.h"
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_head = pq->_tail = NULL;
}
void QueueDestory(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->_head;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	pq->_head = pq->_tail = NULL;
}
//插入
void QueuePush(Queue* pq, QDataType x)
{
	//1.为空
	//2.1个以上
	assert(pq);
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL)
	{
		printf("内存不足");
		exit(-1);
	}
	newNode->_data = x;
	newNode->_next = NULL;
	if (pq->_head == NULL)
	{
		pq->_tail = pq->_head = newNode;
	}
	else
	{
		pq->_tail->_next = newNode;
		pq->_tail = newNode;
		
	}

}
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->_head);
	QueueNode* next = pq->_head->_next;
	free(pq->_head);
	pq->_head = next;
	if (pq->_head == NULL)
	{
		pq->_tail == NULL;
	}
}
//取队头数据
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->_head);
	return pq->_head->_data;
}
//取队尾数据
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->_tail);
	return pq->_tail->_data;
}
//返回1是空，返回0非空
int QueueEmpty(Queue* pq)
{
	assert(pq);
	if (pq->_head == NULL)
		return 1;
	else
		return 0;
}
//获取数据个数
void QueueSize(Queue* pq)
{
	assert(pq);
	//初始化
	QueueNode* cur = pq->_head;
	int size = 0;
	while (cur)
	{
		size++;
		cur = cur->_next;
	}
	return size;

}
