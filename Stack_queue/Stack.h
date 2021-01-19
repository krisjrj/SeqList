#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int STDateTpye;
typedef struct Stack
{
	STDateTpye* _a;
	int _top;//ջ���±�
	int _capacity;
}Stack;
//��ʼ��
void StackInit(Stack* pst);
//����
void StackDestory(Stack* pst);
//��ջ
void StackPush(Stack* pst,STDateTpye x);
//��ջ
void StackPop(Stack* pst);
//��ȡ���ݸ���
int StackSize(Stack st);
//����1�ǿգ�����0�ǿ�
int StackEmpty(Stack* pst);
//��ȡջ������
STDateTpye StackTop(Stack* pst);