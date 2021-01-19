#include"Stack.h"

//初始化
void StackInit(Stack* pst)
{
	assert(pst);
	pst->_a = malloc(sizeof(STDateTpye) * 4);
	pst->_top = 0;
	pst->_capacity = 4;
}
//销毁
void StackDestory(Stack* pst)
{
	assert(pst);
	free(pst->_a);
	pst->_a = NULL;
	pst->_top = pst->_capacity = 0;
}
//入栈
void StackPush(Stack* pst,STDateTpye x)
{
	assert(pst);
	//空间不足增容
	if (pst->_top == pst->_capacity)
	{
		pst->_capacity *= 2;
		STDateTpye* tmp = (STDateTpye*)realloc(pst->_a, sizeof((STDateTpye*)pst->_capacity));
		if (tmp == NULL)
		{
			printf("内存申请失败");
			exit(-1);
		}
		else
		{
			pst->_a = tmp;
		}
	}
	//入栈
	pst->_a[pst->_top] = x;
	pst->_top++;
}
//出栈
void StackPop(Stack* pst)
{
	assert(pst);
	assert(pst->_top > 0);
	--pst->_top;
}
//获取数据个数
int StackSize(Stack* pst)
{
	assert(pst);
	return pst->_top;
}
//返回1是空，返回0飞空
int StackEmpty(Stack* pst)
{
	assert(pst);
	return pst->_top == 0 ? 1 : 0;
}
//获取栈顶数据
STDateTpye StackTop(Stack* pst)
{
	assert(pst);
	assert(pst->_top > 0);
	return pst->_a[pst->_top-1];
}	