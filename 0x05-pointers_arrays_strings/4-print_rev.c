#include "main.h"

/**
 * print_rev - check the code
 *
 * @str: input
 *
 */
void print_rev(char *str)
{
	int i;
	int n = strlen(str);

	for (i = (n - 1); i >= 0; i--)
	{
		_putchar(str[i]);
	}

	_putchar('\n');
}
