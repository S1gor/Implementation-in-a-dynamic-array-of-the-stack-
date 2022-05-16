#include"Stack.h"

/*Задание:
Ввести некоторое число и записать его цифры в стек.Вывести число, у которого цифры идут в обратном порядке.
Цифры из записи числа считывать поочередно(например, с помощью getch()).
Вычислить наименьшую и наибольшую цифры в записи числа.*/

int main()
{
	Stack s;
	stackInit(&s, 0);
	writeANumber(&s);

	stackPrint(&s);
	stackNumberMinAndMax(&s);

	stackDestroy(&s);
	return 0;
}