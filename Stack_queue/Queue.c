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
//����
void QueuePush(Queue* pq, QDataType x)
{
	//1.Ϊ��
	//2.1������
	assert(pq);
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL)
	{
		printf("�ڴ治��");
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
//ȡ��ͷ����
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->_head);
	return pq->_head->_data;
}
//ȡ��β����
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->_tail);
	return pq->_tail->_data;
}
//����1�ǿգ�����0�ǿ�
int QueueEmpty(Queue* pq)
{
	assert(pq);
	if (pq->_head == NULL)
		return 1;
	else
		return 0;
}
//��ȡ���ݸ���
void QueueSize(Queue* pq)
{
	assert(pq);
	//��ʼ��
	QueueNode* cur = pq->_head;
	int size = 0;
	while (cur)
	{
		size++;
		cur = cur->_next;
	}
	return size;

}
