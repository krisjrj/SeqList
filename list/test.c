#include"SList.h"
int main()
{
	SListNode* pList = NULL;
	//SListPrint(pList);
	SListPushBack(&pList,1);
	SListPushBack(&pList,2);
	SListPushBack(&pList,3);
	SListPrint(pList);
	SListPopBack(&pList);
	SListPrint(pList);
	SListPopBack(&pList);
	SListPrint(pList);
	SListPopBack(&pList);
	SListPrint(pList);
	SListPopBack(&pList);
	SListPrint(pList);



	return 0;
}