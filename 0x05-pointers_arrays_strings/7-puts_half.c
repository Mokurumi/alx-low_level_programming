#include "main.h"

/**
 * puts_half - check the code
 *
 * @str: input
 *
 */
void puts_half(char *str)
{
	int i;
	int n = strlen(str);

	for (i = (n - n / 2); i < n; i++)
	{
		_putchar(str[i]);
	}

	_putchar('\n');
}
