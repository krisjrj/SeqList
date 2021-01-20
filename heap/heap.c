#include"heap.h"
void HeapInit(Heap* php, HPDataType* a, int n)
{
	php->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	memcpy(php->_a, a, sizeof(HPDataType) * n);
	php->_capacity = n;
	php->_size = n;
	//¹¹½¨¶Ñ

}
