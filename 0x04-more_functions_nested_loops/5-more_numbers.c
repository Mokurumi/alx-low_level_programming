#include "main.h"
/* more headers goes there */

/**
 * more_numbers - Entry point
 */

void more_numbers(void)
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
