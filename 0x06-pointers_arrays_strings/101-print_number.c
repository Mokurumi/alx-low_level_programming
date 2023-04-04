#include "main.h"

/**
 * print_number - Prints putchar
 *
 * @n: first int
 *
 */
void print_number(int n)
{
	unsigned int a = 0;

	if (n < 0)
	{
		_putchar('-');
		a = -n;
	}
	else
	{
		a = n;
	}

	if (a / 10 != 0)
	{
		print_number(a / 10);
	}

	_putchar('0' + a % 10);
}
