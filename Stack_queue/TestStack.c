#include"Stack.h"
#include"Queue.h"
//void TestStack()
//{
//	Stack st;
//	StackInit(&st);
//
//	//��ջ
//	StackPush(&st, 1);
//	StackPush(&st, 2);
//	printf("%d ", StackTop(&st));
//	StackPop(&st);
//
//	StackPush(&st, 3);
//	StackPush(&st, 4);
//	/*StackPush(&st, 5);
//
//	printf("%d ", StackTop(&st));
//	StackPop(&st);
//
//	StackPush(&st, 6);
//	StackPush(&st, 7);*/
//
//	while (!StackEmpty(&st))
//	{
//		printf("%d ", StackTop(&st));
//		StackPop(&st);
//	}
//	printf("\n");
//	StackDestory(&st);
//
//
//}
void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	printf("%d ", QueueFront(&q));
	QueuePop(&q);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	while(!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");
	QueueDestory(&q);

}
int main()
{
	//TestStack();
	TestQueue();
	return 0;
}