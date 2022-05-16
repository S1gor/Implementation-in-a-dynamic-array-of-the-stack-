#ifndef _STACK_H_
#define _STACK_H_

#include<iostream>

struct Stack
{
	int* element = NULL;
	int len = 0;
	int head = -1;
};

void stackInit(Stack* s, int l);

void stackPush(Stack* s, int data);

int popStack(Stack* s);

void writeANumber(Stack* s);

void stackPrint(Stack* s);

void stackNumberMinAndMax(Stack* s);

void stackDestroy(Stack* s);

#endif