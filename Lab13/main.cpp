#include"Stack.h"

/*�������:
������ ��������� ����� � �������� ��� ����� � ����.������� �����, � �������� ����� ���� � �������� �������.
����� �� ������ ����� ��������� ����������(��������, � ������� getch()).
��������� ���������� � ���������� ����� � ������ �����.*/

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