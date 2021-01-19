#include"Stack.h"

//��ʼ��
void StackInit(Stack* pst)
{
	assert(pst);
	pst->_a = malloc(sizeof(STDateTpye) * 4);
	pst->_top = 0;
	pst->_capacity = 4;
}
//����
void StackDestory(Stack* pst)
{
	assert(pst);
	free(pst->_a);
	pst->_a = NULL;
	pst->_top = pst->_capacity = 0;
}
//��ջ
void StackPush(Stack* pst,STDateTpye x)
{
	assert(pst);
	//�ռ䲻������
	if (pst->_top == pst->_capacity)
	{
		pst->_capacity *= 2;
		STDateTpye* tmp = (STDateTpye*)realloc(pst->_a, sizeof((STDateTpye*)pst->_capacity));
		if (tmp == NULL)
		{
			printf("�ڴ�����ʧ��");
			exit(-1);
		}
		else
		{
			pst->_a = tmp;
		}
	}
	//��ջ
	pst->_a[pst->_top] = x;
	pst->_top++;
}
//��ջ
void StackPop(Stack* pst)
{
	assert(pst);
	assert(pst->_top > 0);
	--pst->_top;
}
//��ȡ���ݸ���
int StackSize(Stack* pst)
{
	assert(pst);
	return pst->_top;
}
//����1�ǿգ�����0�ɿ�
int StackEmpty(Stack* pst)
{
	assert(pst);
	return pst->_top == 0 ? 1 : 0;
}
//��ȡջ������
STDateTpye StackTop(Stack* pst)
{
	assert(pst);
	assert(pst->_top > 0);
	return pst->_a[pst->_top-1];
}	