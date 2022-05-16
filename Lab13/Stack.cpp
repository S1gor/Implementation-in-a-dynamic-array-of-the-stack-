#include"Stack.h"

void stackInit(Stack* s, int l)
{
	if (s->element == NULL)
	{
		s->element = (int*)malloc(sizeof(int) * l);
		s->len = l;
	}
	else
		printf("Stack is init");
}

void stackPush(Stack* s, int data)
{
	s->head++;
	if (s->head >= s->len)
		s->element = (int*)realloc(s->element, sizeof(int) * (s->head + 1));
	s->element[s->head] = data;
}

int popStack(Stack* s)
{
	if (s->head >= 0)
		return s->element[s->head--];
	else return NULL;
}

void writeANumber(Stack* s)
{
	printf("Write a number:");
	for (char symbol = getchar(); symbol != '\n'; symbol = getchar())
		stackPush(s, symbol - 48);
}

void stackPrint(Stack* s)
{
	printf("\nStack:\n");
	for (int i = s->head; i >= 0; i--)
	{
		printf("[%d] -> %d", i + 1, s->element[i]);
		printf("\n");
	}

	printf("\nReverse - ");
	for (int i = s->head; i >= 0; i--)
		printf("%d", s->element[i]);
	printf("\n");
}

void stackNumberMinAndMax(Stack* s)
{
	int min = 10, max = 0;
	for (int i = s->head; i >= 0; i--)
	{
		if (s->element[i] > max)
			max = s->element[i];
		if (s->element[i] < min)
			min = s->element[i];
	}

	printf("Min - %d\nMax - %d\n", min, max);
}

void stackDestroy(Stack* s)
{
	if (s->element)
		free(s->element);
	s->element == NULL;
	s->len = 0;
	s->head = -1;
}