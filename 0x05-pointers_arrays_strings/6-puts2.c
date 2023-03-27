#include "main.h"

/**
 * puts2 - check the code
 *
 * @str: input
 *
 */
void puts2(char *str)
{
	int i;
	int n = strlen(str);

	for (i = 0; i < n; i++)
	{
		_putchar(str[i]);
		i++;
	}

	_putchar('\n');
}
