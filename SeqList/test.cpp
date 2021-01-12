#include"SeqList.h"
//≤‚ ‘Õ∑≤ÂÕ∑…æ
void TestSeqList1()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListprint(&s);

	/*SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListprint(&s);

	SeqListPushFront(&s, -1);
	SeqListPushFront(&s, -2);
	SeqListPushFront(&s, -3);
	SeqListprint(&s);

	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListprint(&s);*/

	SeqListInsert(&s, 2, 4);
	SeqListprint(&s);
	SeqListErase(&s, 1);
	SeqListprint(&s);
}

int main()
{
	TestSeqList1();
	return 0;
}
