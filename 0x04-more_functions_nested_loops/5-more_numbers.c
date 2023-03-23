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
			if (i >= 10)
			{
				_putchar((i / 10) + '0');
			}
			_putchar((i % 10) + '0');
		}

		_putchar('\n');
	}
}
