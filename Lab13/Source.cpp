#include<iostream>

/*Задание:
Ввести некоторое число и записать его цифры в стек.Вывести число, у которого цифры идут в обратном порядке.
Цифры из записи числа считывать поочередно(например, с помощью getch()).
Вычислить наименьшую и наибольшую цифры в записи числа.*/

struct Stack
{
	int* element = NULL;
	int len = -1;
	int head = -1;
};

void stackMalloc(Stack* s,int l)
{
	s->element = (int*)malloc(sizeof(int) * l);
	s->len = l;
}

void stackPush(Stack* s, int data)
{
	s->head++;
	if (s->head >= s->len)
		s->element = (int*)realloc(s->element, sizeof(int) * (s->head + 1));
	s->element[s->head] = data;
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
	for (int i = s->head; i >=0; i--)
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
	s->len = -1;
	s->head = -1;
}

int main()
{
	Stack s;
	stackMalloc(&s, 0);

	writeANumber(&s);

	stackPrint(&s);
	stackNumberMinAndMax(&s);

	stackDestroy(&s);
	return 0;
}