#include"heap.h"
void HeapInit(Heap* php, HPDataType* a, int n)
{
	php->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	memcpy(php->_a, a, sizeof(HPDataType) * n);
	php->_capacity = n;
	php->_size = n;
	//¹¹½¨¶Ñ
	
}
//void Swap(int* p,int* c)
//{
//	int* tmp = *p;
//	*p = *c;
//	*c = *tmp;
//}
void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child<n)
	{
		if (child + 1 < n && a[child + 1] < a[child])
		{
			++child;
		}
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else 
		{
			break;
		}
	}
}