#include "main.h"
/* more headers goes there */

/**
 * print_alphabet_x10 - Entry point
 */

void print_alphabet_x10(void)
{

	char i;
	int k;

	for (k = 0; k < 10; k++)
	{
		for (i = 0; i <= 14; i++)
		{
			_putchar(i + '0');
		}

		_putchar('\n');
	}
}
