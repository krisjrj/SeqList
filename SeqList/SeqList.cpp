//实现
#include"SeqList.h"

//初始化
void SeqListInit(SeqList* ps)
{
	ps->a = (SLDataType*)malloc(sizeof(SLDataType) * 4);
	if (ps->a == NULL)
	{
		printf("申请内存失败\n");
		exit(-1);//结束
	}
	ps->size = 0;
	ps->capacity = 4;
}
void SeqListCheckCapacity(SeqList* ps)
{
	//如果满了需要增容
	if (ps->size >= ps->capacity)
	{
		ps->capacity *= 2;
		ps->a = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * ps->capacity);
		if (ps->a == NULL)
		{
			printf("扩容失败\n");
			exit(-1);
		}
	}
}

void SeqListPushBack(struct SeqList* ps, SLDataType x)//尾插
{
	assert(ps);
	SeqListCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}
void SeqListPopBack(struct SeqList* ps)//尾删
{
	assert(ps);
	ps->size--;
}
void SeqListPushFront(struct SeqList* ps, SLDataType x)//头插
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
void SeqListPopFront(struct SeqList* ps)//头删
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
//任意位置的插入删除
void SeqListInsert(struct SeqList* ps, int pos, SLDataType x)//结构体，位置，数据
{
	assert(ps);
	SeqListCheckCapacity(ps);
	for (int end = ps->size ; end > pos; end--)
	{
		ps->a[end] = ps->a[end - 1];
		
	}
	ps->a[pos] = ps->a[x];
	ps->size++;
}
void SeqListErase(struct SeqList* ps, int pos)
{
	assert(ps);
	for (int start = pos; start < ps->size; start++)
	{
		ps->a[start] = ps->a[start + 1];
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