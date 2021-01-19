#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int STDateTpye;
typedef struct Stack
{
	STDateTpye* _a;
	int _top;//栈顶下标
	int _capacity;
}Stack;
//初始化
void StackInit(Stack* pst);
//销毁
void StackDestory(Stack* pst);
//入栈
void StackPush(Stack* pst,STDateTpye x);
//出栈
void StackPop(Stack* pst);
//获取数据个数
int StackSize(Stack st);
//返回1是空，返回0非空
int StackEmpty(Stack* pst);
//获取栈顶数据
STDateTpye StackTop(Stack* pst);