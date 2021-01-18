#include"SList.h"
int TestSList1()
{
	SListNode* pList = NULL;
	//SListPrint(pList);
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPrint(pList);
	SListPopBack(&pList);
	SListPrint(pList);
	SListPopBack(&pList);
	SListPrint(pList);
	SListPopBack(&pList);
	SListPrint(pList);
	SListPopBack(&pList);
	SListPrint(pList);
	SListPushFront(&pList, 1);
	SListPushFront(&pList, 2);
	SListPushFront(&pList, 3);
	SListPushFront(&pList, 4);
	SListPrint(pList);
	SListPopFront(&pList);
	SListPrint(pList);
	return 0;
}
int TestSList2()
{
	SListNode* pList = NULL;
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPushBack(&pList, 5);
	SListPushBack(&pList, 6);
	SListPushBack(&pList, 7);

	SListPrint(pList);
	/*SListNode* pos = SListFind(pList, 3);
	if (pos)
	{
		pos->data = 30;
	}
	SListPrint(pList);*/
	SListInsertAfter(pList->next->next, 5);
	SListPrint(pList);
	SListEraseAfter(pList);//NULL第1位 pList 2 pList->next 3以次类推
	SListPrint(pList);
	return 0;
}
int main()
{
	//TestSList1();
	TestSList2();
	return 0;
}