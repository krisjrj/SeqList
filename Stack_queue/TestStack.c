#include"Stack.h"
void TestStack()
{
	Stack st;
	StackInit(&st);

	//»Î’ª
	StackPush(&st, 1);
	StackPush(&st, 2);
	printf("%d ", StackTop(&st));
	StackPop(&st);

	StackPush(&st, 3);
	StackPush(&st, 4);
	/*StackPush(&st, 5);

	printf("%d ", StackTop(&st));
	StackPop(&st);

	StackPush(&st, 6);
	StackPush(&st, 7);*/

	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	printf("\n");
	StackDestory(&st);


}
int main()
{
	TestStack();
	return 0;
}