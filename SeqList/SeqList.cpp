//ʵ��
#include"SeqList.h"

//��ʼ��
void SeqListInit(SeqList* ps)
{
	ps->a = (SLDataType*)malloc(sizeof(SLDataType) * 4);
	if (ps->a == NULL)
	{
		printf("�����ڴ�ʧ��\n");
		exit(-1);//����
	}
	ps->size = 0;
	ps->capacity = 10;
}
void SeqListCheckCapacity(SeqList* ps)
{
	//���������Ҫ����
	if (ps->size >= ps->capacity)
	{
		ps->capacity *= 2;
		ps->a = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * ps->capacity);
		if (ps->a == NULL)
		{
			printf("����ʧ��\n");
			exit(-1);
		}
	}
}

void SeqListPushBack(struct SeqList* ps, SLDataType x)//β��
{
	assert(ps);
	SeqListCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}
void SeqListPopBack(struct SeqList* ps)//βɾ
{
	assert(ps);
	ps->size--;
}
void SeqListPushFront(struct SeqList* ps, SLDataType x)//ͷ��
{
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[0] = x;
	ps->size++;
}
void SeqListPopFront(struct SeqList* ps)//ͷɾ
{
	assert(ps);
	int start = 0;
	while (start < ps->size - 1)
	{
		ps->a[start] = ps->a[start + 1];
		++start;
	}
	ps->size--;
}
//����λ�õĲ���ɾ��
void SeqListInsert(struct SeqList* ps, int pos, SLDataType x)//�ṹ�壬λ�ã�����
{
	assert(ps);
	assert(pos < ps->size);
	assert(pos > 0);
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	while (pos <= end)
	{
		ps->a[end] = ps->a[end - 1];
		--end;
	}
	ps->a[pos] = x;
	ps->size++;
}
void SeqListErase(struct SeqList* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	int start = pos;
	while (start < ps->size-1)
	{
		ps->a[start] = ps->a[start + 1];
		++start;
	}
	ps->size--;
}
void SeqListprint(struct SeqList* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}